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
    
	// 윈도우 크기를 구한다
 	winSize = Director::getInstance()->getWinSize();

	// 이미지의 텍스쳐를 구한다.
	texture = Director::getInstance()->getTextureCache()->addImage("CloseNormal.png");

	// 필드 생성 시작 -------------------------------------------------------------------
	
	// 중력의 방향을 결정한다
	b2Vec2 gravity = b2Vec2(0.0f, -30.0f);

	// 월드를 생성한다
	_world = new b2World(gravity);

	// 휴식 상태일 때 포함된 body들을 멈추게(Sleep)할 것인지 결정한다
	_world->SetAllowSleeping(true);

	// 지속적인 물리작용을 할 것인지 결정한다 : 테스트
	_world->SetContinuousPhysics(true);

	// 가장자리 (테둘)를 지정해 공간(Ground Box)을 만든다


	// bodydef에 좌표를 설정한다
	b2BodyDef groundBodyDef;
	groundBodyDef.position.Set(0, 0);

	// 월드에 boduydef의 정보(좌표)로 body를 만든다
	b2Body *groundBody = _world->CreateBody(&groundBodyDef);

	// 가장자리(테두리) 경계선을 그릴 수 있는 모양의 객체를 만든다.
	b2EdgeShape groundEdge;
	b2FixtureDef boxShapeDef;
	boxShapeDef.shape = &groundEdge;

	// edge 모양의 객체에 Set(점1, 점2)로 선을 만든다.
	// 그리고 바디(groundbody)에 모양(groundEdge)을 고정시킨다.
	// 만일 객체간의 거리가 10m가 넘으면 오차가 생길 수 있다.

	// 아래쪽
	groundEdge.Set(b2Vec2(0, 0), b2Vec2(winSize.width / PTM_RATIO, 0));
	groundBody->CreateFixture(&boxShapeDef);
	// 왼쪽
	groundEdge.Set(b2Vec2(0, 0), b2Vec2(winSize.height / PTM_RATIO, 0));
	groundBody->CreateFixture(&boxShapeDef);
	// 위쪽
	groundEdge.Set(b2Vec2(0, winSize.height / PTM_RATIO), b2Vec2(winSize.width / PTM_RATIO, winSize.height / PTM_RATIO));
	groundBody->CreateFixture(&boxShapeDef);
	// 오른쪽
	groundEdge.Set(b2Vec2(winSize.width / PTM_RATIO, winSize.height / PTM_RATIO), b2Vec2(winSize.width / PTM_RATIO, 0));
	groundBody->CreateFixture(&boxShapeDef);

	// 월드 생성 끝 -------------------------------------------------------------------------
	this->schedule(schedule_selector(HelloWorld::tick));

    return true;
}

HelloWorld::~HelloWorld()
{

	// 월드를 C++의 new로 생성했으므로 여기서 지워준다
	delete _world;
	_world = NULL;
}

void HelloWorld::onEnter()
{
	Layer::onEnter();

	// 싱글 터치 모드로 터치리스너 등록
	auto listener = EventListenerTouchOneByOne::create();

	// Swallow touches only avaailiable in OneByOne mode.
	// 핸들링 된 터치 이벤트를 터치 이벤트 array에서 지우겠다는 의미이다
	listener->setSwallowTouches(true);

	listener->onTouchBegan = CC_CALLBACK_2(HelloWorld::onTouchBegan, this);

	// The priority of the touch listener is basd on the draw order of sprite
	// 터치리스너의 우선순위를 (노드가) 화면에 그려진 순서대로 한다.
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
}

void HelloWorld::onExit()
{
	_eventDispatcher->removeAllEventListeners();

	Layer::onExit();
}

