/*
 *	ItemGenerator.hpp
 *		アイテムの生成を管理するクラス
 *		2016/1/16 koka
 */

#ifndef ItemGenerator_hpp
#define ItemGenerator_hpp

#include <stdio.h>
#include <cocos2d.h>
#include "BaseItem.hpp"


class CItemGenerator {
private:
    enum kItemType {
        widthUpItem = 0,
        widthDownItem,
        
        unknownItem,
    };
    
    
public:
    virtual ~CItemGenerator(){}
    CItemGenerator(){};

    void generate(cocos2d::Point pos);  // アイテム生成
    cocos2d::Layer* parentLayer;
};






#endif /* ItemGenerator_hpp */
