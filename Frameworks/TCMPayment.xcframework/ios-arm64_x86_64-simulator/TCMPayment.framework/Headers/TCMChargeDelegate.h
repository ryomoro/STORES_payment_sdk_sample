//
// Copyright 2016 TF PAYMENT SERVICE CO.,LTD.
// All rights reserved.
//
#import <Foundation/Foundation.h>

#import "TCMFrontOfficeDelegate.h"

@class TCMPayment;

/// Charge service delegate.
///
@protocol TCMChargeDelegate <TCMFrontOfficeDelegate>

/// Save thincacloud deal number.
///
/// @param sender           sender object.
/// @param thincaDealNumber thincacloud deal number.
///
- (void)saveThincaDealNumber:(nonnull TCMPayment *)sender
            thincaDealNumber:(nonnull NSString *)thincaDealNumber;

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

/// Authenticate for charge terminal.
///
/// @param sender sender object.
/// @return true if authorize for charge terminal, otherwise false.
///
- (BOOL)authenticateChargeTerminal:(nonnull TCMPayment *)sender;

@end
