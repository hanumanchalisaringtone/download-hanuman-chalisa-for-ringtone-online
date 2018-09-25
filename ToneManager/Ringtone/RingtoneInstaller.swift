//
//  RingtoneInstaller.swift
//  ToneManager
//
//  Created by Jesper Flodin on 2018-09-12.
//  Copyright © 2018 Jesper Flodin. All rights reserved.
//

import Foundation
import BugfenderSDK

/// Class that handles tonelibrary import and deletion of ringtones
final class RingtoneInstaller {
    
    /// Serial queue where import calls are placed
    fileprivate let queue = DispatchQueue(label: "fi.flodin.tonemanager.SerialRingtoneInstallerQueue", attributes: .concurrent)

}

//MARK: Uninstall methods
extension RingtoneInstaller {
    /// Removes ringtone from tonelibrary
    ///
    /// - Parameter identifier: identifier to remove
    /// - Returns: returns true if successful
    func removeRingtone(_ ringtone : Ringtone, deleteFile : Bool = true, shouldCallBackToStore: Bool = true, completionHandler: @escaping (Bool) -> Void) {
        queue.async {
            if !TLToneManagerHandler.sharedInstance().canImport() {
                Bugfender.error("TLToneManager does not respond to required selectors, unknown error")
                DispatchQueue.main.async {
                    completionHandler(false)
                }
                return
            }
            if let identifier = ringtone.identifier {
                TLToneManagerHandler.sharedInstance().removeImportedTone(withIdentifier: identifier)
                ringtone.identifier = nil
            }
            
            if deleteFile {
                BFLog("Deleting ringtone file")
                ringtone.deleteFile()
            }
            
            DispatchQueue.main.async {
                
                if deleteFile {
                    RingtoneStore.sharedInstance.allRingtones.remove(where: { $0 == ringtone })
                }
                if shouldCallBackToStore {
                    RingtoneStore.sharedInstance.writeToPlist()
                }
                completionHandler(true)
            }
        }
    }
    
    func removeRingtones(inArray ringtonesArray: Array<Ringtone>, deleteFiles: Bool = false, completionHandler: @escaping (Int, Int) -> Void) {
        let group = DispatchGroup()
        
        BFLog("Starting uninstall for an array of ringtones with deletefiles = \(deleteFiles)")
        
        var uninstalledTones : Int = 0
        var failedTones : Int = 0
        
        for currentTone in ringtonesArray {
            
            group.enter()
            removeRingtone(currentTone, deleteFile: deleteFiles, shouldCallBackToStore: false, completionHandler: { (success) in
                if success {
                    uninstalledTones += 1
                } else {
                    failedTones += 1
                }
                group.leave()
            })
        }
        
        group.notify(queue: .main) {
            RingtoneStore.sharedInstance.writeToPlist()
            completionHandler(uninstalledTones, failedTones)
        }
        
    }
}

//MARK: Install methods
extension RingtoneInstaller {
    
    fileprivate func handleInstall(status success: Bool,
                                   toneIdentifier: String?,
                                   ringtone: Ringtone,
                                   toneLibraryData: (metaData: [String:Any], toneData: Data),
                                   shouldCallBackToStore: Bool,
                                   retryOnFailure: Bool = false,
                                   completionHandler: @escaping (Ringtone, Bool) -> Void) {
        
        if success, let identifierSuccess = toneIdentifier {
            BFLog("Import success, got identifier: %@", identifierSuccess)
            DispatchQueue.main.async { // to make sure tableview is not reloading
                ringtone.identifier = identifierSuccess
                if shouldCallBackToStore {
                    RingtoneStore.sharedInstance.writeToPlist()
                }
                
                completionHandler(ringtone, success)
            }
            
        } else if !success, handleInstallError(ringtone) {
            //not success, check if name already installed and equals this tone
            Bugfender.warning("Ringtone install failed for ringtone: \(ringtone.description) Will search tonelibrary for matching name...")
            DispatchQueue.main.async { // to make sure tableview is not reloading
                if shouldCallBackToStore {
                    RingtoneStore.sharedInstance.writeToPlist()
                }
                
                completionHandler(ringtone, true)
            }
        } else {
            // Failed
            Bugfender.error("Ringtone install failed (retryonfailure=\(retryOnFailure), could not find installed ringtone with matching name and size/duration for tone: \(ringtone.description)")
            if retryOnFailure {
                queue.async {
                    guard let oldName = toneLibraryData.metaData["Name"] as? String else { return }
                    var newName = oldName
                    newName.appendRandom()
                    BFLog("Retrying ringtone install, oldname=%@, newname=%@",oldName,newName)
                    var newMetaData = toneLibraryData
                    newMetaData.metaData.updateValue(newName, forKey: "Name")
                    
                    self.installRingtone(ringtone, toneLibraryData: newMetaData, retryOnFailure: false, completionHandler: { (tone, installStatus) in
                        DispatchQueue.main.async {
                            if installStatus {
                                ringtone.name = newName
                                RingtoneStore.sharedInstance.writeToPlist()
                            }
                            completionHandler(tone, installStatus)
                        }
                    })
                }
            } else {
                DispatchQueue.main.async { // to make sure tableview is not reloading
                    if shouldCallBackToStore {
                        RingtoneStore.sharedInstance.writeToPlist()
                    }
                    
                    completionHandler(ringtone, success)
                }
            }
        }
    }
    
