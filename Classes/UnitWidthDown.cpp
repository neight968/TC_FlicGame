/*
 *	UnitWidthUP
 *		操作するバーの幅が大きくなるアイテム
 *		2016/1/23 koka
 */

#include "UnitWidthDown.hpp"
#include "Constants.h"

using namespace cocos2d;

bool CUnitWidthDown::init(){
    if(!Sprite::init()){
        return false;
    }
    return true;
}

void CUnitWidthDown::onEnter(){
    Sprite::onEnter();
    
    setTexture(WIDTH_UP_ITEM);
}