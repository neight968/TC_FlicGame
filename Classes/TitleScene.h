/*
 *	TitleScene.h
 *		タイトルシーンを管理するファイル
 *		2016/1/16 inoue
 */

#ifndef __FlicGame__TitleScene__
#define __FlicGame__TitleScene__

#include "Constants.h"
#include "ItemGenerator.hpp"

enum zOrder{
    
    z_hide = 1,
    z_BG = 5,
    z_button = 6
};

enum tagName{
    
    t_BG = 5,
    t_Title = 6,
    t_Start = 7,
    t_Quit = 8,
    t_Tutorial = 9,
    t_Tap = 10
    
};


class TitleScene: public Layer {
private:
    bool tapFlag;		// タップ可否の判定
    
    void createTitleLogo();				// タイトルロゴの生成
    void createImage();					// 画像とか
    void buttonCreate();				// ボタン生成処理
    void tapStart(Ref *pSender);		// 画面がタッチされた際の処理
    void pushStart(Ref *pSender);		// スタートボタンが押された際の処理
    void pushEnd(Ref *pSender);			// 終了ボタンが押された際の処理
    
public:
    
    
    TitleScene();			// コンストラクタ
    virtual ~TitleScene();	// デストラクタ
    
    static Scene* createScene();	// シーン生成
    static TitleScene* create();	// シーン生成時にinit()関数を呼び出す
    
    virtual bool init() override;					// 初期化処理
    virtual void update(float deltaTime) override;	// 更新処理
    virtual void onEnter() override;				// 描画前処理
    virtual void onExit() override;					// 終了処理
    
    virtual bool onTouchBegan(Touch *touch, Event *unused_event);		// タップ開始処理
    virtual void onTouchEnded(Touch *touch, Event *unused_event);		// タップ終了処理
    virtual void onTouchCancelled(Touch *touch, Event *unused_event);	// タップキャンセル処理
    
};

#endif /* defined(__FlicGame__TitleScene__) */
