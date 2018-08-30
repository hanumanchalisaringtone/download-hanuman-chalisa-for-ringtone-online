//
//     Generated by class-dump 3.5 (64 bit) (Debug version compiled Aug 30 2018 09:46:22).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2015 by Steve Nygard.
//

#import <objc/NSObject.h>

@class NSMutableDictionary, NSMutableSet;
@protocol OS_dispatch_queue;

@interface FIRAInAppPurchaseProductCache : NSObject
{
    NSMutableSet *_invalidProductIdentifiers;
    NSMutableDictionary *_validProducts;
    NSObject<OS_dispatch_queue> *_lockQueue;
}

+ (id)sharedInstance;
- (void).cxx_destruct;
- (void)requestProductsWithProductIdentifiers:(id)arg1 queue:(id)arg2 completionHandler:(CDUnknownBlockType)arg3;
- (id)cachedProductForProductIdentifier:(id)arg1;
- (id)init;

@end
