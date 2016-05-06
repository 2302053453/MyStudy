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
    if ( !Layer::init())
    {
        return false;
    }
    
	// 윈도우 크기를 구한다
	winSize = Director::getInstance()->getWinSize();

	// plist로 image 읽어오기
	auto cache = SpriteFrameCache::getInstance();
	cache->addSpriteFramesWithFile("Images/CutTheVerlet.plist");
	
	// vector 초기화
	ropes = new std::vector<VRope*>;
	originRopes = new std::vector<VRope*>;

	// background 생성
	auto bg = Sprite::createWithSpriteFrameName("bg.png");
	bg->setAnchorPoint(Vec2::ZERO);
	bg->setScaleX(1.5f);
	this->addChild(bg, 0);

	// 입 닫은 악어 생성
	auto crocodile_close = Sprite::createWithSpriteFrameName("croc_front_mouthclosed.png");
	crocodile_close->setPosition(Vec2(400, 10));
	crocodile_close->setTag(CROCDILE_CLOSE);
	this->addChild(crocodile_close, 1);

	// 입 닫은 악어 충돌판정 생성
	crocRect = Rect(
		crocodile_close->getBoundingBox().origin.x, 
		crocodile_close->getBoundingBox().origin.y,
		crocodile_close->getBoundingBox().size.width / 2,
		crocodile_close->getBoundingBox().size.height);

	// 입 열린 악어 생성
	auto crocodile_open = Sprite::createWithSpriteFrameName("croc_front_mouthopen.png");
	crocodile_open->setPosition(Vec2(400, 10));
	crocodile_open->setTag(CROCDILE_OPEN);
	crocodile_open->setVisible(false);
	this->addChild(crocodile_open, 1);


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
	
	// bodydef에 좌표를 설정한다
	b2BodyDef groundBodyDef;
	groundBodyDef.position.Set(0, 0);

	// 월드에 boduydef의 정보(좌표)로 body를 만든다
	groundBody = _world->CreateBody(&groundBodyDef);

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

	// 밧줄 이미지 추기
	ropeSpriteSheet = SpriteBatchNode::create("Images/rope_texture.png");
	this->addChild(ropeSpriteSheet);

	// 아이템 추가
	b2Body* body1 = this->AddNewSpriteAt(Vec2(winSize.width / 2, winSize.height * 2 / 3));

	// 4개의 로프를 그린다.
	b2FixtureDef shapeDef;
	b2CircleShape shape;
	shape.m_radius = 0.5f;
	boxShapeDef.shape = &shape;

	b2BodyDef leftUpperBodyDef;
	leftUpperBodyDef.position.Set(100 / PTM_RATIO,300 / PTM_RATIO);
	auto leftUpperBody = _world->CreateBody(&leftUpperBodyDef);
	leftUpperBody->CreateFixture(&boxShapeDef);

	b2BodyDef leftLowerBodyDef;
	leftLowerBodyDef.position.Set(100 / PTM_RATIO, 200 / PTM_RATIO);
	auto leftLowerBody = _world->CreateBody(&leftLowerBodyDef);
	leftLowerBody->CreateFixture(&boxShapeDef);

	b2BodyDef rightUpperBodyDef;
	rightUpperBodyDef.position.Set(400 / PTM_RATIO, 300 / PTM_RATIO);
	auto rightUpperBody = _world->CreateBody(&rightUpperBodyDef);
	rightUpperBody->CreateFixture(&boxShapeDef);

	b2BodyDef rigftLowerBodyDef;
	rigftLowerBodyDef.position.Set(400 / PTM_RATIO, 200 / PTM_RATIO);
	auto rightLowerBody = _world->CreateBody(&rigftLowerBodyDef);
	rightLowerBody->CreateFixture(&boxShapeDef);


	this->createRope(
		leftUpperBody,
		leftUpperBody->GetLocalCenter(),
		body1,
		body1->GetLocalCenter(),
		1.1f);
	this->createRope(
		leftLowerBody,
		leftLowerBody->GetLocalCenter(),
		body1,
		body1->GetLocalCenter(),
		1.1f);

	this->createRope(
		rightUpperBody,
		rightUpperBody->GetLocalCenter(),
		body1,
		body1->GetLocalCenter(),
		1.1f);
	this->createRope(
		rightLowerBody,
		rightLowerBody->GetLocalCenter(),
		body1,
		body1->GetLocalCenter(),
		1.1f);

	


	return true;
}

