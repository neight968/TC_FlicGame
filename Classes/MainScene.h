/*
 *	MainScene.h
 *		メインシーンの管理するファイル
 *		2016/1/16 inoue
 */

#ifndef __FlicGame__MainScene__
#define __FlicGame__MainScene__

#include "constants.h"
#include "Block.hpp"
#include "MyUnit.h"
#include "Ball.hpp"

class MainScene: public Layer {
private:
	
	// 重なった際の優先度
	// 数値が大きい...手前
	enum ZIndex {
        
	};
	
	// タグ
	enum Tags {
        T_Bar = 0,
        T_FirstBlock = 1,
        T_Ball = 41,
	};
	
	bool touchFlag;		// タップの可否
	Point touchPoint;	// タップ開始座標
    
    void initBlocks();    // ブロックの配置
    void initBall();      // ボールの配置
    
    void intersectsBallAndBlock();  // ブロックとバーの衝突判定
    
    void initCollisionSprite();	// ゲームオーバー用矩形スプライト
    void initScoreLabel();		// スコアラベルの初期化
    
    void createMyUnit();		// MyUnitを生成
    
	
public:
	MainScene();		// コンストラクタ
	~MainScene();		// デストラクタ
	
	static Scene* createScene();	// シーン生成
	static MainScene* create();		// シーン生成時にinit()を呼び出す
	
	virtual bool init() override;						// 初期化処理
	virtual void onEnterTransitionDidFinish() override;	// 描画前処理
	virtual void onExitTransitionDidStart() override;	// 終了処理
	virtual void update(float deltaTime) override;		// 更新処理
	
	// タップ処理
	virtual bool onTouchBegan(Touch *touch, Event *unused_event);
	virtual void onTouchMoved(Touch *touch, Event *unused_event);
	virtual void onTouchEnded(Touch *touch, Event *unused_event);
	virtual void onTouchCancelled(Touch *touch, Event *unused_event);
};

#endif /* defined(__FlicGame__MainScene__) */
