// Frequently used macros for uncluttering things

#ifndef Macros_h
#define Macros_h

#pragma mark - C -

#import <Foundation/Foundation.h>
#include <pthread.h>

#pragma mark Numerical Ranges

#define PASTE(a,b) a##b
#if !defined(INRANGE)
#   define __INRANGE(val, low, high, c) ({ \
        __typeof(val) const PASTE(__val,c) = (val); \
        PASTE(__val,c) >= (low) && PASTE(__val,c) <= (high); \
    })
#   define INRANGE(val, low, high) __INRANGE((val), (low), (high), __COUNTER__)
#endif
#if !defined(CLAMP)
#   define CLAMP(val, min, max) MAX((min), MIN((val), (max)))
#endif

#endif /* Macros_h */
