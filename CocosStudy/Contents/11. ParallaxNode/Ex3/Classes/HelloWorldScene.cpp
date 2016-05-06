﻿#include "HelloWorldScene.h"

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
    
	// 배경을 만든다.
	this->createBackgroundParallax();

	// 드래곤을 만든다.
	this->createDragon();

    return true;
}

void HelloWorld::createBackgroundParallax()
{
	// 배경 layer1
	auto background1 = Sprite::create("Images/background1.png");
	background1->setAnchorPoint(Vec2(0, 0));

	// 배경 layer2
	auto background2 = Sprite::create("Images/background2.png");
	background2->setAnchorPoint(Vec2(0, 0));

	// 이미지가 만나는 가장자리(edge)에 검은 선이 생기는 현상을 방지하기 위해
	// 안티엘리어싱(Anti-Aliasing)을 비활성화 한다.
	background1->getTexture()->setAliasTexParameters();
	background2->getTexture()->setAliasTexParameters();

	// 위에서 만든 스프라이트를 담을 부모로 페럴렉스노드를 만든다.
	auto voidNode = ParallaxNode::create();
	voidNode->addChild(background1, 1, Vec2(1, 0), Vec2(0, 0));
	voidNode->addChild(background2, 1, Vec2(1, 0), Vec2(512, 0));

	// 무한반복하는 액션을 만든다.
	auto go = MoveBy::create(4, Vec2(-512, 0));
	auto goBack = go->reverse();
	auto seq = Sequence::create(go, goBack, nullptr);
	auto act = RepeatForever::create(seq);

	voidNode->runAction(act);

	this->addChild(voidNode,0);
}

void HelloWorld::createDragon()
{
	auto texture = Director::getInstance()->getTextureCache()->addImage("Images/dragon_animation.png");

	auto animation = Animation::create();
	animation->setDelayPerUnit(0.1f);

	for (int i = 0; i < 6; ++i)
	{
		// 첫째줄에 4개의 프레임이 있고, 5분쩌부터는 두번째줄에 있으므로
		// 5번째(idx==4)부터는 y좌표의 값을 증가시켜야 한다.
		int idx = i % 4;
		int rowidx = i / 4;

		animation->addSpriteFrameWithTexture(texture, Rect(idx * 130, rowidx * 140, 130, 140));
	}

	// 스프라이트 생성 및 초기화
	auto dragon = Sprite::createWithTexture(texture, Rect(0, 0, 130, 140));
	dragon->setPosition(Vec2(240, 160));
	this->addChild(dragon);

	auto animate = Animate::create(animation);
	auto rep = RepeatForever::create(animate);

	dragon->runAction(rep);
}