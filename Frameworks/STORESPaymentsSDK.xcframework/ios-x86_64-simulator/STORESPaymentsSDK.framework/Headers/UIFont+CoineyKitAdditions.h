// STORESPaymentsSDK
// Copyright © Coiney Inc. All rights reserved.
// For licensing information, contact info@coiney.com.

#import <UIKit/UIKit.h>

// UIFont has no fallback mechanism for when a font isn't found, hence this category.
// it overrides initWithCoder: to preserve font style & size when a font isn't found.
@interface UIFont (CoineyKitAdditions)
// Case insensitive lookup by name/weight
+ (instancetype)cy_fontWithName:(NSString *)aName weight:(NSString *)aWeight size:(CGFloat)aSize;
// Returns the ttf name
+ (NSString *)cy_resolveFontName:(NSString *)aName weight:(NSString *)aWeight;

@end
