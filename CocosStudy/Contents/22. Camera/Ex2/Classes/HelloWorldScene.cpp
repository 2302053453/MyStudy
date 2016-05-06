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

	Size winsize = Director::getInstance()->getWinSize();
	auto bgLayer = LayerColor::create(Color4B(0, 255, 0, 255), winsize.width, winsize.height);
	bgLayer->setRotation3D(cocos2d::Vertex3F(-20.0, 0, 0));
	this->addChild(bgLayer);

	auto bgSprite = Sprite::create("HelloWorld.png");
	bgSprite->setPosition(Vec2(winsize.width / 2, winsize.height / 2));
	bgLayer->addChild(bgSprite);

	auto man = Sprite::create("Images/grossini.png");
	man->setPosition(Vec2(240,-50));
	bgLayer->addChild(man);

	auto act = MoveBy::create(2.0f, Vec2(0, 450));
	auto seq = Sequence::create(Place::create(Vec2(240, -50)), act, nullptr);
	auto rep = RepeatForever::create(seq);
	man->runAction(rep);

    return true;
}

