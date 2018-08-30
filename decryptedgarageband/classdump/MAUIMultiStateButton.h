//
//     Generated by class-dump 3.5 (64 bit) (Debug version compiled Aug 30 2018 09:46:22).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2015 by Steve Nygard.
//

#import <UIKit/UIControl.h>

@class NSMutableDictionary, UIButton, UITapGestureRecognizer;

@interface MAUIMultiStateButton : UIControl
{
    unsigned long long _currentStateIndex;
    unsigned long long _numberOfStates;
    UIButton *_button;
    UITapGestureRecognizer *_doubleTapRecognizer;
    NSMutableDictionary *_stateImages;
}

@property(retain, nonatomic) NSMutableDictionary *stateImages; // @synthesize stateImages=_stateImages;
@property(retain, nonatomic) UITapGestureRecognizer *doubleTapRecognizer; // @synthesize doubleTapRecognizer=_doubleTapRecognizer;
@property(retain, nonatomic) UIButton *button; // @synthesize button=_button;
@property(nonatomic) unsigned long long numberOfStates; // @synthesize numberOfStates=_numberOfStates;
- (void).cxx_destruct;
@property(nonatomic) _Bool adjustsImageWhenHighlighted;
- (void)_doubleTapButtonAction:(id)arg1;
- (void)_buttonAction:(id)arg1;
- (void)setImage:(id)arg1 forState:(unsigned long long)arg2 stateIndex:(unsigned long long)arg3;
@property(nonatomic) unsigned long long currentStateIndex;
- (void)_proceedToNextStateIndex;
- (void)_updateCurrentStateImages;
- (void)setOverridesDoubleTapGesture:(_Bool)arg1;
- (void)awakeFromNib;
- (void)layoutSubviews;
- (void)dealloc;
- (id)initWithCoder:(id)arg1;
- (id)initWithFrame:(struct CGRect)arg1;
- (id)init;
- (void)_initIvars;

@end
