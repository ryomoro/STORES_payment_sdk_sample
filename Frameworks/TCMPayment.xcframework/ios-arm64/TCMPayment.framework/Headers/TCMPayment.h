//
// Copyright 2016 TF PAYMENT SERVICE CO.,LTD.
// All rights reserved.
//
#import <Foundation/Foundation.h>

/// Project version number for TCMPayment.
FOUNDATION_EXPORT double TCMPaymentVersionNumber;

/// Project version string for TCMPayment.
FOUNDATION_EXPORT const unsigned char TCMPaymentVersionString[];

// data type
#import "TCMPaymentType.h"

// NFC R/W delegate
#import "TCMNFCRWDelegate.h"

// service delegate
#import "TCMBackOfficeDelegate.h"
#import "TCMFrontOfficeDelegate.h"
#import "TCMPaymentDelegate.h"
#import "TCMChargeDelegate.h"
#import "TCMPointChargeDelegate.h"
#import "TCMVoidPaymentDelegate.h"
#import "TCMRefundDelegate.h"
#import "TCMVoidChargeDelegate.h"
#import "TCMBalanceInquiryDelegate.h"
#import "TCMCardHistoryDelegate.h"


/// Payment module.
///
@interface TCMPayment : NSObject

/// Is service running property.
@property (nonatomic, readonly, getter=isRunning) BOOL running;

/// NFC R/W delegate property.
@property (nonatomic, weak, nullable) id<TCMNFCRWDelegate> nfcRW;

/// Terminal sequence number property.
@property (nonatomic) NSInteger terminalSequenceNumber;

/// Closing sales sequence number property.
@property (nonatomic) NSInteger closingSequenceNumber;

/// Training mode property.
@property (nonatomic, getter=isTraining) BOOL training;

/// Goods code property.
@property (nonatomic, nonnull) NSString *goodsCode;

/// Initialize with resource and client certificate.
///
/// @param resource resource file path.
/// @param file     client certificate file path.
/// @param password client certificate file password.
///
- (nullable instancetype)initWithResource:(nonnull NSString *)resource
                        clientCertificate:(nonnull NSString *)file
                                 password:(nonnull NSString *)password;

/// Start authenticate terminal service.
///
/// @param uniqueCode unique code.
/// @param passphrase pass phrase.
/// @param delegate   service delegate.
/// @param outError   output error reason.
/// @return true if authenticate terminal service started, otherwise false.
///
- (BOOL)authenticateTerminal:(nonnull NSString *)uniqueCode
                  passphrase:(nonnull NSString *)passphrase
                    delegate:(nonnull id<TCMBackOfficeDelegate>)delegate
                       error:(NSError * __nullable * __nullable)outError;

/// Start remove terminal service.
///
/// @param brand    use brand.
/// @param delegate service delegate.
/// @param outError output error reason.
/// @return true if remove terminal service started, otherwise false.
///
- (BOOL)removeTerminal:(TCMBrand)brand
              delegate:(nonnull id<TCMBackOfficeDelegate>)delegate
                 error:(NSError * __nullable * __nullable)outError;

/// Start authorize charge terminal service.
///
/// @param brand    use brand.
/// @param delegate service delegate.
/// @param outError output error reason.
/// @return true if authorize charge terminal service started, otherwise false.
///
- (BOOL)authorizeChargeTerminal:(TCMBrand)brand
                       delegate:(nonnull id<TCMBackOfficeDelegate>)delegate
                          error:(NSError * __nullable * __nullable)outError;

/// Start closing sales service.
///
/// @param brand    use brand.
/// @param delegate service delegate.
/// @param outError output error reason.
/// @return true if closing sales service started, otherwise false.
///
- (BOOL)closingSales:(TCMBrand)brand
            delegate:(nonnull id<TCMBackOfficeDelegate>)delegate
               error:(NSError * __nullable * __nullable)outError;

