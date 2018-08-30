//
//     Generated by class-dump 3.5 (64 bit) (Debug version compiled Aug 30 2018 09:46:22).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2015 by Steve Nygard.
//

#import <objc/NSObject.h>

@class NSString;

@interface AUAppConfig : NSObject
{
    NSString *_choosenDebugURL;
    _Bool _showNoRingtones;
    _Bool _isNewVersionAvailable;
    _Bool _isRateAlertDisabled;
    NSString *_appiTunesLink;
    long long _nativeAdPeriod;
}

@property(nonatomic) long long nativeAdPeriod; // @synthesize nativeAdPeriod=_nativeAdPeriod;
@property(retain, nonatomic) NSString *appiTunesLink; // @synthesize appiTunesLink=_appiTunesLink;
@property(nonatomic) _Bool isRateAlertDisabled; // @synthesize isRateAlertDisabled=_isRateAlertDisabled;
@property(readonly, nonatomic) _Bool isNewVersionAvailable; // @synthesize isNewVersionAvailable=_isNewVersionAvailable;
@property(nonatomic) _Bool showNoRingtones; // @synthesize showNoRingtones=_showNoRingtones;
- (void).cxx_destruct;
- (void)checkNewestVersion;
- (void)setActualVersion:(id)arg1;
@property(retain, nonatomic) NSString *choosenDebugURL;

@end
