#include "SecondScene.h"

USING_NS_CC;

Scene* SecondScene::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = SecondScene::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool SecondScene::init()
{
	//////////////////////////////
	// 1. super init first
	if (!LayerColor::initWithColor(Color4B(255, 255, 255, 255)))
	{
		return false;
	}

	auto winSize = Director::getInstance()->getWinSize();

	// �޴� ������ ���� �� �ʱ�ȭ
	auto menuItem1 = MenuItemFont::create(
		"Notification Center Test",
		CC_CALLBACK_1(SecondScene::doSendMsg, this));
	menuItem1->setColor(Color3B::BLACK);

	auto menuItem2 = MenuItemFont::create(
		"â�ݱ�",
		CC_CALLBACK_1(SecondScene::doClose, this));
	menuItem2->setColor(Color3B::BLACK);

	//  �޴� ����
	auto menu = Menu::create(menuItem1,menuItem2, nullptr);
	menu->alignItemsVerticallyWithPadding(20.0f);
	menu->setPosition(Vec2(150, 100));

	// layer�� �޴� ��ü �߰�
	this->addChild(menu);


	return true;
}

void SecondScene::doSendMsg(Ref* obj)
{
	std::string str1 = "ȫ�浿";
	char str2[20] = { 0 };
	sprintf(str2, "%s", str1.c_str());

	NotificationCenter::getInstance()->postNotification("TouchStatus", (Ref*)str2);
}

void SecondScene::doClose(Ref* obj)
{
	this->removeFromParentAndCleanup(true);
}
