#include "HelloWorldScene.h"
/*
	2016-03-21
	label 예제 (기초)
	기본적으로 생성(create) -> 위치지정(setPosition) -> 화면에 추가(addChild) 
	이순으로 진행해야 화면에 보이게 된다.
*/
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
    
	// label 생성 및 초기화 1
	// TTF  =ture type font, 실제 게임에서는 채팅외에는 쓰이지 않는다.(폰트 기본크기가 크다)
	//auto label1 = LabelTTF::create("Hello World", "Arial", 64);
	auto label1 = LabelTTF::create("동해물과 백두산이 마르고 닮도록 하느님이 보우하사 우리나라만세 무궁화 삼천리 화려강산", "Arial", 32, Size(300, 200), TextHAlignment::CENTER, TextVAlignment::CENTER);

	// label 위치 지정
	label1->setPosition(Vec2(240, 160));

	// label 색 지정
	label1->setColor(Color3B::BLACK);	// 255,0,0

	// label 투명도 지정
	label1->setOpacity(100.0);

	// layer에 label 객체 추가
	this->addChild(label1);
    
    return true;
}

