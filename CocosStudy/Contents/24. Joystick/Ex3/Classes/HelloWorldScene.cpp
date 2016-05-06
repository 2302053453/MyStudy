#include "HelloWorldScene.h"
#include "Joystick/ControlManager.h"

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
    
	////////////////////////////////////

	// 스프라이트 추가
	man = Sprite::create("Images/grossini.png");
	man->setPosition(Vec2(240, 160));
	this->addChild(man);

	// 터치 이벤트 등록
	auto listener = EventListenerTouchAllAtOnce::create();

	listener->onTouchesBegan = CC_CALLBACK_2(HelloWorld::onTouchesBegan, this);
	listener->onTouchesMoved = CC_CALLBACK_2(HelloWorld::onTouchesMoved, this);
	listener->onTouchesEnded = CC_CALLBACK_2(HelloWorld::onTouchesEnded, this);
    
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
    
	// 조이스틱 초기화
	JControlManager::getInstance();
	JControlManager::getInstance()->Initialize(this);

	// 스케줄러 등록
	schedule(schedule_selector(HelloWorld::Tick));
	
	return true;

	
}


void HelloWorld::Tick(float t)
{
	JControlManager::getInstance()->Update(t);
	
	if (JControlManager::getInstance()->GetDistance() == 0.f)
	{

	}
	else
	{
		float distance = JControlManager::getInstance()->GetDistance() * 0.5f + 0.5f;
		float speed = distance * 100.0f * t;
		Vec2 axis = JControlManager::getInstance()->GetAxis();
		auto velocity_ = axis * speed;

		man->setPosition(man->getPosition() + velocity_);

		if (axis.x < 0)
		{ }
		else if (axis.x > 0)
		{ }
	}
}


void HelloWorld::onTouchesBegan(const std::vector<cocos2d::Touch*>& touches, cocos2d::Event * event)
{
	Vec2 point;
	Vec2 touchGlPoint;

	for (auto item : touches)
	{
		auto touch = item;
		point = touch->getLocation();
		touchGlPoint = Director::getInstance()->convertToGL(point);

		for (int a = 0; a < MAX_BUTTON; ++a)
		{
			if (JControlManager::getInstance()->IsButtonContainsPoint((eButtonID)a, touchGlPoint))
			{
				JControlManager::getInstance()->btnTouchID_[a] = touch;
				JControlManager::getInstance()->btnState_[a] = BEGIN;
				JControlManager::getInstance()->btnTouchPoint_[a] = touchGlPoint;
			}
		}
	}
	JControlManager::getInstance()->SetTouchState(BEGIN);
	JControlManager::getInstance()->SetTouchPoint(touchGlPoint);
}

void HelloWorld::onTouchesMoved(const std::vector<cocos2d::Touch*>& touches, cocos2d::Event * event)
{
	Vec2 point;
	Vec2 touchGlPoint;

	for (auto item : touches)
	{
		auto touch = item;
		point = touch->getLocation();
		touchGlPoint = Director::getInstance()->convertToGL(point);

		for (int a = 0; a < MAX_BUTTON; ++a)
		{
			if (touch == JControlManager::getInstance()->btnTouchID_[a])
			{
				JControlManager::getInstance()->btnState_[a] = MOVE;
				JControlManager::getInstance()->btnTouchPoint_[a] = touchGlPoint;
			}
		}
	}
	JControlManager::getInstance()->SetTouchState(MOVE);
	JControlManager::getInstance()->SetTouchPoint(touchGlPoint);
}


void HelloWorld::onTouchesEnded(const std::vector<cocos2d::Touch*>& touches, cocos2d::Event * event)
{
	Vec2 point;
	Vec2 touchGlPoint;

	for (auto item : touches)
	{
		auto touch = item;
		point = touch->getLocation();
		touchGlPoint = Director::getInstance()->convertToGL(point);

		for (int a = 0; a < MAX_BUTTON; ++a)
		{
			if (touch == JControlManager::getInstance()->btnTouchID_[a])
			{
				JControlManager::getInstance()->btnState_[a] = END;
				JControlManager::getInstance()->btnTouchPoint_[a] = touchGlPoint;
			}
		}
	}
	JControlManager::getInstance()->SetTouchState(END);
	JControlManager::getInstance()->SetTouchPoint(touchGlPoint);
}




