//
//     Generated by class-dump 3.5 (64 bit) (Debug version compiled Aug 30 2018 09:46:22).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2015 by Steve Nygard.
//

#import "NSObject-Protocol.h"

@class GADWebView, NSError, NSString, NSURLRequest;

@protocol GADWebViewDelegate <NSObject>
- (void)webView:(GADWebView *)arg1 runJavaScriptAlertPanelWithTitle:(NSString *)arg2 message:(NSString *)arg3 completionHandler:(void (^)(void))arg4;
- (void)webView:(GADWebView *)arg1 didFailLoadWithError:(NSError *)arg2;
- (void)webViewDidFinishLoad:(GADWebView *)arg1;
- (void)webViewDidStartLoad:(GADWebView *)arg1;
- (_Bool)webView:(GADWebView *)arg1 shouldStartLoadWithRequest:(NSURLRequest *)arg2 navigationType:(long long)arg3;
@end