/// Start totalize sales service.
///
/// @param totalType  totalize type.
/// @param brand      use brand.
/// @param delegate   service delegate.
/// @param outError   output error reason.
/// @return true if totalize sales service started, otherwise false.
///
- (BOOL)totalizeSales:(TCMTotalizeType)totalType
                brand:(TCMBrand)brand
             delegate:(nonnull id<TCMBackOfficeDelegate>)delegate
                error:(NSError * __nullable * __nullable)outError;

/// Start check deal service.
///
/// @param thincaDealNumber thincacloud deal number.
/// @param delegate         service delegate.
/// @param outError         output error reason.
/// @return true if check deal service started, otherwise false.
///
- (BOOL)checkDeal:(nonnull NSString *)thincaDealNumber
         delegate:(nonnull id<TCMBackOfficeDelegate>)delegate
            error:(NSError * __nullable * __nullable)outError;

/// Start check usable brands service.
///
/// @param serviceMethod  service method.
/// @param callback       callback block.
/// @param outError       output error reason.
/// @return true if check usable brands service started, otherwise false.
///
- (BOOL)checkUsableBrands:(nonnull SEL)serviceMethod
                 callback:(nonnull void (^)(TCMPaymentError errorCode,
                                            NSArray<NSNumber *> * __nullable brandList))callback
                    error:(NSError * __nullable * __nullable)outError;

/// Start payment service.
/// It is necessary to set nfcRW property.
///
/// @param amount   amount of payment.
/// @param brand    use brand.
/// @param delegate service delegate.
/// @param outError output error reason.
/// @return true if payment service started, otherwise false.
///
- (BOOL)payment:(nonnull TCMCurrency *)amount
          brand:(TCMBrand)brand
       delegate:(nonnull id<TCMPaymentDelegate>)delegate
          error:(NSError * __nullable * __nullable)outError;

/// Start payment and point service.
/// It is necessary to set nfcRW property.
///
/// @param amount               amount of payment.
/// @param excludedPointAmount  amount of excluded point payment.
/// @param addPoint             additional point.
/// @param pointRatePowerd      point rate powerd.
/// @param brand                use brand.
/// @param delegate             service delegate.
/// @param outError             output error reason.
/// @return true if payment and point service started, otherwise false.
///
- (BOOL)paymentAndPoint:(nonnull TCMCurrency *)amount
    excludedPointAmount:(nonnull TCMCurrency *)excludedPointAmount
               addPoint:(nonnull TCMCurrency *)addPoint
        pointRatePowerd:(nonnull NSNumber *)pointRatePowerd
                  brand:(TCMBrand)brand
               delegate:(nonnull id<TCMPaymentDelegate>)delegate
                  error:(NSError * __nullable * __nullable)outError;

/// Start payment the full balance service.
/// It is necessary to set nfcRW property.
///
/// @param amount           amount of payment.
/// @param thincaDealNumber thincacloud deal number.
/// @param delegate         service delegate.
/// @param outError         output error reason.
/// @return true if payment the full balance service started, otherwise false.
///
- (BOOL)paymentFullBalance:(nonnull TCMCurrency *)amount
          thincaDealNumber:(nonnull NSString *)thincaDealNumber
                  delegate:(nonnull id<TCMPaymentDelegate>)delegate
                     error:(NSError * __nullable * __nullable)outError;

/// Start payment specified card service.
/// It is necessary to set nfcRW property.
///
/// @param amount     amount of payment.
/// @param brand      use brand.
/// @param cardNumber card number.
/// @param delegate   service delegate.
/// @param outError   output error reason.
/// @return true if payment specified card service started, otherwise false.
///
- (BOOL)paymentSpecifiedCard:(nonnull TCMCurrency *)amount
                       brand:(TCMBrand)brand
                  cardNumber:(nonnull NSString *)cardNumber
                    delegate:(nonnull id<TCMPaymentDelegate>)delegate
                       error:(NSError * __nullable * __nullable)outError;

