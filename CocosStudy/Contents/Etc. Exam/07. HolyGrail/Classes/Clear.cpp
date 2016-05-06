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


	// �޴� ������ ���� �� �ʱ�ȭ
	auto item1 = MenuItemFont::create(
		"CLEAR!!");
	item1->setColor(Color3B::BLACK);


	// �޴� ����
	auto menu = Menu::create(item1, nullptr);

	// �޴� ��ġ
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

