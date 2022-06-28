// CommonMPI
// Copyright © Coiney Inc. All rights reserved.
// For licensing information, contact info@coiney.com.

#ifndef NSData_TLV_h
#define NSData_TLV_h

#import <Foundation/Foundation.h>

@interface NSData (TLV)

/// Returns the value of the first matching TLV.
/// \param aTag The tag to search for.
/// \return Value of the first TLV with the specified tag, or nil if none were found.
- (NSData * _Nullable)valueForTag:(uint32_t)aTag;

/// Returns all values with the specified tag.
/// Use this if you expect multiple TLVs with the same tag.
/// \param aTag The tag to search for.
/// \return Values of all TLVs matching the specified tag (order is preserved).
- (NSArray<NSData*> * _Nonnull)valuesForTag:(uint32_t)aTag;

@end

#endif /* NSData_TLV_h */