/// Start payment specified card and point service.
/// It is necessary to set nfcRW property.
///
/// @param amount               amount of payment.
/// @param excludedPointAmount  amount of excluded point payment.
/// @param addPoint             additional point.
/// @param pointRatePowerd      point rate powerd.
/// @param brand                use brand.
/// @param cardNumber           card number.
/// @param delegate             service delegate.
/// @param outError             output error reason.
/// @return true if payment specified card and point service started, otherwise false.
///
- (BOOL)paymentSpecifiedCardAndPoint:(nonnull TCMCurrency *)amount
                 excludedPointAmount:(nonnull TCMCurrency *)excludedPointAmount
                            addPoint:(nonnull TCMCurrency *)addPoint
                     pointRatePowerd:(nonnull NSNumber *)pointRatePowerd
                               brand:(TCMBrand)brand
                          cardNumber:(nonnull NSString *)cardNumber
                            delegate:(nonnull id<TCMPaymentDelegate>)delegate
                               error:(NSError * __nullable * __nullable)outError;

/// Start payment and just charge service.
/// It is necessary to set nfcRW property.
///
/// @param amount           amount of payment.
/// @param thincaDealNumber thincacloud deal number.
/// @param delegate         service delegate.
/// @param outError         output error reason.
/// @return true if payment and just charge service started, otherwise false.
///
- (BOOL)paymentJustCharge:(nonnull TCMCurrency *)amount
         thincaDealNumber:(nonnull NSString *)thincaDealNumber
                 delegate:(nonnull id<TCMPaymentDelegate>)delegate
                    error:(NSError * __nullable * __nullable)outError;

/// Start charge service.
/// It is necessary to set nfcRW property.
///
/// @param amount     amount of charge.
/// @param chargeType charge type.
/// @param brand      use brand.
/// @param delegate   service delegate.
/// @param outError   output error reason.
/// @return true if charge service started, otherwise false.
///
- (BOOL)charge:(nonnull TCMCurrency *)amount
    chargeType:(TCMChargeType)chargeType
         brand:(TCMBrand)brand
      delegate:(nonnull id<TCMChargeDelegate>)delegate
         error:(NSError * __nullable * __nullable)outError;

/// Start charge specified card service.
/// It is necessary to set nfcRW property.
///
/// @param amount     amount of charge.
/// @param chargeType charge type.
/// @param brand      use brand.
/// @param cardNumber card number.
/// @param delegate   service delegate.
/// @param outError   output error reason.
/// @return true if charge specified card service started, otherwise false.
///
- (BOOL)chargeSpecifiedCard:(nonnull TCMCurrency *)amount
                 chargeType:(TCMChargeType)chargeType
                      brand:(TCMBrand)brand
                 cardNumber:(nonnull NSString *)cardNumber
                   delegate:(nonnull id<TCMChargeDelegate>)delegate
                      error:(NSError * __nullable * __nullable)outError;

/// Start point charge service.
/// It is necessary to set nfcRW property.
///
/// @param point    point.
/// @param brand    use brand.
/// @param delegate service delegate.
/// @param outError output error reason.
/// @return true if point charge service started, otherwise false.
///
- (BOOL)pointCharge:(nonnull TCMCurrency *)point
              brand:(TCMBrand)brand
           delegate:(nonnull id<TCMPointChargeDelegate>)delegate
              error:(NSError * __nullable * __nullable)outError;

/// Start void payment service.
/// It is necessary to set nfcRW property.
///
/// @param thincaDealNumber thincacloud deal number.
/// @param delegate         service delegate.
/// @param outError         output error reason.
/// @return true if void payment service started, otherwise false.
///
- (BOOL)voidPayment:(nonnull NSString *)thincaDealNumber
           delegate:(nonnull id<TCMVoidPaymentDelegate>)delegate
              error:(NSError * __nullable * __nullable)outError;

