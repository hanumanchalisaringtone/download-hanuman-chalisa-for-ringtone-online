//
//     Generated by class-dump 3.5 (64 bit) (Debug version compiled Aug 30 2018 09:46:22).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2015 by Steve Nygard.
//

#import <Foundation/NSObject.h>

@interface FABNetworkResponseHandler : NSObject
{
}

+ (void)handleCompletedResponse:(id)arg1 forOriginalRequest:(id)arg2 error:(id)arg3 block:(CDUnknownBlockType)arg4;
+ (void)clientResponseType:(id)arg1 handler:(CDUnknownBlockType)arg2;
+ (id)errorForResponse:(id)arg1 ofType:(long long)arg2 status:(long long)arg3;
+ (id)errorForCode:(long long)arg1 userInfo:(id)arg2;
+ (_Bool)contentTypeForResponse:(id)arg1 matchesRequest:(id)arg2;
+ (id)requestIdForResponse:(id)arg1;
+ (double)retryValueForResponse:(id)arg1;
+ (id)headerForResponse:(id)arg1 withKey:(id)arg2;

@end
