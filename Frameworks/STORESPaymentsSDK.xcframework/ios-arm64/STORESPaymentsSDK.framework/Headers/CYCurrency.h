// 
// STORESPaymentsSDK
// Copyright © Coiney Inc. All rights reserved.
// For licensing information, contact info@coiney.com.
//

#import <Foundation/Foundation.h>

#ifndef CYCurrency_h
#define CYCurrency_h

/// \~english
/// Represents a currency.
/// (Currently only Japanese Yen are supported)
/// \~japanese
/// 通貨を表します。
/// (現在日本円のみ対応)
typedef NS_ENUM(int64_t, CYCurrency) {
    /// \~english
    /// Invalid currency code
    /// \~japanese
    /// 不正な通貨コード
    CYCurrencyInvalid,
    /// \~english
    /// Japanese Yen
    /// \~japanese
    /// 日本円
    CYCurrencyJPY
};

#endif /* CYCurrency_h */
