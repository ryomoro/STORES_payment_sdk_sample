//
// Copyright 2016 TF PAYMENT SERVICE CO.,LTD.
// All rights reserved.
//
#import <Foundation/Foundation.h>

/// Currency value type.
typedef NSDecimalNumber TCMCurrency;

/// Currency value type for Swift.
typedef TCMCurrency * TCMCurrencyValue;

/// Payment module error type.
///
typedef NS_ENUM(NSInteger, TCMPaymentError) {
    /// No error.
    TCMPaymentErrorNo                           = 0,

    /// Cancel.
    TCMPaymentErrorCancel                       = 101,

    /// Invalid argument.
    TCMPaymentErrorInvalidArgument              = 201,
    /// Busy.
    TCMPaymentErrorBusy                         = 202,
    /// Network error.
    TCMPaymentErrorNetwork                      = 203,
    /// Network timeout.
    TCMPaymentErrorNetworkTimeout               = 204,
    /// Reader/writer error.
    TCMPaymentErrorRW                           = 205,
    /// Illegal state.
    TCMPaymentErrorIllegalState                 = 206,
    /// File I/O error.
    TCMPaymentErrorFileIO                       = 251,

    /// Invalid terminal.
    TCMPaymentErrorInvalidTerminal              = 301,
    /// Invalid merchant.
    TCMPaymentErrorInvalidMerchant              = 302,
    /// Invalid request.
    TCMPaymentErrorInvalidRequest               = 303,
    /// Invalid service.
    TCMPaymentErrorInvalidService               = 304,
    /// Service has failed.
    TCMPaymentErrorServiceHasFailed             = 305,
    /// Log full error.
    TCMPaymentErrorLogFull                      = 309,
    /// Failed deal.
    TCMPaymentErrorFailedDeal                   = 310,
    /// Before terminal use start date.
    TCMPaymentErrorBeforeTerminalUseStartDate   = 311,
    /// After terminal use end date.
    TCMPaymentErrorAfterTerminalUseEndDate      = 312,

    /// Insufficient balance.
    TCMPaymentErrorInsufficientBalance          = 401,
    /// Discover multiple cards.
    TCMPaymentErrorDiscoverMultipleCards        = 402,
    /// Unknown card.
    TCMPaymentErrorUnknownCard                  = 403,
    /// Card timeout.
    TCMPaymentErrorCardTimeout                  = 404,
    /// Card command error.
    TCMPaymentErrorCardCommand                  = 405,
    /// Over the payment limit.
    TCMPaymentErrorOverPaymentLimit             = 406,
    /// Over the possession limit.
    TCMPaymentErrorOverPossessionLimit          = 407,
    /// Over the charge limit.
    TCMPaymentErrorOverChargeLimit              = 408,
    /// Not transactable card status.
    TCMPaymentErrorNotTransactableCardStatus    = 409,
    /// Card authorization has failed.
    TCMPaymentErrorCardAuthorizationHasFailed   = 412,
    /// Different card.
    TCMPaymentErrorDifferentCard                = 413,
    /// Void has failed.
    TCMPaymentErrorVoidHasFailed                = 414,
    /// Insufficient point balance.
    TCMPaymentErrorInsufficientPointBalance     = 415,
    /// Point unavailable card.
    TCMPaymentErrorPointUnavailableCard         = 416,

    /// Invalid card.
    TCMPaymentErrorInvalidCard                  = 502,
    /// Negative card.
    TCMPaymentErrorNegativeCard                 = 503,
    /// Expired card.
    TCMPaymentErrorExpiredCard                  = 504,
    /// Mobile PIN lock.
    TCMPaymentErrorMobilePINLock                = 505,

    /// Card withdrawal.
    TCMPaymentErrorCardWithdrawal               = 700,

    /// Unconfirmed status.
    TCMPaymentErrorUnconfirmedStatus            = 801,
    /// Transaction unconfirmed status.
    TCMPaymentErrorTransactionUnconfirmedStatus = 803,

    /// Fatal error.
    TCMPaymentErrorFatal                        = 900,
    /// Session timeout.
    TCMPaymentErrorSessionTimeout               = 901,
    /// ICAS server error.
    TCMPaymentErrorTCAPClient                   = 902,
    /// Brand center error.
    TCMPaymentErrorBrandCenter                  = 903
};

