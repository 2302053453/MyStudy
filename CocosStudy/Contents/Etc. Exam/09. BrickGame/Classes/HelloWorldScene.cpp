#include "HelloWorldScene.h"

// 매크로 정의 추가
#define FIX_POS(_pos, _min, _max)	\
	if (_pos < _min)				\
		_pos = _min;				\
	else if (_pos >_max)			\
		_pos = _max;				\

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
    if ( !LayerColor::initWithColor(Color4B::BLACK) )
    {
        return false;
    }
  
	srand((int)time(NULL));

	// 터치 활성화 : 앞의 예제들 처럼 onEnter, onExit에서 처리

	// 벽돌 갯수 지정
	BRICKS_WIDTH = 5;
	BRICKS_HEIGHT = 4;

	// 벽돌에 사용할 텍스쳐 로딩
	texture = Director::getInstance()->getTextureCache()->addImage("Images/white-512x512.png");

	// 벽돌 초기화
	this->initializeBricks();

	// 공 초기화
	this->initializeBall();
	
	// Paddle 초기화
	this->initializePaddle();
	
	// 2초후 게임 시작
	this->scheduleOnce(schedule_selector(HelloWorld::startGame), 2.0f);

    return true;
}

void HelloWorld::initializeBricks() 
{
	int count = 0;

	for (int y = 0; y < BRICKS_HEIGHT; ++y)
	{
		for (int x = 0; x < BRICKS_WIDTH; ++x)
		{
			Sprite* bricks = Sprite::createWithTexture(texture, Rect(0, 0, 64, 40));

			// 색 지정
			switch (count++ %4)
			{
			case 0:
				bricks->setColor(Color3B::WHITE);
				break;
			case 1:
				bricks->setColor(Color3B::RED);
				break;
			case 2:
				bricks->setColor(Color3B::YELLOW);
				break;
			case 3:
				bricks->setColor(Color3B(5, 255, 0));
				break;
			default:
				break;
			}

			// 좌표 지정
			bricks->setPosition(Vec2(x * 64 + 32, (y * 48) + 280));

			// 화면에 추가
			this->addChild(bricks);

			// Vector에 추가
			targets.pushBack(bricks);

		}
	}
}

void HelloWorld::initializeBall() 
{
	ball = Sprite::createWithTexture(texture, Rect(0, 0, 16, 16));

	ball->setColor(Color3B(0, 255, 255));
	ball->setPosition(Vec2(160, 240));
	this->addChild(ball);
}

void HelloWorld::initializePaddle() 
{
	paddle = Sprite::createWithTexture(texture, Rect(0, 0, 80, 10));
	paddle->setColor(Color3B::YELLOW);
	paddle->setPosition(Vec2(160, 50));
	this->addChild(paddle);
}

void HelloWorld::startGame(float dt)
{
	ball->setPosition(Vec2(160, 240));
	ballMovement = Vec2(4, 4);
	if (rand() % 100 < 50)
	{
		ballMovement.x = -ballMovement.x;
	}
	ballMovement.y = -ballMovement.y;

	isPlaying = true;

	this->schedule(schedule_selector(HelloWorld::gameLogic), 2.0f / 60.0f);
}

void HelloWorld::gameLogic(float dt)
{
	// ballMovement.y가 음수이면 볼이 내려오고 있는 것
	// ballMovement.y가 양수이면 볼이 올라가고 있는 것
	// log("tick...%f",ballmovement.y);

	// 볼의 현재 위치
	ball->setPosition(
		Vec2(ball->getPosition().x + ballMovement.x,
		ball->getPosition().y + ballMovement.y));

	// 볼과 Paddle 충돌 여부
	bool paddleCollision =
		ball->getPosition().y <= paddle->getPosition().y + 13 &&
		ball->getPosition().x >= paddle->getPosition().x - 48 &&
		ball->getPosition().x <= paddle->getPosition().x + 48;

	// Paddle과 충돌 시 처리
	if (paddleCollision)
	{
		if (ball->getPosition().y <= paddle->getPosition().y + 13 && ballMovement.y < 0)
			ball->setPosition(Vec2(ball->getPosition().x, ball->getPosition().y + 13));

		// 내려오던 것을 위로 올라가도록 공의 상하 진행 방향 바꾸기
		ballMovement.y	= -ballMovement.y;
	}

	// 블록과 충돌 파악
	bool there_are_solid_bricks = false;

	for (auto item : targets)
	{
		Sprite* brick = item;
		if (255 == brick->getOpacity())
		{
			there_are_solid_bricks = true;

			Rect rectA = ball->getBoundingBox();
			Rect rectB = brick->getBoundingBox();
			
			// 블록과 충돌 처리
			if (rectA.intersectsRect(rectB))
				this->processCollision(brick);
		}
	}

	// 블록이 없을 때 - 게임 종료 상태
	if (!there_are_solid_bricks)
	{
		isPlaying = false;
		ball->setOpacity(0);

		// 모든 스케줄 제거
		this->unscheduleAllSelectors();

		log("You Win !!");

		// 게임에 이겼다. 새로운 대기 화면
		// 이후 구현
	}

	// 벽면 충돌 체크
	if (ball->getPosition().x > 312 || ball->getPosition().x < 8)
		ballMovement.x = -ballMovement.x;

	if (ball->getPosition().y > 450)
		ballMovement.y = -ballMovement.y;

	// Paddle을 빠져 나갈 때
	if (ball->getPosition().y < (50 + 5 + 8))
	{
		isPlaying = false;
		ball->setOpacity(0);

		// 모든 스케줄 제거
		this->unscheduleAllSelectors();

		log("You lose...");

		// 게임에서 졌다. 새로운 게임 대기 화면은
		// 이후 구현
	}
}

