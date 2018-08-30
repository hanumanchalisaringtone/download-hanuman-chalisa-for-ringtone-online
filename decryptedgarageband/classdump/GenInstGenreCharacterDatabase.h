//
//     Generated by class-dump 3.5 (64 bit) (Debug version compiled Aug 30 2018 09:46:22).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2015 by Steve Nygard.
//

#import <Foundation/NSObject.h>

#import "GenInstGenreCharacterDatabase-Protocol.h"

@class NSMutableDictionary, NSString, NSURL;

@interface GenInstGenreCharacterDatabase : NSObject <GenInstGenreCharacterDatabase>
{
    _Bool _showHiddenCharacters;
    NSURL *_databaseURL;
    NSMutableDictionary *_genreCharacterDatabase;
    unsigned long long _version;
    long long _appVariant;
}

@property long long appVariant; // @synthesize appVariant=_appVariant;
@property _Bool showHiddenCharacters; // @synthesize showHiddenCharacters=_showHiddenCharacters;
@property unsigned long long version; // @synthesize version=_version;
@property(retain) NSMutableDictionary *genreCharacterDatabase; // @synthesize genreCharacterDatabase=_genreCharacterDatabase;
@property(retain) NSURL *databaseURL; // @synthesize databaseURL=_databaseURL;
- (id)characterForGenreIdentifier:(id)arg1 characterIdentifier:(id)arg2;
- (id)charactersForGenreIdentifier:(id)arg1;
- (id)genreWithIdentifier:(id)arg1;
- (id)mutableGenres;
- (id)genres;
- (void)updateVersionNumber;
- (void)loadDatabase;
- (void)removeHiddenCharacters;
- (void)processCharacters;
- (void)updateCharactersAndGenresWithLocalizableStrings;
- (void)localizeCharacter:(id)arg1 withLocalizableStringsDict:(id)arg2;
- (void)localizeGenre:(id)arg1 withLocalizableStringsDict:(id)arg2;
- (void)iterateCharactersWithBlock:(CDUnknownBlockType)arg1;
- (void)iterateGenresWithBlock:(CDUnknownBlockType)arg1;
- (id)localizableStringsDict;
- (void)setupPatchesForCharacterV4:(id)arg1;
- (void)setupPatchesForCharacter:(id)arg1;
- (void)addAutoHalfTimeThresholdIfMissingForCharacter:(id)arg1;
- (void)addCharacterTypePropertyIfMissingForCharacter:(id)arg1;
- (void)checkPatchesEntryForCharacter:(id)arg1;
- (void)updateSwingTypeForCharacter:(id)arg1;
- (void)dealloc;
- (id)initWithURL:(id)arg1 options:(id)arg2;
- (id)initWithURL:(id)arg1;
- (long long)appVariantFromString:(id)arg1;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end
