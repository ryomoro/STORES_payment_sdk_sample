//
// STORESPaymentsSDK
// Copyright © Coiney Inc. All rights reserved.
// For licensing information, contact info@coiney.com.
//

#import <UIKit/UIKit.h>

@interface NSString (CoineyKitAdditions)

- (NSString *)cy_multiply:(NSUInteger)aTimes;

// Similar to -length, except full width characters are counted twice
- (NSUInteger)cy_width;

/// This API is going to been deprecated. Consider using a alignWithSpace(within:,shouldTruncateIfLonger:,alignment:)
- (NSString *)cy_stringByPaddingToWidth:(NSUInteger)aLength
                       truncateIfLonger:(BOOL)aTruncate
                              alignment:(NSTextAlignment)aAlignment;
/// This API is going to been deprecated. Consider using a alignWithSpace(within:,shouldTruncateIfLonger:,alignment:)
- (NSString *)cy_stringByPaddingToWidth:(NSUInteger)aLength
                              lineWidth:(NSUInteger)aLineWidth
                       truncateIfLonger:(BOOL)aTruncate
                              alignment:(NSTextAlignment)aAlignment;
                        

// "Blits" two strings already padded to the same length (Blit = BLock Image Transfer)
// aString overwrites characters in self
- (NSString *)cy_stringByBlittingWithString:(NSString *)aString;

- (NSData *)cy_dataUsingEncoding:(NSStringEncoding)aEncoding allowLossyConversion:(BOOL)aLossy;
@end

@interface NSMutableString (CoineyKitAdditions)
- (void)cy_deleteCharactersInWidthRange:(NSRange)aRange;
@end

BOOL CYCharacterIsFullWidth(unichar const aChar);

static inline NSString *CYStringToAlignmentMode(NSString * const aStr)
{
    return [aStr isEqualToString:kCAAlignmentNatural]   ? kCAAlignmentNatural
            : [aStr isEqualToString:kCAAlignmentRight]     ? kCAAlignmentRight
                    : [aStr isEqualToString:kCAAlignmentCenter]    ? kCAAlignmentCenter
                            : [aStr isEqualToString:kCAAlignmentJustified] ? kCAAlignmentJustified
                                    : kCAAlignmentLeft;
}

static inline NSTextAlignment CYStringToNSTextAlignment(NSString * const aStr)
{
    return [aStr isEqualToString:kCAAlignmentNatural]   ? NSTextAlignmentNatural
            : [aStr isEqualToString:kCAAlignmentRight]     ? NSTextAlignmentRight
                    : [aStr isEqualToString:kCAAlignmentCenter]    ? NSTextAlignmentCenter
                            : [aStr isEqualToString:kCAAlignmentJustified] ? NSTextAlignmentJustified
                                    : NSTextAlignmentLeft;
}
