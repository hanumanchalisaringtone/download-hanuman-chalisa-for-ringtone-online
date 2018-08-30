//
//     Generated by class-dump 3.5 (64 bit) (Debug version compiled Aug 30 2018 09:46:22).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2015 by Steve Nygard.
//

#import "ANSEvent.h"

@class ANSAttributeDictionary, NSString;

@interface ANSCustomEvent : ANSEvent
{
    NSString *_customEventName;
    ANSAttributeDictionary *_customAttributes;
}

@property(retain, nonatomic) ANSAttributeDictionary *customAttributes; // @synthesize customAttributes=_customAttributes;
@property(readonly, nonatomic) NSString *customEventName; // @synthesize customEventName=_customEventName;
- (void).cxx_destruct;
- (id)description;
- (id)dictionaryRepresentation;
- (id)name;
- (id)initWithCustomEventName:(id)arg1 customAttributes:(id)arg2;

@end
