/*
 *	TitleScene.cpp
 *		タイトルシーンを管理するファイル
 *		2016/1/16 inoue
 */

#include "TitleScene.h"
#include "MainScene.h"


#define start "t_start.png"
#define quit "t_quit.png"
#define tutorial "t_tutorial.png"
#define bg "t_BG.png"
#define bar "t_bar.png"
#define tapBar "t_tapBar.png"

#pragma mark --- コンストラクタ ---
TitleScene::TitleScene()
:tapFlag(true)	// タップの許可
{}

#pragma mark --- デストラクタ ---
TitleScene::~TitleScene() {
    getEventDispatcher()->removeEventListenersForTarget(this);	// タッチイベントの解放
    this->removeAllChildrenWithCleanup(true);					// 全解放
}

#pragma mark --- シーン生成 ---
Scene* TitleScene::createScene() {
    auto scene = Scene::create();
    auto layer = TitleScene::create();
    scene->addChild(layer);
    return scene;
}

#pragma mark --- create() メソッド ---
TitleScene* TitleScene::create() {
    auto pRet = new TitleScene();
    pRet->autorelease();
    pRet->init();
    return pRet;
    
}

#pragma mark --- 初期化処理 ---
bool TitleScene::init() {
    if(!Layer::init()) return false;	// エラーチェック
    scheduleUpdate();					// 更新処理の呼び出し
    
    // シングルタップイベント
    auto listener = EventListenerTouchOneByOne::create();
    listener->setSwallowTouches(_swallowsTouches);
    
    // イベント関数の割り当て
    listener->onTouchBegan = bind(&TitleScene::onTouchBegan, this, placeholders::_1, placeholders::_2);
    listener->onTouchEnded = bind(&TitleScene::onTouchEnded, this, placeholders::_1, placeholders::_2);
    listener->onTouchCancelled = bind(&TitleScene::onTouchCancelled, this, placeholders::_1, placeholders::_2);
    
    // イベントリスナーの登録
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
    
    

    
    return true;
}

#pragma mark --- 描画前処理 ---
void TitleScene::onEnter() {
    Layer::onEnter();
    createTitleLogo();	// タイトルロゴ生成処理
    buttonCreate();		// ボタン生成処理
    createImage();		// 画像生成
    
}

#pragma mark --- 終了処理 ---
void TitleScene::onExit() {
    Layer::onExit();
}

#pragma mark --- 更新処理 ---
void TitleScene::update(float deltaTime) {
    
}



#pragma mark --- 画像とかの生成 ---
void TitleScene::createImage(){
    
    // タイトル背景
    auto BG = Sprite::create(bg);
    BG->setPosition( Point(WINSIZE.width * 5/10, WINSIZE.height * 5/10) );
    this->addChild(BG,z_BG,t_BG);
    
    // 開始前のタップ要求(?)ボタン
    auto b_tap = MenuItemImage::create(tapBar, tapBar,
                                       CC_CALLBACK_1(TitleScene::tapStart, this));
    Menu* m_tap = Menu::create(b_tap, NULL);	// menuにbuttonを入れる
    m_tap->setPosition(Point(WINSIZE.width * 5/10, WINSIZE.height * 5/10));	// 表示座標の設定
    this->addChild(m_tap,z_button);
    auto l_tap = Label::createWithSystemFont( "画面をタッチしてください", "Arial", 32 );
    l_tap->setPosition(Point(WINSIZE.width * 5/10, WINSIZE.height * 2/10));
    l_tap->enableOutline(Color4B::BLUE, 1);
    this->addChild(l_tap,z_button);
    
    
    
}

#pragma mark --- タイトルロゴの生成 ---
void TitleScene::createTitleLogo() {
    // ラベルの生成(P nBall)
    auto label = Label::createWithSystemFont("P nball", "Arial", 180);
    label->setPosition(Point(WINSIZE.width * .5, WINSIZE.height * .5 + 200));
    this->addChild(label);
    
    // I の部分をNodeで作成
    auto node_I = DrawNode::create();
    node_I->drawSegment(Point(185, 710), Point(185, 790),
                        6.0f, Color4F(1.0f, 1.0f, 1.0f, 1.0f)); // 開始座標, 終了座標, 太さ, 色
    this->addChild(node_I);
}

#pragma mark --- ボタン生成処理 ---
void TitleScene::buttonCreate() {
    
    /*	START,END,TUTORIAL ボタンを生成(一旦,背景より奥に表示)
     */
    
    // メニューアイテム(スタートボタン)の作成
    auto b_start = MenuItemImage::create(start, start,
                                         CC_CALLBACK_1(TitleScene::pushStart, this));
    Menu* m_start = Menu::create(b_start, NULL);	// menuにbuttonを入れる
    m_start->setPosition(Point(WINSIZE.width * 0.5, WINSIZE.height * 0.5));	// 表示座標の設定
    this->addChild(m_start,10,t_Start);						// 表示
    
    // メニューアイテムラベル(終了ボタン)の作成
    auto b_quit = MenuItemImage::create(quit, quit,
                                        CC_CALLBACK_1(TitleScene::pushEnd, this));
    Menu* m_quit = Menu::create(b_quit, NULL);	// menuにbuttonを入れる
    m_quit->setPosition(Point(WINSIZE.width * 0.5, WINSIZE.height * 0.3));	// 表示座標の設定
    this->addChild(m_quit,10,t_Quit);						// 表示
}

#pragma mark --- ボタンが押された際の処理 ---
void TitleScene::pushStart(Ref *pSender) {
    Director::getInstance()->replaceScene(MainScene::createScene());
    log("タップされました");
}


void TitleScene::pushEnd(Ref *pSender) {
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
    MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
    return;
#endif
    Director::getInstance()->end();
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}

void TitleScene::tapStart(Ref *pSender){
    
    
}


#pragma mark --- タップ開始処理 ---
bool TitleScene::onTouchBegan(Touch *touch, Event *unused_event) {
    if(!tapFlag == true) return false;		// タップが出来るときのみ処理を通す
    CCLOG("タップ開始");
    
    
    
    return true;
}

#pragma mark --- タップ終了処理 ---
void TitleScene::onTouchEnded(Touch *touch, Event *unuseed_event) {
    CCLOG("タップ終了");
}

#pragma mark --- タップキャンセル処理 ---
void TitleScene::onTouchCancelled(Touch *touch, Event *unused_event) {
    onTouchEnded(touch, unused_event);		// タップ終了処理を呼び出す
}