    fileprivate func handleInstallError(_ ringtone : Ringtone) -> Bool {
        // does tone with this name already exist in tonelibrary?
        let library = ToneLibraryProxy()
        if library.setIdentifierIfToneIsInstalled(ringtone) {
            BFLog("Successfully set identifier for ringtone: %@", ringtone.description)
            return true
        }
        Bugfender.error("Current ringtone could not be installed and does not seem to already be installed, retry with different name")
        
        
        return false
    }
    
    fileprivate func prepareToneLibraryData(forRingtone ringtone: Ringtone) -> (metaData: [String:Any], toneData: Data)? {
        if ringtone.identifier != nil {
            BFLog("Ringtone is already installed, tone: %@", ringtone.fileURL.path)
            return nil
        }
        var toneLibraryMetaData = [String:Any]()
        toneLibraryMetaData["Name"] = ringtone.name
        toneLibraryMetaData["Total Time"] = NSNumber(value: ringtone.rawDuration*1000).intValue
        toneLibraryMetaData["Purchased"] = ringtone.purchased
        toneLibraryMetaData["Protected Content"] = ringtone.protectedContent
        
        guard let toneData = ringtone.getData() else {
            Bugfender.error("Could not get data for ringtone with path \(ringtone.fileURL.path)")
            return nil
        }
        
        return (toneLibraryMetaData, toneData)
    }
    
    /// Installs ringtone in tonelibrary
    ///
    /// - Parameters:
    ///   - ringtone: Ringtone object to install
    ///   - completionHandler: Gets executed after import, ringtone object is passed to it. identifier is set if import was successful
    func installRingtone(_ ringtone : Ringtone,
                         toneLibraryData: (metaData: [String:Any], toneData: Data)? = nil,
                         shouldCallBackToStore: Bool = true,
                         retryOnFailure: Bool = false,
                         completionHandler: @escaping (Ringtone, Bool) -> Void)  {
        queue.async {
            if !TLToneManagerHandler.sharedInstance().canImport() {
                Bugfender.error("TLToneManager does not respond to required selectors, unknown error")
                DispatchQueue.main.async {
                    completionHandler(ringtone, false)
                }
                return
            }
            
            let toneLibraryTuple: (metaData: [String:Any], toneData: Data)
            if let metaData = toneLibraryData {
                toneLibraryTuple = metaData
            } else {
                guard let toneLibraryInfo = self.prepareToneLibraryData(forRingtone: ringtone) else { return }
                toneLibraryTuple = toneLibraryInfo
            }
            
            TLToneManagerHandler.sharedInstance().importTone(toneLibraryTuple.toneData, metadata: toneLibraryTuple.metaData) { [weak self] (success : Bool, toneIdentifier : String?) in
                BFLog("Ringtone install completionblock")
                guard let strongSelf = self else { return }
                
                strongSelf.handleInstall(status: success,
                                         toneIdentifier: toneIdentifier,
                                         ringtone: ringtone,
                                         toneLibraryData: toneLibraryTuple,
                                         shouldCallBackToStore: shouldCallBackToStore,
                                         retryOnFailure: retryOnFailure,
                                         completionHandler: completionHandler)
            }
        }
    }
    
    func installRingtones(inArray ringtonesArray: Array<Ringtone>, completionHandler: @escaping (Int, Int) -> Void) {
        let group = DispatchGroup()
        
        BFLog("Starting install for an array of ringtones")
        
        var installedTones : Int = 0
        var failedTones : Int = 0
        
        for currentTone in ringtonesArray {
            
            group.enter()
            installRingtone(currentTone, shouldCallBackToStore: false) { (ringtone, success) in
                if success {
                    installedTones += 1
                } else {
                    failedTones += 1
                }
                group.leave()
            }
        }
        
        group.notify(queue: .main) {
            RingtoneStore.sharedInstance.writeToPlist()
            completionHandler(installedTones, failedTones)
        }
    }
}