void HelloWorld::tick(float t)
{
	// 물리적 위치를 이영해 그래픽 위치를 갱신한다.

	// velocityIterations : body들을 정상적으로 이동시키기 위해 필요한 충돌들을 반복적으로 계산
	// positionIterations ; 조인트 분리와 겹침 현상을 줄이기 위해 바디의 위치를 반복적으로 적용
	// 값이 클수록 정확한 연산이 가능하지만 성능이 떨어진다

	// 프로젝트 생성 시 기본값
	int velocityIterations = 8;
	 int positionIterations = 3;

	// Step : 물리 세계를 시뮬레이션한다
	 _world->Step(t, velocityIterations, positionIterations);

	 // 모든 물리 객체들은  linkedList에 저장되어 참조해 볼 수 있게 구현돼 있다.
	 // 만들어진 객체 만큼 루프를 돌리면서 바다에 붙인 스프라이트를 여기서 제어한다.
	 for (b2Body *b = _world->GetBodyList(); b; b = b->GetNext())
	 {
		 if (b->GetUserData() != NULL)
		 {
			 Sprite* spriteData = (Sprite*)b->GetUserData();
			 spriteData->setPosition(Vec2(b->GetPosition().x * PTM_RATIO, b->GetPosition().y * PTM_RATIO));
			 spriteData->setRotation(-1 * CC_RADIANS_TO_DEGREES(b->GetAngle()));
		 }
	 }
}

bool HelloWorld::onTouchBegan(Touch* touch, Event* event)
{
	auto touchPoint = touch->getLocation();

	// 터치된 지점에 새로운 물리 객체의 바디와 해당 스프라이트를 추가한다.
	addNewSpriteAtPosition(touchPoint);

	return true;

}

void HelloWorld::addNewSpriteAtPosition(Vec2 location)
{
	// 스프라이트를 파라미터로 넘어온 위치에 만든다.
	Sprite* sprite = Sprite::createWithTexture(texture,Rect(0, 0, 37, 37));
	sprite->setPosition(Vec2(location.x, location.y));
	this->addChild(sprite);

	// BodyDef를 만들고 속성들을 지정한다.
	b2BodyDef bodyDef;
	bodyDef.type = b2_dynamicBody;
	bodyDef.position.Set(location.x / PTM_RATIO, location.y / PTM_RATIO);
	
	// 유저데이터에 스프라이트를 붙인다
	bodyDef.userData = sprite;

	// 월드에 바디데프의 정보로 바디를 만든다.
	b2Body* body = _world->CreateBody(&bodyDef);

	// 박스 모양의 객체 생성
	b2PolygonShape dynamicBox;
	dynamicBox.SetAsBox(.5f, .5f);

	b2FixtureDef fixtureDef;
	fixtureDef.shape = &dynamicBox;
	fixtureDef.density = 1.0f;
	fixtureDef.friction = 0.3f;
	fixtureDef.restitution = 1.f;
	body->CreateFixture(&fixtureDef);


	/*
	// 바디에 적용할 물리 속성용 바디의 모양을 만든다.
	// 원형태를 선태갷 반지름을 지정한다.
	b2CircleShape circle;
	circle.m_radius = 0.55f;

	// 그리고 바디의 모양(Circle)을 고정시킨다.
	b2FixtureDef fixtureDef;

	// 모양을 지정한다
	fixtureDef.shape = &circle;
	// 밀도 (밀도 != 질량이나  질량에 대한 정의가 없을 경우에는 밀도 = 질량이다)
	fixtureDef.density = 1.0f;
	// 마찰력 : 0 ~ 1
	fixtureDef.friction = 0.2f;
	// 반발력 : 물체가 다른 물체에 닿았을 떄 튕기는 값
	fixtureDef.restitution = 0.7f;

	body->CreateFixture(&fixtureDef);
	*/

	/*
	// 다각형 모양의 객체 생성 - 벡터값의 크기에 따라 다양하고 복잡한 모양을 만들 수 있다.
    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    bodyDef.position.Set(p.x/PTM_RATIO, p.y/PTM_RATIO);
    b2Body *body = world->CreateBody(&bodyDef);

    b2PolygonShape dynamicBox;
    b2Vec2 tri[3];

    tri[0].x = -.5;
    tri[0].y = 0.0;

    tri[1].x = .5;
    tri[1].y = 0.0;

    tri[2].x = 0;
    tri[2].y = 1.0;

    dynamicBox.Set(tri, 3);


    b2FixtureDef fixtureDef;
    fixtureDef.shape = &dynamicBox;
    fixtureDef.density = 1.0f;
    fixtureDef.friction = 0.3f;
    fixtureDef.restitution = 1.f;
    body->CreateFixture(&fixtureDef);

	*/

}
