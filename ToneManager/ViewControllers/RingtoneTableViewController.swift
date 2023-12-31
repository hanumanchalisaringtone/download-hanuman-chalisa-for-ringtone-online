//
//  RingtoneTableViewController.swift
//  ToneManager
//
//  Created by Jesper Flodin on 2018-09-07.
//
//
//  MIT License
//
//  Copyright (c) 2018 Jesper Flodin
//
//  Permission is hereby granted, free of charge, to any person obtaining a copy
//  of this software and associated documentation files (the "Software"), to deal
//  in the Software without restriction, including without limitation the rights
//  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
//  copies of the Software, and to permit persons to whom the Software is
//  furnished to do so, subject to the following conditions:
//
//  The above copyright notice and this permission notice shall be included in all
//  copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
//  SOFTWARE.

import UIKit
import BugfenderSDK
import PKHUD
import AVFoundation
import XLActionController
import FileBrowser
import ContactsUI


/// Shows available and installed ringtones
final class RingtoneTableViewController : UITableViewController {
    
    /// Identifier for Cell used to show a ringtone
    private let cellId = "RingtoneTableCell"
    
    /// Height for each row
    private let rowHeight : CGFloat = 60
    
    /// Userdefaults object
    let defaults = UserDefaults.standard
    
    /// Table filter variable 0=All, 1=Installed, 2=Not installed
    var ringtoneFilter : Int = 0
    
    var ringtonePlayer : RingtonePlayer?
    
    var contactPicker : CNContactPickerViewController? = nil
    var ringtoneAssigner : RingtoneAssigner? = nil
    
}


//MARK: RingtoneStore methods
extension RingtoneTableViewController {
    
    func updateAvailableRingtones() {
        BFLog("update called in ringtonetableview")
        ringtonePlayer?.stopPlaying()
        
        RingtoneManager.updateRingtones { [weak self] in
            guard let strongSelf = self else { return }
            
            RingtoneStore.sharedInstance.allRingtones.lockArray()
            strongSelf.tableView.reloadData()
            RingtoneStore.sharedInstance.allRingtones.unlockArray()
            
        }
    }
}

extension RingtoneTableViewController : CNContactPickerDelegate {
    
    func openContactPicker() {
        contactPicker = CNContactPickerViewController()
        contactPicker!.delegate = self

        present(contactPicker!, animated: true, completion: nil)
    }
    
    func contactPicker(_ picker: CNContactPickerViewController, didSelect contact: CNContact) {
        BFLog("contactpicker didselect")
        NSLog("Contactpicker didselect")
        
        let actionController = ActionSheetController()
        
        actionController.addAction(Action(ActionData(title: "Set as default ringtone for contact", image: ColorPalette.actionSheetMenuMobile!), style: .default, handler: { [weak self] action in
            
            guard let strongSelf = self else { return }
            guard let assigner = strongSelf.ringtoneAssigner else { return }
            
            assigner.assignDefaultRingtone(forContact: contact)
            
            strongSelf.contactPicker = nil
            strongSelf.ringtoneAssigner = nil
            
        }))
        actionController.addAction(Action(ActionData(title: "Set as default text tone for contact", image: ColorPalette.actionSheetMenuMessage!), style: .default, handler: { [weak self] action in
            
            guard let strongSelf = self else { return }
            guard let assigner = strongSelf.ringtoneAssigner else { return }
            
            assigner.assignDefaultTextTone(forContact: contact)
            
            strongSelf.contactPicker = nil
            strongSelf.ringtoneAssigner = nil
            
        }))
        actionController.addAction(Action(ActionData(title: "Cancel", image: ColorPalette.actionSheetMenuCancel!), style: .cancel, handler: nil))
        
        picker.dismiss(animated: true) {
            self.present(actionController, animated: true, completion: nil)
        }
        
    }
    
    func contactPickerDidCancel(_ picker: CNContactPickerViewController) {
        BFLog("contactpicker didcancel")
        NSLog("Contactpicker didcancel")
        picker.dismiss(animated: true, completion: nil)
        
        contactPicker = nil
    }
    
}


//MARK: UI Actions
extension RingtoneTableViewController {
    
