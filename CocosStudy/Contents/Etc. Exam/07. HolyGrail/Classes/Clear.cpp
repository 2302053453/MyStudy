#include "Clear.h"

USING_NS_CC;

Scene* Clear::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = Clear::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool Clear::init()
{
	//////////////////////////////
	// 1. super init first
	if (!LayerColor::initWithColor(Color4B::GREEN))
	{
		return false;
	}


	// 메뉴 아이템 생성 및 초기화
	auto item1 = MenuItemFont::create(
		"CLEAR!!");
	item1->setColor(Color3B::BLACK);


	// 메뉴 생성
	auto menu = Menu::create(item1, nullptr);

	// 메뉴 위치
	menu->setPosition(Vec2(240, 50));

	this->addChild(menu);

	this->schedule(schedule_selector(Clear::doClose), 1.0f);
	return true;
}

void Clear::doClose(float time)
{
	HelloWorld* hello;
	auto scene = HelloWorld::createScene();
	//Director::getInstance()->replaceScene(TransitionFadeBL::create(0.5f, scene));
	Sleep(2000);
	Director::getInstance()->popScene();
	
}

