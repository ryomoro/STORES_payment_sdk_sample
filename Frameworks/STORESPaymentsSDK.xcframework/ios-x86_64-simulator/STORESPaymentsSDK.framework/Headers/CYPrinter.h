// STORESPaymentsSDK
// Copyright © Coiney Inc. All rights reserved.
// For licensing information, contact info@coiney.com.

// Implements support for ESC/POS based bluetooth printers
#import <UIKit/UIKit.h>
#import "cy_printer.h"

void CYEnablePrinting(BOOL aFlag);

extern NSString * const kCYPrinterConnectedNotification,
                * const kCYPrinterDisconnectedNotification,
                * const kCYPrinterBeganPrintingNotification,
                * const kCYPrinterEndedPrintingNotification,
                * const kCYPrinterNotificationLocalizedErrorKey,
                * const kCYPrintingStatusChangedNotification;

extern NSMutableArray *_PrinterClasses;
extern NSMutableArray *_ConnectedPrinters;

extern BOOL _PrintingEnabled;

typedef void (^CYPaperWidthBlock)(enum cy_printer_paper_width aWidth);

@interface CYPrinter : NSObject
@property(nonatomic, assign) enum cy_printer_paper_width paperWidth;

@property(nonatomic, readonly, getter=isConnected) BOOL connected;

// Paper width in pixels
@property(nonatomic, readonly) NSInteger bitmapWidth;

// Paper width in characters
@property(nonatomic, readonly) NSInteger lineLength;

// Name of printer for displaying to user
@property(nonatomic, readonly) NSString *displayName;

// Serial number of printer for displaying to user
@property(nonatomic, readonly) NSString *serialNumber;

// Returns a list of connected printers.
+ (NSArray *)connectedPrinters;

// Whether bitmap printing is impractical, due to its speed or other considerations.
// (This does *not* mean that it is unsupported)
+ (BOOL)bitmapPrintingIsImpractical;

// Executes a collection of print instructions
- (void)batchPrint:(dispatch_block_t)aBlock cutWhenDone:(BOOL)aCut;

/// Prints a string. Wraps as necessary.
- (void)printText:(NSString *)aText;

/// Prints an image.
- (void)printImage:(UIImage *)aImage;

+ (BOOL)registerClass:(Class)aPrinterClass;
+ (cy_printer)printerType;

+ (void)_addConnectedPrinter:(CYPrinter *)aPrinter;

- (void)_sendDataToPrinter:(NSData *)aData;
- (BOOL)_handlePrinterResponse:(NSData * const)aResponse;
- (BOOL)detectPaperWidth:(CYPaperWidthBlock)aBlock;

// If there is no automatic cutting mechanism, paper is fed until
// the printed content is above the manual cutting head
- (BOOL)cutPaper;
@end

@interface NSArray (CYPrinter)
- (BOOL)containsPrinterWithSerialNumber:(NSString *)aSerialNumber;
@end
