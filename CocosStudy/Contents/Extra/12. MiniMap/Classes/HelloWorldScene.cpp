#include "HelloWorldScene.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !LayerColor::initWithColor(Color4B(255,255,255,255)) )
    {
        return false;
    }
    
	Size winSize = Director::getInstance()->getWinSize();

	// 게임용 레이어 추가
	gameLayer = LayerColor::create(Color4B(255, 0, 0, 255),
		winSize.width,
		winSize.height);
	gameLayer->setAnchorPoint(Vec2(0, 0));
	gameLayer->setPosition(Vec2(0, 0));
	this->addChild(gameLayer);

	// 메뉴용 레이어 추가
	menuLayer = LayerColor::create(Color4B(0, 0, 0, 0),
		winSize.width,
		winSize.height);
	menuLayer->setAnchorPoint(Vec2(0, 0));
	menuLayer->setPosition(Vec2(0, 0));
	this->addChild(menuLayer);

	auto man = Sprite::create("Images/grossini.png");
	man->setPosition(Vec2(90, 160));
	gameLayer->addChild(man);

	auto myActionForward = MoveBy::create(2, Vec2(380, 0));
	auto myActionBack = myActionForward->reverse();
	auto myAction = Sequence::create(myActionForward, myActionBack, nullptr);
	auto rep = RepeatForever::create(myAction);

	man->runAction(rep);

	auto back = Sprite::create("Images/minimap_back.png");
	back->setPosition(Vec2(400, 260));
	menuLayer->addChild(back);

	miniMap = RenderTexture::create(480, 320, Texture2D::PixelFormat::RGBA8888);
	miniMap->retain();
	miniMap->setPosition(400, 260);

    return true;
}

void HelloWorld::onEnter()
{
	Layer::onEnter();

	miniMap->begin();
	gameLayer->visit();
	miniMap->end();

	Sprite* mms = miniMap->getSprite();
	mms->setScale(0.22f);

	// Filp sprite along Y axis as visited sprite is filpped vertically
	// for som reason...
	// Fixed in 3, 6,... 그래서 -1 대신 1을 곱한다.
	mms->setScaleY(mms->getScaleY() * 1);

	menuLayer->addChild(miniMap);

	this->schedule(schedule_selector(HelloWorld::UpdateMiniMap));
}
void HelloWorld::UpdateMiniMap(float f)
{
	miniMap->clear(0, 0, 0, 255);
	miniMap->begin();
	gameLayer->visit();
	miniMap->end();
}