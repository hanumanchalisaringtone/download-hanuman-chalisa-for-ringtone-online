//
//     Generated by class-dump 3.5 (64 bit) (Debug version compiled Aug 30 2018 09:46:22).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2015 by Steve Nygard.
//

#import <objc/NSObject.h>

@interface FBDevice : NSObject
{
}

+ (_Bool)systemVersionIsLessThan:(id)arg1;
+ (_Bool)systemVersionIsGreaterThanOrEqualTo:(id)arg1;
+ (id)systemVersion;
+ (_Bool)isRunningOnPadInPhoneEmulator;
+ (_Bool)supportsCamera;
+ (unsigned long long)freeDiskCount;
+ (unsigned long long)totalMemoryCount;
+ (unsigned long long)freeMemoryCount;
+ (struct FBDeviceBatteryInfo)deviceBatteryInfo;
+ (unsigned long long)deviceModel;
+ (unsigned int)coreCount;
+ (_Bool)isPad;
+ (id)systemName;
+ (id)model;
+ (id)architecture;
+ (id)machine;
+ (void)resetCache;
+ (void)initializeAndCacheValues;
+ (void)initialize;

@end
