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
	// 화면 사이즈 구하기
	winSize = Director::getInstance()->getWinSize();

	// 터렛 탐의 이미지
	player = Sprite::create("Images/turret.png");
	player->setPosition(Vec2(player->getContentSize().width / 2 + 80,
		winSize.height));
	this->addChild(player);

	// 총알 벡터 초기화
	projectiles.clear();

	// 상태 변수들 초기화
	bprojectiles = false;

	// 터치 이벤트 등록
	auto listener = EventListenerTouchOneByOne::create();
	listener->setSwallowTouches(true);
	listener->onTouchBegan = CC_CALLBACK_2(HelloWorld::onTouchBegan, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
    
    return true;
}

bool HelloWorld::onTouchBegan(Touch* touch, Event* event)
{
	if (bprojectiles)
		return true;
	else
		bprojectiles = true;

	auto touchPoint = touch->getLocation();

	auto nextProjectile = Sprite::create("Images/bullet2.png");

	// 회전해야 할 각도를 구한다
	Vec2 shootVector = touchPoint - player->getPosition();
	float shootAngle = shootVector.getAngle();
	float cocosAngle = CC_RADIANS_TO_DEGREES(-1 * shootAngle);

	// 회전시간을 결정한다
	float curAngle = player->getRotation();
	float rotateDiff = cocosAngle - curAngle;
	if (rotateDiff > 180)
		rotateDiff -= 360;
	if(rotateDiff < 180)
		rotateDiff += 360;

	// Would take 0.5 seconds to rotate half a circle
	float rotateSpeed = 0.5f / 180;
	float rotateDuration = fabsf(rotateDiff * rotateSpeed);

	// 액션 실행
	auto actRotate1 = RotateTo::create(rotateDuration, cocosAngle);
	auto setAct1 = Sequence::create(
		actRotate1,
		CallFunc::create(CC_CALLBACK_0(HelloWorld::finishRotate, this, nextProjectile)),
		nullptr);
	player->runAction(setAct1);
	
	// 총알을 화면 밖으로 보낸다
	shootVector.normalize();
	Vec2 overshotVector = shootVector * 420;

	// 캐릭터와 같은 각도로 총알 방향 바꾸기(회전)
	nextProjectile->setRotation(cocosAngle);

	// 총알 화면 밖으로 보낸다.
	auto actMove2 = MoveBy::create(1.0f, overshotVector);
	auto seqAct2 = Sequence::create(
		actMove2,
		CallFunc::create(CC_CALLBACK_0(HelloWorld::spriteMoveFinished, this, nextProjectile)),
		nullptr);
	nextProjectile->runAction(seqAct2);
	
	return true;
}

void HelloWorld::finishRotate(Ref* sender)
{
	Sprite* sprite = (Sprite*)sender;
	
	// Ok to add now - we've finished rotation!
	Vec2 npos1 = Vec2(player->getContentSize().width, player->getContentSize().height / 2);
	Vec2 npos2 = player->convertToWorldSpace(npos1);

	sprite->setPosition(npos2);

	// 화면에 추가
	// 추가된 이후부터 액션이 run되는지 확인
	this->addChild(sprite);

	// 벡터에 추가
	projectiles.pushBack(sprite);

	bprojectiles = false;
}

void HelloWorld::spriteMoveFinished(Ref* sender)
{
	Sprite* sprite = (Sprite*)sender;
	this->removeChild(sprite, true);

	projectiles.eraseObject(sprite);
}
