//
// STORESPaymentsSDK
// Copyright © Coiney Inc. All rights reserved.
// For licensing information, contact info@coiney.com.
//

#import <Foundation/Foundation.h>
#import "CYCollectionNullRemoval.h"

@interface NSArray (CoineyKitAdditions)
// nil from `aMapBlock` is substituted by NSNull if `aIgnoreNil` is true
// otherwise nothing is inserted into the result array
- (NSArray *)cy_map:(id (^)(NSUInteger aIdx, id aObj))aMapBlock
          ignoreNil:(BOOL const)aIgnoreNil;
// Identical to cy_map:ignoreNil: with `aIgnoreNil` set to NO
- (NSArray *)cy_map:(id (^)(NSUInteger aIdx, id aObj))aMapBlock;
- (id)cy_firstObjectPassingTest:(BOOL (^)(id obj))aPredicate;
@end

@interface NSMutableArray (CoineyKitAdditions)
- (id)cy_pop;
@end