void HelloWorld::processCollision(Sprite* brick) 
{
	Vec2 brickPos = brick->getPosition();
	Vec2 ballPos = ball->getPosition();

	if (ballMovement.x > 0 && brick->getPosition().x < ball->getPosition().x)
		ballMovement.x = -ballMovement.x;
	else if (ballMovement.x < 0 && brick->getPosition().x < ball->getPosition().x)
		ballMovement.x = -ballMovement.x;

	if (ballMovement.y > 0 && brick->getPosition().y > ball->getPosition().y)
			ballMovement.y = -ballMovement.y;
	else if (ballMovement.y < 0 && brick->getPosition().y < ball->getPosition().y)
			ballMovement.y = -ballMovement.y;

	brick->setOpacity(0);
}

void HelloWorld::onEnter()
{
	Layer::onEnter();

	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = CC_CALLBACK_2(HelloWorld::onTouchBegan, this);
	listener->onTouchMoved = CC_CALLBACK_2(HelloWorld::onTouchMoved, this);

	Device::setAccelerometerEnabled(true);

	auto listener2 = EventListenerAcceleration::create(	CC_CALLBACK_2(HelloWorld::onAcceleration, this));

	
	/*_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener2, this);*/

	_eventDispatcher->addEventListenerWithFixedPriority(listener2, 2);
	_eventDispatcher->addEventListenerWithFixedPriority(listener, 1);
}

void HelloWorld::onExit() 
{
	_eventDispatcher->removeEventListenersForType(EventListener::Type::TOUCH_ONE_BY_ONE);
	_eventDispatcher->removeEventListenersForType(EventListener::Type::ACCELERATION);
	Layer::onExit();
}

bool HelloWorld::onTouchBegan(Touch* touch, Event* event)
{
	if (!isPlaying)
		return true;

	// 하나의 터치이벤트만 가져온다.
	auto touchPoint = touch->getLocation();

	// Paddle을 터치했는지 체크한다.
	Rect rect = paddle->getBoundingBox();
	
	// Paddle이 터치되었음을 체크
	if (rect.containsPoint(touchPoint))
		isPaddleTouched = true;
	else
		isPaddleTouched = false;

	return true;
}

void HelloWorld::onTouchMoved(Touch* touch, Event* event)
{
	if (isPaddleTouched)
	{
		auto touchPoint = touch->getLocation();

		// Paddle이 좌우로만 움직이게 y값은 바뀌지 않는다.
		// 또한 paddle이 화면 밖으로 나가지 않게 한다.

		if (touchPoint.x < 40)
			touchPoint.x = 40;
		if(touchPoint.x > 280)
			touchPoint.x = 280;

		Vec2 newLocation = Vec2(touchPoint.x, paddle->getPosition().y);
		paddle->setPosition(newLocation);
	}
}

void HelloWorld::onAcceleration(cocos2d::Acceleration* acc, cocos2d::Event* event)
{
	auto pDir = Director::getInstance();

	// 윈도우 사이즈 구하기
	auto winSize = pDir->getVisibleSize();

	// FIXME : Testing on the Nexus S somtimes _ball is NULL
	if (paddle == NULL)
		return;

	auto paddleSize = paddle->getContentSize();

	auto ptNow = paddle->getPosition();
	auto ptTemp = pDir->convertToUI(ptNow);

	ptTemp.x += acc->x * 9.81f;

	auto ptNext = pDir->convertToGL(ptTemp);

	FIX_POS(ptNext.x, (paddleSize.width / 2.0), (winSize.width - paddleSize.width / 2.0));

	paddle->setPosition(ptNext);
}