/// Brand type.
///
typedef NS_ENUM(NSInteger, TCMBrand) {
    /// nanaco.
    TCMBrandNanaco    = 1,
    /// Edy.
    TCMBrandEdy       = 2,
    /// iD.
    TCMBrandId        = 3,
    /// QUICPay.
    TCMBrandQuicpay   = 4,
    /// Transportation IC.
    TCMBrandTransport = 5,
    /// WAON.
    TCMBrandWaon      = 6,
    /// nanaco 2.
    TCMBrandNanaco2   = 7,
    /// PASELI.
    TCMBrandPaseli    = 8,
    /// SAPICA.
    TCMBrandSapica    = 9,

    /// Apple Pay.
    TCMBrandApplePay  = 9997,

    /// Brand select.
    TCMBrandSelect    = -1
};

/// Totalize type.
///
typedef NS_ENUM(NSInteger, TCMTotalizeType) {
    /// Intermediate total.
    TCMTotalizeTypeIntermediate = 1
};

/// Charge type.
///
typedef NS_ENUM(NSInteger, TCMChargeType) {
    /// Cash.
    TCMChargeTypeCash     = 1,
    /// Account.
    TCMChargeTypeAccount  = 2,
    /// Credit.
    TCMChargeTypeCredit   = 4
};

/// Amount view type.
///
typedef NS_ENUM(NSInteger, TCMAmountViewType) {
    /// Payment amount.
    TCMAmountViewTypePayment      = 1,
    /// Charge amount.
    TCMAmountViewTypeCharge       = 2,
    /// Balance amount.
    TCMAmountViewTypeBalance      = 3,
    /// Void payment amount.
    TCMAmountViewTypeVoidPayment  = 4,
    /// Void charge amount.
    TCMAmountViewTypeVoidCharge   = 5,
    /// Auto charge amount.
    TCMAmountViewTypeAutoCharge   = 7
};

/// Button view type.
///
typedef NS_ENUM(NSInteger, TCMButtonViewType) {
    /// Retry button.
    TCMButtonViewTypeRetry          = 1,
    /// Payment check button.
    TCMButtonViewTypePaymentCheck   = 2,
    /// Charge check button.
    TCMButtonViewTypeChargeCheck    = 3,
    /// Void check button.
    TCMButtonViewTypeVoidCheck      = 4,
    /// Confirmed button.
    TCMButtonViewTypeConfirmed      = 5,
    /// Cancel button.
    TCMButtonViewTypeCancel         = 90,
    /// Balance inquiry button.
    TCMButtonViewTypeBalanceInquiry = 91
};

/// PIN encrypt type.
///
typedef NS_ENUM(NSInteger, TCMPINEncryptType) {
    /// No encryption.
    TCMPINEncryptTypeNo         = 1,
    /// Triple DES encrypt.
    TCMPINEncryptTypeTripleDES  = 3,
    /// AES encrypt.
    TCMPINEncryptTypeAES        = 4
};

/// PIN block cipher mode.
///
typedef NS_ENUM(NSInteger, TCMPINCipherMode) {
    /// No cipher.
    TCMPINCipherModeNo    = 0,
    /// ECB.
    TCMPINCipherModeECB   = 1
};

/// PIN padding mode.
///
typedef NS_ENUM(NSInteger, TCMPINPaddingMode) {
    /// No padding.
    TCMPINPaddingModeNo       = 0,
    /// Space key padding.
    TCMPINPaddingModeSpace    = 1,
    /// PKCS#7 padding.
    TCMPINPaddingModePKCS7    = 2
};

/// Receipt type.
///
typedef NS_ENUM(NSInteger, TCMReceiptType) {
    /// Network outage receipt.
    TCMReceiptTypeNetworkOutage                 = 1,

    /// Edy center communication result receipt.
    TCMReceiptTypeEdyCenterCommunicationResult  = 10,
    /// Intermediate totalize sales receipt.
    TCMReceiptTypeIntermediateTotalizeSales     = 11,

    /// Payment receipt.
    TCMReceiptTypePayment                       = 20,
    /// Payment alarm receipt.
    TCMReceiptTypePaymentAlarm                  = 21,

    /// Charge receipt.
    TCMReceiptTypeCharge                        = 30,
    /// Charge alarm receipt.
    TCMReceiptTypeChargeAlarm                   = 31,
    /// Point charge receipt.
    TCMReceiptTypePointCharge                   = 32,
    /// Point charge alarm receipt.
    TCMReceiptTypePointChargeAlarm              = 33,

    /// Void payment receipt.
    TCMReceiptTypeVoidPayment                   = 40,
    /// Void payment alarm receipt.
    TCMReceiptTypeVoidPaymentAlarm              = 41,
    /// Refund receipt.
    TCMReceiptTypeRefund                        = 42,
    /// Refund alarm receipt.
    TCMReceiptTypeRefundAlarm                   = 43,

    /// Void charge receipt.
    TCMReceiptTypeVoidCharge                    = 50,
    /// Void charge alarm receipt.
    TCMReceiptTypeVoidChargeAlarm               = 51,

    /// Balance inquiry receipt.
    TCMReceiptTypeBalanceInquiry                = 60,
    /// Card history receipt.
    TCMReceiptTypeCardHistory                   = 61
};

