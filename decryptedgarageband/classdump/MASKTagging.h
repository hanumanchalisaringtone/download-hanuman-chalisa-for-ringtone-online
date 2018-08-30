//
//     Generated by class-dump 3.5 (64 bit) (Debug version compiled Aug 30 2018 09:46:22).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2015 by Steve Nygard.
//

#import <CoreData/NSManagedObject.h>

@class MASKItem, MASKTag;

@interface MASKTagging : NSManagedObject
{
}

+ (id)entityName;
@property(readonly, nonatomic) _Bool doubleValueEnabled; // @dynamic doubleValueEnabled;
@property(readonly, nonatomic) _Bool integerValueEnabled; // @dynamic integerValueEnabled;

// Remaining properties
@property(nonatomic) double doubleUpperValue; // @dynamic doubleUpperValue;
@property(nonatomic) double doubleValue; // @dynamic doubleValue;
@property(nonatomic) long long flags; // @dynamic flags;
@property(nonatomic) long long integerValue; // @dynamic integerValue;
@property(retain, nonatomic) MASKItem *item; // @dynamic item;
@property(retain, nonatomic) MASKTag *tag; // @dynamic tag;
@property(nonatomic) float weight; // @dynamic weight;

@end
