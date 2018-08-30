//
//     Generated by class-dump 3.5 (64 bit) (Debug version compiled Aug 30 2018 09:46:22).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2015 by Steve Nygard.
//

#import <objc/NSObject.h>

#import "FBAdBrowserControllerDelegate-Protocol.h"
#import "FBInterstitialAdDelegate-Protocol.h"
#import "SKStoreProductViewControllerDelegate-Protocol.h"

@class FBAdBrowserController, FBAdDataModel, FBInterstitialAdInternal, NSDate, NSString;
@protocol FBAdCommandProcessorDelegate;

@interface FBAdCommandProcessor : NSObject <SKStoreProductViewControllerDelegate, FBAdBrowserControllerDelegate, FBInterstitialAdDelegate>
{
    _Bool _hideStatusBarOnStoreViewController;
    id <FBAdCommandProcessorDelegate> _delegate;
    FBAdDataModel *_adDataModel;
    CDUnknownBlockType _completionHandler;
    FBAdBrowserController *_adBrowser;
    FBInterstitialAdInternal *_interstitialAd;
    NSDate *_lastActionStartTime;
    long long _lastAdAction;
}

+ (void)sendBouncebackInfo:(id)arg1 withAdAction:(long long)arg2 withRequestId:(id)arg3;
+ (_Bool)shouldInvalidate:(id)arg1;
@property(nonatomic) long long lastAdAction; // @synthesize lastAdAction=_lastAdAction;
@property(retain, nonatomic) NSDate *lastActionStartTime; // @synthesize lastActionStartTime=_lastActionStartTime;
@property(retain, nonatomic) FBInterstitialAdInternal *interstitialAd; // @synthesize interstitialAd=_interstitialAd;
@property(retain, nonatomic) FBAdBrowserController *adBrowser; // @synthesize adBrowser=_adBrowser;
@property(copy, nonatomic) CDUnknownBlockType completionHandler; // @synthesize completionHandler=_completionHandler;
@property(retain, nonatomic) FBAdDataModel *adDataModel; // @synthesize adDataModel=_adDataModel;
@property(nonatomic) _Bool hideStatusBarOnStoreViewController; // @synthesize hideStatusBarOnStoreViewController=_hideStatusBarOnStoreViewController;
@property(nonatomic) __weak id <FBAdCommandProcessorDelegate> delegate; // @synthesize delegate=_delegate;
- (void).cxx_destruct;
- (void)interstitialAdDidClose:(id)arg1;
- (_Bool)showInterstitialAd;
- (void)viewControllerDismissed:(id)arg1;
- (void)productViewControllerDidFinish:(id)arg1;
- (_Bool)isValidViewController:(id)arg1;
- (void)doneCommandProcessing;
- (void)callCompletionHanlderForCommand:(long long)arg1 withAdAction:(long long)arg2;
- (_Bool)launchURLOutOfApp:(id)arg1 withAdAction:(long long)arg2;
- (_Bool)openLinkInApp:(id)arg1;
- (_Bool)preloadProductViewControllerIfAvailable:(id)arg1;
- (_Bool)launchAppForEngagement:(id)arg1;
- (_Bool)processCommand:(id)arg1 adDataModel:(id)arg2 completionHandler:(CDUnknownBlockType)arg3;
- (void)dealloc;
- (id)init;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end
