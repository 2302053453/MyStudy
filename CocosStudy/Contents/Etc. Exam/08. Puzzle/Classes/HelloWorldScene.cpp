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
    if ( !LayerColor::initWithColor(Color4B::BLACK) )
    {
        return false;
    }
    
	// 원본 이미지를 가져온 후 숨긴다.
	auto image = Sprite::create("Images/Puzzle.png");

	image->setAnchorPoint(Vec2(0, 0));
	image->setVisible(false);
	image->setTag(10);
	this->addChild(image,0);

	// 현재 창의 Size를 사용하여 각 퍼즐의 width와 height를 구한다.
	Size winSize = this->getContentSize();
	auto width = (winSize.width -4) /3;
	auto height = (winSize.height-4) /3;

	// 원본이미지를 9개롲 잘라서 cache에 넣는다.
	// spriteFrame에서의 0,0위치 ->RightTop
	// 퍼즐의 갯수 : 3x3 -> 각width와 height를 3으로 나눈다.
	// 각 puzzle에 선이 나타날것을 고려 검은선의 크기(1~2)를 고려하여 구한다.
	auto cache = SpriteFrameCache::getInstance();
	for (int i = 0; i < 9; i++)
	{
		int col = i % 3;
		int row = i / 3;
		auto name = "IMG" + ConvertIntToString(i);
		auto sprite = SpriteFrame::create("Images/Puzzle.png", Rect(col*(height + 2), row *(width + 2), width, height));
		cache->addSpriteFrame(sprite, name);
	}

	// 자른 이미지를 배치
	// view에서의 0,0위치 : LeftDown
	for (int i = 0; i < 9; i++)
	{
		int col =  i % 3;
		int row =  i / 3;
		auto position = Vec2(col*(height + 2), (2 - row) *(width + 2));
		auto name = "IMG" + ConvertIntToString(i);
		auto sprite = Sprite::createWithSpriteFrame(cache->getInstance()->getSpriteFrameByName(name));
		sprite->setAnchorPoint(Vec2(0, 0));
		sprite->setPosition(position);
		sprite->setTag(i);
		this->addChild(sprite,1);

	}
	
	// 조각들을 섞는다
	Suffle();

	// IMG0을 기준으로 
	hideImage = (Sprite*)this->getChildByTag(random(0,8));
	hideImage->setVisible(false);
    return true;
}

void HelloWorld::onEnter()
{
	Layer::onEnter();

	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = CC_CALLBACK_2(HelloWorld::onTouchBegan, this);
	listener->onTouchEnded = CC_CALLBACK_2(HelloWorld::onTouchEnded, this);

	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
}

void HelloWorld::onExit()
{
	_eventDispatcher->removeEventListenersForType(EventListener::Type::TOUCH_ONE_BY_ONE);
	Layer::onExit();
}

bool HelloWorld::onTouchBegan(Touch* touch, Event* event)
{
	auto touchPoint = touch->getLocation();

	// 각 sprite에 touch 했는지 확인
	for (int i = 0; i < 9; i++)
	{
		auto sprite = (Sprite*)this->getChildByTag(i);
		
		if (sprite->boundingBox().containsPoint(touchPoint))
		{
			if (sprite == hideImage)
			{
				return false;
			}
			else
			{ 
				selectImage = sprite;

				// 인접한 위치의 Image가 아닐 경우
				if (!ChecAdjacentImage(hideImage, selectImage))
					return false;
				else
				{
					// Image끼리 자리교체
					Swap(hideImage, selectImage);
					selectImage = NULL;
					return true;
				}
			}
		}
	}
	return true;
}

void HelloWorld::onTouchEnded(Touch* touch,Event* event)
{
	Size winSize = this->getContentSize();
	auto width = (winSize.width - 4) / 3;
	auto height = (winSize.height - 4) / 3;

	for (int i = 0; i < 9; i++)
	{ 
		int col = i % 3;
		int row = i / 3;
		auto position = Vec2(col*(height + 2), (2 - row) *(width + 2));

		// 각 image들의 위치가 초기값이랑 동일한지 확인
		auto sprite = (Sprite*)this->getChildByTag(i);
		if (position != sprite->getPosition())
			return;
	}
	auto image = (Sprite*)this->getChildByTag(10);
	image->setVisible(true);
}

void HelloWorld::Swap(Sprite* sprite1, Sprite* sprite2)
{
	auto temp = sprite1->getPosition();
	sprite1->setPosition(sprite2->getPosition());
	sprite2->setPosition(temp);
}

void HelloWorld::Suffle()
{
	for (int count = 0; count < 100; count++)
	{
		for (int i = 0; i < 9; i++)
		{
			auto sprite1 = (Sprite*)this->getChildByTag(i);
			auto sprite2 = (Sprite*)this->getChildByTag(random(0, 8));
			// random으로 저장한 sprite가 인접한 sprite면 교환
			if (ChecAdjacentImage(sprite1, sprite2))
				Swap(sprite1, sprite2);
		}
	}
}

bool HelloWorld::ChecAdjacentImage(Sprite* sprite1, Sprite* sprite2)
{
	Size winSize = this->getContentSize();
	auto width = (winSize.width - 4) / 3;
	auto height = (winSize.height - 4) / 3;

	auto sprite1Position = sprite1->getPosition();
	auto sprite2ePosition = sprite2->getPosition();

	// X축으로 움직일 경우, Y축은 전후 위치가 동일
	auto moveX = abs(sprite1Position.x - sprite2ePosition.x) <= width + 2 && sprite1Position.y == sprite2ePosition.y;

	// Y축으로 움직일 경우, X축은 전후 위치가 동일
	auto moveY = abs(sprite1Position.y - sprite2ePosition.y) <= width + 2 && sprite1Position.x == sprite2ePosition.x;

	// X,Y축 동시에 움직일 순 없으므로 서로 결과값이 달라야한다.
	return moveX != moveY;
}

std::string HelloWorld::ConvertIntToString(int i)
{
	std::stringstream strStream;
	// 정수를 읽는다.
	strStream << i;

	// string type으로 변환
	std::string s = strStream.str();
	return s;
}

