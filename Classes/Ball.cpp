/*
 *	Ball.cpp
 *		ボールクラスを管理するファイル
 *		2016/1/16 koka
 */

#include "Ball.hpp"
USING_NS_CC;


Ball::Ball(){
    setPOS(Point(0,0));
    setVEL_X(0.0);
    setVEL_Y(0.0);
    m_intersect = false;
    m_scoreFlag = false;
}

bool Ball::init(){
    if(!Sprite::init()){
        return false;
    }
    
    
    
    return true;
}

void Ball::onEnter(){
    Sprite::onEnter();
    
}


void Ball::Falling(){
    
    // 移動速度を取得
    float x = this->getVEL_X();
    float y = this->getVEL_Y();
    
    // 自身の vel に応じて 再設定していく
    Point pos = this->getPOS();
    
    pos = Point(pos.x += x, pos.y += y);
    
    this->setPosition(pos);
    
    this->setPOS(pos);
}

void Ball::removeSelf(Point pos){
    // ゲームオーバー処理
    
}

void Ball::remove(){
    auto remove = RemoveSelf::create();
    runAction(remove);
}