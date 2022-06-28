//
// STORESPaymentsSDK
// Copyright © Coiney Inc. All rights reserved.
// For licensing information, contact info@coiney.com.
//

#import <Foundation/Foundation.h>
#import "CYCollectionNullRemoval.h"

typedef void (^CYDictionaryMapBlock)(id *aoKey, id *aoValue);

@interface NSDictionary (CoineyKitAdditions) <CYCollectionNullRemoval>
- (NSDictionary *)cy_dictionaryBySubstitutingValuesUsingDictionary:(NSDictionary *)aSubstitutions;
- (NSDictionary *)cy_map:(CYDictionaryMapBlock)aMapBlock;
- (NSDictionary *)cy_dictionaryByRemovingEntries:(NSArray *)aKeys;
- (id)cy_collectionByRemovingNullItems;

- (NSDictionary *)cy_map:(CYDictionaryMapBlock)aMapBlock
               ignoreNil:(BOOL)aIgnoreNil;

@end
