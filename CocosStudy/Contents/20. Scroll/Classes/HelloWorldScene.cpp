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
    
	auto sprite1 = Sprite::create("HelloWorld.png");
	auto sprite2 = Sprite::create("HelloWorld.png");

	sprite1->setScale(0.4f);
	sprite2->setScale(0.4f);

	sprite1->setPosition(Vec2(100, 80));
	sprite2->setPosition(Vec2(850, 80));

	// 스크롤 뷰를 구분해서 보여주기 위한 layer
	auto layer = LayerColor::create(Color4B(255,0,255,255));
	layer->setAnchorPoint(Vec2::ZERO);
	layer->setPosition(Vec2(0, 0));
	layer->setContentSize(Size(960., 160));

	layer->addChild(sprite1);
	layer->addChild(sprite2);

	// CCScrollView
	scrollView = ScrollView::create();
	scrollView->retain();
	scrollView->setDirection(ScrollView::Direction::HORIZONTAL);
	scrollView->setContentSize(layer->getContentSize());
	scrollView->setPosition(Vec2(0, 100));
	scrollView->setContentOffset(Vec2::ZERO,false);
	scrollView->setContainer(layer);
	scrollView->setDelegate(this);

	this->addChild(scrollView);
    return true;
}

void HelloWorld::scrollViewDidScroll(ScrollView* view) 
{
	log("scrollViewDidScroll..");
}

void HelloWorld::scrollViewDidZoom(ScrollView* view) 
{
	log("scrollViewDidZoom..");
}
