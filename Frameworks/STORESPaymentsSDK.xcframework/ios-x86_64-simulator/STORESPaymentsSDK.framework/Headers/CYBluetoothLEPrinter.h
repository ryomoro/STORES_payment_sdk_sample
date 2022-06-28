// STORESPaymentsSDK
// Copyright © Coiney Inc. All rights reserved.
// For licensing information, contact info@coiney.com.

#import "CYPrinter.h"
#import <CoreBluetooth/CoreBluetooth.h>

typedef void (^CYBLEPrinterCompletionBlock)(NSError * aError);

@interface CYBluetoothLEPrinter : CYPrinter
@property(nonatomic, strong) CBPeripheral *peripheral;

+ (NSString *)peripheralNamePrefix;

- (instancetype)initWithPeripheral:(CBPeripheral *)aPeripheral;
- (void)connectWithCompletion:(CYBLEPrinterCompletionBlock)aBlock;
- (void)disconnectWithCompletion:(CYBLEPrinterCompletionBlock)aBlock;
@end
