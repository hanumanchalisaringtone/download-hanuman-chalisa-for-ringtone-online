//
//     Generated by class-dump 3.5 (64 bit) (Debug version compiled Aug 30 2018 09:46:22).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2015 by Steve Nygard.
//

#import <UIKit/UITableViewCell.h>

@class NSString, UILabel;

@interface SCNameAndEmailCell : UITableViewCell
{
    UILabel *nameLabel;
    UILabel *emailLabel;
    UILabel *mailTypeLabel;
}

@property(nonatomic) UILabel *mailTypeLabel; // @synthesize mailTypeLabel;
@property(nonatomic) UILabel *emailLabel; // @synthesize emailLabel;
@property(nonatomic) UILabel *nameLabel; // @synthesize nameLabel;
- (void)layoutSubviews;
@property(retain) NSString *mailType;
@property(retain) NSString *email;
@property(retain) NSString *name;
- (id)init;

@end
