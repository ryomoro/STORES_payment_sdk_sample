// CommonMPI
// Copyright © Coiney Inc. All rights reserved.
// For licensing information, contact info@coiney.com.

#ifndef CMResponse_h
#define CMResponse_h

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSUInteger, CMResponseType) {
    CMResponseTypeSolicited,
    CMResponseTypeUnsolicited,
    CMResponseTypeFelica,
    CMResponseTypeUnknown
};

@interface CMResponse: NSObject

@property (readonly) CMResponseType type;
@property (readonly) uint8_t nad;
@property (readonly) uint8_t pcb;
@property (readonly) size_t length;
@property (readonly, nullable) NSData *body;
@property (readonly) uint8_t sw1;
@property (readonly) uint8_t sw2;
@property (readonly) uint8_t lrc;

// Derived
@property (readonly) uint16_t status;
@property (readonly) BOOL isSuccess;

// Shared
+ (NSArray<CMResponse *> * _Nonnull)splitResponses:(NSData * _Nonnull)aData;
+ (NSArray<CMResponse *> * _Nonnull)splitResponses:(NSData * _Nonnull)aData
                                    bytesProcessed:(size_t * _Nonnull)oBytesProcessed;

@end

#endif /* CMResponse_h */
