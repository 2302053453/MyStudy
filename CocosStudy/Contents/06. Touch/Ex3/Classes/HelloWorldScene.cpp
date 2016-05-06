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
    
	//////////////////////////////////
	// 람다 함수 타입
	
	auto label = Label::create("{블럭을 터치해서 드래그 하세여", "Arial", 20);
	label->setPosition(Vec2(240, 280));
	label->setColor(Color3B::BLACK);
	this->addChild(label);

	sprite1 = Sprite::create("Images/CyanSquare.png");
	sprite1->setPosition(Vec2(240, 160) + Vec2(-80, 80));
	this->addChild(sprite1);

	sprite2 = Sprite::create("Images/MagentaSquare.png");
	sprite2->setPosition(Vec2(240, 160));
	this->addChild(sprite2);

	sprite3 = Sprite::create("Images/YellowSquare.png");
	sprite3->setPosition(Vec2(0, 0));
	sprite2->addChild(sprite3);

    return true;
}

void HelloWorld::OnEnter()
{
	Layer::onEnter();

	// 싱글 터치 모드로 터치 리스너 등록
	auto listener = EventListenerTouchOneByOne::create();

	// Swallow touches only avaliable in onebyone mode
	// 핸들링된 터치 이벤트를 터치 이벤트 array에서 지우겠다는 의미다.
	listener->setSwallowTouches(true);

	// 람다 함수 형식을 이용해 터치에 타깃을 지정할 수 있다
	// 람다 -> c+=14에서 등장
	listener->onTouchBegan = [=](Touch* touch, Event* event) 
	{
		log("touch began...");

		auto target = static_cast<Sprite*>(event->getCurrentTarget());
		
		Vec2 locationInMode = target->convertToNodeSpace(touch->getLocation());
		Size s = target->getContentSize();

		Rect rect = Rect(0, 0, s.width, s.height);

		if (rect.containsPoint(locationInMode))
		{
			reZorder(target);
			
			log("sprite OnTouchBegan...x=%f, y=%f", locationInMode.x, locationInMode.y);
			target->setOpacity(100);
			return true;
		}
		return false;
	};

	listener->onTouchMoved = [=](Touch* touch, Event* event)
	{
		log("touch began...");

		auto target = static_cast<Sprite*>(event->getCurrentTarget());
		target->setPosition(target -> getPosition() + touch->getDelta());
	};

	listener->onTouchEnded = [=](Touch* touch, Event* event)
	{
		log("sprite onTouchEnded...");

		auto target = static_cast<Sprite*>(event->getCurrentTarget());
		target->setPosition(target->getPosition() + touch->getDelta());
	};

	// the priority of the touch listener is based on the draw order of sprite
	// 터치 리스너의 우선순위를 (노드가)화면에 그려진 순서대로 한다.
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, sprite1);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener->clone(), sprite2);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener->clone(), sprite3);
}
void HelloWorld::OnExit()
{
	_eventDispatcher->removeEventListenersForType(EventListener::Type::TOUCH_ONE_BY_ONE);

	Layer::onExit();
}
void HelloWorld::reZorder(cocos2d::Sprite* sender)
{
	sprite1->setZOrder(0);
	sprite2->setZOrder(0);
	sprite3->setZOrder(0);

	sender->setZOrder(1);
}
