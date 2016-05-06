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
    
	// Sprite의 색 지정은 그림이 흰색이거나 밝은색이어야 효과가 나타난다.
	auto parent = Sprite::create("Images/texture512x512.png");

	parent->setTextureRect(Rect(0, 0, 150, 150));

	parent->setPosition(Vec2(240, 160));

	parent->setColor(Color3B::BLUE);

	this->addChild(parent);



	// 부모 sprite에 자식 sprite추가
	// 자식의 좌표는 부모를 기준으로 정해진다
	auto child = Sprite::create("Images/texture512x512.png");

	child->setTextureRect(Rect(0, 0, 50, 5));

	// position(0,0) => 부모의 size를 구하고 이를 바탕으로 위치 지정
	auto parentSize = parent->getContentSize();
	child->setPosition(Vec2(parentSize.width/2, parentSize.height+10));

	child->setColor(Color3B::RED);

	parent->addChild(child);
    
    return true;
}

