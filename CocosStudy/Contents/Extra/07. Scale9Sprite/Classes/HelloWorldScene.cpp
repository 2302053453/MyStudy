#include "HelloWorldScene.h"

USING_NS_CC;

using namespace cocos2d;
using namespace cocos2d::extension;

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
    
	auto sprite1 = Sprite::create("test9.png");
	sprite1->setPosition(Vec2(140, 160));
	this->addChild(sprite1);

	Texture2D* texture = Director::getInstance()->getTextureCache()->addImage("test9/png");
	
	auto spriteTop = Sprite::createWithTexture(texture, Rect(0, 0, 50, 20));
	spriteTop->setPosition(Vec2(240, 300));
	this->addChild(spriteTop);

	auto spriteBottom = Sprite::createWithTexture(texture, Rect(0, 30, 50, 20));
	spriteBottom->setPosition(Vec2(240, 20));
	this->addChild(spriteBottom);

	auto spriteMiddle = Sprite::createWithTexture(texture, Rect(0, 20, 50, 10));
	spriteMiddle->setPosition(Vec2(240, 160));
	this->addChild(spriteMiddle);

	// 세번쨰 parameter : 늘어나는 부분
	/*
		Scale9Sprite : 해당 Sprite의 크기를 늘릴때 지정한 부분만 확장되는 Sprite 
	*/
	Scale9Sprite* sprite2 = Scale9Sprite::create(
		"test9.png",
		Rect(0, 0, 50, 50),
		Rect(0, 20, 50, 10));

	sprite2->setPosition(Vec2(340, 160));
	sprite2->setContentSize(Size(50, 300));

	this->addChild(sprite2);

    return true;
}

