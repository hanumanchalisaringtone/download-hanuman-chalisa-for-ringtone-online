//
//     Generated by class-dump 3.5 (64 bit) (Debug version compiled Aug 30 2018 09:46:22).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2015 by Steve Nygard.
//

#import "MAVeGraphShape.h"

#import "MAVeGraphDrawingProtocol-Protocol.h"

@class NSData, NSDictionary, NSNumber, NSString, NSValue;

@interface MAVeGraphShCustomLine : MAVeGraphShape <MAVeGraphDrawingProtocol>
{
    _Bool _filled;
    _Bool _pixelAccurateDrawing;
    id _currentPath;
    NSDictionary *_lineColors;
    NSData *_linePointsX;
    NSData *_linePointsY;
    NSDictionary *_lineWidths;
    NSValue *_startEndAddition;
    CDUnknownBlockType _customDrawing;
    CDUnknownBlockType _customPathCreation;
    CDUnknownBlockType _customPathModification;
    CDUnknownBlockType _customLinePointMapping;
    CDUnknownBlockType _customFillColor;
    CDUnknownBlockType _customLineColor;
    CDUnknownBlockType _customLineWidth;
    NSDictionary *_fillColors;
    NSData *_mappedLinePointsX;
    NSData *_mappedLinePointsY;
}

+ (id)graphCustomLine;
@property(retain, nonatomic) NSData *mappedLinePointsY; // @synthesize mappedLinePointsY=_mappedLinePointsY;
@property(retain, nonatomic) NSData *mappedLinePointsX; // @synthesize mappedLinePointsX=_mappedLinePointsX;
@property(retain, nonatomic) NSDictionary *fillColors; // @synthesize fillColors=_fillColors;
@property(copy, nonatomic) CDUnknownBlockType customLineWidth; // @synthesize customLineWidth=_customLineWidth;
@property(copy, nonatomic) CDUnknownBlockType customLineColor; // @synthesize customLineColor=_customLineColor;
@property(copy, nonatomic) CDUnknownBlockType customFillColor; // @synthesize customFillColor=_customFillColor;
@property(copy, nonatomic) CDUnknownBlockType customLinePointMapping; // @synthesize customLinePointMapping=_customLinePointMapping;
@property(copy, nonatomic) CDUnknownBlockType customPathModification; // @synthesize customPathModification=_customPathModification;
@property(copy, nonatomic) CDUnknownBlockType customPathCreation; // @synthesize customPathCreation=_customPathCreation;
@property(copy, nonatomic) CDUnknownBlockType customDrawing; // @synthesize customDrawing=_customDrawing;
@property(retain, nonatomic) NSValue *startEndAddition; // @synthesize startEndAddition=_startEndAddition;
@property(nonatomic) _Bool pixelAccurateDrawing; // @synthesize pixelAccurateDrawing=_pixelAccurateDrawing;
@property(nonatomic) _Bool filled; // @synthesize filled=_filled;
@property(retain, nonatomic) NSDictionary *lineWidths; // @synthesize lineWidths=_lineWidths;
@property(retain, nonatomic) NSData *linePointsY; // @synthesize linePointsY=_linePointsY;
@property(retain, nonatomic) NSData *linePointsX; // @synthesize linePointsX=_linePointsX;
@property(retain, nonatomic) NSDictionary *lineColors; // @synthesize lineColors=_lineColors;
- (void).cxx_destruct;
- (id)actionInfoForPoint:(struct CGPoint)arg1 event:(id)arg2;
- (void)setNeedsPathUpdate;
- (void)drawLayer:(id)arg1 inContext:(struct CGContext *)arg2;
- (_Bool)containsPoint:(struct CGPoint)arg1;
- (struct CGPath *)pathFromLinePoints;
- (void)updateLinePoints;
- (float)yFromX:(double)arg1;
@property(readonly, nonatomic) unsigned long long numLinePoints;
- (float *)linePointBufferY;
- (float *)linePointBufferX;
@property(readonly, nonatomic) NSNumber *lineWidth;
@property(readonly, nonatomic) struct CGColor *lineColor;
@property(readonly, nonatomic) struct CGColor *fillColor;
@property(readonly, nonatomic) NSNumber *currentLineWidth;
@property(readonly, nonatomic) struct CGColor *currentLineColor;
@property(readonly, nonatomic) struct CGColor *currentFillColor;
- (void)setScaleFactor:(double)arg1;
- (void)setCoPosition:(id)arg1;
@property(readonly, nonatomic) id currentPath; // @synthesize currentPath=_currentPath;
- (id)coSize;
- (id)coPosition;
- (struct CGRect)coFrame;
- (struct CGPoint)anchorPoint;
- (id)init;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end
