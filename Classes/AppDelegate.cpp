#include "AppDelegate.h"
#include "TitleScene.h"

USING_NS_CC;

AppDelegate::AppDelegate() {
}

AppDelegate::~AppDelegate() 
{
}

bool AppDelegate::applicationDidFinishLaunching() {
    // initialize director
    auto director = Director::getInstance();
    auto glview = director->getOpenGLView();
    if(!glview) {
        glview = GLView::create("My Game");
        director->setOpenGLView(glview);
    }

    director->setDisplayStats(true);			// FPSの表示設定
    director->setAnimationInterval(1.0 / 16);	// フレームレートの設定
	
	// 画面伸縮処理
	// glview->setDesignResolutionSize( 1136, 640, ResolutionPolicy::FIXED_HEIGHT ) ;

    auto scene = TitleScene::createScene();		// シーン生成
    director->runWithScene(scene);				// 起動

    return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground() {
    Director::getInstance()->stopAnimation();

    // if you use SimpleAudioEngine, it must be pause
    // SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() {
    Director::getInstance()->startAnimation();

    // if you use SimpleAudioEngine, it must resume here
    // SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
}

// xcode6.0パッチ
extern "C" {
	size_t fwrite$UNIX2003(const void *a, size_t b, size_t c, FILE *d) {
		return fwrite(a, b, c, d);
	}
	char* strerror$UNIX2003( int errnum ) {
		return strerror(errnum);
	}
}
