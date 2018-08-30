//
//     Generated by class-dump 3.5 (64 bit) (Debug version compiled Aug 30 2018 09:46:22).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2015 by Steve Nygard.
//

#import <UIKit/UIViewController.h>

#import "UIPopoverPresentationControllerDelegate-Protocol.h"

@class CbStepSequencerMenuViewController, CbStepSequencerNoteSelectorViewController, NSMutableDictionary, NSString, UINavigationController;
@protocol CbStepSequencerPopoverViewControllerDelegate;

@interface CbStepSequencerPopoverViewController : UIViewController <UIPopoverPresentationControllerDelegate>
{
    UINavigationController *_navigationController;
    CbStepSequencerMenuViewController *_swingSelectorViewController;
    CbStepSequencerNoteSelectorViewController *_noteSelectorViewController;
    CbStepSequencerMenuViewController *_globalMenuViewController;
    CbStepSequencerMenuViewController *_globalPlaybackModeViewController;
    CbStepSequencerMenuViewController *_globalPlaybackSpeedViewController;
    CbStepSequencerMenuViewController *_sequenceLengthViewController;
    CbStepSequencerMenuViewController *_patternMenuViewController;
    CbStepSequencerMenuViewController *_secondaryEditModeViewController;
    NSMutableDictionary *_rowModelUUIDToRowMenuController;
    NSMutableDictionary *_rowModelUUIDToPlaybackModeController;
    NSMutableDictionary *_rowModelUUIDToPlaybackSpeedController;
    NSMutableDictionary *_rowModelUUIDToRandomizationSeedController;
    id <CbStepSequencerPopoverViewControllerDelegate> _delegate;
}

@property(nonatomic) __weak id <CbStepSequencerPopoverViewControllerDelegate> delegate; // @synthesize delegate=_delegate;
- (void).cxx_destruct;
- (void)showPopover;
- (id)randomizationSeedMenuForRowModel:(id)arg1 seedPool:(id)arg2 sourceView:(id)arg3;
- (id)playbackModeMenuForRowModel:(id)arg1 sourceView:(id)arg2;
- (id)playbackSpeedMenuForRowModel:(id)arg1 sourceView:(id)arg2;
- (id)rowMenuForModel:(id)arg1 sourceView:(id)arg2;
- (void)dismissPopover:(CDUnknownBlockType)arg1;
- (void)configurePopoverWithSourceView:(id)arg1 permittedArrowDirections:(unsigned long long)arg2 backgroundColor:(id)arg3;
- (void)setupNavigationController;
- (long long)adaptivePresentationStyleForPresentationController:(id)arg1;
- (void)showPatternLibraryWithSourceView:(id)arg1;
- (void)reloadMenu;
- (void)updatePassthroughViews;
- (void)removePopoversForAllRowModels;
- (void)removePopoversForRowModel:(id)arg1;
- (void)showRandomizationSeedsMenuForRowModel:(id)arg1 seedPool:(id)arg2 sourceView:(id)arg3;
- (void)showSecondaryEditModeMenuWithSourceView:(id)arg1;
- (void)showNoteSelectorWithRowIndex:(unsigned long long)arg1 noteModels:(id)arg2 selectedNoteModel:(id)arg3 sourceView:(id)arg4;
- (void)showPlaybackModeMenuForRowModel:(id)arg1 sourceView:(id)arg2;
- (void)showPlaybackSpeedMenuForRowModel:(id)arg1 sourceView:(id)arg2;
- (void)showGlobalSubmenu:(id)arg1 sourceView:(id)arg2;
- (void)showSequenceLengthMenuWithModel:(id)arg1 sourceView:(id)arg2;
- (void)showGlobalPlaybackModeMenuWithModel:(id)arg1 sourceView:(id)arg2;
- (void)showGlobalPlaybackSpeedMenuWithModel:(id)arg1 sourceView:(id)arg2;
- (void)showGlobalMenuWithSourceView:(id)arg1;
- (void)showSwingMenuWithModel:(id)arg1 sourceView:(id)arg2;
- (void)showRowMenuWithModel:(id)arg1 sourceView:(id)arg2;
- (void)dismissPopover;
- (_Bool)isShowingRowMenuForModel:(id)arg1;
- (_Bool)isShowingPopover;
- (id)initWithDelegate:(id)arg1;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end
