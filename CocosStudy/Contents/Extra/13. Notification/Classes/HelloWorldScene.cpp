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
    
	// 메뉴 아이템 생성 및 초기화
	auto menuItem = MenuItemFont::create(
		"팝업창 띄우기",
		CC_CALLBACK_1(HelloWorld::doPopup, this));
	menuItem->setColor(Color3B::BLACK);

	//  메뉴 생성
	auto menu = Menu::create(menuItem, nullptr);

	// 메뉴 위치 지정
	menu->setPosition(Vec2(240, 40));

	// layer에 메뉴 객체 추가
	this->addChild(menu);

	// notification receiver 등록
	NotificationCenter::getInstance()->addObserver(
		this,
		callfuncO_selector(HelloWorld::doMsgReceived),
		"TouchStatus",
		NULL);

    
    return true;
}

void HelloWorld::doPopup(Ref* obj)
{
	Scene* popWin;
	popWin = SecondScene::createScene();
	this->addChild(popWin, 2000, 2000);
}

void HelloWorld::doMsgReceived(Ref* obj)
{
	char* inputStr = (char*)obj;
	char testText[20];
	sprintf(testText, "%s", inputStr);

	log("[%s] 메세지 도착", testText);

}
