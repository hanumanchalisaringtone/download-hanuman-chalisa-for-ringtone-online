//
//     Generated by class-dump 3.5 (64 bit) (Debug version compiled Aug 30 2018 09:46:22).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2015 by Steve Nygard.
//

#import "GSDK_PBGeneratedMessage.h"

@class ACPResultData;

@interface ACPAudienceLeafFilterResult : GSDK_PBGeneratedMessage
{
}

+ (id)descriptor;

// Remaining properties
@property(nonatomic) int audienceId; // @dynamic audienceId;
@property(retain, nonatomic) ACPResultData *currentData; // @dynamic currentData;
@property(nonatomic) _Bool hasAudienceId; // @dynamic hasAudienceId;
@property(nonatomic) _Bool hasCurrentData; // @dynamic hasCurrentData;
@property(nonatomic) _Bool hasNewAudience; // @dynamic hasNewAudience;
@property(nonatomic) _Bool hasPreviousData; // @dynamic hasPreviousData;
@property(nonatomic) _Bool newAudience; // @dynamic newAudience;
@property(retain, nonatomic) ACPResultData *previousData; // @dynamic previousData;

@end
