#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"

using namespace cocos2d;
using namespace CocosDenshion;

HelloWorld::HelloWorld() :
regenCheckTime_(-1.0f)
{
}

Scene* HelloWorld::createScene()
{
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = HelloWorld::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

bool HelloWorld::init()
{
	if (!LayerColor::initWithColor(Color4B(255, 255, 255, 255)))
    {
        return false;
    }

	MenuItemImage *pCloseItem = MenuItemImage::create("CloseNormal.png",
		"CloseSelected.png",
		CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));

    pCloseItem->setPosition( Vec2(Director::getInstance()->getWinSize().width - 20, 20) );

    Menu* pMenu = Menu::create(pCloseItem, NULL);
    pMenu->setPosition( Vec2::ZERO);
    this->addChild(pMenu, 1);

    size_ = Director::getInstance()->getWinSize();

	auto* pLabel = LabelTTF::create("1945", "Thonburi", 34);
	pLabel->setColor(Color3B::RED);
    pLabel->setPosition( Vec2(size_.width / 2, size_.height - 20) );
    this->addChild(pLabel, 1);

    Sprite* pSprite = Sprite::create("Images/1945/bg.png");
    pSprite->setPosition( Vec2(size_.width/2, size_.height/2) );
    this->addChild(pSprite, 0);

    player_ = Sprite::create("Images/1945/airplain_01.png");
    player_->setPosition( Vec2(size_.width/2, 50) );
	player_->setTag(10);
    this->addChild(player_, 1);
	
	setTouchEnabled(true);
	


	schedule(schedule_selector(HelloWorld::RegenEnemy), 1.0f);
	schedule(schedule_selector(HelloWorld::Update));
	schedule(schedule_selector(HelloWorld::Shooting), 0.2f);
	
	//enemy 배열 생성
	enemy_ = new Vector<Sprite*>();

	//missile 배열 생성
	for (int a = 0; a < MAX_MISSILE; ++a)
		missile_[a] = new Vector<Sprite*>();

    return true;
}

void HelloWorld::AddEnemy(const Vec2& position)
{
    Size size = Director::getInstance()->getWinSize();

	//적비행기 하나를 Scene에 추가
	Sprite *enemy = Sprite::create("Images/1945/enemy_01.png");
	addChild(enemy);

	enemy->setPosition(position);
	//화면 아래로 내려가는 액션 등록
	auto *move = MoveBy::create(3.0f, Vec2(0, -size.height));
	enemy->runAction(move);
	
	//배열에 방금 생성된 적비행기 스프라이트 포인터를 배열 요소로 추가
	enemy_->pushBack(enemy);
	
}

void HelloWorld::Update(float time)
{
	int eIdx = 0, mIdx=0;
	Size size = Director::getInstance()->getWinSize();

	for (; eIdx < enemy_->size(); eIdx++)
	{
		auto enemy = enemy_->at(eIdx);

		if (5 > enemy_->at(eIdx)->getPositionY())
		{
			removeChild(enemy, false);
			enemy_->eraseObject(enemy);
			continue;
		}

		for (; mIdx < MAX_MISSILE; mIdx++)
		{ 
			for (int j = 0; j < missile_[mIdx]->size(); ++j)
			{
				auto missile = missile_[mIdx]->at(j);

				//미사일이 화면 위쪽으로 사라졌을 때
				if (missile->getPositionY() >= size.height)
				{
					//미사일 삭제
				//	removeChild(missile, true);

					missile_[mIdx]->eraseObject(missile);
					continue;
				}

				//if (enemy->getBoundingBox().intersectsRect(missile->boundingBox()))
				//{
				//	//미사일과 적 비행기가 부딪혔을 때
				//	PutCrashEffect(enemy->getPosition());
				//	//적 비행기 삭제
				//	this->removeChild(enemy, true);
				//	enemy_->eraseObject(enemy);
				//	//미사일 삭제
				//	removeChild(missile, true);

				//	missile_[mIdx]->eraseObject(missile);
				//}

			}
		}
		if (player_)
		{
			//intersectsRect함수 리턴값이 충돌하면 true를 리턴
			if (player_->boundingBox().intersectsRect(enemy->boundingBox()))
			{
				//충돌했을때 처리

				//1.폭파 이펙트 출력
				PutCrashEffect(player_->getPosition());
				PutCrashEffect(enemy->getPosition());

				//2.적 비행기를 화면에서 없애준다	
				this->removeChild(enemy, false);
				enemy_->eraseObject(enemy);

				//Scene에서 비행기 스프라이트를 Remove한다
				this->removeChild(player_, false);
				player_ = NULL;
				regenCheckTime_ = 0;

			}
		}
	}

	//유저 비행기가 죽었을때만 체크하여 부활처리
	if (!player_ && regenCheckTime_ != -1.0f)
	{
		//시간을 누적시켜서 3초 이상 경과되었을 때만 부활시킨다
		regenCheckTime_ += time;
		if (regenCheckTime_ >= 3.0f)
		{
			//유저 비행기 부활처리
			player_ = Sprite::create("Images/1945/airplain_01.png");
			player_->setPosition(Vec2(size_.width / 2, 50));
			this->addChild(player_, 1);
			regenCheckTime_ = -1.0;
		}
	}


	
	
}

