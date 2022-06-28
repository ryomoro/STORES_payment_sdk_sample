//
// Copyright 2016 TF PAYMENT SERVICE CO.,LTD.
// All rights reserved.
//
#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#import "TCMPaymentType.h"

@class TCMPayment;

/// Front office operation delegate.
///
@protocol TCMFrontOfficeDelegate <NSObject>

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

/// Update salesclerk amount view.
/// The amount list contains the following keys.
///
/// - TCMAmountViewTypeKey: amount view type.
/// - TCMAmountTitleKey:    amount view title.
/// - TCMAmountKey:         amount value.
///
/// @param sender     sender object.
/// @param amountList salesclerk amount list.
///
- (void)updateSalesclerkAmountView:(nonnull TCMPayment *)sender
                        amountList:(nonnull
                                    NSArray<NSDictionary<NSString *, NSObject *> *> *)amountList;

/// Show salesclerk button view.
/// The button list contains the following keys.
///
/// - TCMButtonViewTypeKey: button view type.
/// - TCMButtonTitleKey:    button view title.
/// - TCMButtonIDKey:       button ID.
///
/// @param sender     sender object.
/// @param buttonList salesclerk button list.
///
- (void)showSalesclerkButtonView:(nonnull TCMPayment *)sender
                      buttonList:(nonnull
                                  NSArray<NSDictionary<NSString *, NSObject *> *> *)buttonList;

/// Hide salesclerk button view.
///
/// @param sender sender object.
///
- (void)hideSalesclerkButtonView:(nonnull TCMPayment *)sender;

/// Show customer view.
///
/// @param sender   sender object.
/// @param brand    use brand.
///
- (void)showCustomerView:(nonnull TCMPayment *)sender
                   brand:(TCMBrand)brand;

/// Hide customer view.
///
/// @param sender sender object.
///
- (void)hideCustomerView:(nonnull TCMPayment *)sender;

/// Update customer message view.
///
/// @param sender   sender object.
/// @param message  customer message.
///
- (void)updateCustomerMessageView:(nonnull TCMPayment *)sender
                          message:(nonnull NSString *)message;

/// Update customer amount view.
/// The amount list contains the following keys.
///
/// - TCMAmountViewTypeKey: amount view type.
/// - TCMAmountTitleKey:    amount view title.
/// - TCMAmountKey:         amount value.
///
/// @param sender     sender object.
/// @param amountList customer amount list.
///
- (void)updateCustomerAmountView:(nonnull TCMPayment *)sender
                      amountList:(nonnull
                                  NSArray<NSDictionary<NSString *, NSObject *> *> *)amountList;

/// Play sound.
///
/// @param sender     sender object.
/// @param soundFile  sound file.
///
- (void)playSound:(nonnull TCMPayment *)sender
        soundFile:(nonnull NSString *)soundFile;

/// Stop sound.
///
/// @param sender sender object.
///
- (void)stopSound:(nonnull TCMPayment *)sender;

/// Result action.
///
/// @param sender           sender object.
/// @param errorCode        error code.
/// @param warningMessage   warning message.
/// @param thincaDealNumber thincacloud deal number.
/// @param cardInfo         card information.
/// @param receipts         receipt list.
/// @param optionInfo       optional information.
///
- (void)resultAction:(nonnull TCMPayment *)sender
           errorCode:(TCMPaymentError)errorCode
      warningMessage:(nullable NSString *)warningMessage
    thincaDealNumber:(nullable NSString *)thincaDealNumber
            cardInfo:(nullable NSDictionary<NSString *, NSObject *> *)cardInfo
            receipts:(nullable NSArray<NSDictionary<NSString *, NSObject *> *> *)receipts
          optionInfo:(nonnull NSDictionary<NSString *, NSObject *> *)optionInfo;

@optional

/// Enable cancel.
///
/// @param sender sender object.
///
- (void)enableCancel:(nonnull TCMPayment *)sender;

/// Disable cancel.
///
/// @param sender sender object.
///
- (void)disableCancel:(nonnull TCMPayment *)sender;

/// Show progress view.
///
/// @param sender sender object.
///
- (void)showProgressView:(nonnull TCMPayment *)sender;

/// Hide progress view.
///
/// @param sender sender object.
///
- (void)hideProgressView:(nonnull TCMPayment *)sender;

/// Update LED color.
///
/// @param sender   sender object.
/// @param ledColor LED color.
///
- (void)updateLEDColor:(nonnull TCMPayment *)sender
              ledColor:(nonnull UIColor *)ledColor;

/// Pre result action.
///
/// @param sender           sender object.
/// @param errorCode        error code.
/// @param warningMessage   warning message.
/// @param thincaDealNumber thincacloud deal number.
/// @param cardInfo         card information.
/// @param receipts         receipt list.
/// @param optionInfo       optional information.
///
- (void)preResultAction:(nonnull TCMPayment *)sender
              errorCode:(TCMPaymentError)errorCode
         warningMessage:(nullable NSString *)warningMessage
       thincaDealNumber:(nullable NSString *)thincaDealNumber
               cardInfo:(nullable NSDictionary<NSString *, NSObject *> *)cardInfo
               receipts:(nullable NSArray<NSDictionary<NSString *, NSObject *> *> *)receipts
             optionInfo:(nonnull NSDictionary<NSString *, NSObject *> *)optionInfo;

@end
