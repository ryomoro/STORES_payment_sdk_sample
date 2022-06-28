//
// Copyright 2016 TF PAYMENT SERVICE CO.,LTD.
// All rights reserved.
//
#import <Foundation/Foundation.h>

#import "TCMFrontOfficeDelegate.h"
#import "TCMPaymentType.h"

@class TCMPayment;

/// Payment service delegate.
///
@protocol TCMPaymentDelegate <TCMFrontOfficeDelegate>

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

/// Recalculate payment.
///
/// @param sender               sender object.
/// @param amount               amount of payment.
/// @param excludedPointAmount  amount of excluded point payment.
/// @param addPoint             additional point.
/// @param pointRatePowerd      point rate powerd.
/// @param cardIssuerID         card issuer ID.
/// @param valueIssuerID        value issuer ID.
/// @param point1IssuerID       point1 issuer ID.
/// @param point2IssuerID       point2 issuer ID.
/// @param point3IssuerID       point3 issuer ID.
/// @return recalculate values.
///
- (nullable NSDictionary<NSString *, NSNumber *> *)recalculatePayment:(nonnull TCMPayment *)sender
                 amount:(nonnull TCMCurrency *)amount
    excludedPointAmount:(nonnull TCMCurrency *)excludedPointAmount
               addPoint:(nonnull TCMCurrency *)addPoint
        pointRatePowerd:(nonnull NSNumber *)pointRatePowerd
           cardIssuerID:(NSUInteger)cardIssuerID
          valueIssuerID:(NSUInteger)valueIssuerID
         point1IssuerID:(NSUInteger)point1IssuerID
         point2IssuerID:(NSUInteger)point2IssuerID
         point3IssuerID:(NSUInteger)point3IssuerID;

@end
