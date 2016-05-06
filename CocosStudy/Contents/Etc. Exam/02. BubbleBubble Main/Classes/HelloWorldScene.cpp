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
   
	// 배경
	auto backGround = Sprite::create("Images//Main/Background/Background.png");
	backGround->setAnchorPoint(Vec2(0, 0));

	// star
	auto leftStar = Sprite::create("Images/Main/Background_Effect/Blue_Star.png");
	leftStar->setPosition(100, 170);
	auto centerStar = Sprite::create("Images/Main/Background_Effect/Gold_Star.png");
	centerStar->setPosition(350, 50);
	auto rightStar = Sprite::create("Images/Main/Background_Effect/Purple_Star.png");
	rightStar->setPosition(580, 100);
	
	// Bubble 
	auto frontBubble = Sprite::create("Images/Main/Bubble_Effect/Title_Bubble_002.png");
	frontBubble->setAnchorPoint(Vec2(0, 0));
	auto backBubble1 = Sprite::create("Images/Main/Bubble_Effect/Title_Bubble_001.png");
	backBubble1->setAnchorPoint(Vec2(0, 0));
	auto backBubble2 = Sprite::create("Images/Main/Bubble_Effect/Title_Bubble_003.png");
	backBubble2->setAnchorPoint(Vec2(0, 0));
	auto backBubble3 = Sprite::create("Images/Main/Bubble_Effect/Title_Bubble_004.png");
	backBubble3->setAnchorPoint(Vec2(0, 0));

	// fish
	auto leftFish = Sprite::create("Images/Main/Fish_Effect/Fish_001.png");
	leftFish->setPosition(0, 480);
	auto leftDownFish = Sprite::create("Images/Main/Fish_Effect/Fish_001.png");
	leftDownFish->setPosition(0, 100);
	auto rightFish = Sprite::create("Images/Main/Fish_Effect/Fish_002.png");
	rightFish->setPosition(480, 480);
	
	// sunlight
	auto upLight = Sprite::create("Images/Main/Bubble_Effect/Lighting_Background.png");
	upLight->setPosition(Vec2(300, 850));
	auto allLight = Sprite::create("Images/Main/Flash_Effect/All_Light.png");
	allLight->setAnchorPoint(Vec2(0, 0));
	auto upRightLight = Sprite::create("Images/Main/Flash_Effect/Flash_003.png");
	upRightLight->setPosition(Vec2(400, 850));

	// TITLE
	Sprite *flashTitle = Sprite::create("Images/Main/Logo/Logo_Light.png");
	Sprite *title = Sprite::create("Images/Main/Logo/Bubble_Logo.png");
	title->setPosition(Vec2(300, 650));
	flashTitle->setPosition(Vec2(280, 140));
	title->addChild(flashTitle, -1);

	// PLAY, CONNECT BUTTON
	auto btnPlay = MenuItemImage::create(
		"Images/Main/Bubble_Button/Play_Button/Play_Button_01.png",
		"Images/Main/Bubble_Button/Play_Button/Play_Button_02.png",
		CC_CALLBACK_1(HelloWorld::OnClick,this));
	auto btnConntection = MenuItemImage::create(
		"Images/Main/Bubble_Button/Setting_Button/Vibration_ON.png",
		"Images/Main/Bubble_Button/Setting_Button/Vibration_OFF.png",
		CC_CALLBACK_1(HelloWorld::OnClick, this));
	auto outerPlayAndConn = Sprite::create("Images/Main/Bubble_Button/Base.png");
	outerPlayAndConn->setPosition(320, 275);

	// SETTING BUTTON
	auto btnSetting = MenuItemImage::create("Images/Main/Bubble_Button/Create_Button/Create_Button_01.png",
		"Images/Main/Bubble_Button/Create_Button/Create_Button_02.png",
		CC_CALLBACK_1(HelloWorld::OnClick, this));
	auto outerSetting = Sprite::create("Images/Main/Bubble_Button/Create_Button/Create_base.png");
	outerSetting->setAnchorPoint(Vec2(-6.85, 0));

	// Menu
	auto menu = Menu::create(btnPlay, btnConntection, btnSetting, nullptr);
	btnPlay->setPosition(-30, -180);
	btnConntection->setPosition(105, -305);
	btnSetting->setPosition(275, -440);

	// button 동작정의
	auto seqInBtn = Sequence::create(FadeIn::create(1.0f), DelayTime::create(1.0f), FadeOut::create(1.0f), nullptr);
	auto refeatBtn = RepeatForever::create(seqInBtn);
	outerPlayAndConn->runAction(refeatBtn->clone());
	outerSetting->runAction(refeatBtn->clone());
	
	// star 동작정의
	auto seqInStar = RotateBy::create(2.0f, 360);
	auto refeatStar = RepeatForever::create(seqInStar);
	leftStar->runAction(refeatStar->clone());
	centerStar->runAction(refeatStar->clone());
	rightStar->runAction(refeatStar->clone());

	// title 동작 정의
	auto seqInTitle = Sequence::create(
		MoveBy::create(2, Vec2(0, 30)),
		MoveBy::create(2, Vec2(0, -30)),
		nullptr);
	auto refeatTitle = RepeatForever::create(seqInTitle);
	title->runAction(refeatTitle);

	auto seqInFlashTitle = Sequence::create(
		FadeIn::create(2.0f), FadeOut::create(2.0f), nullptr);
	auto refeatFlashTitle = RepeatForever::create(seqInFlashTitle);
	flashTitle->runAction(refeatFlashTitle);

	// bubble 동작정의
	auto seqInfrontBubble = Sequence::create(
		Place::create(Vec2(0, -960)),
		MoveTo::create(2, Vec2(0, 960)),
		nullptr);
	auto refeatFrontBubble = RepeatForever::create(seqInfrontBubble);
	frontBubble->runAction(refeatFrontBubble);

	auto seqInbackBubble = Sequence::create(
		Place::create(Vec2(0, -960)),
		DelayTime::create(1.0f),
		MoveTo::create(4, Vec2(0, 960)),
		nullptr);
	auto refeatBackBubble = RepeatForever::create(seqInbackBubble);
	backBubble3->runAction(refeatBackBubble);

	auto seqInbackSlowBubble1 = Sequence::create(
		Place::create(Vec2(0, -960)),
		DelayTime::create(1.0f),
		MoveTo::create(6, Vec2(0, 960)),
		DelayTime::create(8.0f),
		nullptr);
	auto refeatBackSlowBubble1 = RepeatForever::create(seqInbackSlowBubble1);
	backBubble1->runAction(refeatBackSlowBubble1);

	auto seqInbackSlowBubble2 = Sequence::create(
		Place::create(Vec2(0, -960)),
		DelayTime::create(8.0f),
		MoveTo::create(6, Vec2(0, 960)),	
		nullptr);
	auto refeatBackSlowBubble2 = RepeatForever::create(seqInbackSlowBubble2);
	backBubble2->runAction(seqInbackSlowBubble2);

	// fish 동작정의
	auto seqInLeftFish = Sequence::create(
		Place::create(Vec2(-100, 480)),
		DelayTime::create(2.0f),
		MoveTo::create(6, Vec2(720, 480)),
		nullptr);
	auto refeatLeftFish = RepeatForever::create(seqInLeftFish);
	leftFish->runAction(refeatLeftFish);

	auto seqInLeftDownFish = Sequence::create(
		Place::create(Vec2(-100, 100)),
		DelayTime::create(2.0f),
		MoveTo::create(6, Vec2(720, 100)),
		nullptr);
	auto refeatDownLeftFish = RepeatForever::create(seqInLeftDownFish);
	leftDownFish->runAction(refeatDownLeftFish);

	auto seqInRightFish = Sequence::create(
		Place::create(Vec2(800, 480)),
		DelayTime::create(2.0f),
		MoveTo::create(4, Vec2(-100, 480)),
		nullptr);
	auto refeatRightFish = RepeatForever::create(seqInRightFish);
	rightFish->runAction(refeatRightFish);

	// light 동작 정의
	auto seqInUpLight = Sequence::create( FadeIn::create(2.0f), FadeOut::create(2.0f), nullptr);
	auto refeatUpLight = RepeatForever::create(seqInUpLight);
	upLight->runAction(refeatUpLight);

	auto seqInAllLight = Sequence::create(FadeIn::create(4.0f), FadeOut::create(4.0f), nullptr);
	auto refeatAllLight = RepeatForever::create(seqInAllLight);
	allLight->runAction(refeatAllLight);

	auto seqInUpRightLight = Sequence::create(FadeIn::create(1.0f), FadeOut::create(1.0f), nullptr);
	auto refeatUpRightLight = RepeatForever::create(seqInUpRightLight);
	upRightLight->runAction(refeatUpRightLight);


	this->addChild(backGround);
	this->addChild(leftFish);
	this->addChild(leftDownFish);
	this->addChild(rightFish);
	this->addChild(leftStar);
	this->addChild(centerStar);
	this->addChild(rightStar);
	this->addChild(frontBubble);
	this->addChild(backBubble1);
	this->addChild(backBubble2);
	this->addChild(backBubble3);
	this->addChild(allLight);
	this->addChild(upLight);
	this->addChild(upRightLight);
	this->addChild(title);
	this->addChild(outerPlayAndConn);
	this->addChild(outerSetting);
	this->addChild(menu);
	

    return true;
}

void HelloWorld::OnClick(Ref* sender)
{

}