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

#pragma mark - Objective-C -

#if CGFLOAT_IS_DOUBLE
#    define CGFLOAT_EPSILON DBL_EPSILON
#    define cgfabs fabs
#else
#    define CGFLOAT_EPSILON FLT_EPSILON
#    define cgfabs fabsf
#endif

#pragma mark GCD Utilities
#if __has_extension(blocks)
#   include <dispatch/dispatch.h>
#   define GlobalQueue dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0)
#   define MainQueue dispatch_get_main_queue()

#   define Once(body...) do { \
static dispatch_once_t __token; \
dispatch_once(&__token, ##body); \
} while(0)

static inline void Async(dispatch_block_t const blk)       { dispatch_async(GlobalQueue, blk); }
static inline void AsyncOnMain(dispatch_block_t const blk) { dispatch_async(MainQueue, blk);   }
static inline void SyncOnMain(dispatch_block_t  const blk) {
    if(pthread_main_np())
        blk();
    else
        dispatch_sync(MainQueue, blk);
}
static inline void AfterDelay(float const seconds, dispatch_block_t const blk) {
    dispatch_after(dispatch_time(DISPATCH_TIME_NOW, seconds * NSEC_PER_SEC),
                   MainQueue, blk);
}
#endif

#pragma mark Logging
enum FLogLevel {
    FLogLevel_Emergency,
    FLogLevel_Alert,
    FLogLevel_Critical,
    FLogLevel_Err,
    FLogLevel_Warning,
    FLogLevel_Notice
};

void _FLog(enum FLogLevel aLevel,
           const char * aFile,
           int aLine,
           NSString *aFormat, ...) NS_FORMAT_FUNCTION(4,5);
#define Log(lvl, msg...)   _FLog((lvl), __FILE__, __LINE__, ##msg)
#define LogError(msg...)   Log(FLogLevel_Err, ##msg)
#define LogWarning(msg...) Log(FLogLevel_Warning, ##msg)
#define LogNotice(msg...)  Log(FLogLevel_Notice, ##msg)

#pragma mark Shorthands
#define NotificationCenter      [NSNotificationCenter defaultCenter]
#define Bundle                  [NSBundle mainBundle]
#define FileManager             [NSFileManager defaultManager]
#define Defaults                [NSUserDefaults standardUserDefaults]
#define NSFormat(fmt...)        [NSString stringWithFormat:fmt]
#if TARGET_OS_IPHONE
#   define UIApp  [UIApplication sharedApplication]
#endif

#define DefineThreadLocal(name) \
    static void __ThreadLocalCleanup_##name##__(void *ptr) { id const __unused obj = (__bridge_transfer id)ptr; } \
    static pthread_key_t __ThreadLocal_##name##__
#define InitThreadLocal(name) \
    Once(^{ pthread_key_create(&__ThreadLocal_##name##__, &__ThreadLocalCleanup_##name##__); })
#define ReadThreadLocal(name) \
    (__bridge id)pthread_getspecific(__ThreadLocal_##name##__)
#define WriteThreadLocal(name, value) ({ \
    id const __unused __oldValue__ = (__bridge_transfer id)pthread_getspecific(__ThreadLocal_##name##__); \
    id const __value__ = (value); \
    pthread_setspecific(__ThreadLocal_##name##__, (__bridge_retained void *)__value__); \
    __value__; \
})

#pragma mark Device Detection (iOS)
#if TARGET_OS_IPHONE
#   define UIIdiomString() ((UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPad) ? @"ipad" : @"iphone")
#   define DeviceIsIPad() (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPad)

#    define iOS Version Detection
#    ifndef __IPHONE_7_0
#        define __IPHONE_7_0 (70000)
#    endif
#    ifndef NSFoundationVersionNumber_iOS_6_1
#        define NSFoundationVersionNumber_iOS_6_1 (DBL_MAX)
#    endif

#   define SixOrOlder() (NSFoundationVersionNumber <= NSFoundationVersionNumber_iOS_6_1)
#endif

#pragma mark Drawing Utils
#if TARGET_OS_IPHONE
#   define LetPath(__path, body...) ({ \
        UIBezierPath * const path = (__path); \
        do { body; } while(0); \
        path; \
    })
#   define RGBA(r,g,b,a) [UIColor colorWithRed:(r) green:(g) blue:(b) alpha:(a)]
#   define HSBA(h,s,b,a) [UIColor colorWithHue:(h) saturation:(s) brightness:(b) alpha:(a)]
#else
#   define RGBA(r,g,b,a) [NSColor colorWithCalibratedRed:(r) green:(g) blue:(b) alpha:(a)]
#   define HSBA(h,s,b,a) [NSColor colorWithCalibratedHue:(h) saturation:(s) brightness:(b) alpha:(a)]
#   define LetPath(__path, body...) ({ \
        NSBezierPath * const path = (__path); \
        do { body; } while(0); \
        path; \
    })
#endif
#define RGB(r,g,b) RGBA((r), (g), (b), 1)
#define HSB(h,s,b) HSBA((h), (s), (b), 1)
#define GRAY(b) ({ __typeof(b) b_ = (b); RGB(b_,b_,b_); })

#pragma mark Subscripts

@interface NSUserDefaults (Subscripts)
- (id)objectForKeyedSubscript:(id)aKey;
- (void)setObject:(id)aObj forKeyedSubscript:(id)aKey;
@end

#endif /* Macros_h */
