/*
 *	UnitWidthUP
 *		操作するバーの幅が大きくなるアイテム
 *		2016/1/16 koka
 */

#ifndef UnitWidthUp_hpp
#define UnitWidthUp_hpp

#include <stdio.h>
#include "BaseItem.hpp"

class CUnitWidthUp : public CItem {
public:
    virtual bool init();
    virtual void onEnter();    // 表示前処理
    
    CUnitWidthUp(){}
    virtual ~CUnitWidthUp(){}
    
    CREATE_FUNC(CUnitWidthUp);
};

#endif /* UnitWidthUp_hpp */
