//
//  AppListViewController.swift
//  ToneManager
//
//  Created by Jesper Flodin on 2018-09-11.
//  Copyright © 2018 Jesper Flodin. All rights reserved.
//

import UIKit
import BugfenderSDK

/// Table view controller that uses Applist to show list of apps
public class AppListViewController : UITableViewController {
    
    var tabView : UITableView = UITableView()
    var appNames : [String] = []
    var theApps : [String:String] = [:]
    
    private var dataSource : ALApplicationTableDataSource
    
    override public func viewDidLoad() {
        super.viewDidLoad()
        self.tableView.dataSource = dataSource
        dataSource.tableView = self.tableView
        
        
        guard let _ : AnyClass = NSClassFromString("ALApplicationList") else {
            errorAlert("Failed to load AppList. Is AppList really installed?")
            return
        }
        guard (ALApplicationList.shared()) != nil else {
            errorAlert("Error occured when loading apps with AppList.")
            return
        }
        
        
        
    }
    
    /// Shows an alert with a back button that pops back to the latest view controller (settings)
    ///
    /// - Parameter message: Message to show in alert
    private func errorAlert(_ message : String) {
        let ac = UIAlertController(title: "AppList Error", message: message, preferredStyle: .alert)
        
        let backAction = UIAlertAction(title: "Back", style: .cancel, handler:
        { (action) -> Void in
            self.navigationController?.popViewController(animated: true)
        })
        ac.addAction(backAction)
        present(ac, animated: true, completion: nil)
    }
    
    
    /// Init method that gets called when storyboard initiates this view controller
    ///
    /// - Parameter aDecoder: not used here
    required public init?(coder aDecoder: NSCoder) {
        dataSource = ALApplicationTableDataSource()
        dataSource.sectionDescriptors = ALApplicationTableDataSource.standardSectionDescriptors()
        super.init(coder: aDecoder)
    }
    
    
}