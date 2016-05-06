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
    

	// 메뉴 아이템 생성 및 초기화(MenuItemFont)
	auto menuItem1 = MenuItemFont::create(
		"Menu-1",
		CC_CALLBACK_1(HelloWorld::OnClick, this));
	menuItem1->setColor(Color3B::BLACK);
	auto menuItem2 = MenuItemFont::create(
		"Menu-2",
		CC_CALLBACK_1(HelloWorld::OnClick, this));
	menuItem2->setColor(Color3B::BLUE);

	menuItem1->setTag(1);
	menuItem2->setTag(2);

	// 메뉴 생성
	auto menu = Menu::create(menuItem1, menuItem2, nullptr);


	// 메뉴 배치
	menu->alignItemsHorizontally();

	this->addChild(menu);

    
    return true;
}



void HelloWorld::OnClick(Ref* sender)
{
	auto item = (MenuItem*)sender;


	if ((item->getTag()) == 1)
	{
		auto man = Sprite::create("Images/grossini.png");
		man->setPosition(Vec2(100, 160));
		man->setTag(11);
		this->addChild(man);
	}
	else
	{
		auto man = (Sprite*)getChildByTag(11);
		this->removeChild(man, true);

	}

	//switch(item->getTag())
	//{ 
	//	case 1:
	//	{
	//		auto man = Sprite::create("Images/grossini.png");
	//		man->setPosition(Vec2(100, 160));
	//		man->setTag(11);
	//		this->addChild(man);
	//		break;
	//	}
	//	case 2:
	//	{
	//		auto man = (Sprite*)getChildByTag(11);
	//		this->removeChild(man, true);
	//		break;
	//	}
	//}

}
