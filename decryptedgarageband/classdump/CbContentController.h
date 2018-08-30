//
//     Generated by class-dump 3.5 (64 bit) (Debug version compiled Aug 30 2018 09:46:22).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2015 by Steve Nygard.
//

#import <Foundation/NSObject.h>

@interface CbContentController : NSObject
{
}

+ (id)unreadContentPacks;
+ (id)allInstalledPackageBundleInfoDicts;
+ (id)packageBundleInfoDictForPackWithID:(id)arg1;
+ (void)_flushBundleCacheForPackWithID:(id)arg1;
+ (id)allInstalledPackageBundleNames;
+ (_Bool)canBeInstalledOnThisAppVersionForContentPackWithID:(id)arg1;
+ (_Bool)canBeInstalledOnThisHardwareForContentPackWithID:(id)arg1;
+ (_Bool)canBeInstalledForContentPackWithID:(id)arg1;
+ (id)packageVersionNumberForContentPackWithID:(id)arg1;
+ (unsigned long long)installSizeForContentPackWithID:(id)arg1;
+ (id)downloadURLforContentPackWithID:(id)arg1;
+ (_Bool)hasPlistInfoForPackWithID:(id)arg1;
+ (id)allAvailableAndCompatiblePackageBundleNames;
+ (id)_filteredCompatiblePackBundleIDs:(id)arg1;
+ (id)allAvailablePackageBundleNames;
+ (id)contentPacksWithIDsContainGrids:(id)arg1;
+ (id)contentPacksWithIDsContainLoops:(id)arg1;
+ (id)contentPacksWithIDs:(id)arg1 containCSTsForInstrumentBrowserCategoryWithKey:(id)arg2;
+ (id)contentPacksWithIDs:(id)arg1 containCSTsForInputMethodWithKey:(id)arg2;
+ (id)localizedPackDisplayNameForID:(id)arg1;
+ (id)localizedStringForKey:(id)arg1 value:(id)arg2 table:(id)arg3 includeFactoryAppTables:(_Bool)arg4 explicitAdditionalContentIdentifier:(id)arg5;
+ (_Bool)hasDebugImportedAdditionalContentBundles;
+ (void)debugAutoImportAdditionalContentIfNeeded;
+ (void)debugClearAdditionalContentFolder;
+ (void)debugMarkAllPacksAsUnread;
+ (id)autoCorrectedContentPathIfPossible:(id)arg1;
+ (id)contentPathForFactoryLocation:(id)arg1 explicitAdditionalContentIdentifier:(id)arg2 excludeFactoryContent:(_Bool)arg3;
+ (id)contentPathForFactoryLocation:(id)arg1;
+ (void)markPackage:(id)arg1 read:(_Bool)arg2;
+ (id)readContentPacks;
+ (void)additionalContentInstallationsChanged;
+ (void)delayedReinitInstrumentsIfNecessaryAfterAdditionalContentInstallationsChanged;
+ (void)_reinitInstruments;
+ (_Bool)_isReinitInstrumentsPossible;
+ (void)_handleSpecialSongNotifications:(id)arg1;
+ (void)showDownloadAndInstallationFinishedAlertForBundleName:(id)arg1;
+ (void)showDownloadOrInstallationFailedAlertForBundleName:(id)arg1;
+ (_Bool)handleDownloadedAdditionalContentTempZipFileAtPath:(id)arg1 expectedBundleName:(id)arg2 finishedHandler:(CDUnknownBlockType)arg3;
+ (void)checkForAvailableUpdates;
+ (void)deleteContentPack:(id)arg1;
+ (_Bool)contentPacksAreInstalled:(id)arg1;
+ (_Bool)contentPackIsInstalled:(id)arg1;
+ (_Bool)hasLocalAdditionalContentBundles;
+ (void)enumerateLocalAdditionalContentBundlePaths:(CDUnknownBlockType)arg1;
+ (id)additionalContentBundleNameForID:(id)arg1;
+ (id)contentBundleNameFromFullPath:(id)arg1;
+ (id)samplerInstrumentsFolders;
+ (id)additionalContentLocation;
+ (void)appStartInitialization;
+ (void)initialize;

@end
