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
    if ( !Layer::init())
    {
        return false;
    }
    
	// 윈도우 크기를 구한다
	winSize = Director::getInstance()->getWinSize();

	// 이미지의 텍스쳐를 구한다
	texture = Director::getInstance()->getTextureCache()->addImage("CloseNormal.png");

	// 월드 생성
	if (this->createBox2dWorld(true))
	{
		this->schedule(schedule_selector(HelloWorld::tick));
	}

    return true;
}

bool HelloWorld::createBox2dWorld(bool debug)
{
	// 월드 생성 시작------------------------------

	// wndfurdml qkdgiddmf rufwjdgksek]
	b2Vec2 gravity = b2Vec2(0.0f, -30.0f);
	
	_world = new b2World(gravity);
	_world->SetAllowSleeping(true);
	_world->SetContinuousPhysics(true);
	
	// 디버그 드로잉 설정
	if (debug)
	{
		// 적색 : 현재 물리 운동을 하는 것
		// 회색 : 현재 물리 운동량이 없는 것
		m_debugDraw = new GLESDebugDraw(PTM_RATIO);
		_world->SetDebugDraw(m_debugDraw);

		uint32 flags = 0;
		flags += b2Draw::e_shapeBit;
	/*	flags += b2Draw::e_jointBit;
		flags += b2Draw::e_aabbBit;
		flags += b2Draw::e_pairBit;
		flags += b2Draw::e_centerOfMessBit;*/
		m_debugDraw->SetFlags(flags);
	}

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
	groundEdge.Set(b2Vec2(0, 0), b2Vec2(0, winSize.height / PTM_RATIO));
	groundBody->CreateFixture(&boxShapeDef);
	// 위쪽
	groundEdge.Set(b2Vec2(0, winSize.height / PTM_RATIO), b2Vec2(winSize.width / PTM_RATIO, winSize.height / PTM_RATIO));
	groundBody->CreateFixture(&boxShapeDef);
	// 오른쪽
	groundEdge.Set(b2Vec2(winSize.width / PTM_RATIO, winSize.height / PTM_RATIO), b2Vec2(winSize.width / PTM_RATIO, 0));
	groundBody->CreateFixture(&boxShapeDef);

	// 월드 생성 끝  -------------------------------------------------------


	body0 = this->AddNewSprite(Vec2(340, 70), Size(100, 40), b2_dynamicBody, NULL, 0);
	auto body1 = this->AddNewSprite(Vec2(310, 50), Size(30, 30), b2_dynamicBody, NULL, 1);
	auto body2 = this->AddNewSprite(Vec2(370, 50), Size(30, 30), b2_dynamicBody, NULL, 1);

	b2Vec2 axis(0.0f, 1.0f);

	wheelJointDef1.Initialize(body0, body1, body1->GetPosition(), axis);
	wheelJointDef1.motorSpeed = 30.0f;
	wheelJointDef1.maxMotorTorque = 20.0f;
	wheelJointDef1.enableMotor = true;
	wheelJointDef1.frequencyHz = 4.0f;
	wheelJointDef1.dampingRatio = 0.7f;

	wheelJointDef2.Initialize(body0, body2, body2->GetPosition(), axis);
	wheelJointDef2.motorSpeed = 30.0f;
	wheelJointDef2.maxMotorTorque = 20.0f;
	wheelJointDef2.enableMotor = true;
	wheelJointDef2.frequencyHz = 4.0f;
	wheelJointDef2.dampingRatio = 1.0f;

	wheelJoint1 = (b2WheelJoint *)_world->CreateJoint(&wheelJointDef1);
	wheelJoint2 = (b2WheelJoint *)_world->CreateJoint(&wheelJointDef2);

	return true;
}

HelloWorld::~HelloWorld()
{
	delete _world;
	_world = NULL;
}

void HelloWorld::draw(Renderer *renderer, const Mat4 &transform, uint32_t flags)
{
	Layer::draw(renderer, transform, flags);

	_customCmd.init(_globalZOrder, transform, flags);
	_customCmd.func = CC_CALLBACK_0(HelloWorld::onDraw, this, transform, flags);
	renderer->addCommand(&_customCmd);
}

