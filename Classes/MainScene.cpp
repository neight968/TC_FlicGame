/*
 *	MainScene.cpp
 *		メインシーンを管理するファイル
 *		2016/1/16 inoue
 */

#include "MainScene.h"


#pragma mark --- コンストラクタ ---
MainScene::MainScene()
:touchFlag(true)		// タップの許可
{
}

#pragma mark --- デストラクタ ---
MainScene::~MainScene() {
	getEventDispatcher()->removeEventListenersForTarget(this);	// タッチイベントの解放
	this->removeAllChildrenWithCleanup(true);					// 全解放
}

#pragma mark --- シーン生成 ---
Scene* MainScene::createScene() {
	auto scene = Scene::createWithPhysics();
	auto layer = MainScene::create();
	scene->addChild(layer);
	return scene;
}

#pragma mark --- create()メソッド ---
MainScene* MainScene::create(){
	auto pRet = new MainScene();
	pRet->autorelease();
	pRet->init();
	return pRet;
}

#pragma mark --- 初期化処理 ---
bool MainScene::init() {
	if(!Layer::init()) return false;	// エラーチェック
	scheduleUpdate();					// 更新処理の呼び出し
	
	// シングルタップイベント
	auto listener = EventListenerTouchOneByOne::create();
	listener->setSwallowTouches(_swallowsTouches);
	
	// イベント関数の割り当て
	listener->onTouchBegan = bind(&MainScene::onTouchBegan, this, placeholders::_1, placeholders::_2);
	listener->onTouchEnded = bind(&MainScene::onTouchEnded, this, placeholders::_1, placeholders::_2);
    listener->onTouchMoved = bind(&MainScene::onTouchMoved, this, placeholders::_1, placeholders::_2);
	listener->onTouchCancelled = bind(&MainScene::onTouchCancelled, this, placeholders::_1, placeholders::_2);
	
	// イベントリスナーの登録
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
    
	
	return true;
}


// ブロックの配置
void MainScene::initBlocks() {
    // 縦に置く回数分回す
    for ( int i = 0; i < BLOCK_TATE; i++ ) {
        // 横に置く回数分回す
        for ( int j = 0; j < BLOCK_YOKO; j++ ) {
            // 画像を配置する
            auto block = BlockSprite::create();
            block->setPosition( Point(FIRST_BLOCK_POS_X + (BLOCK_SIZE_X + BLOCK_SIZE_X * 0.1) * j, FIRST_BLOCK_POS_Y - (BLOCK_SIZE_Y + BLOCK_SIZE_Y * 0.1) * i) );
            block->setPOS( Point(FIRST_BLOCK_POS_X + (BLOCK_SIZE_X + BLOCK_SIZE_X * 0.1) * j, FIRST_BLOCK_POS_Y - (BLOCK_SIZE_Y + BLOCK_SIZE_Y * 0.1) * i) );
            
            block->setTag( Tags(T_FirstBlock + (i * BLOCK_YOKO) + j) );
            
            addChild( block );
        }
    }
}




// ボールの配置
void MainScene::initBall() {
    auto ball = Ball::create();
    ball->setPosition( Point(WINSIZE.width * 0.5, WINSIZE.height * 0.5) );
    ball->setPOS( Point(WINSIZE.width * 0.5, WINSIZE.height * 0.5) );
    ball->setTag( Tags(T_Ball) );
    addChild(ball);
}

#pragma mark --- MyUnitの生成 ---
void MainScene::createMyUnit() {
    auto myUnit = MyUnit::create();
    this->addChild(myUnit);
}


#pragma mark --- スコアラベルの初期化 ---
void MainScene::initScoreLabel() {
    // Score
    auto scoreText = Label::createWithSystemFont("Score:", "Arial", 32);
    scoreText->setPosition(WINSIZE.width/10-5, WINSIZE.height*7/10+35);
    addChild(scoreText,5);
    
    // BestScore
    auto BscoreText = Label::createWithSystemFont("前回までの BestScore:", "Arial", 22);
    BscoreText->setPosition(BscoreText->getContentSize().width*.5f, WINSIZE.height*7/10);
    addChild(BscoreText,5);
    
    // スコア表示用 ラベル
    auto scoreLabel = (Label*)getChildByTag(108);
    scoreLabel = Label::createWithSystemFont("", "Arial", 32);
    scoreLabel->setPosition(WINSIZE.width/10+120, WINSIZE.height*7/10+35);
    scoreLabel->setTag(108);
    addChild(scoreLabel, 5);
    scoreLabel->setString("");
    
    // ベストスコア表示用 ラベル
    auto userdef = UserDefault::getInstance();
    int B_score = userdef->getIntegerForKey("HiScore");
    auto BscoreLabel = Label::createWithSystemFont("", "Arial", 22);
    BscoreLabel->setString(StringUtils::format("%5d", B_score));
    BscoreLabel->setPosition(BscoreText->getPosition().x + BscoreText->getContentSize().width*.5f
                             + BscoreLabel->getContentSize().width*.5f, WINSIZE.height*7/10);
    addChild(BscoreLabel,5);
}

#pragma mark --- ゲームオーバー用矩形スプライトの初期化 ---
void MainScene::initCollisionSprite() {
    CCLOG("CollisionSprite初期化");
    auto collisionSprite = Sprite::create();
    collisionSprite->setAnchorPoint(Point(0, 0));
    collisionSprite->setTextureRect(Rect(0, 0, 640, 100));
    collisionSprite->setOpacity(0);
    collisionSprite->setPosition(0, 0);
    this->addChild(collisionSprite);
}


#pragma mark --- 描画前処理 ---
void MainScene::onEnterTransitionDidFinish() {
	Layer::onEnterTransitionDidFinish();
    
    
    initBlocks();             // ブロックを配置する関数の呼び出し
    initCollisionSprite();		// コリジョンスプライトの作成
    initScoreLabel();			// スコアラベルの作成
    createMyUnit();				// MyUnitの生成
    initBall();
    
}

#pragma mark --- 終了処理 ---
void MainScene::onExitTransitionDidStart() {
	Layer::onExitTransitionDidStart();
}

#pragma mark --- 更新処理 ---
void MainScene::update(float deltaTime) {
}



#pragma mark --- 衝突判定 ---
void MainScene::intersectsBallAndBlock() {
    
    // ブロックの数分回す
    for( int i = 1; i <= 40; i++ ) {
        auto block = reinterpret_cast<BlockSprite*>(getChildByTag( i ));
        auto ball = reinterpret_cast<Ball*>(getChildByTag(Tags(T_Ball)));
        
        
    }
}


#pragma mark --- タップ開始処理 ---
bool MainScene::onTouchBegan(Touch *touch, Event *unused_event) {
	if(!touchFlag == true) return false;		// タップが出来るときのみ処理を通す
	
	CCLOG("タップ開始");
	
	return true;
}

#pragma mark --- スワイプ処理 ---
void MainScene::onTouchMoved(Touch *touch, Event *unused_event){
	
}

#pragma mark --- タップ終了処理 ---
void MainScene::onTouchEnded(Touch *touch, Event *unuseed_event) {
	CCLOG("タップ終了");
}

#pragma mark --- タップキャンセル処理 ---
void MainScene::onTouchCancelled(Touch *touch, Event *unused_event) {
	onTouchEnded(touch, unused_event);		// タップ終了処理を呼び出す
}