#import <UIKit/UIKit.h>

@class RootViewController;

// 2016/1/8 追加
extern "C" {
	#import <GoogleMobileAds/GoogleMobileAds.h>
}

@interface AppController : NSObject <UIApplicationDelegate> {
	UIWindow *window;
	GADBannerView *bannerView_;		// 2016/1/8 追加
}

@property(nonatomic, readonly) RootViewController* viewController;

@end