HelloWorld::~HelloWorld()
{
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
	listener->onTouchMoved = CC_CALLBACK_2(HelloWorld::onTouchMoved, this);

	// The priority of the touch listener is basd on the draw order of sprite
	// 터치리스너의 우선순위를 (노드가) 화면에 그려진 순서대로 한다.
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
}

void HelloWorld::onExit() 
{
	_eventDispatcher->removeAllEventListeners();

	Layer::onExit();
}

bool HelloWorld::onTouchBegan(Touch* touch, Event* event) 
{
	return true;
}

void HelloWorld::onTouchMoved(Touch * touch, Event * event)
{
	Vec2 pt0 = touch->getPreviousLocation();
	Vec2 pt1 = touch->getLocation();

	std::vector<VRope*>::iterator rope;
	for (rope = ropes->begin(); rope != ropes->end(); ++rope)
	{
		std::vector<VStick*>::iterator stick;
		for (stick = (*rope)->getSticks().begin(); stick != (*rope)->getSticks().end(); ++stick)
		{
			Vec2 pa = (*stick)->getPointA()->point();
			Vec2 pb = (*stick)->getPointB()->point();
			if (this->checkLineIntersection(pt0, pt1, pa, pb))
			{
				// Cut the rope here
				b2Body *newBodyA = createRopeTipBody();
				b2Body *newBodyB = createRopeTipBody();

				VRope *newRope = (*rope)->cutRopeInStick((*stick), newBodyA, newBodyB);
				ropes->push_back(newRope);

				return;
			}
		}
	}
}