void HelloWorld::onDraw(const Mat4 &transform, uint32_t flags)
{
	Director* director = Director::getInstance();
	CCASSERT(nullptr != director, "Director is null when seting matrix stack");
	director->pushMatrix(MATRIX_STACK_TYPE::MATRIX_STACK_MODELVIEW);
	director->loadMatrix(MATRIX_STACK_TYPE::MATRIX_STACK_MODELVIEW, transform);

	GL::enableVertexAttribs(cocos2d::GL::VERTEX_ATTRIB_FLAG_POSITION);
	_world->DrawDebugData();
	CHECK_GL_ERROR_DEBUG();

	director->popMatrix(MATRIX_STACK_TYPE::MATRIX_STACK_MODELVIEW);
}


void HelloWorld::tick(float t)
{

	// 물리적 위치를 이용해 그래픽 위치를 갱신한다.

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

	if (body0->GetPosition().x <= 1.6)
	{

		wheelJointDef1.motorSpeed = -30.0f;
		wheelJointDef2.motorSpeed = -30.0f;
		wheelJoint1 = (b2WheelJoint *)_world->CreateJoint(&wheelJointDef1);
		wheelJoint2 = (b2WheelJoint *)_world->CreateJoint(&wheelJointDef2);
	}
	else if (body0->GetPosition().x >= 13.4)
	{
		wheelJointDef1.motorSpeed = 30.0f;
		wheelJointDef2.motorSpeed = 30.0f;
		wheelJoint1 = (b2WheelJoint *)_world->CreateJoint(&wheelJointDef1);
		wheelJoint2 = (b2WheelJoint *)_world->CreateJoint(&wheelJointDef2);
	}
}

b2Body * HelloWorld::AddNewSprite(Vec2 point, Size size, b2BodyType bodyType, const char * spriteName, int type)
{
	// bodyDef를 만들고 속성들을 저장한다.
	b2BodyDef bodyDef;
	bodyDef.type = bodyType;
	bodyDef.position.Set(point.x / PTM_RATIO, point.y / PTM_RATIO);

	if (spriteName)
	{
		if (strcmp(spriteName, "test") == 0)
		{
			int idx = CCRANDOM_0_1() > .5 ? 0 : 1;
			int idy = CCRANDOM_0_1() > .5 ? 0 : 1;
			Sprite* sprite = Sprite::createWithTexture(texture, Rect(32 * idx, 32 * idy, 32, 32));
			sprite->setPosition(point);
			this->addChild(sprite);

			bodyDef.userData = sprite;
		}
		else
		{
			Sprite* sprite = Sprite::create(spriteName);
			sprite->setPosition(point);
			this->addChild(sprite);
			bodyDef.userData = sprite;
		}
	}

	// 월드에 bodyDef의 정보로 body를 만든다.
	b2Body *body = _world->CreateBody(&bodyDef);

	// body에 적용할 물리 속성용 body의 모양을 만든다.
	b2FixtureDef fixtureDef;
	b2PolygonShape dynamicBox;
	b2CircleShape circle;

	if (type == 0)
	{
		dynamicBox.SetAsBox(size.width / 2 / PTM_RATIO, size.height / 2 / PTM_RATIO);
		fixtureDef.shape = &dynamicBox;
	}
	else
	{
		circle.m_radius = (size.width / 2 / PTM_RATIO);
		fixtureDef.shape = &circle;
	}

	// Define the dynamic body fixture
	fixtureDef.density = 1.0f;
	fixtureDef.friction = 0.3f;
	fixtureDef.restitution = 0;

	body->CreateFixture(&fixtureDef);

	return body;
}

b2Body * HelloWorld::GetBodyAtTab(Vec2 p)
{
	b2Fixture* fix;

	for (b2Body *b = _world->GetBodyList(); b; b = b->GetNext())
	{
		if (b->GetUserData() != NULL)
		{
			if (b->GetType() == b2_staticBody)
				continue;
			fix = b->GetFixtureList();
			if (fix->TestPoint(b2Vec2(p.x / PTM_RATIO, p.y / PTM_RATIO)))
				return b;
		}
	}
	return nullptr;
}


