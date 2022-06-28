//
// Copyright 2016 TF PAYMENT SERVICE CO.,LTD.
// All rights reserved.
//
#import <Foundation/Foundation.h>

#import "TCMPaymentType.h"

@class TCMPayment;

/// Back office operation delegate.
///
@protocol TCMBackOfficeDelegate <NSObject>

/// Show salesclerk view.
///
/// @param sender sender object.
///
- (void)showSalesclerkView:(nonnull TCMPayment *)sender;

/// Hide salesclerk view.
///
/// @param sender sender object.
///
- (void)hideSalesclerkView:(nonnull TCMPayment *)sender;

/// Update salesclerk message view.
///
/// @param sender   sender object.
/// @param message  salesclerk message.
///
- (void)updateSalesclerkMessageView:(nonnull TCMPayment *)sender
                            message:(nonnull NSString *)message;

/// Result action.
///
/// @param sender     sender object.
/// @param errorCode  error code.
/// @param receipts   receipt list.
/// @param optionInfo optional information.
///
- (void)resultAction:(nonnull TCMPayment *)sender
           errorCode:(TCMPaymentError)errorCode
            receipts:(nullable NSArray<NSDictionary<NSString *, NSObject *> *> *)receipts
          optionInfo:(nonnull NSDictionary<NSString *, NSObject *> *)optionInfo;

@end