/// Receipt destination.
///
typedef NS_ENUM(NSInteger, TCMReceiptDestination) {
    /// Destination is customer.
    TCMReceiptDestinationCustomer           = 1,
    /// Destination is store.
    TCMReceiptDestinationStore              = 2,
    /// Destination is tenant.
    TCMReceiptDestinationTenant             = 3,
    /// Destination is credit card company.
    TCMReceiptDestinationCreditCardCompany  = 4
};

/// Point type.
///
typedef NS_ENUM(NSInteger, TCMPointType) {
    /// SAPICA point.
    TCMPointTypeSapica        = 91,
    /// SAPICA E-money point.
    TCMPointTypeSapicaEMoney  = 92,
};

/// Card history type.
///
typedef NS_ENUM(NSInteger, TCMCardHistoryType) {
    /// History is invalid.
    TCMCardHistoryTypeInvalid         = 0,
    /// History is payment.
    TCMCardHistoryTypePayment         = 10,
    /// History is charge.
    TCMCardHistoryTypeCharge          = 20,
    /// History is recovery charge.
    TCMCardHistoryTypeRecoveryCharge  = 21,
    /// History is gift charge.
    TCMCardHistoryTypeGiftCharge      = 22,
    /// History is void payment.
    TCMCardHistoryTypeVoidPayment     = 30,
    /// History is void charge.
    TCMCardHistoryTypeVoidCharge      = 40,
    /// History is closing
    TCMCardHistoryTypeClosing         = 50,
    /// History is illegal.
    TCMCardHistoryTypeIllegal         = 51,
    /// History is unknown.
    TCMCardHistoryTypeUnknown         = 90
};

NS_ASSUME_NONNULL_BEGIN

/// Unspecified thincacloud deal number for iD.
FOUNDATION_EXPORT NSString *const TCMUnspecifiedThincaDealNumberForId;

/// Amount view type key.
/// value is NSNumber(TCMAmountViewType) object.
FOUNDATION_EXPORT NSString *const TCMAmountViewTypeKey;
/// Amount title key.
/// value is NSString object.
FOUNDATION_EXPORT NSString *const TCMAmountTitleKey;
/// Amount key.
/// value is TCMCurrency object.
FOUNDATION_EXPORT NSString *const TCMAmountKey;

/// Button view type key.
/// value is NSNumber(TCMButtonViewType) object.
FOUNDATION_EXPORT NSString *const TCMButtonViewTypeKey;
/// Button title key.
/// value is NSString object.
FOUNDATION_EXPORT NSString *const TCMButtonTitleKey;
/// Button ID key.
/// value is NSNumber(NSInteger) object.
FOUNDATION_EXPORT NSString *const TCMButtonIDKey;

/// Excluded point amount key.
/// value is TCMCurrency object.
FOUNDATION_EXPORT NSString *const TCMExcludedPointAmountKey;
/// Add point key.
/// value is TCMCurrency object.
FOUNDATION_EXPORT NSString *const TCMAddPointKey;
/// Point rate powerd key.
/// value is NSNumber(NSInteger) object.
FOUNDATION_EXPORT NSString *const TCMPointRatePowerdKey;