void HelloWorld::createRope(b2Body * bodyA, b2Vec2 anchorA, b2Body * bodyB, b2Vec2 anchorB, float sag)
{
	b2RopeJointDef jd;
	jd.bodyA = bodyA;
	jd.bodyB = bodyB;
	jd.localAnchorA = anchorA;
	jd.localAnchorB = anchorB;
	
	// Max length of joint = current distance between bodies * sag
	float32 ropeLength = (bodyA->GetWorldPoint(anchorA) - bodyB->GetWorldPoint(anchorB)).Length()*sag;
	jd.maxLength = ropeLength;

	// Create joints...
	b2RopeJoint* ropeJoint = (b2RopeJoint*)_world->CreateJoint(&jd);

	VRope* newRope = new VRope(ropeJoint, ropeSpriteSheet);
	
	ropes->push_back(newRope);
	originRopes->push_back(newRope);
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


			if (spriteData->getTag() == PINEAPPLE && crocRect.intersectsRect(spriteData->getBoundingBox()))
			{
				this->removeChild(spriteData);
				spriteData = nullptr;
				b->SetUserData(nullptr);
				b = nullptr;

				auto crocClose = (Sprite*)this->getChildByTag(CROCDILE_CLOSE);
				auto act_croc_close = Sequence::create(Hide::create(), DelayTime::create(1.0f), Show::create(), nullptr);
				crocClose->runAction(act_croc_close);

				auto crocOpen = (Sprite*)this->getChildByTag(CROCDILE_OPEN);
				auto act_croc_open = Sequence::create(Show::create(), DelayTime::create(1.0f), Hide::create(), nullptr);
				crocOpen->runAction(act_croc_open);

				std::vector<VRope*>::iterator rope;
				
				for (rope = ropes->begin(); rope != ropes->end();)
				{
					(*rope)->update(t);
					(*rope)->updateSprites();
					bool isDeleted = true;

					std::vector<VRope*>::iterator originRope;
					for (originRope = originRopes->begin(); originRope != originRopes->end(); ++originRope)
					{
						if ((*rope) == (*originRope))
						{ 
							isDeleted = false;
							break;
						}
					}

					if (isDeleted)
					{
						(*rope)->removeSprites();
						rope = ropes->erase(rope);
					}
					else
						++rope;
				}

				return;
			}
		}
	}

	std::vector<VRope*>::iterator rope;
	for (rope = ropes->begin(); rope != ropes->end(); ++rope)
	{
		(*rope)->update(t);
		(*rope)->updateSprites();
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

b2Body * HelloWorld::AddNewSpriteAt(Vec2 point)
{
	auto sprite = Sprite::createWithSpriteFrameName("pineapple.png");
	sprite->setTag(PINEAPPLE);
	this->addChild(sprite);

	// Defiones the body of your candy
	b2BodyDef bodyDef;
	bodyDef.type = b2_dynamicBody;
	bodyDef.position = b2Vec2(point.x / PTM_RATIO, point.y / PTM_RATIO);
	bodyDef.userData = sprite;
	bodyDef.linearDamping = 0.3f;
	b2Body* body = _world->CreateBody(&bodyDef);

	b2Vec2 verts[] = {
		b2Vec2(-7.6f / PTM_RATIO, -34.4f / PTM_RATIO),
		b2Vec2(8.3f / PTM_RATIO, -34.4f / PTM_RATIO),
		b2Vec2(15.55f / PTM_RATIO, -27.15f / PTM_RATIO),
		b2Vec2(13.8f / PTM_RATIO, 23.05f / PTM_RATIO),
		b2Vec2(-3.25f / PTM_RATIO, 35.25f / PTM_RATIO),
		b2Vec2(-16.25f / PTM_RATIO, 25.55f / PTM_RATIO),
		b2Vec2(-15.55f / PTM_RATIO, -23.95f / PTM_RATIO),
	};

	b2PolygonShape spriteShape;
	spriteShape.Set(verts, 7);

	b2FixtureDef fixtureDef;
	fixtureDef.shape = &spriteShape;
	fixtureDef.density = 30.0f;
	fixtureDef.filter.categoryBits = 0x01;
	fixtureDef.filter.maskBits = 0x01;

	body->CreateFixture(&fixtureDef);

	return body;
}

bool HelloWorld::checkLineIntersection(Vec2 p1, Vec2 p2, Vec2 p3, Vec2 p4)
{
	float denominator = (p4.y - p3.y) *(p2.x - p1.x) - (p4.x - p3.x) *(p2.y - p1.y);

	// In this case the lines are parallel so yuo assume they don't intersect
	if (denominator == 0.0f)
		return false;

	float ua = ((p4.x - p3.x)*(p1.y - p3.y) - (p4.y - p3.y) * (p1.x - p3.x)) / denominator;
	float ub = ((p2.x - p1.x)*(p1.y - p3.y) - (p2.y - p1.y) * (p1.x - p3.x)) / denominator;
	
	if (ua >= 0.0f && ua < 1.0f && ub>0.0f && ub < 1.0f)
		return true;

	return false;
}

b2Body * HelloWorld::createRopeTipBody()
{
	b2BodyDef bodyDef;

	bodyDef.type = b2_dynamicBody;
	bodyDef.linearDamping = 0.5f;
	b2Body *body = _world->CreateBody(&bodyDef);

	b2FixtureDef circleDef;
	b2CircleShape circle;
	circle.m_radius = 1.0f / PTM_RATIO;
	circleDef.shape = &circle;
	circleDef.density = 10.0f;

	// Since these tips don't have to collide with anything
	// set the mask bits to zero
	circleDef.filter.maskBits = 0;
	body->CreateFixture(&circleDef);

	return body;
}


