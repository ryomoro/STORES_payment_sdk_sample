// STORESPaymentsSDK
// Copyright © Coiney Inc. All rights reserved.
// For licensing information, contact info@coiney.com.

#import "CYPrinter.h"

@interface CYPrinter (CYReceiptPrinting)

// Prints a receipt using a connected printer.
- (void)printReceiptML:(NSString *)aSource;

- (void)printReceiptML:(NSString *)aSource
     withSubstitutions:(NSDictionary *)aSubs;
@end
