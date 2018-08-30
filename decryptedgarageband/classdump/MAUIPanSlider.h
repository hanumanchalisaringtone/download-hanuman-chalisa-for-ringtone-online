//
//     Generated by class-dump 3.5 (64 bit) (Debug version compiled Aug 30 2018 09:46:22).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2015 by Steve Nygard.
//

#import <UIKit/UIControl.h>

#import "MAAssetManagerMixInParentProtocol-Protocol.h"

@class MAAssetManagerMixIn, NSObject, NSString, UIColor, UIImage;
@protocol MAUIPanSliderDelegate;

@interface MAUIPanSlider : UIControl <MAAssetManagerMixInParentProtocol>
{
    struct CGPoint _startPoint;
    float _startValue;
    _Bool _tapDown;
    _Bool _panModeDisabled;
    _Bool _drawMiddle;
    _Bool _ignoresValueChangesWhileDragging;
    float _minimumValue;
    float _maximumValue;
    float _value;
    float _defaultValue;
    float _magneticTickMarkArea;
    MAAssetManagerMixIn *_assetManagerMixIn;
    long long _numberOfTickMarks;
    UIImage *_trackImage;
    UIImage *_panTrackImageLeft;
    UIImage *_panTrackImageRight;
    UIImage *_knobImage;
    UIImage *_knobPressedImage;
    UIColor *_tickMarkColor;
    NSObject<MAUIPanSliderDelegate> *_sliderDelegate;
    struct CGSize _trackInset;
    struct CGSize _trackOffset;
    struct CGSize _knobInset;
}

+ (id)assetSetFamily;
@property(nonatomic) NSObject<MAUIPanSliderDelegate> *sliderDelegate; // @synthesize sliderDelegate=_sliderDelegate;
@property(retain, nonatomic) UIColor *tickMarkColor; // @synthesize tickMarkColor=_tickMarkColor;
@property(retain, nonatomic) UIImage *knobPressedImage; // @synthesize knobPressedImage=_knobPressedImage;
@property(retain, nonatomic) UIImage *knobImage; // @synthesize knobImage=_knobImage;
@property(retain, nonatomic) UIImage *panTrackImageRight; // @synthesize panTrackImageRight=_panTrackImageRight;
@property(retain, nonatomic) UIImage *panTrackImageLeft; // @synthesize panTrackImageLeft=_panTrackImageLeft;
@property(retain, nonatomic) UIImage *trackImage; // @synthesize trackImage=_trackImage;
@property(nonatomic) float magneticTickMarkArea; // @synthesize magneticTickMarkArea=_magneticTickMarkArea;
@property(nonatomic) long long numberOfTickMarks; // @synthesize numberOfTickMarks=_numberOfTickMarks;
@property(nonatomic) struct CGSize knobInset; // @synthesize knobInset=_knobInset;
@property(nonatomic) struct CGSize trackOffset; // @synthesize trackOffset=_trackOffset;
@property(nonatomic) struct CGSize trackInset; // @synthesize trackInset=_trackInset;
@property(nonatomic) _Bool ignoresValueChangesWhileDragging; // @synthesize ignoresValueChangesWhileDragging=_ignoresValueChangesWhileDragging;
@property(nonatomic) _Bool drawMiddle; // @synthesize drawMiddle=_drawMiddle;
@property(nonatomic) _Bool panModeDisabled; // @synthesize panModeDisabled=_panModeDisabled;
@property(nonatomic) float defaultValue; // @synthesize defaultValue=_defaultValue;
@property(nonatomic) float value; // @synthesize value=_value;
@property(nonatomic) float maximumValue; // @synthesize maximumValue=_maximumValue;
@property(nonatomic) float minimumValue; // @synthesize minimumValue=_minimumValue;
- (void).cxx_destruct;
- (id)assetSetFamily;
- (_Bool)tryInitializationOnAssetChange;
- (void)assetSetHasChanged:(id)arg1;
@property(retain, nonatomic) MAAssetManagerMixIn *assetManagerMixIn; // @synthesize assetManagerMixIn=_assetManagerMixIn;
- (id)resourceBundleID;
- (void)setResourceBundleID:(id)arg1;
- (id)assetSetPath;
- (void)setAssetSetPath:(id)arg1;
- (void)setAssetSet:(id)arg1;
- (void)touchesCancelled:(id)arg1 withEvent:(id)arg2;
- (void)touchesEnded:(id)arg1 withEvent:(id)arg2;
- (void)touchesBegan:(id)arg1 withEvent:(id)arg2;
- (void)doubleTapGestureAction:(id)arg1;
- (_Bool)continueTrackingWithTouch:(id)arg1 withEvent:(id)arg2;
- (_Bool)beginTrackingWithTouch:(id)arg1 withEvent:(id)arg2;
- (_Bool)isTracking;
- (void)setValueInternal:(float)arg1;
- (void)drawRect:(struct CGRect)arg1;
- (struct CGRect)knobRect;
- (struct CGRect)trackRect;
- (struct CGSize)sizeThatFits:(struct CGSize)arg1;
- (void)dealloc;
- (id)initWithFrame:(struct CGRect)arg1;
- (id)initWithCoder:(id)arg1;
- (void)setup;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end
