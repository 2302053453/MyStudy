#include "SecondScene.h"
#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h" // 추가

USING_NS_CC;

using namespace cocos2d;
using namespace CocosDenshion; // 추가

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
	if (!LayerColor::initWithColor(Color4B::GREEN))
	{
		return false;
	}

	auto item1 = MenuItemFont::create(
		"play background music",
		CC_CALLBACK_1(SecondScene::doPlayMusic, this));
	item1->setColor(Color3B::BLACK);

	auto item2 = MenuItemFont::create(
		"Close Scene 2",
		CC_CALLBACK_1(SecondScene::doClose, this));
	item1->setColor(Color3B::BLACK);

	auto cache = SpriteFrameCache::getInstance();

	auto man = Sprite::createWithSpriteFrameName("grossini_dance_01.png");
	man->setPosition(Vec2(240, 220));
	this->addChild(man);

	// 메뉴 생성
	auto menu = Menu::create(item1,item2, nullptr);

	menu->alignItemsVertically();

	// 레이어에 메뉴 추가
	addChild(menu);

	log("SecondScene :: Init");

	return true;
}

void SecondScene::doClose(Ref* sender)
{
	// 두 번째 장면
	auto scene = HelloWorld::createScene();
	Director::getInstance()->replaceScene(scene);
}

// 앞에서 미리 메모리에 올려두었으므로 기존 play보다 더 빠르게 실행된다.
void SecondScene::doPlayMusic(Ref* sender)
{
	SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
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