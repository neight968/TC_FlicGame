/*
 *	Constants.h
 *		汎用処理を管理するファイル
 *		2016/1/16 inoue
 */

#ifndef FlicGame_Constants_h
#define FlicGame_Constants_h

// 頻繁に読み込む系
#include "cocos2d.h"

// ネームスペース
using namespace cocos2d;
using namespace std;
USING_NS_CC;

// 画面サイズの取得
#define WINSIZE Director::getInstance()->getWinSize()
#define CENTER Director::getInstance()->getWinSize().width * 0.5, Director::getInstance()->getWinSize().height * 0.5


// 配置するブロック関連
#define BLOCK_YOKO 8        // ブロックの横方向の数
#define BLOCK_TATE 5        // ブロックの縦方向の数
#define BLOCK_SIZE_X 63     // ブロックの横サイズ
#define BLOCK_SIZE_Y 42     // ブロックの縦サイズ
#define FIRST_BLOCK_POS_X WINSIZE.width * 0.1 + BLOCK_SIZE_X * 0.2  // ブロックの基準点X
#define FIRST_BLOCK_POS_Y WINSIZE.height * 0.8                      // ブロックの基準点Y


// 画像ファイル名
#define MYUNIT_IMAGE "MyUnitImg.png"　// 操作するバー(=ユニット)

#define WIDTH_UP_ITEM   "red.png"          // ユニット幅増加アイテム　仮定義
#define WIDTH_DOWN_ITEM "red.png"          // ユニット幅低下アイテム 仮定義

#endif
