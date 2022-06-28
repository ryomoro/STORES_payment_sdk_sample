// STORESPaymentsSDK
// Copyright © Coiney Inc. All rights reserved.
// For licensing information, contact info@coiney.com.

#import <CoreBluetooth/CoreBluetooth.h>
#import "CYBluetoothLEPrinter.h"

@protocol CYPrinterDiscoveryDelegate <NSObject>
@required
- (void)printersChanged;
@end

@interface CYPrinterDiscoveryManager : NSObject <CBCentralManagerDelegate>
+ (nonnull NSArray<CYBluetoothLEPrinter *> *)discoveredPrinters;
+ (void)scan;
+ (void)stopScan;
+ (void)reconnectSavedPrinters;
+ (void)connectPeripheral:(nonnull CBPeripheral *)aPeripheral
               completion:(nullable CYBLEPrinterCompletionBlock)aBlock;
+ (void)disconnectPeripheral:(nonnull CBPeripheral *)aPeripheral
                  completion:(nullable CYBLEPrinterCompletionBlock)aBlock;
+ (void)setDiscoveryDelegate:(nonnull id<CYPrinterDiscoveryDelegate>)aDelegate;
@end
