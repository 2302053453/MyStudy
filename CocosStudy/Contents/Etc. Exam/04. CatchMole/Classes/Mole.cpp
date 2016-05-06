#include "Mole.h"

USING_NS_CC;

Mole::Mole()
	:_listener(nullptr)
{
	bool b0k = initWithTexture(nullptr, Rect(0, 0, 83, 93));
	if (b0k)
		this->autorelease();

	this->setTexture(filePath);
}

void Mole::onEnter()
{
	Sprite::onEnter();

	auto listener = EventListenerTouchOneByOne::create();
	listener->setSwallowTouches(true);

	listener->onTouchBegan = [=](Touch* touch, Event* event)
	{
		log("Touch!");

		Vec2 locationInMode = this->convertToNodeSpace(touch->getLocation());
		Size s = this->getContentSize();

		Rect rect = Rect(0, 0, s.width, s.height);

		if (rect.containsPoint(locationInMode))
		{
			log("Ouch!");
			return true;
		}
		return false;
	};
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

	_listener = listener;
}

void Mole::onExit()
{
	_eventDispatcher->removeEventListener(_listener);

	Sprite::onExit();
}

char* Mole::getMoleImagePath()
{
	return filePath;
}

// 두더지 액션 정의
void Mole::doAction()
{ 
	auto act = Sequence::create(
		DelayTime::create(INTERVAL),
		JumpTo::create(0.7f, this->getPosition(), 90,1),
		nullptr);

	auto repeat = RepeatForever::create(act);
	this->runAction(repeat);
}