/// Receipt type key.
/// value is NSNumber(NSInteger) object.
FOUNDATION_EXPORT NSString *const TCMReceiptTypeKey;
/// Receipt destination key.
/// value is NSNumber(NSInteger) object.
FOUNDATION_EXPORT NSString *const TCMReceiptDestinationKey;
/// Brand key.
/// value is NSNumber(NSInteger) object.
FOUNDATION_EXPORT NSString *const TCMBrandKey;
/// Is training key.
/// value is NSNumber(BOOL) object.
FOUNDATION_EXPORT NSString *const TCMIsTrainingKey;
/// Processing date key.
/// value is NSDate object.
FOUNDATION_EXPORT NSString *const TCMProcessingDateKey;
/// Terminal sequence number key.
/// value is NSNumber(NSInteger) object.
FOUNDATION_EXPORT NSString *const TCMTerminalSequenceNumberKey;
/// Thincacloud deal number key.
/// value is NSString object.
FOUNDATION_EXPORT NSString *const TCMThincaDealNumberKey;
/// Card number key.
/// value is NSString object.
FOUNDATION_EXPORT NSString *const TCMCardNumberKey;
/// Balance key.
/// value is TCMCurrency object.
FOUNDATION_EXPORT NSString *const TCMBalanceKey;
/// Before balance key.
/// value is TCMCurrency object.
FOUNDATION_EXPORT NSString *const TCMBeforeBalanceKey;
/// After balance key.
/// value is TCMCurrency object.
FOUNDATION_EXPORT NSString *const TCMAfterBalanceKey;
/// Upper terminal ID key.
/// value is NSString object.
FOUNDATION_EXPORT NSString *const TCMUpperTerminalIDKey;
/// Auto charge amount key.
/// value is TCMCurrency object.
FOUNDATION_EXPORT NSString *const TCMAutoChargeAmountKey;
/// Auto charge has failed key.
/// value is NSNumber(BOOL) object.
FOUNDATION_EXPORT NSString *const TCMAutoChargeHasFailedKey;
/// Had done Auto charge key.
/// value is NSNumber(BOOL) object.
FOUNDATION_EXPORT NSString *const TCMHadDoneAutoChargeKey;
/// Just charge amount key.
/// value is TCMCurrency object.
FOUNDATION_EXPORT NSString *const TCMJustChargeAmountKey;
/// Point type key.
/// value is NSNumber(TCMPointType) object.
FOUNDATION_EXPORT NSString *const TCMPointTypeKey;
/// Point key.
/// value is TCMCurrency object.
FOUNDATION_EXPORT NSString *const TCMPointKey;
/// Point details key.
/// value is NSArray object.
FOUNDATION_EXPORT NSString *const TCMPointDetailsKey;
/// Cumulative point key.
/// value is TCMCurrency object.
FOUNDATION_EXPORT NSString *const TCMCumulativePointKey;
/// Display cumulative point key.
/// value is TCMCurrency object.
FOUNDATION_EXPORT NSString *const TCMDisplayCumulativePointKey;
/// Cumulative point details key.
/// value is NSArray object.
FOUNDATION_EXPORT NSString *const TCMCumulativePointDetailsKey;
/// Item title key.
/// value is NSString object.
FOUNDATION_EXPORT NSString *const TCMItemTitleKey;
/// Item point key.
/// value is TCMCurrency object.
FOUNDATION_EXPORT NSString *const TCMItemPointKey;
/// Point message key.
/// value is NSString object.
FOUNDATION_EXPORT NSString *const TCMPointMessageKey;
/// Edy deal number key.
/// value is NSString object.
FOUNDATION_EXPORT NSString *const TCMEdyDealNumberKey;
/// Card deal number key.
/// value is NSString object.
FOUNDATION_EXPORT NSString *const TCMCardDealNumberKey;
/// Paseli deal number key.
/// value is NSString object.
FOUNDATION_EXPORT NSString *const TCMPaseliDealNumberKey;
/// Deal detail ID key.
/// value is NSString object.
FOUNDATION_EXPORT NSString *const TCMDealDetailIdKey;
/// Deal type code key.
/// value is NSNumber(NSInteger) object.
FOUNDATION_EXPORT NSString *const TCMDealTypeCodeKey;
/// Deal type name key.
/// value is NSString object.
FOUNDATION_EXPORT NSString *const TCMDealTypeNameKey;
/// Approval code key.
/// value is NSString object.
FOUNDATION_EXPORT NSString *const TCMApprovalCodeKey;
/// Goods code key.
/// value is NSString object.
FOUNDATION_EXPORT NSString *const TCMGoodsCodeKey;
/// Expiry date view key.
/// value is NSString object.
FOUNDATION_EXPORT NSString *const TCMExpiryDateViewKey;
/// Credit card company name.
/// value is NSString object.
FOUNDATION_EXPORT NSString *const TCMCreditCardCompanyNameKey;
/// Card histories key.
/// value is NSArray object.
FOUNDATION_EXPORT NSString *const TCMCardHistoriesKey;
/// Card history type key.
/// value is NSNumber(NSInteger) object.
FOUNDATION_EXPORT NSString *const TCMCardHistoryTypeKey;
/// Card history type code key.
/// value is NSNumber(NSInteger) object.
FOUNDATION_EXPORT NSString *const TCMCardHistoryTypeCodeKey;
/// Card history type name key.
/// value is NSString object.
FOUNDATION_EXPORT NSString *const TCMCardHistoryTypeNameKey;
/// Card history date view key.
/// value is NSString object.
FOUNDATION_EXPORT NSString *const TCMCardHistoryDateViewKey;
/// Card history sequence number key.
/// value is NSString object.
FOUNDATION_EXPORT NSString *const TCMCardHistorySequenceNumberKey;
/// Payment amount key.
/// value is TCMCurrency object.
FOUNDATION_EXPORT NSString *const TCMPaymentAmountKey;
/// Charge amount key.
/// value is TCMCurrency object.
FOUNDATION_EXPORT NSString *const TCMChargeAmountKey;
/// Edy center communication result key.
/// value is NSNumber(BOOL) object.
FOUNDATION_EXPORT NSString *const TCMEdyCenterCommunicationResultKey;
/// Total payment count key.
/// value is NSNumber(NSInteger) object.
FOUNDATION_EXPORT NSString *const TCMTotalPaymentCountKey;
/// Total payment amount key.
/// value is TCMCurrency object.
FOUNDATION_EXPORT NSString *const TCMTotalPaymentAmountKey;
/// Total payment alarm count key.
/// value is NSNumber(NSInteger) object.
FOUNDATION_EXPORT NSString *const TCMTotalPaymentAlarmCountKey;
/// Total payment alarm amount key.
/// value is TCMCurrency object.
FOUNDATION_EXPORT NSString *const TCMTotalPaymentAlarmAmountKey;
/// Total charge count key.
/// value is NSNumber(NSInteger) object.
FOUNDATION_EXPORT NSString *const TCMTotalChargeCountKey;
/// Total charge amount key.
/// value is TCMCurrency object.
FOUNDATION_EXPORT NSString *const TCMTotalChargeAmountKey;
/// Total charge alarm count key.
/// value is NSNumber(NSInteger) object.
FOUNDATION_EXPORT NSString *const TCMTotalChargeAlarmCountKey;
/// Total charge alarm amount key.
/// value is TCMCurrency object.
FOUNDATION_EXPORT NSString *const TCMTotalChargeAlarmAmountKey;
/// Begin terminal sequence number key.
/// value is NSNumber(NSInteger) object.
FOUNDATION_EXPORT NSString *const TCMBeginTerminalSequenceNumberKey;
/// End terminal sequence number key.
/// value is NSNumber(NSInteger) object.
FOUNDATION_EXPORT NSString *const TCMEndTerminalSequenceNumberKey;
/// Last deal date key.
/// value is NSDate object.
FOUNDATION_EXPORT NSString *const TCMLastDealDateKey;
/// Total refund count key.
/// value is NSNumber(NSInteger) object.
FOUNDATION_EXPORT NSString *const TCMTotalRefundCountKey;
/// Total refund amount key.
/// value is TCMCurrency object.
FOUNDATION_EXPORT NSString *const TCMTotalRefundAmountKey;
/// Totals by credit card company unit.
/// value is NSArray object.
FOUNDATION_EXPORT NSString *const TCMTotalsByCreditCardCompanyKey;

/// Selector name key.
/// value is NSString object.
FOUNDATION_EXPORT NSString *const TCMSelectorNameKey;
/// Result code key.
/// value is NSNumber(NSInteger) object.
FOUNDATION_EXPORT NSString *const TCMResultCodeKey;
/// Result code extended key.
/// value is NSNumber(NSInteger) object.
FOUNDATION_EXPORT NSString *const TCMResultCodeExtendedKey;
/// Usable brands key.
/// value is NSArray<NSNumber(NSInteger) *> object.
FOUNDATION_EXPORT NSString *const TCMUsableBrandsKey;
/// Is usable payment the balance in full service key.
/// value is NSNumber(BOOL) object.
FOUNDATION_EXPORT NSString *const TCMIsUsablePaymentBalanceInFullKey;
/// Is usable payment just charge service key.
/// value is NSNumber(BOOL) object.
FOUNDATION_EXPORT NSString *const TCMIsUsablePaymentJustChargeKey;
/// Card processing time key.
/// value is NSNumber(NSInteger) object.
FOUNDATION_EXPORT NSString *const TCMCardProcessingTimeKey;

NS_ASSUME_NONNULL_END
