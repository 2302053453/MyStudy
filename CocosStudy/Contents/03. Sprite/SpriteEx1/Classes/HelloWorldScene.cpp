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
    
	// 스프라이트 생성 및 초기화
	auto man = Sprite::create("Images/grossini.png");

	// 스프라이트 위치 지정
	man->setPosition(Vec2(320, 160));

	//Layer에 스프라이트 추가+ordering
	this->addChild(man,2);	// 위치지정 : 2층

	// 스프라이트 생성 및 초기화
	auto woman = Sprite::create("Images/grossinis_sister1.png");

	// 스프라이트 위치 지정
	woman->setPosition(Vec2(300, 160));

	//Layer에 스프라이트 추가+ordering
	//this->addChild(woman,1);// 위치지정 : 1층

	// addChild()후에 스프라이트 위치 지정 (동적 지정)
	this->addChild(woman);
	woman->setLocalZOrder(1);
	
	/*
		addChild()시에 순서를 ordeing 하지 않으면
		insert한 순으로 밑에 깔리게 된다. 이 순서를 바꾸고싶으면 
		insert순서를 바꾸거나 ordering을 해야한다.
	*/

    return true;
}

