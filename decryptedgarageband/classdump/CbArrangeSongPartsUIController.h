//
//     Generated by class-dump 3.5 (64 bit) (Debug version compiled Aug 30 2018 09:46:22).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2015 by Steve Nygard.
//

#import <Foundation/NSObject.h>

#import "CbArrangeAnimationsDelegate-Protocol.h"

@class CbArrangeAnimationsController, CbArrangeModel, CbArrangeSongPartsIndicatorView, CbArrangeViewController, DfDocument, NSString, UIView;

@interface CbArrangeSongPartsUIController : NSObject <CbArrangeAnimationsDelegate>
{
    CbArrangeViewController *_arrangeController;
    DfDocument *_document;
    CbArrangeModel *_model;
    long long _activeSongPartIndexAfterAnimation;
    CbArrangeAnimationsController *_animationsController;
    CbArrangeSongPartsIndicatorView *_specialSongPartsRulerView;
    CbArrangeSongPartsIndicatorView *_specialSongPartsView;
    _Bool _isRunning;
    long long _fakeActiveSongPartIndex;
}

@property(readonly, nonatomic) UIView *specialSongPartsRulerView; // @synthesize specialSongPartsRulerView=_specialSongPartsRulerView;
@property(readonly, nonatomic) UIView *specialSongPartsView; // @synthesize specialSongPartsView=_specialSongPartsView;
@property(readonly, nonatomic) _Bool isRunning; // @synthesize isRunning=_isRunning;
@property(nonatomic) long long fakeActiveSongPartIndex; // @synthesize fakeActiveSongPartIndex=_fakeActiveSongPartIndex;
- (void).cxx_destruct;
- (void)switchToSongPartWithIndexDueToScrollViewBounceStretch:(long long)arg1;
- (void)moveSongPartAtIndex:(long long)arg1 toIndex:(long long)arg2;
- (void)duplicateSongPartAtIndex:(long long)arg1;
- (void)setLengthOfSongPartAtIndex:(long long)arg1 toBarCount:(int)arg2 animate:(_Bool)arg3;
- (void)deleteSongPartAtIndex:(long long)arg1;
- (void)addNewSongPart;
- (void)abortWithoutAnimation;
- (void)stop;
- (void)start;
- (void)synchronizeWithModel;
- (void)zoomToCurrentFakeActiveSongPartAndSetInModel;
- (void)zoomAndScrollToSongPartWithIndex:(long long)arg1 setModelToIndexAfterAnimation:(_Bool)arg2 animationSubID:(id)arg3 gridOptimization:(int)arg4;
- (void)zoomAndScrollToSongPartWithIndex:(long long)arg1 setModelToIndexAfterAnimation:(_Bool)arg2;
- (void)zoomAndScrollToTotalSongView;
- (void)_startZoomToWholeSongAnimation;
@property(readonly, nonatomic) _Bool isAnimating;
- (void)arrangeAnimationDidEnd:(id)arg1;
- (void)_zoomToActiveSongPartsAnimationEnded;
- (void)arrangeAnimationWillStart:(id)arg1;
@property(readonly, nonatomic) NSString *animationSubID;
@property(readonly, nonatomic) NSString *animationID;
- (void)relayoutHelperViews;
- (void)_switchToNeighborSongPartAndScrollToSameVisualPosition:(long long)arg1;
- (void)switchToAllSongPartsAndScrollToSameVisualPosition;
- (void)_setActiveSongPart:(long long)arg1 autoCalcZoom:(_Bool)arg2;
- (void)_updateArrangeUI:(_Bool)arg1:(_Bool)arg2;
- (void)_removeHelperViews;
- (void)dealloc;
- (id)initWithArrangeViewController:(id)arg1;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end
