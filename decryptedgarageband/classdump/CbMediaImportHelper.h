//
//     Generated by class-dump 3.5 (64 bit) (Debug version compiled Aug 30 2018 09:46:22).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2015 by Steve Nygard.
//

#import <Foundation/NSObject.h>

#import "CbCopyFilesControllerDelegate-Protocol.h"

@class DfDocument, NSURL;

@interface CbMediaImportHelper : NSObject <CbCopyFilesControllerDelegate>
{
    NSURL *_lockedURL;
    _Bool _targetIsGrid;
    CDUnknownBlockType __actionBlock;
    CDUnknownBlockType __removeUIHelpersBlock;
    CDUnknownBlockType __samplerImportFinishedBlock;
    DfDocument *_document;
}

@property(nonatomic) _Bool targetIsGrid; // @synthesize targetIsGrid=_targetIsGrid;
@property(nonatomic) __weak DfDocument *document; // @synthesize document=_document;
@property(copy, nonatomic) CDUnknownBlockType _samplerImportFinishedBlock; // @synthesize _samplerImportFinishedBlock=__samplerImportFinishedBlock;
@property(copy, nonatomic) CDUnknownBlockType _removeUIHelpersBlock; // @synthesize _removeUIHelpersBlock=__removeUIHelpersBlock;
@property(copy, nonatomic) CDUnknownBlockType _actionBlock; // @synthesize _actionBlock=__actionBlock;
- (void).cxx_destruct;
- (void)dealloc;
- (void)clearReferences;
- (_Bool)importFileWithDragInfo:(id)arg1 targetTrack:(id)arg2 targetIsGrid:(_Bool)arg3 allowSamplerImport:(_Bool)arg4 samplerImportFinishedBlock:(CDUnknownBlockType)arg5 doActionBlock:(CDUnknownBlockType)arg6 removeUIHelpersBlock:(CDUnknownBlockType)arg7 pIsAsyncOperation:(_Bool *)arg8;
- (void)copyFilesController:(id)arg1 finishedWithError:(id)arg2 destinationFilePaths:(id)arg3;
- (_Bool)_copyExternalFile:(id)arg1 targetTrack:(id)arg2 isSamplerImport:(_Bool)arg3 isInternalLoop:(_Bool)arg4 additionalUserInfo:(id)arg5;
- (void)_unlockURL;
- (void)_callRemoveDragUIHelpersBlock;
- (_Bool)_callDoActionBlockWithFilePath:(id)arg1 targetTrack:(id)arg2 newTrackCreated:(_Bool)arg3;
- (id)_getDiskSpaceAlert;
- (void)_showDefaultErrorAlertForError:(id)arg1;
- (id)model;
- (id)initWithDocument:(id)arg1;

@end
