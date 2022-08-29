// 
// STORESPaymentsSDK
// Copyright © Coiney Inc. All rights reserved.
// For licensing information, contact info@coiney.com.
//

#import "cy_printer.h"
#import <Foundation/Foundation.h>

typedef NS_ENUM(cy_printer, CYPrinterTraits) {
    // Star Micronics
    SM_TSP_650II = CY_SM_TSP_650II,
    SM_S210I = CY_SM_S210I,
    // Actually SM-S214i, but there is no way to tell the 2 apart
    SM_L200 = CY_SM_L200,
    SM_MC_PRINT3 = CY_SM_MC_PRINT3,
    
    // Epson
    EPSON_PORTABLE = _CY_EPSON_PORTABLE, // TMP60II and TMP20BI
    EPSON_TMT20II = CY_EPSON_TMT20II,
    EPSON_TMM10 = CY_EPSON_TMM10,
    EPSON_TMM30 = CY_EPSON_TMM30,
    
    // Seiko Instruments
    SII_MPB20 = CY_SII_MPB20
};
