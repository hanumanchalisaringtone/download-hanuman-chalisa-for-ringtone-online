//
//     Generated by class-dump 3.5 (64 bit) (Debug version compiled Aug 30 2018 09:46:22).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2015 by Steve Nygard.
//

#import "MAVeContinuousControl.h"

#import "CALayerDelegate-Protocol.h"

@class CALayer, NSMutableArray, NSMutableDictionary, NSString;

@interface MAVeLinearSlider : MAVeContinuousControl <CALayerDelegate>
{
    NSMutableArray *_tickmarks;
    _Bool _bipolar;
    _Bool _inverse;
    _Bool _vertical;
    double _bipolarCenterValue;
    NSMutableDictionary *_parts;
    NSString *_actionPartID;
    CALayer *_trackLayer;
    struct CGPoint _mouseOffset;
}

+ (_Bool)partID:(id)arg1 isEqualToPartID:(id)arg2;
@property(retain, nonatomic) CALayer *trackLayer; // @synthesize trackLayer=_trackLayer;
@property(nonatomic) struct CGPoint mouseOffset; // @synthesize mouseOffset=_mouseOffset;
@property(nonatomic) NSString *actionPartID; // @synthesize actionPartID=_actionPartID;
@property(nonatomic) _Bool vertical; // @synthesize vertical=_vertical;
@property(retain, nonatomic) NSMutableDictionary *parts; // @synthesize parts=_parts;
@property(nonatomic) _Bool inverse; // @synthesize inverse=_inverse;
@property(nonatomic) double bipolarCenterValue; // @synthesize bipolarCenterValue=_bipolarCenterValue;
@property(nonatomic) _Bool bipolar; // @synthesize bipolar=_bipolar;
- (void).cxx_destruct;
- (void)setValue:(id)arg1 forKeyPath:(id)arg2;
- (id)valueForKeyPath:(id)arg1;
- (void)removeAllTickmarks;
- (void)addTickmarkForValue:(double)arg1;
- (void)addTickmarkAtPosition:(double)arg1;
- (void)setTickmarks:(id)arg1;
- (id)mutableTickmarks;
- (id)tickmarks;
- (void)valueDidChangeValue:(id)arg1 oldValue:(double)arg2;
- (void)scrollEvent:(id)arg1;
- (void)gestureDetected:(id)arg1;
- (_Bool)onDraggedEvent:(id)arg1;
- (_Bool)onUpEvent:(id)arg1;
- (_Bool)onDownEvent:(id)arg1;
- (void)resetValueAtPosition:(struct CGPoint)arg1;
- (id)layerOfClass:(Class)arg1 withName:(id)arg2 zPosition:(double)arg3;
- (void)setPartForID:(id)arg1 valueID:(id)arg2 inverse:(_Bool)arg3;
- (void)removeAllParts;
- (id)partIDForPosition:(struct CGPoint)arg1;
- (double)valueForPosition:(struct CGPoint)arg1 partID:(id)arg2;
- (double)distanceOfEvent:(id)arg1;
- (struct CGPoint)valuePositionForEvent:(id)arg1;
- (struct CGPoint)valuePositionOfPartWithID:(id)arg1;
- (struct CGPoint)positionForValue:(double)arg1;
- (struct CGPoint)minPositionOfPartWithID:(id)arg1;
- (struct CGPoint)maxPositionOfPartWithID:(id)arg1;
- (struct CGPoint)bipolarCenterPosition;
- (void)updateTickmarkLayers;
- (void)updateThumbLayers;
- (void)updateTrackFillLayers;
- (void)updateLayers;
- (void)tearDownTickmarkLayers;
- (void)tearDownThumbLayers;
- (void)tearDownTrackFillLayers;
- (void)tearDownLayers;
- (void)setupTickmarkLayers;
- (void)setupThumbLayers;
- (void)setupTrackFillLayers;
- (void)setupLayers;
@property(nonatomic, setter=set_mainValueDefault:) double mainValueDefault;
@property(nonatomic, setter=set_mainValueMax:) double mainValueMax;
@property(nonatomic, setter=set_mainValueMin:) double mainValueMin;
@property(nonatomic, setter=set_mainValueNormed:) double mainValueNormed;
@property(nonatomic, setter=set_mainValue:) double mainValue;
@property(nonatomic) struct CGPoint design_trackOrigin;
@property(readonly, nonatomic) struct CGPoint trackOrigin;
@property(readonly, nonatomic) double trackLength;
- (id)init;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end
