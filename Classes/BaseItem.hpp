/*
 *	BaseItem.hpp
 *		アイテム全てに適用されるものを入れるクラス
 *		2016/1/16 koka
 */

#ifndef BaseItem_hpp
#define BaseItem_hpp

#include <stdio.h>
#include <cocos2d.h>

class CItem : public cocos2d::Sprite {
protected:
    // 表示位置
    CC_SYNTHESIZE(cocos2d::Point, m_pos, POS);
    // 落下処理
    void FallItem();
    
public:
    virtual bool init();
    virtual void onEnter();    // 表示前処理
    
    CItem(){}
    virtual ~CItem(){}
    
    CREATE_FUNC(CItem);
};

#endif /* BaseItem_hpp */