    @IBAction func importFileTapped(_ sender: UIBarButtonItem) {
        let fileBrowser = FileBrowser(initialPath: URL(fileURLWithPath: Preferences.fileBrowserDefaultPath), allowEditing: false, showCancelButton: true)
        fileBrowser.excludesFileExtensions = Preferences.defaultExcludedFileExtensions
        
        fileBrowser.didSelectFile = { [weak self] (file: FBFile) -> Void in
            
            RingtoneManager.importRingtoneFile(file, onSuccess: {
                guard let strongSelf = self else { return }
                RingtoneStore.sharedInstance.allRingtones.lockArray()
                strongSelf.tableView.reloadData()
                RingtoneStore.sharedInstance.allRingtones.unlockArray()
            })
        }
        present(fileBrowser, animated: true, completion: nil)
    }
    
    @IBAction func cellMenuTapped(_ sender: RingtoneCellButton) {
        let row = sender.tag
        guard let cell = tableView.cellForRow(at: IndexPath(row: row, section: 0)) as? RingtoneTableCell else {
            Bugfender.error("Error! Failed to get cell on menu tap")
            return
        }
        
        ringtonePlayer?.stopPlaying()
        
        guard let actionController = ActionSheetGenerator.ringtoneCellMenu(ringtoneCell: cell, ringtoneTableController: self) else { return }
        
        present(actionController, animated: true, completion: nil)
    }
    
    @IBAction func playTappedInCell(_ sender: UIButton) {
        if ringtonePlayer == nil {
            ringtonePlayer = RingtonePlayer(inTableView: tableView)
        }
        
        ringtonePlayer?.togglePlayForSelectedRingtone()
        
    }
    
    @IBAction func installAllTapped(_ sender: UIBarButtonItem) {
        ringtonePlayer?.stopPlaying()
        RingtoneManager.installAllRingtones(withAlert: true) { [weak self] in
            guard let strongSelf = self else { return }
            RingtoneStore.sharedInstance.allRingtones.lockArray()
            strongSelf.tableView.reloadData()
            RingtoneStore.sharedInstance.allRingtones.unlockArray()
        }
    }
    
    
    @IBAction func uninstallAllTapped(_ sender: UIBarButtonItem) {
        ringtonePlayer?.stopPlaying()
        RingtoneManager.uninstallAll(withAlert: true) { [weak self] in
            guard let strongSelf = self else { return }
            RingtoneStore.sharedInstance.allRingtones.lockArray()
            strongSelf.tableView.reloadData()
            RingtoneStore.sharedInstance.allRingtones.unlockArray()
        }
    }
    
    /// Executes when the user changes the filter to show either "All", "Installed" or "Not installed" Ringtones
    ///
    /// - Parameter sender: UISegmentedControl that triggered this
    @IBAction func filterChanged(_ sender: UISegmentedControl) {
        ringtonePlayer?.stopPlaying()
        
        ringtoneFilter = sender.selectedSegmentIndex
        RingtoneStore.sharedInstance.allRingtones.lockArray()
        tableView.reloadData()
        RingtoneStore.sharedInstance.allRingtones.unlockArray()
    }
    
    /// Refresh button was tapped. Rescans apps to find new ringtones
    ///
    /// - Parameter sender: Button that triggered this
    @IBAction func updateTapped(_ sender: UIBarButtonItem) {
        updateAvailableRingtones()
    }
    
    private func deselectCurrentRow() {
        let selectedRow: IndexPath? = tableView.indexPathForSelectedRow
        if let selectedRowNotNill = selectedRow {
            
            if let cell = tableView.cellForRow(at: selectedRowNotNill) as? RingtoneTableCell {
                UIView.animate(withDuration: 0.2, animations: {
                    cell.updateButtons(false)
                })
            }
            tableView.deselectRow(at: selectedRowNotNill, animated: true)
            self.tableView.beginUpdates()
            self.tableView.endUpdates()
        }
    }
}

//MARK: Notification observers
extension RingtoneTableViewController {
    
