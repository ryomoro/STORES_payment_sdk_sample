// CommonMPI
// Copyright © Coiney Inc. All rights reserved.
// For licensing information, contact info@coiney.com.

#ifndef CMCommand_h
#define CMCommand_h

#import <Foundation/Foundation.h>

// Item to display with DISPLAY MEDIA command
@interface CMDisplayElement : NSObject
+ (instancetype _Nonnull)elementWithText:(NSString * _Nonnull)aText
                                 xOffset:(uint16_t)aXOfs
                                 yOffset:(uint16_t)aYOfs;
+ (instancetype _Nonnull)elementWithImage:(NSString * _Nonnull)aFilename
                                  xOffset:(uint16_t)aXOfs
                                  yOffset:(uint16_t)aYOfs;
@end

@interface CMCommand: NSObject

// Standard MPI Commands
+ (NSData * _Nonnull)removeSystemLog;
+ (NSData * _Nonnull)batteryStatus;
+ (NSData * _Nonnull)getDeviceInfo;
+ (NSData * _Nonnull)softReset;
+ (NSData * _Nonnull)hardReset;
+ (NSData * _Nonnull)systemClock;
+ (NSData * _Nonnull)setSystemClockWithYear:(uint8_t)aTwoDigitYear
                                      month:(uint8_t)aMonth
                                        day:(uint8_t)aDay
                                       hour:(uint8_t)aHour
                                     minute:(uint8_t)aMinute
                                     second:(uint8_t)aSecond;
+ (NSData * _Nonnull)cardStatus;
+ (NSData * _Nonnull)getConfiguration;
+ (NSData * _Nonnull)p2peStatus;
+ (NSData * _Nonnull)p2peInitialize;
+ (NSData * _Nonnull)p2peImport;
+ (NSData * _Nonnull)selectFileToAppend:(NSString * _Nonnull)aFilename;
+ (NSData * _Nonnull)selectFileToTruncate:(NSString * _Nonnull)aFilename;
+ (NSData * _Nonnull)readBinaryWithOffset:(uint32_t)aOffset;
+ (NSData * _Nonnull)streamBinaryWithOffset:(uint32_t)aOffset
                                       size:(uint32_t)aStreamSize
                               requiringMD5:(BOOL)aNeedMD5;
+ (NSData * _Nonnull)startTransactionWithAmount:(uint64_t)aYenAmount
                                           year:(uint8_t)aTwoDigitYear
                                          month:(uint8_t)aMonth
                                            day:(uint8_t)aDay
                                           hour:(uint8_t)aHour
                                         minute:(uint8_t)aMinute
                                         second:(uint8_t)aSecond;
+ (NSData * _Nonnull)startContactlessTransactionWithAmount:(uint64_t)aYenAmount
                                                      year:(uint8_t)aTwoDigitYear
                                                     month:(uint8_t)aMonth
                                                       day:(uint8_t)aDay
                                                      hour:(uint8_t)aHour
                                                    minute:(uint8_t)aMinute
                                                    second:(uint8_t)aSecond;
+ (NSData * _Nonnull)continueTransactionWithARPC:(NSData * _Nonnull)aARPCData;
+ (NSData * _Nonnull)abort;
+ (NSData * _Nonnull)displayText:(NSString * _Nonnull)aText; // Fullscreen, no status bar
+ (NSData * _Nonnull)displayText:(NSString * _Nonnull)aText
                showingStatusBar:(BOOL)aStatusBarVisible;
+ (NSData * _Nonnull)displayImage:(NSString * _Nonnull)aFilename;
+ (NSData * _Nonnull)displayMedia:(NSArray<CMDisplayElement*> * _Nonnull)aItems;
+ (NSData * _Nonnull)displayMedia:(NSArray<CMDisplayElement*> * _Nonnull)aItems
                    blinkDuration:(uint16_t)aDuration;
+ (NSData * _Nonnull)startNFC;
+ (NSData * _Nonnull)stopNFC;
+ (NSData * _Nonnull)flashLED1:(BOOL)aLED1
                          LED2:(BOOL)aLED2
                          LED3:(BOOL)aLED3
                          LED4:(BOOL)aLED4;
+ (NSData * _Nonnull)illuminateLED1:(BOOL)aLED1
                               LED2:(BOOL)aLED2
                               LED3:(BOOL)aLED3
                               LED4:(BOOL)aLED4;

// TLV Protocol Commands
+ (NSData * _Nonnull)felicaCardDataWithCommand:(NSData * _Nonnull)aCommand;
+ (NSData * _Nonnull)felicaCardDataWithCommand:(NSData * _Nonnull)aCommand
                                       timeout:(uint16_t)aTimeoutMilliseconds;
+ (NSData * _Nonnull)stopFelicaCardData;

@end

#endif /* CMCommand_h */
