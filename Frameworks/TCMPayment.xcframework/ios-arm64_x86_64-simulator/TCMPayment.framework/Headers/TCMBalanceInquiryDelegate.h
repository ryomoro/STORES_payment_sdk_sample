//
// Copyright 2016 TF PAYMENT SERVICE CO.,LTD.
// All rights reserved.
//
#import <Foundation/Foundation.h>

#import "TCMFrontOfficeDelegate.h"

@class TCMPayment;

/// Balance inquiry service delegate.
///
@protocol TCMBalanceInquiryDelegate <TCMFrontOfficeDelegate>

@optional

/// Show select brand view.
///
/// @param sender     sender object.
/// @param brandList  brand code list.
///
- (void)showSelectBrandView:(nonnull TCMPayment *)sender
                  brandList:(nonnull NSArray<NSNumber *> *)brandList;

/// Hide select brand view.
///
/// @param sender sender object.
///
- (void)hideSelectBrandView:(nonnull TCMPayment *)sender;

@end