    private func registerObservers() {
        NotificationCenter.default.addObserver(self, selector:#selector(self.willEnterForeground), name: NSNotification.Name.UIApplicationWillEnterForeground, object: nil)
        
        NotificationCenter.default.addObserver(self, selector:#selector(self.dataFinishedLoading(notification:)), name: .ringtoneStoreDidFinishLoading, object: nil)
        NotificationCenter.default.addObserver(self, selector:#selector(self.storeDidReload(notification:)), name: .ringtoneStoreDidReload, object: nil)
    }
    
    /// Called from notification observer when app will enter foreground. Updates available ringtones
    @objc func willEnterForeground() {
        BFLog("did become active, autoinstall = %d", Preferences.autoInstall)
        updateAvailableRingtones()
    }
    
    @objc func dataFinishedLoading(notification: NSNotification) {
        BFLog("store finished loading")
        tableView.reloadData()
        updateAvailableRingtones()
    }
    @objc func storeDidReload(notification: NSNotification) {
        BFLog("store did reload")
        RingtoneStore.sharedInstance.allRingtones.lockArray()
        tableView.reloadData()
        RingtoneStore.sharedInstance.allRingtones.unlockArray()
    }
}




//MARK: UIViewController method overrides
extension RingtoneTableViewController {
    
    /// Called when view has finished loading
    override func viewDidLoad() {
        BFLog("ringtonetableview didload called")
        self.tableView.dataSource = self
        self.tableView.delegate = self
        registerObservers()
        
        super.viewDidLoad()
        AppSetupManager.report_memory()
    }
    
    /// Called when view will appear
    ///
    /// - Parameter animated: true if view appears with animation
    override func viewWillAppear(_ animated: Bool) {
        BFLog("ringtonetableview willappear called")
        deselectCurrentRow()
        super.viewWillAppear(animated)
    }
    
    override func viewDidAppear(_ animated: Bool) {
        BFLog("ringtonetableview didappear called")
        super.viewDidAppear(animated)
        if RingtoneStore.sharedInstance.finishedLoading {
            RingtoneStore.sharedInstance.allRingtones.lockArray()
            tableView.reloadData()
            RingtoneStore.sharedInstance.allRingtones.unlockArray()
//            updateAvailableRingtones()
        }
    }
    
    /// Called whe view will disappear. Deselects a selected row, if any is selected. Also makes sure the buttons in the
    /// selected cell is hidden
    ///
    /// - Parameter animated: true if view will disappear with animation
    override func viewWillDisappear(_ animated: Bool) {
        ringtonePlayer?.stopPlaying()
        
        deselectCurrentRow()
        AppSetupManager.report_memory()
        super.viewWillDisappear(animated)
    }
}

//MARK: Segues handling
extension RingtoneTableViewController {
    /// Called when a segue is triggered
    ///
    /// - Parameters:
    ///   - segue: segue that was triggered. Has a unique identifier.
    ///   - sender: sender that initiated the segue
    override public func prepare(for segue: UIStoryboardSegue, sender: Any?) {
        AppSetupManager.report_memory()
        switch segue.identifier {
        case "showDetailsFromCellLabel"?:
            let cell = sender as! RingtoneTableCell
            let detailViewController = segue.destination as! RingtoneDetailViewController
            detailViewController.ringtone = cell.ringtoneItem
            
        case "showDetailsFromCellButton"?:
            if let indexPath = tableView.indexPathForSelectedRow {
                let cell = tableView.cellForRow(at: indexPath) as! RingtoneTableCell
                let detailViewController = segue.destination as! RingtoneDetailViewController
                detailViewController.ringtone = cell.ringtoneItem
            }
        default: break
        }
    }
}


//MARK: UITableView Delegate methods
extension RingtoneTableViewController {
    
    /// UITableView delegate method. Called when a ringtone should be removed
    ///
    /// - Parameters:
    ///   - tableView: current UITableView
    ///   - editingStyle: Style for editing
    ///   - indexPath: Indexpath for cell
    override func tableView(_ tableView: UITableView, commit editingStyle: UITableViewCellEditingStyle, forRowAt indexPath: IndexPath) {
        if editingStyle == .delete {
            let cell = tableView.cellForRow(at: indexPath) as! RingtoneTableCell
            
            RingtoneManager.deleteRingtone(inCell: cell) {
                if let index = self.tableView.indexPath(for: cell) {
                    self.tableView.deleteRows(at: [index], with: .automatic)
                }
            }
        }
    }
    /// UITableView delegate method. If a row already is selected, it will deselect it.
    ///
    /// - Parameters:
    ///   - tableView: current UITableView
    ///   - indexPath: IndexPath for tapped row
    /// - Returns: IndexPath
    override func tableView(_ tableView: UITableView, willSelectRowAt indexPath: IndexPath) -> IndexPath? {
        if let indexPathForSelectedRow = tableView.indexPathForSelectedRow, // second tap on already selected cell
            indexPathForSelectedRow == indexPath {
            
            ringtonePlayer?.stopPlaying()
            
            tableView.deselectRow(at: indexPath, animated: true)
            self.tableView.beginUpdates()
            self.tableView.endUpdates()
            if let cell = tableView.cellForRow(at: indexPath) as? RingtoneTableCell {
                UIView.animate(withDuration: 0.2, animations: {
                    cell.updateButtons(false)
                })
            }
            return nil
        }
        return indexPath
    }
    /// UITableView delegate method. Selects row that was tapped and unhides buttons available for this cell
    ///
    /// - Parameters:
    ///   - tableView: current UITableView
    ///   - indexPath: IndexPath for selected row
    override func tableView(_ tableView: UITableView, didSelectRowAt indexPath: IndexPath) {
        
        self.tableView.beginUpdates()
        self.tableView.endUpdates()
        let cell = tableView.cellForRow(at: indexPath) as! RingtoneTableCell
        UIView.animate(withDuration: 0.2, delay: 0.2, options: .curveEaseOut, animations: {
            cell.updateButtons(true)
        }, completion: nil)
    }
    
    override func tableView(_ tableView: UITableView, willDeselectRowAt indexPath: IndexPath) -> IndexPath? {
        ringtonePlayer?.stopPlaying()
        return indexPath
    }
    
    /// UITableView delegate method. Row at indexpath was deselected. Hides buttons in cell.
    ///
    /// - Parameters:
    ///   - tableView: current UITableView
    ///   - indexPath: Indexpath for cell
    override func tableView(_ tableView: UITableView, didDeselectRowAt indexPath: IndexPath) {
        if let cell = tableView.cellForRow(at: indexPath) as? RingtoneTableCell {
            UIView.animate(withDuration: 0.2, animations: {
                cell.updateButtons(false)
            })
        }
    }
}

//MARK: UITableView DataSource methods
extension RingtoneTableViewController {
    
    /// UITableView Datasource method. Returns height depending on if the cell is selected or not
    ///
    /// - Parameters:
    ///   - tableView: current UITableView
    ///   - indexPath: IndexPath for cell
    /// - Returns: Row height
    override public func tableView(_ tableView: UITableView, heightForRowAt indexPath: IndexPath) -> CGFloat {
        if tableView.indexPathForSelectedRow?.row == indexPath.row {
            return rowHeight*2.0
        } else {
            return rowHeight
        }
    }
    
    /// UITableView datasource method.
    ///
    /// - Parameters:
    ///   - tableView: current UITableView
    ///   - section: Current section
    /// - Returns: Returns number of rows in this section (usually number of ringtones)
    override public func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        if RingtoneStore.sharedInstance.finishedLoading {
            switch ringtoneFilter {
            case 0:
                return RingtoneStore.sharedInstance.allRingtones.count
            case 1:
                return RingtoneStore.sharedInstance.installedRingtones.count
            case 2:
                return RingtoneStore.sharedInstance.notInstalledRingtones.count
            default:
                return 0
            }
        } else { return 0 }
    }
    
    /// UITableView Datasource method
    ///
    /// - Parameters:
    ///   - tableView: current UITableView
    ///   - indexPath: Indexpath for current cell
    /// - Returns: UITableViewCell of subclass RingtoneTableCell
    override public func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        let cell = tableView.dequeueReusableCell(withIdentifier: cellId, for: indexPath) as! RingtoneTableCell
        
        if RingtoneStore.sharedInstance.finishedLoading {
            RingtoneStore.sharedInstance.allRingtones.lockArray()
            
            let ringtone : Ringtone?
            switch ringtoneFilter {
            case 0:
                ringtone = RingtoneStore.sharedInstance.allRingtones[indexPath.row]
            case 1:
                ringtone = RingtoneStore.sharedInstance.installedRingtones[indexPath.row]
            case 2:
                ringtone = RingtoneStore.sharedInstance.notInstalledRingtones[indexPath.row]
            default:
                RingtoneStore.sharedInstance.allRingtones.unlockArray()
                return cell
            }
            RingtoneStore.sharedInstance.allRingtones.unlockArray()
            cell.ringtoneItem = ringtone
            cell.nameLabel.text = ringtone?.name
            cell.fromAppLabel.text = ringtone?.appName
            cell.cellMenuButton.addedTouchArea = 10
            cell.cellMenuButton.tag = indexPath.row
            
            cell.updateInstallStatus()
            
            let selectedRow: IndexPath? = tableView.indexPathForSelectedRow
            if let selectedRowNotNill = selectedRow {
                if selectedRowNotNill == indexPath {
                    // current row is selected
                    cell.updateButtons(true)
                }
            }
        }
        
        return cell
    }
}


