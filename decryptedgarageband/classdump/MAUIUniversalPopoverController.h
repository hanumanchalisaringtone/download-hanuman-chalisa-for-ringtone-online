//
//     Generated by class-dump 3.5 (64 bit) (Debug version compiled Aug 30 2018 09:46:22).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2015 by Steve Nygard.
//

#import <Foundation/NSObject.h>

#import "UIGestureRecognizerDelegate-Protocol.h"

@class MAUIPopoverBackgroundView, NSArray, NSString, UIImage, UIView, UIViewController;
@protocol MAUIUniversalPopoverControllerDelegate;

@interface MAUIUniversalPopoverController : NSObject <UIGestureRecognizerDelegate>
{
    UIView *_popoverView;
    MAUIPopoverBackgroundView *_backgroundView;
    double leftFrameImageInset;
    double rightFrameImageInset;
    double topFrameImageInset;
    double bottomFrameImageInset;
    double topShadowHeight;
    double frameWidth;
    _Bool _popoverVisible;
    id <MAUIUniversalPopoverControllerDelegate> _delegate;
    UIViewController *_contentViewController;
    unsigned long long _popoverArrowDirection;
    NSArray *_passthroughViews;
    UIImage *_frameImage;
    struct CGSize _popoverContentSize;
}

@property(retain, nonatomic) UIImage *frameImage; // @synthesize frameImage=_frameImage;
@property(copy, nonatomic) NSArray *passthroughViews; // @synthesize passthroughViews=_passthroughViews;
@property(readonly, nonatomic) unsigned long long popoverArrowDirection; // @synthesize popoverArrowDirection=_popoverArrowDirection;
@property(readonly, nonatomic, getter=isPopoverVisible) _Bool popoverVisible; // @synthesize popoverVisible=_popoverVisible;
@property(nonatomic) struct CGSize popoverContentSize; // @synthesize popoverContentSize=_popoverContentSize;
@property(retain, nonatomic) UIViewController *contentViewController; // @synthesize contentViewController=_contentViewController;
@property(nonatomic) id <MAUIUniversalPopoverControllerDelegate> delegate; // @synthesize delegate=_delegate;
@property(nonatomic) double frameWidth; // @synthesize frameWidth;
@property(nonatomic) double topShadowHeight; // @synthesize topShadowHeight;
@property(nonatomic) double bottomFrameImageInset; // @synthesize bottomFrameImageInset;
@property(nonatomic) double topFrameImageInset; // @synthesize topFrameImageInset;
@property(nonatomic) double rightFrameImageInset; // @synthesize rightFrameImageInset;
@property(nonatomic) double leftFrameImageInset; // @synthesize leftFrameImageInset;
- (void).cxx_destruct;
- (void)backgroundTapGestureAction:(id)arg1;
- (_Bool)gestureRecognizerShouldBegin:(id)arg1;
- (_Bool)_tapIsForAPassThroughView:(id)arg1 currentView:(id)arg2;
- (_Bool)isPassthroughView:(id)arg1;
- (void)setPopoverContentSize:(struct CGSize)arg1 animated:(_Bool)arg2;
- (void)setContentViewController:(id)arg1 animated:(_Bool)arg2;
- (void)dismissPopoverAnimated:(_Bool)arg1;
- (void)presentPopoverFromRect:(struct CGRect)arg1 inView:(id)arg2 permittedArrowDirections:(unsigned long long)arg3 animated:(_Bool)arg4;
- (void)presentPopoverFromBarButtonItem:(id)arg1 permittedArrowDirections:(unsigned long long)arg2 animated:(_Bool)arg3;
- (void)updateToContentViewControllersSizeAnimated:(_Bool)arg1;
- (void)dealloc;
- (id)initWithContentViewController:(id)arg1;
- (id)init;
- (id)keyView;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end
