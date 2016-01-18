/*
 *	MyUnit.cpp
 *		操作をする板を管理するファイル
 *		2016/1/16 inoue
 */

#include "MyUnit.h"

#pragma mark --- コンストラクタ ---
MyUnit::MyUnit(){
}

#pragma mark --- デストラクタ ---
MyUnit::~MyUnit() {
}

#pragma mark --- create()メソッド ---
MyUnit* MyUnit::create(){
	auto pRet = new MyUnit();
	pRet->autorelease();
	pRet->init();
	return pRet;
}

#pragma mark --- 初期化処理 ---
bool MyUnit::init() {
	if(!Sprite::initWithFile(MYUNIT_IMAGE)) return false;
	this->setScale(1.0f, .5f);
	this->setPosition(WINSIZE.width*.5f, 100);
	
	return true;
}

#pragma mark --- 描画前処理 ---
void MyUnit::onEnter() {
	Sprite::onEnter();
}

#pragma mark --- 終了処理 ---
void MyUnit::onExit() {
	Sprite::onExit();
}

#pragma mark --- 画像範囲を求める ---
Rect MyUnit::getRect() {
	CCLOG("MyUnitの画像サイズを取得)");
	Point point = this->getPosition();	// 画像中央の座標を取得
	
	int w = this->getContentSize().width;	// 画像の幅
	int h = this->getContentSize().height;	// 画像の高さ
	
	CCLOG("%d, %d", w, h);
	
	return Rect(point.x - (w * 0.5), point.y - (h * 0.5), w, h);	// 画像範囲をリターン
}