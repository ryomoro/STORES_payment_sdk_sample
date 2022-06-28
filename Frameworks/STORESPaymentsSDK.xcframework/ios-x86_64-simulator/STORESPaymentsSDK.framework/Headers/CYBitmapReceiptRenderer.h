// STORESPaymentsSDK
// Copyright © Coiney Inc. All rights reserved.
// For licensing information, contact info@coiney.com.
#import <UIKit/UIKit.h>

#import "CYReceiptRenderer.h"

@interface CYBitmapReceiptRenderer : NSObject <CYReceiptRenderer>
@property BOOL enableAntiAliasing;
- (UIImage *)imageRepresentationOfReceiptML:(NSString *)aSource
                                 usingWidth:(float)aWidth
                          withSubstitutions:(NSDictionary *)aSubs;
@end
