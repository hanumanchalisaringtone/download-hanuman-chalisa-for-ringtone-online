//
//     Generated by class-dump 3.5 (64 bit) (Debug version compiled Aug 30 2018 09:46:22).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2015 by Steve Nygard.
//

#import "CLSAnalyticsEvent.h"

@interface CLSAnalyticsApplicationLifecycleEvent : CLSAnalyticsEvent
{
}

- (id)initApplicationCrashedEventWithTimestamp:(unsigned long long)arg1 eventIdentifier:(id)arg2;
- (id)initApplicationLaunchedEventWithTimestamp:(unsigned long long)arg1 eventIdentifier:(id)arg2;
- (id)initApplicationInstalledEventWithTimestamp:(unsigned long long)arg1 eventIdentifier:(id)arg2;
- (id)initWithApplicationNotificationName:(id)arg1 timestamp:(unsigned long long)arg2 eventIdentifier:(id)arg3 highPriorityEventOnBackground:(_Bool)arg4;

@end
