//
//  UnitWidthUp.cpp
//  FlicGame
//
//  Created by 小菓嵩拡 on 2016/01/18.
//
//

#include "UnitWidthUp.hpp"
#include "Constants.h"

using namespace cocos2d;

bool CUnitWidthUp::init(){
    if(!Sprite::init()){
        return false;
    }
    return true;
}

void CUnitWidthUp::onEnter(){
    Sprite::onEnter();
    
    setTexture(WIDTH_UP_ITEM);
}