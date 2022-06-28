#import <Foundation/Foundation.h>

@class CYPrinter;

@protocol CYReceiptRenderer <NSObject>
- (void)printReceiptML:(NSString *)aSource
     withSubstitutions:(NSDictionary *)aSubs
          usingPrinter:(CYPrinter *)aPrinter;
@end
