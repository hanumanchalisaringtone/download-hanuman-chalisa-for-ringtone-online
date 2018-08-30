//
//     Generated by class-dump 3.5 (64 bit) (Debug version compiled Aug 30 2018 09:46:22).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2015 by Steve Nygard.
//

#import <objc/NSObject.h>

@class NSString;

@interface GSDK_GTMRegex : NSObject
{
    NSString *pattern_;
    unsigned long long options_;
    struct {
        int re_magic;
        unsigned long long re_nsub;
        char *re_endp;
        struct re_guts *re_g;
    } regexData_;
}

+ (id)escapedPatternForString:(id)arg1;
+ (id)regexWithPattern:(id)arg1 options:(unsigned long long)arg2 withError:(id *)arg3;
+ (id)regexWithPattern:(id)arg1 options:(unsigned long long)arg2;
+ (id)regexWithPattern:(id)arg1;
- (id)description;
- (id)stringByReplacingMatchesInString:(id)arg1 withReplacement:(id)arg2;
- (id)matchSegmentEnumeratorForString:(id)arg1;
- (id)segmentEnumeratorForString:(id)arg1;
- (_Bool)matchesSubStringInString:(id)arg1;
- (id)firstSubStringMatchedInString:(id)arg1;
- (id)subPatternsOfString:(id)arg1;
- (_Bool)matchesString:(id)arg1;
- (unsigned long long)subPatternCount;
- (void)dealloc;
- (id)initWithPattern:(id)arg1 options:(unsigned long long)arg2 withError:(id *)arg3;
- (id)initWithPattern:(id)arg1 options:(unsigned long long)arg2;
- (id)initWithPattern:(id)arg1;
- (id)init;
- (_Bool)runRegexOnUTF8:(const char *)arg1 nmatch:(unsigned long long)arg2 pmatch:(CDStruct_912cb5d2 *)arg3 flags:(int)arg4;
- (id)errorMessage:(int)arg1;

@end
