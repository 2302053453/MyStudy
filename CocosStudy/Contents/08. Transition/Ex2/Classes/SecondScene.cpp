#include "SecondScene.h"
#include "HelloWorldScene.h"

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

	auto item1 = MenuItemFont::create(
		"Close Scene 2",
		CC_CALLBACK_1(SecondScene::doClose, this));
	item1->setColor(Color3B::BLACK);

	// �޴� ����
	auto menu = Menu::create(item1, nullptr);

	// ���̾ �޴� �߰�
	addChild(menu);

	log("SecondScene :: Init");

	return true;
}

void SecondScene::doClose(Ref* sender)
{
	// �� ��° ���
	auto scene = HelloWorld::createScene();
	Director::getInstance()->replaceScene(scene);
}

void SecondScene::onEnter()
{
	Layer::onEnter();

	log("SecondScene :: onEnter");
}
void SecondScene::onEnterTransitionDidFinish()
{
	Layer::onEnterTransitionDidFinish();

	log("SecondScene:: onEnterTransitionDidFinish");
}

void SecondScene::onEnterTransitionDidStart()
{
	SecondScene::onEnterTransitionDidStart();

	log("SecondScene:: onEnterTransitionDidStart");
}

void SecondScene::onExit()
{
	Layer::onExit();

	log("SecondScene :: onExit");
}

SecondScene::~SecondScene()
{
	log("SecondScene :: dealloc");
}