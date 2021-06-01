//
//  UtilsMacros.h
//  Macros
//
//  Created by ZF xie on 2021/6/1.
//

#ifndef UtilsMacros_h
#define UtilsMacros_h

//获取系统对象
#define kApplication        [UIApplication sharedApplication]
#define kAppWindow          [UIApplication sharedApplication].delegate.window
#define kRootViewController [UIApplication sharedApplication].delegate.window.rootViewController
#define kUserDefaults       [NSUserDefaults standardUserDefaults]
#define kNotificationCenter [NSNotificationCenter defaultCenter]


// 防止多次调用
#define kPreventRepeatClickTime(_seconds_) \
static BOOL shouldPrevent; \
if (shouldPrevent) return; \
shouldPrevent = YES; \
dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)((_seconds_) * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{ \
shouldPrevent = NO; \
});\


//View 圆角和加边框
#define ViewBorderRadius(View, Radius, Width, Color)\
\
[View.layer setCornerRadius:(Radius)];\
[View.layer setMasksToBounds:YES];\
[View.layer setBorderWidth:(Width)];\
[View.layer setBorderColor:[Color CGColor]]

// View 圆角
#define ViewRadius(View, Radius)\
\
[View.layer setCornerRadius:(Radius)];\
[View.layer setMasksToBounds:YES]


/* ****** 沙盒目录文件 ****** */
//获取 Temp
#define PATH_TEMP                    NSTemporaryDirectory()
//获取 Home
#define PATH_HOME                    NSHomeDirectory()
//获取 Document
#define PATH_DOCUMENT                [NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES) firstObject]
//获取 Cache
#define PATH_CACHE                   [NSSearchPathForDirectoriesInDomains(NSCachesDirectory, NSUserDomainMask, YES) firstObject]



/* ****** 系统信息 ****** */
//获取当前语言
#define CURRENT_LANGUAGE            ([[NSLocale preferredLanguages] objectAtIndex:0])
// 手机系统版本号 e.g. 8.4.1
#define CURRENT_SYSTEM_VERSION      [[UIDevice currentDevice] systemVersion]
// APP build e.g. 1
#define CURRENT_APP_BUILD           [[[NSBundle mainBundle] infoDictionary] objectForKey:@"CFBundleVersion"]
// APP version e.g. 1.01
#define CURRENT_APP_VERSION         [[[NSBundle mainBundle] infoDictionary] objectForKey:@"CFBundleShortVersionString"]
#define isSystemVerionGreaterOrEqualTo(x) ([CURRENT_APP_VERSION floatValue] >= (x))


/* ****** Foundtion  ****** */
//拼接字符串
#define NSStringFormat(format,...) [NSString stringWithFormat:format,##__VA_ARGS__]

//强弱引用
#define kWeakSelf(type)      __weak typeof(type) weak##type = type;
#define kStrongSelf(type)    __strong typeof(type) type = weak##type;

//类型校验
#define isDictionary(f)      (f!=nil && [f isKindOfClass:[NSDictionary class]])
#define isArray(f)           (f!=nil && [f isKindOfClass:[NSArray class]] && [f count]>0)
#define isNumber(f)          (f!=nil && [f isKindOfClass:[NSNumber class]])
#define isClass(f,cls)       (f!=nil && [f isKindOfClass:[cls class]])
#define isData(f)            (f!=nil && [f isKindOfClass:[NSData class]])

//判空
#define isEmptyString(a)     (!s  || [a isEqual:[NSNull null]] ||![a isKindOfClass:[NSString class]] || [a isEqualToString:@""])
#define isEmptyArray(a)      (!a || [a isEqual:[NSNull null]] || [a count] == 0)
#define isEmptyDictionary(a) (isDictionary(a)&&a.allKeys.count>0)
#define isNilObject(a) ((nil == a) || [a isKindOfClass:[NSNull class]])


// 角度弧度转换
#define kDegreeToRadians(x) (M_PI * (x) / 180.f)

// 浮点数比较
#define kFloatCompare(x, y)  (isgreaterequal(x, y) && islessequal(x, y))

// 执行blcok
#define execBlock(b, ...) if (b != nil) {b(__VA_ARGS__);}


//-------------------打印日志-------------------------
//DEBUG  模式下打印日志,当前行
#ifdef DEBUG
#define DLog(fmt, ...) NSLog((@"%s [Line %d] " fmt), __PRETTY_FUNCTION__, __LINE__, ##__VA_ARGS__);

#else
#define DLog(...)
#endif

//单例创建

//.h文件
#define SingletonH +(instancetype)sharedInstance;

//加上斜杠是为了让编辑器认为下一行代码也是宏的内容
//.m文件
#define SingletonM                                          \
    static id _instance;                                    \
                                                            \
    +(instancetype)sharedInstance {                         \
        static dispatch_once_t onceToken;                   \
        dispatch_once(&onceToken, ^{                        \
            _instance = [[self alloc] init];                \
        });                                                 \
        return _instance;                                   \
    }                                                       \
                                                            \
    +(instancetype)allocWithZone : (struct _NSZone *)zone { \
        static dispatch_once_t onceToken;                   \
        dispatch_once(&onceToken, ^{                        \
            _instance = [super allocWithZone:zone];         \
        });                                                 \
        return _instance;                                   \
    }                                                       \
                                                            \
    -(id)copyWithZone : (NSZone *)zone {                    \
        return _instance;                                   \
    }



#endif /* UtilsMacros_h */
