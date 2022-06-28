//
// STORESPaymentsSDK
// Copyright © Coiney Inc. All rights reserved.
// For licensing information, contact info@coiney.com.
//

#import <Foundation/Foundation.h>

#define RegEx(pattern, opts) [NSRegularExpression regularExpressionWithPattern:(pattern) options:(opts) error:NULL]
@interface NSRegularExpression (CoineyKitAdditions)
- (NSString *)cy_lastMatchString:(NSString *)aStr;
@end
