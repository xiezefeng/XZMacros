//
//  UIMacro.h
//  Macros
//
//  Created by ZF xie on 2021/6/1.
//

#ifndef UIMacro_h
#define UIMacro_h


// 获取屏幕宽高
#ifndef kScreenWidth
#define kScreenWidth ([UIScreen mainScreen].bounds.size.width)
#endif

#ifndef kScreenHeight
#define kScreenHeight ([UIScreen mainScreen].bounds.size.height)
#endif
#define kScreenBounds [UIScreen mainScreen].bounds

/*TabBar高度*/
#define kTabBarHeight ([[UIApplication sharedApplication] statusBarFrame].size.height>20?83:49)
/*是否是iphoneX*/
#define kIs_iPhoneX kScreenWidth >=375.0f && kScreenHeight >=812.0f&& kIs_iphone
/*状态栏高度*/
#define kStatusBarHeight (CGFloat)(kIs_iPhoneX?(44.0):(20.0))
/*导航栏高度*/
#define kNavBarHeight (44)
/*状态栏和导航栏总高度*/
#define kNavBarAndStatusBarHeight (CGFloat)(kIs_iPhoneX?(88.0):(64.0))
/*顶部安全区域远离高度*/
#define kTopBarSafeHeight (CGFloat)(kIs_iPhoneX?(44.0):(0))
/*底部安全区域远离高度*/
#define kBottomSafeHeight (CGFloat)(kIs_iPhoneX?(34.0):(0))
/*iPhoneX的状态栏高度差值*/
#define kTopBarDifHeight (CGFloat)(kIs_iPhoneX?(24.0):(0))
/*导航条和Tabbar总高度*/
#define kNavAndTabHeight (kNavBarAndStatusBarHeight + kTabBarHeight)

//根据ip6的屏幕来拉伸
#define kRealValue(with) ((with)*(kScreenWidth/375.0f))



#define kView_X(v) (v).frame.origin.x
#define kView_Y(v) (v).frame.origin.y
#define kView_WIDTH(v) (v).frame.size.width
#define kView_HEIGHT(v) (v).frame.size.height
#define kView_WIDTH(v) (v).bounds.size.width
#define kView_HEIGHT(v) (v).bounds.size.height

#define kImage_WIDTH(v) (v).size.width
#define kImage_HEIGHT(v) (v).size.height

#define MinX(v) CGRectGetMinX((v).frame)
#define MinY(v) CGRectGetMinY((v).frame)

#define MidX(v) CGRectGetMidX((v).frame)
#define MidY(v) CGRectGetMidY((v).frame)

#define MaxX(v) CGRectGetMaxX((v).frame)
#define MaxY(v) CGRectGetMaxY((v).frame)



/* ****** 设备类型 ****** */
#define IPAD (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPad)
#define IPHONE (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPhone)

#define isiPhone4 ([[UIScreen mainScreen]bounds].size.height == 480)
#define isiPhone5 ([[UIScreen mainScreen]bounds].size.height == 568)
#define isiPhone6 ([[UIScreen mainScreen]bounds].size.height == 667)
#define isiPhonep ([[UIScreen mainScreen]bounds].size.height == 736)
//判断iPHoneX、iPHoneXs
#define isiPhoneX ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(1125, 2436), [[UIScreen mainScreen] currentMode].size) && !IPAD : NO)

#define isiPhoneXs ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(1125, 2436), [[UIScreen mainScreen] currentMode].size) && !IPAD : NO)

//判断iPHoneXr
#define isiPhoneXr ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(828, 1792), [[UIScreen mainScreen] currentMode].size) && !IPAD : NO)

//判断iPhoneXs Max
#define isiPhoneXsMax ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(1242, 2688), [[UIScreen mainScreen] currentMode].size) && !IPAD : NO)



/* ****** UIKit ****** */
//定义UIImage对象
#define kImageWithFile(_pointer)      [UIImage imageWithContentsOfFile:([[NSBundle mainBundle] pathForResource:[NSString stringWithFormat:@"%@@%dx", _pointer, (int)[UIScreen mainScreen].nativeScale] ofType:@"png"])]

#define kImage(name)                 [UIImage imageNamed:name]

//颜色
#define RGBA(r,g,b,a) [UIColor colorWithRed:(r)/255.0f green:(g)/255.0f blue:(b)/255.0f alpha:(a)]
#define RGB(r, g, b) RGBA(r, g, b, 1.0f)
#define kHexColorA(rgbValue, a) [UIColor colorWithRed:((float)(((rgbValue)&0xFF0000) >> 16)) / 255.0 green:((float)(((rgbValue)&0xFF00) >> 8)) / 255.0 blue:((float)((rgbValue)&0xFF)) / 255.0 alpha:(a)]

//随机色
#define kRandomColor LBColor(arc4random_uniform(256), arc4random_uniform(256), arc4random_uniform(256))


//字体大小
#define BOLD_SYSTEM_FONT(FONTSIZE) [UIFont boldSystemFontOfSize:FONTSIZE]
#define SYSTEM_FONT(FONTSIZE) [UIFont systemFontOfSize:FONTSIZE]
#define MEDIUM_FONT(FONTSIZE) [UIFont fontWithName:@"PingFangSC-Medium" size:FONTSIZE]
#define FONT(NAME, FONTSIZE) [UIFont fontWithName:(NAME) size:(FONTSIZE)]


#endif /* UIMacro_h */
