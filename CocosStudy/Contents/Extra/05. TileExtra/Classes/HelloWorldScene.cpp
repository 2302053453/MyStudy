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

Vec2 HelloWorld::vec21(float x, float y)
{
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	return Vec2(x + origin.x, y + origin.y);
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
    
	Size size1 = Director::getInstance()->getWinSize();
	Size size2 = Director::getInstance()->getVisibleSize();

	log("Size1 : %f...%f", size1.width, size1.height);
	log("Size2 : %f...%f", size2.width, size2.height);

	auto back = Sprite::create("HelloWorld.png");
	back->setPosition(Vec2(size1.width / 2, size1.height / 2));
	this->addChild(back);

	auto box = Sprite::create("blocks.png");
	box->setPosition(Vec2(0, size1.height / 2));
	this->addChild(box);

	auto box2 = Sprite::create("blocks.png");
	box2->setPosition(Vec2(size1.width, size1.height / 2));
	this->addChild(box2);

	//auto box3 = Sprite::create("blocks.png");
	//box3->setPosition(Vec2(size1.width / 2, 0));
	//this->addChild(box3);

	auto box31 = Sprite::create("blocks.png");
	box31->setPosition(Vec2(size1.width/2 - 50, 0));
	this->addChild(box31);

	auto box32 = Sprite::create("blocks.png");
	box32->setPosition(Vec2(size1.width / 2 + 50, 0));
	this->addChild(box32);

	//auto box4 = Sprite::create("blocks.png");
	//box4->setPosition(Vec2(size1.width / 2, size1.height));
	//this->addChild(box4);

	//auto box41 = Sprite::create("blocks.png");
	//box41->setPosition(Vec2(size1.width / 2 - 50, size1.height));
	//this->addChild(box41);

	//auto box42 = Sprite::create("blocks.png");
	//box42->setPosition(Vec2(size1.width / 2 + 50, size2.height));
	//this->addChild(box42);

    return true;
}

