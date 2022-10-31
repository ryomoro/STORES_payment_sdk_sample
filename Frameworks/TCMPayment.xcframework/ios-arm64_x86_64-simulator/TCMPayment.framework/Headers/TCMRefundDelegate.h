//
// Copyright 2016 TF PAYMENT SERVICE CO.,LTD.
// All rights reserved.
//
#import <Foundation/Foundation.h>

#import "TCMFrontOfficeDelegate.h"
#import "TCMPaymentType.h"

@class TCMPayment;

/// Refund service delegate.
///
@protocol TCMRefundDelegate <TCMFrontOfficeDelegate>

/// Save thincacloud deal number.
///
/// @param sender           sender object.
/// @param thincaDealNumber thincacloud deal number.
///
- (void)saveThincaDealNumber:(nonnull TCMPayment *)sender
            thincaDealNumber:(nonnull NSString *)thincaDealNumber;

@optional

/// Require PIN.
///
/// @param sender       sender object.
/// @param encryptType  PIN encrypt type.
/// @param cipherMode   PIN cipher mode.
/// @param paddingMode  PIN padding mode.
/// @param encryptKey   PIN encrypt key.
/// @param encryptIV    PIN encrypt IV.
/// @return encrypted PIN data if PIN entered, otherwise nil.
///
- (nullable NSData *)requirePIN:(nonnull TCMPayment *)sender
                    encryptType:(TCMPINEncryptType)encryptType
                     cipherMode:(TCMPINCipherMode)cipherMode
                    paddingMode:(TCMPINPaddingMode)paddingMode
                     encryptKey:(nullable NSData *)encryptKey
                      encryptIV:(nullable NSData *)encryptIV;

@end
