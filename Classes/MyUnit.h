/*
 *	MyUnit.h
 *		操作をする板を管理するファイル
 *		2016/1/16 inoue
 */

#ifndef __FlicGame__MyUnit__
#define __FlicGame__MyUnit__

#include "Constants.h"

class MyUnit: public Sprite {
private:
	Rect getRect();		// 画像範囲を求める
	
public:
	MyUnit();			// コンストラクタ
	virtual ~MyUnit();	// デストラクタ
	
	static MyUnit* create();			// createメソッド
	virtual bool init() override;		// 初期化処理
	virtual void onEnter() override;	// 描画前処理
	virtual void onExit() override;		// 終了処理
	
};

#endif /* defined(__FlicGame__MyUnit__) */
