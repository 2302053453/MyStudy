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
    
	// 메뉴 아이템 생성 및 초기화
	auto menuItem = MenuItemFont::create(
		"Action",
		CC_CALLBACK_1(HelloWorld::doAction, this));
	menuItem->setColor(Color3B::BLACK);

	// 메뉴 생성
	auto menu = Menu::create(menuItem, nullptr);

	// 메뉴 위치 지정
	menu->setPosition(Vec2(240, 160));

	this->addChild(menu);

	man = Sprite::create("Images/grossini.png");
	man->setPosition(Vec2(50, 150));
	man->setScale(0.5f);
	this->addChild(man);
    
    return true;
}

void HelloWorld::doAction(Ref* sender)
{
	man->removeFromParentAndCleanup(true);

	this->removeChildByTag(1, true);
	this->removeChildByTag(2, true);
	this->removeChildByTag(3, true);

	man = Sprite::create("Images/grossini.png");
	man->setPosition(Vec2(50, 150));
	man->setScale(0.5f);
	this->addChild(man);

	man->setVisible(false);

	auto action = Sequence::create(
		Place::create(Vec2(200, 200)),
		DelayTime::create(1.0),
		Show::create(),
		MoveBy::create(1, Vec2(200, 0)),
		CallFunc::create(CC_CALLBACK_0(HelloWorld::callback1, this)),
		CallFunc::create(CC_CALLBACK_0(HelloWorld::callback2, this, man)),
		CallFunc::create(CC_CALLBACK_0(HelloWorld::callback3, this, man, 42)),
		nullptr);

	man->runAction(action);
}


#pragma mark -
#pragma mark Callback Functions

void HelloWorld::callback1()
{
	auto label1 = LabelTTF::create("callback 1 called", "Marker Felt", 16);
	label1->setPosition(Vec2(120, 160));
	label1->setColor(Color3B::BLACK);
	label1->setTag(1);
	this->addChild(label1);
}

void HelloWorld::callback2(Node* sender)
{
	auto label1 = LabelTTF::create("callback 1 called", "Marker Felt", 16);
	label1->setPosition(Vec2(240, 140));
	label1->setColor(Color3B::RED);
	label1->setTag(2);
	this->addChild(label1);

	auto item = (Sprite*)sender;
	int i = item->getTag();
	log("tag num = %d", i);
}

void HelloWorld::callback3(Node* sender, long data)
{
	auto label1 = LabelTTF::create("callback 1 called", "Marker Felt", 16);
	label1->setPosition(Vec2(360, 120));
	label1->setColor(Color3B::BLUE);
	label1->setTag(3);
	this->addChild(label1);

	log("param data L %d", data);
}

