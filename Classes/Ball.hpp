/*
 *	Ball.hpp
 *		ボールクラスを管理するファイル
 *		2016/1/16 koka
 */

#ifndef Ball_hpp
#define Ball_hpp

#include <stdio.h>
#include <cocos2d.h>

class Ball : public cocos2d::Sprite{
private:
    CC_SYNTHESIZE(float, m_velX, VEL_X);
    CC_SYNTHESIZE(float, m_velY, VEL_Y);
    
    CC_SYNTHESIZE(cocos2d::Point, m_pos, POS);
    
    bool m_intersect;
    bool m_scoreFlag;
    
public:
    ~Ball(){}
    Ball();
    
    virtual bool init();
    
    void onEnter() override;    // 表示前処理
    
    
    void Falling();
    
    CREATE_FUNC(Ball);
    
    void removeSelf(cocos2d::Point pos);
    void remove();
};


#endif /* Ball_hpp */
