//
//     Generated by class-dump 3.5 (64 bit) (Debug version compiled Aug 30 2018 09:46:22).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2015 by Steve Nygard.
//

#import <Foundation/NSObject.h>

@class NSSet, NSString;

@interface TAGFunctionCallImplementation : NSObject
{
    NSString *_instanceFunctionId;
    NSSet *_requiredKeys;
}

+ (id)notDefaultMacroKey;
+ (id)instanceNameKey;
+ (id)functionKey;
@property(readonly, retain, nonatomic) NSSet *requiredKeys; // @synthesize requiredKeys=_requiredKeys;
@property(readonly, copy, nonatomic) NSString *instanceFunctionId; // @synthesize instanceFunctionId=_instanceFunctionId;
- (void).cxx_destruct;
- (_Bool)hasRequiredKeys:(id)arg1;
- (id)evaluate:(id)arg1;
- (_Bool)isCacheable;
- (id)initWithFunctionId:(id)arg1 requiredKeys:(id)arg2;
- (id)init;

@end
