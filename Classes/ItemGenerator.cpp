//
//  ItemGenerator.cpp
//  FlicGame
//
//  Created by 小菓嵩拡 on 2016/01/18.
//
//

#include "ItemGenerator.hpp"
#include "UnitWidthUp.hpp"
#include "UnitWidthDown.hpp"

// アイテムの生成からシーンへの取り付け
void CItemGenerator::generate(cocos2d::Point pos){
    int i = rand() % unknownItem;
    
    CItem* item = new CItem();
    
    switch ( i ) {
        case widthUpItem:
            item = CUnitWidthUp::create();
            cocos2d::log("幅増加生成");
            break;
        case widthDownItem:
            item = CUnitWidthDown::create();
            cocos2d::log("幅低下生成");
            break;
            
        default:
            break;
    }
    
    item->setPosition( pos );
    item->setPOS( pos );
    item->setZOrder( 50 );
    parentLayer->addChild( item );
    
    item->FallItem();
}