/// Start refund service.
/// It is necessary to set nfcRW property.
///
/// @param thincaDealNumber thincacloud deal number.
/// @param amount           amount of refund.
/// @param delegate         service delegate.
/// @param outError         output error reason.
/// @return true if refund service started, otherwise false.
///
- (BOOL)refund:(nonnull NSString *)thincaDealNumber
        amount:(nonnull TCMCurrency *)amount
      delegate:(nonnull id<TCMRefundDelegate>)delegate
         error:(NSError * __nullable * __nullable)outError;

/// Start refund without card service.
/// It is necessary to set nfcRW property.
///
/// @param thincaDealNumber thincacloud deal number.
/// @param amount           amount of refund.
/// @param delegate         service delegate.
/// @param outError         output error reason.
/// @return true if refund without card service started, otherwise false.
///
- (BOOL)refundWithoutCard:(nonnull NSString *)thincaDealNumber
                   amount:(nonnull TCMCurrency *)amount
                 delegate:(nonnull id<TCMRefundDelegate>)delegate
                    error:(NSError * __nullable * __nullable)outError;

/// Start void charge service.
/// It is necessary to set nfcRW property.
///
/// @param thincaDealNumber thincacloud deal number.
/// @param delegate         service delegate.
/// @param outError         output error reason.
/// @return true if void charge service started, otherwise false.
///
- (BOOL)voidCharge:(nonnull NSString *)thincaDealNumber
          delegate:(nonnull id<TCMVoidChargeDelegate>)delegate
             error:(NSError * __nullable * __nullable)outError;

/// Start balance inquiry service.
/// It is necessary to set nfcRW property.
///
/// @param brand    use brand.
/// @param delegate service delegate.
/// @param outError output error reason.
/// @return true if balance inquiry service started, otherwise false.
///
- (BOOL)balanceInquiry:(TCMBrand)brand
              delegate:(nonnull id<TCMBalanceInquiryDelegate>)delegate
                 error:(NSError * __nullable * __nullable)outError;

/// Start balance inquiry include card number service.
/// It is necessary to set nfcRW property.
///
/// @param brand    use brand.
/// @param delegate service delegate.
/// @param outError output error reason.
/// @return true if balance inquiry include card number service started, otherwise false.
///
- (BOOL)balanceInquiryIncludeCardNumber:(TCMBrand)brand
                               delegate:(nonnull id<TCMBalanceInquiryDelegate>)delegate
                                  error:(NSError * __nullable * __nullable)outError;

/// Start card history service.
/// It is necessary to set nfcRW property.
///
/// @param brand    use brand.
/// @param delegate service delegate.
/// @param outError output error reason.
/// @return true if card history service started, otherwise false.
///
- (BOOL)cardHistory:(TCMBrand)brand
           delegate:(nonnull id<TCMCardHistoryDelegate>)delegate
              error:(NSError * __nullable * __nullable)outError;

/// Select brand.
///
/// @param brand    use brand.
/// @param outError output error reason.
/// @return true if successful, otherwise false.
///
- (BOOL)selectBrand:(TCMBrand)brand
              error:(NSError * __nullable * __nullable)outError;

/// Cancel brand.
///
/// @param outError output error reason.
/// @return true if successful, otherwise false.
///
- (BOOL)cancelBrand:(NSError * __nullable * __nullable)outError;

/// Service cancel request.
///
/// @return true if successful, otherwise false.
///
- (BOOL)cancelRequest;

/// Select button.
///
/// @param buttonID button ID.
/// @param outError output error reason.
/// @return true if successful, otherwise false.
///
- (BOOL)selectButton:(NSInteger)buttonID
               error:(NSError * __nullable * __nullable)outError;

/// Get brand name.
///
/// @param brand  brand.
/// @return brand name if valid brand, otherwise nil.
///
- (nullable NSString *)getBrandName:(TCMBrand)brand;

/// Get brand icon file.
///
/// @param brand  brand.
/// @return brand icon file if valid brand, otherwise nil.
///
- (nullable NSString *)getBrandIcon:(TCMBrand)brand;

@end
