/*
 *	UnitWidthUP
 *		操作するバーの幅が大きくなるアイテム
 *		2016/1/23 koka
 */

#ifndef UnitWidthDown_hpp
#define UnitWidthDown_hpp

#include <stdio.h>
#include "BaseItem.hpp"

class CUnitWidthDown : public CItem {
public:
    virtual bool init();
    virtual void onEnter();    // 表示前処理
    
    CUnitWidthDown(){}
    virtual ~CUnitWidthDown(){}
    
    CREATE_FUNC(CUnitWidthDown);
};

#endif /* UnitWidthDown_hpp */
