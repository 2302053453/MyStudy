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
    
	auto man = Sprite::create("Images/grossini.png");
	man->setPosition(Vec2(50, 160));
	this->addChild(man);

	auto r1 = Sprite::create("Images/r1.png");
	r1->setPosition(Vec2(25, 160));
	this->addChild(r1);

	auto r2 = Sprite::create("Images/r1.png");
	r2->setPosition(Vec2(960-25, 160));
	this->addChild(r2);

	auto move = MoveBy::create(2, Vec2(480 * 2 - 100, 0));
	auto move_back = move->reverse();
	auto seq = Sequence::create(move, move_back, nullptr);
	auto rep = RepeatForever::create(seq);

	man->runAction(rep);

	// Follow : action의 주체로 카메라가 따라간다.
	this->runAction(Follow::create(man, Rect(0, 0, 480 * 2, 320)));

    return true;
}

