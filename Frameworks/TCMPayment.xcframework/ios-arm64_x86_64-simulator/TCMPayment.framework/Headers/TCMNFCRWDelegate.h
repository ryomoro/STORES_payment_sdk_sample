//
// Copyright 2016 TF PAYMENT SERVICE CO.,LTD.
// All rights reserved.
//
#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

/// NFC target type.
///
typedef NS_OPTIONS(NSUInteger, TCMNFCType) {
  /// No type.
  TCMNFCTypeNo        = 0,
  /// ISO 14443 A.
  TCMNFCTypeISO14443A = 1 << 0,
  /// ISO 14443 B.
  TCMNFCTypeISO14443B = 1 << 1,
  /// ISO 15693.
  TCMNFCTypeISO15693  = 1 << 2,
  /// FeliCa.
  TCMNFCTypeFelica    = 1 << 3
};

NS_ASSUME_NONNULL_BEGIN

/// NFC type key.
/// value is NSNumber(TCMNFCType) object.
FOUNDATION_EXPORT NSString *const TCMNFCTypeKey;
/// NFC ID key.
/// value is NSData object.
FOUNDATION_EXPORT NSString *const TCMNFCIDKey;
/// NFC additional data key.
/// value is NSData object.
FOUNDATION_EXPORT NSString *const TCMNFCAdditionalDataKey;
/// Is detect multi target key.
/// value is NSNumber(BOOL) object.
FOUNDATION_EXPORT NSString *const TCMNFCIsDetectMultiTargetKey;

NS_ASSUME_NONNULL_END

@class TCMPayment;

/// NFC R/W delegate.
///
@protocol TCMNFCRWDelegate <NSObject>

/// Claim device.
///
/// @param sender sender object.
/// @return true if successful, otherwise false.
///
- (BOOL)claimDevice:(nonnull TCMPayment *)sender;

/// Release device.
///
/// @param sender sender object.
/// @return true if successful, otherwise false.
///
- (BOOL)releaseDevice:(nonnull TCMPayment *)sender;

/// Open FeliCa.
///
/// @param sender sender object.
/// @return true if successful, otherwise false.
///
- (BOOL)openFelica:(nonnull TCMPayment *)sender;

/// Close FeliCa.
///
/// @param sender sender object.
/// @return true if successful, otherwise false.
///
- (BOOL)closeFelica:(nonnull TCMPayment *)sender;

/// Execute FeliCa command.
///
/// @param sender     sender object.
/// @param timeout    felica command timeout.
/// @param retryCount felica command retry count.
/// @param command    felica command data.
/// @return felica response data if target responed, otherwise nil.
///
- (nullable NSData *)executeFelica:(nonnull TCMPayment *)sender
                           timeout:(NSInteger)timeout
                        retryCount:(NSInteger)retryCount
                           command:(nonnull NSData *)command;

/// Cancel execute.
///
/// @param sender sender object.
///
- (void)cancel:(nonnull TCMPayment *)sender;

/// Reset cancel state.
///
/// @param sender sender object.
///
- (void)resetCancel:(nonnull TCMPayment *)sender;

@optional

/// Open NFC.
///
/// @param sender   sender object.
/// @param nfcType  NFC type flag.
/// @return true if successful, otherwise false.
///
- (BOOL)openNFC:(nonnull TCMPayment *)sender
        nfcType:(TCMNFCType)nfcType;

/// Close NFC.
///
/// @param sender sender object.
/// @return true if successful, otherwise false.
///
- (BOOL)closeNFC:(nonnull TCMPayment *)sender;

/// Detect NFC target.
///
/// @param sender   sender object.
/// @param timeout  detect timeout.
/// @return NFC target information if detect NFC target, otherwise nil.
///
- (nullable NSDictionary *)detectNFC:(nonnull TCMPayment *)sender
                             timeout:(NSInteger)timeout;

/// Execute APDU command.
///
/// @param sender       sender object.
/// @param commandAPDU  command APDU data.
/// @return response APDU data if target responed, otherwise nil.
///
- (nullable NSData *)executeAPDU:(nonnull TCMPayment *)sender
                     commandAPDU:(nonnull NSData *)commandAPDU;

/// Execute NFC-F command.
///
/// @param sender     sender object.
/// @param timeout    felica command timeout.
/// @param retryCount felica command retry count.
/// @param command    felica command data.
/// @return felica response data if target responed, otherwise nil.
///
- (nullable NSData *)executeNFCF:(nonnull TCMPayment *)sender
                         timeout:(NSInteger)timeout
                      retryCount:(NSInteger)retryCount
                         command:(nonnull NSData *)command;

/// Turn on LED.
///
/// @param sender   sender object.
/// @param ledColor LED color.
/// @param timeout  timeout time for LED on, or nil.
///
- (void)turnOnLED:(nonnull TCMPayment *)sender
         ledColor:(nonnull UIColor *)ledColor
          timeout:(nullable NSNumber *)timeout;

/// Turn on LED blink.
///
/// @param sender         sender object.
/// @param ledColor       LED color.
/// @param ledOnInterval  interval time for LED on.
/// @param ledOffInterval interval time for LED off.
/// @param timeout        timeout time for LED blink, or nil.
///
- (void)turnOnLEDBlink:(nonnull TCMPayment *)sender
              ledColor:(nonnull UIColor *)ledColor
         ledOnInterval:(NSInteger)ledOnInterval
        ledOffInterval:(NSInteger)ledOffInterval
               timeout:(nullable NSNumber *)timeout;

/// Turn off LED.
///
/// @param sender sender object.
///
- (void)turnOffLED:(nonnull TCMPayment *)sender;

/// Raw LED.
///
/// @param sender     sender object.
/// @param ledColor   LED color.
/// @param actionType LED action type.
/// @param sendData   send data.
///
- (void)rawLED:(nonnull TCMPayment *)sender
      ledColor:(nonnull UIColor *)ledColor
    actionType:(NSInteger)actionType
      sendData:(nullable NSData *)sendData;

@end
