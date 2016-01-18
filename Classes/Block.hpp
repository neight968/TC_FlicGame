/*
 *	Block.hpp
 *      破壊するブロッククラスを管理するファイル
 *		2016/1/16 koka
 */

#ifndef Block_hpp
#define Block_hpp

#include <stdio.h>
#include <cocos2d.h>

class BlockSprite : public cocos2d::Sprite{
private:
    CC_SYNTHESIZE(cocos2d::Point, m_pos, POS);
    
    bool m_activeFlag;
    
public:
    ~BlockSprite(){}
    BlockSprite();
    
    virtual bool init();
    
    void onEnter() override;    // 表示前処理
    
    void remove();
    
    CREATE_FUNC(BlockSprite);
    
    
};


#endif /* Block_hpp */
