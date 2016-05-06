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
	if (!LayerColor::initWithColor(Color4B(255, 255, 255, 255)))
	{
		return false;
	}
	layer1 = Layer::create();
	layer2 = Layer::create();
	this->addChild(layer1);
	this->addChild(layer2);


	// 화면의 픽셀 크기를 구한다.
	winSize = Director::getInstance()->getWinSize();

	// 배경을 만든다.
	this->createBackgroundParallax();

	// 드래곤을 만든다.
	this->createDragon();

	// 메누 버튼을 만든다.
	this->createArrowButtons();

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

	// 위에서 만든 스프라이트를 담을 부모로 페럴렉스노드를 만든다.
	auto voidNode = ParallaxNode::create();

	// 배경 스프리으트를 페럴렉스노드에 넣는다
	// 배경이미지의 사이즈 : 512 X 320
	voidNode->addChild(background1, 1, Vec2(1, 0), Vec2(0, 0));
	voidNode->addChild(background2, 1, Vec2(1, 0), Vec2(512, 0));

	voidNode->setTag(1);

	layer1->addChild(voidNode,0);
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
	dragon = Sprite::createWithTexture(texture, Rect(0, 0, 130, 140));
	dragon->setPosition(Vec2(240, 160));
	layer1->addChild(dragon);

	auto animate = Animate::create(animation);
	auto rep = RepeatForever::create(animate);

	dragon->runAction(rep);
}

void HelloWorld::createArrowButtons()
{
	// 왼쪽화살표
	leftSprite = Sprite::create("Images/b1.png");
	leftSprite->setPosition(Vec2(180, 30));
	layer2->addChild(leftSprite, 2);

	//눌렷을 때 쓰일 왼쪽 화살표
	leftPressedSprite = Sprite::create("Images/b2.png");
	// leftSprite와 같은위치에 표시한다.
	leftPressedSprite->setPosition(leftSprite->getPosition());
	layer2->addChild(leftPressedSprite, 1);

	// 오른쪽 화살표
	rightSprite = Sprite::create("Images/f1.png");
	rightSprite->setPosition(Vec2(300, 30));
	layer2->addChild(rightSprite, 2);

	//눌렷을 때 쓰일 오른쪽 화살표
	rightPressedSprite = Sprite::create("Images/f2.png");
	// rightSprite와 같은위치에 표시한다.
	rightPressedSprite->setPosition(rightSprite->getPosition());
	layer2->addChild(rightPressedSprite, 1);

}

void HelloWorld::onEnter() 
{
	Layer::onEnter();

	auto listener = EventListenerTouchOneByOne::create();
	listener->setSwallowTouches(true);
	listener->onTouchBegan = CC_CALLBACK_2(HelloWorld::onTouchBegan, this);
//	listener->onTouchMoved = CC_CALLBACK_2(HelloWorld::onTouchesMoved, this);
	listener->onTouchEnded = CC_CALLBACK_2(HelloWorld::onTouchEnded, this);

	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
}

void HelloWorld::onExit() 
{
	_eventDispatcher->removeEventListenersForType(EventListener::Type::TOUCH_ONE_BY_ONE);

	Layer::onExit();
}

bool HelloWorld::onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event)
{
	// 아래 boolean 변수 대신 leftSp[rite와 rightSprite의 visible 값을 직ㅈ버 사용해도 무방하다.
	isLeftPressed = false;
	isRightPressed = false;

	// 터치가 왼쪽  또는 오른쪽 화살표 안에 들어왔는지 확인한다.
	if (this->isTouchInside(leftSprite, touch))
	{
		// 왼쪽 화살표를 안 보이게 한다
		// 그럼 그 아래에 있던 눌릴 때 보여지는 이미지가 나타날 것이다.
		leftSprite->setVisible(false);
		isLeftPressed = true;
	}

	else if (this->isTouchInside(rightSprite, touch))
	{
		// 오른쪽 화살표를 안 보이게 한다
		// 그럼 그 아래에 있던 눌릴 때 보여지는 이미지가 나타날 것이다.
		rightSprite->setVisible(false);
		isRightPressed = true;
	}

	// 버튼이 눌려졌으면 화면을 움직인다.
	if (isLeftPressed || isRightPressed)
		this->startMovingBackground();

	return true;
}

#pragma mark -
#pragma Game Play

void HelloWorld::onTouchMoved(cocos2d::Touch* touch, cocos2d::Event* event)
{
	// 손가락이 버튼을 벗어나면 움직임을 중단한다.
	// 배경화면을 멈춘다
	// 감춰졌던 버튼을 보이게한다
	if (isLeftPressed && !isTouchInside(leftSprite, touch))
	{
		this->stopMovingBackground();
		leftSprite->setVisible(true);
	}
	else if (isRightPressed &&!isTouchInside(leftSprite, touch))
	{
		this->stopMovingBackground();
		rightSprite->setVisible(true);
	}
}

void HelloWorld::onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event)
{
	// 배경화면을 멈춘다
	if (isLeftPressed || isRightPressed)
		this->stopMovingBackground();

	// 감춰졌던 버튼을 보이게한다
	if (isLeftPressed)
		leftSprite->setVisible(true);
	if (isRightPressed)
		rightSprite->setVisible(true);
	
}

bool HelloWorld::isTouchInside(cocos2d::Sprite* sprite, cocos2d::Touch* touch) 
{
	auto touchPoint = touch->getLocation();

	bool isTouched = sprite->getBoundingBox().containsPoint(touchPoint);

	return isTouched;
}

void HelloWorld::startMovingBackground() 
{
	// 만약 버튼 두개가 다 눌려졌으면 화면을 이동시키지 않는다.
	if (isLeftPressed && isRightPressed)
		return;

	// 스케줄을 이용해 매 프레임마다 배경화면을 움직인다.
	this->schedule(schedule_selector(HelloWorld::moveBackground));

	log("Start Moving...");
}

void HelloWorld::stopMovingBackground() 
{
	this->unschedule(schedule_selector(HelloWorld::moveBackground));
}

void HelloWorld::moveBackground(float f)
{
	log("Moving Background...");

	// 매 프레임마다 움직일 거리
	auto moveStep = 3;
	if (isLeftPressed)
	{
		moveStep = -3;
		dragon->setFlippedX(false);
	}
	else
		dragon->setFlippedX(true);

	auto newPos = Vec2(dragon->getPosition().x + moveStep, dragon->getPosition().y);

	if (newPos.x < 0)
		newPos.x = 0;
	else if (newPos.x > 512 * 2)
		newPos.x = 512*2;

	dragon->setPosition(newPos);

	// view를 해당위치로 이동시킨다(카메라(시점을 dragon기준으로)조정
	layer1->runAction(Follow::create(dragon, Rect(0, 0, 512 * 2, 320)));
}