void HelloWorld::Shooting(float time)
{
	if (!player_)
		return;
	
	for (int a = 0; a < MAX_MISSILE; ++a)
	{
		Sprite *missile = Sprite::create("Images/1945/missile.png");
		
		if (a == 0)
		{
			missile->setPosition(Vec2(player_->getPosition().x - 16.0f, player_->getPosition().y));
		}
		else if (a == 1)
		{
			missile->setPosition(Vec2(player_->getPosition().x + 16.0f, player_->getPosition().y));
		}
		
		addChild(missile);
		
		Size size = Director::getInstance()->getWinSize();
		auto *move = MoveBy::create(0.75f, Vec2(0, size.height));
		missile->runAction(move);
		
		missile_[a]->pushBack(missile);
	}
}

void HelloWorld::RegenEnemy(float time)
{
	for (int a = 0; a < cocos2d::random(1, 5); ++a) {
		Size size = Director::getInstance()->getWinSize();
		AddEnemy(Vec2(cocos2d::random(0, (int)size.width), size.height));
	}
}

void HelloWorld::PutCrashEffect(const Vec2 &pos)
{
	//맨첫번째 스프라이트가 로딩되어 베이스가 된다
	Sprite *expBase = Sprite::create("Images/1945/explosion/exp_01.png");
    expBase->setPosition(pos);
    
	//애니메이션 스프라이트 5프레임을 차례로 등록해줌
    Animation *animation = Animation::create();
    animation->addSpriteFrameWithFile("Images/1945/explosion/exp_01.png");
    animation->addSpriteFrameWithFile("Images/1945/explosion/exp_02.png");
    animation->addSpriteFrameWithFile("Images/1945/explosion/exp_03.png");
    animation->addSpriteFrameWithFile("Images/1945/explosion/exp_04.png");
    animation->addSpriteFrameWithFile("Images/1945/explosion/exp_05.png");
    
	//0.1초 간격으로 애니메이션 처리 설정
    animation->setDelayPerUnit(0.1f);
	
	//애니메이션이 끝나고 시작 프레임(1번)으로 돌아간다
    animation->setRestoreOriginalFrame(true);
    
	//에니메이션 생성
    auto *animate = Animate::create(animation);
	
	//애니메이션이 끝나면 removeChild를 자동으로 호출하여 메모리 삭제.. 이것도 일종의 액션이다
	CallFunc *removeAction = CallFunc::create(expBase, CC_CALLFUNC_SELECTOR(Node::removeFromParent));
	
	//애니메이션과 리무브액션 2개의 액션을 하나의 시퀀스로 등록후 runAction 실행
    FiniteTimeAction *seq = Sequence::create(animate, removeAction, NULL);
    this->addChild(expBase);//씬에 이펙트(베이스 스프라이트)를 추가
    expBase->runAction(seq);//베이스 스프라이트는 애니메이션 시퀀스를 실행한다
}

bool HelloWorld::TouchBegan(Touch *pTouch, Event *pEvent)
{
	if (!player_)
		return true;
		
	Vec2 touchVec2 = pTouch->getLocation();
    Vec2 touchGlVec2 = Director::getInstance()->convertToGL(touchVec2);
	
	Vec2 playerPos = player_->getPosition();
	distance_ = Vec2(playerPos.x - touchGlVec2.x, playerPos.y - touchGlVec2.y);
	
	return true;
}

void HelloWorld::TouchMoved(Touch *pTouch, Event *pEvent)
{
	if (!player_)
		return;

	Vec2 touchVec2 = pTouch->getLocation();
    Vec2 touchGlVec2 = Director::getInstance()->convertToGL(touchVec2);
	
	Vec2 pos = Vec2(touchGlVec2.x + distance_.x, touchGlVec2.y + distance_.y);
	
	if (pos.x < 0.0f)
	{
		pos.x = 0.0f;
		distance_ = Vec2(pos.x - touchGlVec2.x, pos.y - touchGlVec2.y);
	}
	else if (pos.x > size_.width)
	{
		pos.x = size_.width;
		distance_ = Vec2(pos.x - touchGlVec2.x, pos.y - touchGlVec2.y);
	}

	if (pos.y < 0.0f)
	{
		pos.y = 0.0f;
		distance_ = Vec2(pos.x - touchGlVec2.x, pos.y - touchGlVec2.y);
	}
	else if (pos.y > size_.height)
	{
		pos.y = size_.height;
		distance_ = Vec2(pos.x - touchGlVec2.x, pos.y - touchGlVec2.y);
	}
	
	player_->setPosition(pos);
}

void HelloWorld::TouchEnded(Touch *pTouch, Event *pEvent)
{
}

void HelloWorld::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}

