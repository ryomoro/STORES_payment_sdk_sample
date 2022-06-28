// STORESPaymentsSDK
// Copyright © Coiney Inc. All rights reserved.
// For licensing information, contact info@coiney.com.

#import <UIKit/UIKit.h>
#import "CYCurrency.h"

@class CYReceiptParser;

@protocol CYReceiptParserDelegate <NSObject>
- (void)receiptParser:(CYReceiptParser *)aParser beganParsingWithCurrency:(CYCurrency)aCurrency;

- (void)receiptParserFinishedParsing:(CYReceiptParser *)aParser;
- (void)receiptParserFailedParsing:(CYReceiptParser *)aParser;

- (void)receiptParser:(CYReceiptParser *)aParser
           foundTitle:(NSString *)aValue
       withAttributes:(NSDictionary *)aAttributes;

- (void)receiptParser:(CYReceiptParser *)aParser
        foundSubtitle:(NSString *)aValue
       withAttributes:(NSDictionary *)aAttributes;

- (void)receiptParser:(CYReceiptParser *)aParser
            foundText:(NSString *)aValue
       withAttributes:(NSDictionary *)aAttributes;

- (void)   receiptParser:(CYReceiptParser *)aParser
foundRulerWithAttributes:(NSDictionary *)aAttributes;

- (void)receiptParser:(CYReceiptParser *)aParser
foundLineItemWithName:(NSString *)aName
           attributes:(NSDictionary *)aNameAttributes
                price:(NSInteger)aPrice
           attributes:(NSDictionary *)aPriceAttributes;

- (void)receiptParser:(CYReceiptParser *)aParser
           foundTotal:(NSInteger)aCurrentTotal
       withAttributes:(NSDictionary *)aAttributes;
@end

@interface CYReceiptParser : NSObject
@property(nonatomic, readonly) BOOL isParsing;
@property(nonatomic, readonly) NSString *source;
@property(nonatomic, readonly) NSDictionary *substitutions;
@property(nonatomic, readonly) NSNumberFormatter *currencyFormatter;
@property(nonatomic, weak) id<CYReceiptParserDelegate> delegate;

- (instancetype)init __attribute__((unavailable("-init not available; use -initWithReceiptML:")));;
- (instancetype)initWithReceiptML:(NSString *)aSource;
- (instancetype)initWithReceiptML:(NSString *)aSource substitutions:(NSDictionary *)aSubs;

- (BOOL)parse;
- (NSString *)applySubstitutions;
@end
