//
//     Generated by class-dump 3.5 (64 bit) (Debug version compiled Aug 30 2018 09:46:22).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2015 by Steve Nygard.
//

#import "GenInstDrummer_TrackModelProtocolPublic-Protocol.h"

@class NSArray, NSDictionary, NSString, NSURL;

@protocol GenInstDrummer_TrackModelProtocol <GenInstDrummer_TrackModelProtocolPublic>
- (NSDictionary *)state;
- (void)setStateFromTrackCopy:(NSDictionary *)arg1;
- (void)setState:(NSDictionary *)arg1;
- (_Bool)keepDrumKitWhenChangingDrummer;
- (void)setKeepDrumKitWhenChangingDrummer:(_Bool)arg1;
- (_Bool)parametersWhereChangedAfterCharacterRecall;
- (void)setParametersWhereChangedAfterCharacterRecall:(_Bool)arg1;
- (_Bool)loadPatchForURL:(NSURL *)arg1 options:(NSDictionary *)arg2;
- (_Bool)isContentBeingDownloadedForPatchWithURL:(NSURL *)arg1;
- (_Bool)contentWasDownloadedForPatchWithURL:(NSURL *)arg1;
- (void)downloadContentForPatchWithURL:(NSURL *)arg1 groupInfo:(NSDictionary *)arg2;
- (_Bool)loadPatchForSelectedCharacterAtIndex:(unsigned long long)arg1;
- (NSArray *)patchURLsForGenreIdentifier:(NSString *)arg1 characterIdentifier:(NSString *)arg2;
- (_Bool)isDefaultContentBeingDownloadedForGenreIdentifier:(NSString *)arg1 characterIdentifier:(NSString *)arg2;
- (_Bool)defaultContentWasDownloadedForGenreIdentifier:(NSString *)arg1 characterIdentifier:(NSString *)arg2;
- (void)downloadDefaultContentForGenreIdentifier:(NSString *)arg1 characterIdentifier:(NSString *)arg2;
- (_Bool)saveNewPresetForRegion:(struct CRegion *)arg1 outPresetUniqueIdentifier:(id *)arg2;
- (void)setSelectedGenre:(NSString *)arg1 characterIdentifier:(NSString *)arg2 options:(NSDictionary *)arg3;
- (_Bool)keepSettingsWhenChangingDrummer;
- (void)setKeepSettingsWhenChangingDrummer:(_Bool)arg1;
- (void)setKeepSettingsWhenChangingDrummer:(_Bool)arg1 parameterKeysToKeep:(NSArray *)arg2;
- (auto_ptr_9f8f0b23)noteNrHelper;
- (void)generateEventsWithSameSeedsForRegions:(vector_e75b7d21)arg1;
- (void)generateEventsWithZeroSeedsAndOption:(int)arg1;
- (void)generateEventsWithSameSeedsAndOption:(int)arg1;
- (void)generateEventsWithNewSeedsAndOption:(int)arg1;
- (void)prepareGenerateToSpeedUpFirstPlayOnTrack:(struct CVirtualTrack)arg1;
- (NSString *)proposedClaveTrackUUIDForRegion:(const struct CRegion *)arg1;
- (vector_e94a763c)claveCandidateTracks;
- (unsigned long long)drummerTrackPatchType;
- (NSString *)drumKitDesignerPresetName;
- (void)togglePlugInEditor;
- (void)convertTrackAndItsRegionsToMidi:(struct CVirtualTrack)arg1;
- (void)convertRegionToMidiRegion:(struct CEvLaunch *)arg1;
- (void)convertSelectedRegionsToMidiRegions;
- (void)convertSelectedRegionsToDrummerRegions;
- (void)resetRegionParametersForRegion:(struct CRegion *)arg1;
- (void)initializeNewDrummerRegion:(struct CRegion *)arg1 options:(NSDictionary *)arg2;
- (void)initializeDrumTrackWithOptions:(NSDictionary *)arg1;
- (struct CSong *)song;
- (struct CVirtualTrack)associatedDrumTrack;
@end
