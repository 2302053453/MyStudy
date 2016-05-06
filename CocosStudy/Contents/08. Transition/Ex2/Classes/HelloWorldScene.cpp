#include "HelloWorldScene.h"
#include "SecondScene.h"

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
    
	auto item1 = MenuItemFont::create(
		"pushScene",
		CC_CALLBACK_1(HelloWorld::doChangeScene, this));
	item1->setColor(Color3B::BLACK);

	// 메뉴 생성
	auto menu = Menu::create(item1, nullptr);

	// 레이어에 메뉴 추가
	addChild(menu);
    
	log("HelloWorld :: Init");

    return true;
}

void HelloWorld::doChangeScene(Ref* sender)
{
	// 두 번째 장면
	auto scene = SecondScene::createScene();
	Director::getInstance()->replaceScene(scene);
}

void HelloWorld::onEnter()
{
	Layer::onEnter();

	log("HelloWorld :: onEnter");
}
void HelloWorld::onEnterTransitionDidFinish()
{
	Layer::onEnterTransitionDidFinish();

	log("HelloWorld:: onEnterTransitionDidFinish");
}

void HelloWorld::onEnterTransitionDidStart()
{
	HelloWorld::onEnterTransitionDidStart();

	log("HelloWorld:: onEnterTransitionDidStart");
}

void HelloWorld::onExit()
{
	Layer::onExit();

	log("HelloWorld :: onExit");
}

// 다른화면을 호출한후 소멸자를 호출한다.(메모리 주의 할 것)
HelloWorld::~HelloWorld()
{
	log("HelloWorld :: dealloc");
}