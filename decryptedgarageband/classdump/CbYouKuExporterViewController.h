//
//     Generated by class-dump 3.5 (64 bit) (Debug version compiled Aug 30 2018 09:46:22).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2015 by Steve Nygard.
//

#import "CbExporterViewController.h"

#import "CbExporterDescriptionCellDelegate-Protocol.h"

@class CbYouKuExporterPublisher, NSString;

@interface CbYouKuExporterViewController : CbExporterViewController <CbExporterDescriptionCellDelegate>
{
    CbYouKuExporterPublisher *_publisher;
    double _descriptionCellHeight;
    CbYouKuExporterViewController *_continueViewController;
}

- (void).cxx_destruct;
- (void)descriptionCellTextDidChange:(id)arg1;
- (void)descriptionCellDidResize:(id)arg1;
- (void)descriptionCellDidStartEditing:(id)arg1;
- (void)titleCellTextDidChange:(id)arg1;
- (void)titleCellDidEndEditing:(id)arg1;
- (void)titleCellDidStartEditing:(id)arg1;
- (void)tableView:(id)arg1 didSelectRowAtIndexPath:(id)arg2;
- (long long)tableView:(id)arg1 editingStyleForRowAtIndexPath:(id)arg2;
- (double)tableView:(id)arg1 heightForRowAtIndexPath:(id)arg2;
- (id)tableView:(id)arg1 titleForFooterInSection:(long long)arg2;
- (id)tableView:(id)arg1 viewForFooterInSection:(long long)arg2;
- (double)tableView:(id)arg1 heightForFooterInSection:(long long)arg2;
- (id)tableView:(id)arg1 titleForHeaderInSection:(long long)arg2;
- (_Bool)tableView:(id)arg1 canEditRowAtIndexPath:(id)arg2;
- (long long)numberOfSectionsInTableView:(id)arg1;
- (id)tableView:(id)arg1 cellForRowAtIndexPath:(id)arg2;
- (long long)tableView:(id)arg1 numberOfRowsInSection:(long long)arg2;
- (_Bool)publishesVideo;
- (void)setSignedIn;
- (id)warningText;
- (void)cleanUp;
- (void)signOut:(id)arg1;
- (void)showTermsOfUse:(id)arg1;
- (void)publish:(id)arg1;
- (void)storeCustomStillImage:(id)arg1;
- (void)continueSettings:(id)arg1;
- (void)cancel:(id)arg1;
@property(nonatomic) CbYouKuExporterPublisher *publisher; // @dynamic publisher;
- (_Bool)disablesAutomaticKeyboardDismissal;
- (void)dealloc;
- (void)viewDidUnload;
- (void)didReceiveMemoryWarning;
- (void)viewDidLoad;
- (id)initWithNibName:(id)arg1 bundle:(id)arg2;
- (_Bool)passwordCellSelected;
- (long long)titleSectionNumber;
- (long long)imageSectionNumber;
- (long long)privacySectionNumber;
- (void)setPasswordCellFocus;
- (void)setTitleCellFocus;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end
