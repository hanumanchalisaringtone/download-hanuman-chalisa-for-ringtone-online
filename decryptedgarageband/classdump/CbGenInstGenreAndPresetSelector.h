//
//     Generated by class-dump 3.5 (64 bit) (Debug version compiled Aug 30 2018 09:46:22).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2015 by Steve Nygard.
//

#import <UIKit/UIControl.h>

#import "CbGenInstItemSelectorProtocol-Protocol.h"
#import "CbGenInstPickerViewDataSource-Protocol.h"
#import "CbGenInstPickerViewDelegate-Protocol.h"

@class CbGenInstPickerView, NSString, UIView;
@protocol CbGenInstItemSelectorDatasource, CbGenInstItemSelectorDelegate;

@interface CbGenInstGenreAndPresetSelector : UIControl <CbGenInstItemSelectorProtocol, CbGenInstPickerViewDataSource, CbGenInstPickerViewDelegate>
{
    _Bool shouldHideForXYPad;
    id <CbGenInstItemSelectorDatasource> _dataSource;
    id <CbGenInstItemSelectorDelegate> _delegate;
    CbGenInstPickerView *_pickerView;
}

@property(retain, nonatomic) CbGenInstPickerView *pickerView; // @synthesize pickerView=_pickerView;
@property(nonatomic) id <CbGenInstItemSelectorDelegate> delegate; // @synthesize delegate=_delegate;
@property(nonatomic) id <CbGenInstItemSelectorDatasource> dataSource; // @synthesize dataSource=_dataSource;
@property(nonatomic) _Bool shouldHideForXYPad; // @synthesize shouldHideForXYPad;
- (void).cxx_destruct;
- (void)pickerTableView:(id)arg1 didSelectIndexPath:(id)arg2;
- (long long)indexOfSelectedItemInPickerTableView:(id)arg1;
- (id)pickerTableView:(id)arg1 titleForRow:(long long)arg2;
- (long long)numberOfRowsInPickerTableView:(id)arg1;
- (void)selectPresetWithRowIndex:(long long)arg1;
- (void)reloadData;
@property(readonly) UIView *itemSelectorLabelView;
- (void)awakeFromNib;
- (void)internalInit;
- (void)dealloc;
- (id)initWithFrame:(struct CGRect)arg1;
- (id)initWithCoder:(id)arg1;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end
