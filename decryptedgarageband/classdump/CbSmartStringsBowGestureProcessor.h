//
//     Generated by class-dump 3.5 (64 bit) (Debug version compiled Aug 30 2018 09:46:22).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2015 by Steve Nygard.
//

#import <Foundation/NSObject.h>

@class CbSmartStringsInteraction;
@protocol CbSmartStringsBowingDelegate;

@interface CbSmartStringsBowGestureProcessor : NSObject
{
    _Bool _performingBowedGesture;
    _Bool _enabled;
    CbSmartStringsInteraction *_interaction;
    id <CbSmartStringsBowingDelegate> _delegate;
}

@property(nonatomic) _Bool enabled; // @synthesize enabled=_enabled;
@property(nonatomic) id <CbSmartStringsBowingDelegate> delegate; // @synthesize delegate=_delegate;
@property(readonly, nonatomic) CbSmartStringsInteraction *interaction; // @synthesize interaction=_interaction;
- (void).cxx_destruct;
- (void)_finishPriorBowingWithNewRecognizer:(id)arg1;
- (void)startPizz:(id)arg1;
- (void)startStaccato:(id)arg1;
- (void)startBowedNotes:(_Bool)arg1 forRecognizer:(id)arg2;
- (void)playPizz:(id)arg1;
- (void)handleBowing:(id)arg1;
- (void)handleQuickStaccato:(id)arg1;
- (id)init;

@end
