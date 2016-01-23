//
//  BaseItem.cpp
//  FlicGame
//
//  Created by 小菓嵩拡 on 2016/01/18.
//
//

#include "BaseItem.hpp"
using namespace cocos2d;


bool CItem::init(){
    if(!Sprite::init()){
        return false;
    }
    return true;
}

void CItem::onEnter(){
    Sprite::onEnter();
}

void CItem::FallItem(){
    log("落下開始\n");
}