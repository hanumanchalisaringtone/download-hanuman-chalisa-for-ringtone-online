//
//     Generated by class-dump 3.5 (64 bit) (Debug version compiled Aug 30 2018 09:46:22).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2015 by Steve Nygard.
//

#import <Foundation/NSObject.h>

@interface ECNonBlockingQueue : NSObject
{
    // Error parsing type: {atomic<ECNonBlockingQueueItem *>="__a_"A^{ECNonBlockingQueueItem}}, name: head
    // Error parsing type: {atomic<ECNonBlockingQueueItem *>="__a_"A^{ECNonBlockingQueueItem}}, name: tail
}

- (void)clearAllObjects;
- (id)dequeueObject;
- (void)addObject:(id)arg1;
- (void)dealloc;
- (id)init;

@end
