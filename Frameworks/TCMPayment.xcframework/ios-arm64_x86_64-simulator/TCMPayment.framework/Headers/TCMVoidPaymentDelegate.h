//
// Copyright 2016 TF PAYMENT SERVICE CO.,LTD.
// All rights reserved.
//
#import <Foundation/Foundation.h>

#import "TCMFrontOfficeDelegate.h"

@class TCMPayment;

/// Void payment service delegate.
///
@protocol TCMVoidPaymentDelegate <TCMFrontOfficeDelegate>

/// Save thincacloud deal number.
///
/// @param sender           sender object.
/// @param thincaDealNumber thincacloud deal number.
///
- (void)saveThincaDealNumber:(nonnull TCMPayment *)sender
            thincaDealNumber:(nonnull NSString *)thincaDealNumber;

@end
