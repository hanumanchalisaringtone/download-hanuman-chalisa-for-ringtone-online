//
//     Generated by class-dump 3.5 (64 bit) (Debug version compiled Aug 30 2018 09:46:22).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2015 by Steve Nygard.
//

#import <UIKit/UIView.h>

@class UIImage;

@interface MAUIPageControl : UIView
{
    double _dotDistance;
    double _dotSize;
    id _target;
    SEL _action;
    _Bool _hidesForSinglePage;
    _Bool _allowTapBeyondDotsForPaging;
    long long _currentPage;
    long long _numberOfPages;
    UIImage *_dotImage;
    UIImage *_selectedDotImage;
}

@property(nonatomic) _Bool allowTapBeyondDotsForPaging; // @synthesize allowTapBeyondDotsForPaging=_allowTapBeyondDotsForPaging;
@property(retain, nonatomic) UIImage *selectedDotImage; // @synthesize selectedDotImage=_selectedDotImage;
@property(retain, nonatomic) UIImage *dotImage; // @synthesize dotImage=_dotImage;
@property(nonatomic) _Bool hidesForSinglePage; // @synthesize hidesForSinglePage=_hidesForSinglePage;
@property(nonatomic) long long numberOfPages; // @synthesize numberOfPages=_numberOfPages;
@property(nonatomic) long long currentPage; // @synthesize currentPage=_currentPage;
- (void).cxx_destruct;
- (void)touchesEnded:(id)arg1 withEvent:(id)arg2;
- (void)drawRect:(struct CGRect)arg1;
- (struct CGPoint)positionOfFirstDot;
- (void)setTarget:(id)arg1 action:(SEL)arg2;
- (id)initWithFrame:(struct CGRect)arg1;
- (id)initWithCoder:(id)arg1;
- (void)commonInit;

@end
