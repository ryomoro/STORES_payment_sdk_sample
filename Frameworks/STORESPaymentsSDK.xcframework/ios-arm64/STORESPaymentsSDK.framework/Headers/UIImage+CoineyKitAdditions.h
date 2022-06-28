//
// STORESPaymentsSDK
// Copyright © Coiney Inc. All rights reserved.
// For licensing information, contact info@coiney.com.
//

#import <UIKit/UIKit.h>
#import "CYTypes.h"

@interface UIImage (CoineyKitAdditions)
- (UIImage *)cy_resizedImage:(CGSize)newSize interpolationQuality:(CGInterpolationQuality)quality;
- (UIImage *)cy_resizedImageWithContentMode:(UIViewContentMode)contentMode
                                     bounds:(CGSize)bounds
                       interpolationQuality:(CGInterpolationQuality)quality;
- (UIImage *)cy_resizedImageWithContentMode:(UIViewContentMode)contentMode
                                     bounds:(CGSize)bounds
                       interpolationQuality:(CGInterpolationQuality)quality
                            backgroundColor:(UIColor *)aBackgroundColor;
@end
