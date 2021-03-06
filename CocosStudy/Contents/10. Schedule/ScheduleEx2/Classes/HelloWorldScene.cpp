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
    
	///////////////////////////////////
	
	// umscheduleSelecters
	// pauseSchedulerAndActions
	// resumeSchedulerAndActions
	// stopAllActions

	// 메뉴 아이템 생성 및 초기화
	auto item1 = MenuItemFont::create(
		"start",
	CC_CALLBACK_1(HelloWorld::doStart, this));
	item1->setColor(Color3B::BLACK);

	auto item2 = MenuItemFont::create(
		"pause",
		CC_CALLBACK_1(HelloWorld::doPause, this));
	item2->setColor(Color3B::BLACK);

	auto item3 = MenuItemFont::create(
		"resume",
		CC_CALLBACK_1(HelloWorld::doResume, this));
	item3->setColor(Color3B::BLACK);

	auto item4 = MenuItemFont::create(
		"change",
		CC_CALLBACK_1(HelloWorld::doChange, this));
	item4->setColor(Color3B::BLACK);

	auto item5 = MenuItemFont::create(
		"stop",
		CC_CALLBACK_1(HelloWorld::doStop, this));
	item5->setColor(Color3B::BLACK);

	// 메뉴 생성
	auto menu = Menu::create(item1, item2, item3, item4, item5, nullptr);

	// 세로로 정렬
	menu->alignItemsVertically();

	// 레이어에 메뉴 객체 추가
	this->addChild(menu);
	isChange = false;
    
    return true;
}

void HelloWorld::doStart(Ref* sender)
{
	this->schedule(schedule_selector(HelloWorld::tick1), 1.0f);
	this->schedule(schedule_selector(HelloWorld::tick2), 2.0f);
}

void HelloWorld::doPause(Ref* sender)
{
	Director::getInstance()->getScheduler()->pauseTarget(this);
}
void HelloWorld::doResume(Ref* sender)
{
	Director::getInstance()->getScheduler()->resumeTarget(this);
}

void HelloWorld::doChange(Ref* sender)
{
	if (isChange)
	{
		isChange = false;
		this->unschedule(schedule_selector(HelloWorld::tick2));
		this->schedule(schedule_selector(HelloWorld::tick2), 2.0f);
	}
	else
	{
		isChange = true;
		this->unschedule(schedule_selector(HelloWorld::tick2));
		this->schedule(schedule_selector(HelloWorld::tick2), 3.0f);
	}
}

void HelloWorld::doStop(Ref* sender)
{
	this->unschedule(schedule_selector(HelloWorld::tick1));
	this->unschedule(schedule_selector(HelloWorld::tick2));
}
void HelloWorld::tick1(float f)
{
	log("tick1");
}
void HelloWorld::tick2(float f)
{
	log("tick2");
}