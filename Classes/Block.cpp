/*
 *	Block.cpp
 *      破壊するブロッククラスを管理するファイル
 *		2016/1/16 koka
 */

#include "Block.hpp"
USING_NS_CC;


BlockSprite::BlockSprite(){
    setPOS(Point(0,0));
    m_activeFlag = true;
}

bool BlockSprite::init(){
    if(!Sprite::init()){
        return false;
    }
    return true;
}

void BlockSprite::onEnter(){
    Sprite::onEnter();
    
    setTexture( "Blocks.png" );
}

void BlockSprite::remove(){
    
    this->m_activeFlag = false;
    auto remove = RemoveSelf::create();
    runAction(remove);
}