/*
* This header is generated by classdump-dyld 1.0
* on Wednesday, August 22, 2018 at 12:28:31 AM Central European Summer Time
* Operating System: Version 11.3.1 (Build 15E302)
* Image Source: /System/Library/PrivateFrameworks/ToneLibrary.framework/ToneLibrary
* classdump-dyld is licensed under GPLv3, Copyright © 2013-2016 by Elias Limneos.
*/


@class TLAlert;

@interface TLAlertActivationAssertion : NSObject {

	TLAlert* _alert;
	Aq _activeAcquisitionCount;

}
-(void)dealloc;
-(id)description;
-(void)_relinquish;
-(void)_acquire;
-(id)initWithAlert:(id)arg1 ;
-(void)acquire;
-(void)relinquish;
@end
