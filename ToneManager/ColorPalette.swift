//
//  ColorPalette.swift
//  ToneManager
//
//  Created by Jesper Flodin on 2018-09-15.
//  Copyright © 2018 Jesper Flodin. All rights reserved.
//

import UIKit

struct ColorPalette {
    
    static let backgroundColor = UIColor.white
    
    static let navBarTextColor = UIColor.white
    
    static let themeColor = UIColor(red: 79/255, green: 143/255, blue: 0, alpha: 0.7)
    
    static let destructiveColor = UIColor(red: 252/255, green: 33/255, blue: 37/255, alpha: 1.0) //red
    
    static let cellActionColor = UIColor(red: 29/255, green: 155/255, blue: 246/255, alpha: 1.0) //blue
    
    static let ringtoneInstalledColor = UIColor(red: 79/255, green: 143/255, blue: 0, alpha: 1.0)
    static let ringtoneNotInstalledColor = UIColor(red: 252/255, green: 33/255, blue: 37/255, alpha: 1.0)
    
    static let actionSheetLabelDefault = UIColor.lightGray
    static let actionSheetLabelDestructive = UIColor(red: 210/255.0, green: 77/255.0, blue: 56/255.0, alpha: 1.0)
    
    
}

//MARK: Images
extension ColorPalette {
    static let navBarBackground = UIImage(named: "navbar")
    static let sideMenuBackground = UIImage(named: "colorful")
    
    static let ringtoneCellPlayImage = UIImage(named: "play-circle44")
    static let ringtoneCellStopImage = UIImage(named: "stop-circle44")
    
    static let actionSheetMenuInstall = UIImage(named: "plus")
    static let actionSheetMenuUninstall = UIImage(named: "minus")
    static let actionSheetMenuDelete = UIImage(named: "trash")
    static let actionSheetMenuInfo = UIImage(named: "info")
    static let actionSheetMenuCancel = UIImage(named: "cross")
    static let actionSheetMenuAddressbook = UIImage(named: "address-book20")
    static let actionSheetMenuExternallink = UIImage(named: "external-link20")
    static let actionSheetMenuMobile = UIImage(named: "mobile20")
    static let actionSheetMenuMessage = UIImage(named: "comment-dots20")
    
    static let cellUpArrow = UIImage(named: "chevron-up")
    static let cellDownArrow = UIImage(named: "chevron-down")
    
    static let alertBackground = UIImage(named: "alertBackground")
}

//MARK: Fonts
extension ColorPalette {
    static let navBarTitleFont = UIFont(name: "CopperPlate", size: 30)
}
