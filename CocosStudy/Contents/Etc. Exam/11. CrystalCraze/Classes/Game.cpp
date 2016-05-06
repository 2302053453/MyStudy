#include "Game.h"
#include "SimpleAudioEngine.h" 
#include "HelloWorldScene.h"

using namespace CocosDenshion;

Scene* GameScene::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = GameScene::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool GameScene::init()
{
	//////////////////////////////
	// 1. super init first
	if (!LayerColor::initWithColor(Color4B(255, 255, 255, 255)))
	{
		return false;
	}

	// random method receive time seed 
	srand((int)time(NULL));

	// Background
	auto backGround = Sprite::create("CrystalCraze/Common/Image/background.png");
	backGround->setAnchorPoint(Vec2(0, 0));
	this->addChild(backGround);

	// header
	auto header = Sprite::create("CrystalCraze/GameScene/header.png");
	header->setPosition(Vec2(300, 460));
	header->setScaleY(0.4f);
	this->addChild(header);

	// timer
	auto timer = Sprite::create("CrystalCraze/GameScene/timer.png");
	timer->setTextureRect(Rect(0, 0, 320, 30));
	timer->setPosition(Vec2(160, 440));
	timer->setTag(TIMER);
	this->addChild(timer);
	
	// label
	auto score = LabelBMFont::create("0", "fonts/scorefont.fnt");
	score->setPosition(260, 465);
	score->setScale(0.25f);
	score->setTag(SCORE);
	this->addChild(score);


	reduceWidthPerSecond = timer->getTextureRect().size.width / 60;
	positionXPerSecond = timer->getPositionX() / 60;

	SimpleAudioEngine::getInstance()->setEffectsVolume(0.5);

	auto go = Sprite::create("CrystalCraze/GameScene/go.png");
	go->setScale(0.001f);
	go->setPosition(Vec2(160, 280));
	go->setTag(GO_IMG);

	// Init Gem Sprite
	this->addChild(go,2);

	go->runAction(Sequence::create(
		CallFunc::create(CC_CALLBACK_0(GameScene::FillGems, this)),
		ScaleTo::create(0.5f, 0.5f),
		DelayTime::create(0.3f),
		ScaleTo::create(0.5f, 0.01f),
		CallFunc::create(CC_CALLBACK_0(GameScene::Start, this)),
		nullptr));

	return true;
}

void GameScene::FillGems()
{
	// ȭ���� ����, ���μ����� üũ�Ͽ� �ش� ��ġ�� data�� ���� ��� ���� ����	
	for (int x = 0; x < BOARD_WIDTH; ++x)
		for (int y = 0; y < BOARD_HEIGHT; ++y)
			if(!crystals[x * 10 + y].isExist)
				CreateNewGem(x,y);
}

void GameScene::CreateNewGem(int x, int y)
{
	// GemType���� Image���� �б� 
	auto type = random(0, 4);
	char filePath[50];
	sprintf(filePath, GEM_IMGPATH, type);
	log("%s", filePath);
	auto crystalSprite = Sprite::create(filePath);
	auto position = Vec2(x *GEMSIZE + MARGIN, 480);

	// position, scale, tag ����
	crystalSprite->setScale(0.3f);
	crystalSprite->setPosition(position);
	crystalSprite->setTag(x * 10 + y);

	// layer�� array�� insert
	Gem gem = { type, crystalSprite, 0, true };
	crystals[x * 10 + y] = gem;
	this->addChild(crystalSprite, 1);

	// action ����
	auto act = MoveTo::create(0.3f, Vec2(crystalSprite->getPositionX(), y*GEMSIZE + MARGIN));
	crystalSprite->runAction(act);
}

void GameScene::onEnter()
{
	Layer::onEnter();

	 auto listener = EventListenerTouchOneByOne::create();
	 listener->onTouchBegan = CC_CALLBACK_2(GameScene::onTouchBegan, this);
	 _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
}

void GameScene::onExit()
{
	auto scene = HelloWorld::createScene();
	Director::getInstance()->replaceScene(scene);

	if (score < gameScore)
		score = gameScore;

	 Layer::onExit();
}

void GameScene::CheckTheConnect(int x, int y, int gemType)
{
	// x,y�� �ε��� ������ ������ return
	if (x >= BOARD_WIDTH || x < 0 ||
		y >= BOARD_HEIGHT || y < 0)
		return;
	
	// ���� ��ġ�� index�� ���Ѵ�
	int idx = x * 10 + y;
	
	// �̹� ����ȸ�Ͽ� ���ԵǾ������� return
	for (std::vector<int>::iterator iter = connectedGems.begin(); iter != connectedGems.end(); ++iter)
		if (*iter == idx)
			return;
	
	// ���� ��ġ�� gemType�� ���Ѵ�.
	auto type = crystals[idx].gemType;

	// gemType�� ��ġ���������� return
	if (gemType == type)
		connectedGems.push_back(x * 10 + y);
	else
		return;

	// �ֺ��� ������ gemtype�� �ִ��� Ȯ��
	CheckTheConnect(x + 1, y, gemType);
	CheckTheConnect(x - 1, y, gemType);
	CheckTheConnect(x, y + 1, gemType);
	CheckTheConnect(x, y - 1, gemType);
}

bool GameScene::onTouchBegan(Touch * touch, Event * event)
{
	// ���� ��ġ�� ���� ó�����̸� �Է��� ���� �ʴ´�.
	if (isTouching)
		return false;
	else
		isTouching = true;

	// ��ġ�� ��ġ�� getype�� ���Ѵ�.
	Vec2 touchPoint = touch->getLocation();
	int x = touchPoint.x / 40;
	int y = touchPoint.y / 40;
	int idx = IDX(x, y);
	auto gemType = crystals[idx].gemType;

	// ��ź�̸� ��ź ����
	if (gemType == BOMB)
		RunBomb(idx);
	else
	// ���� ������ ���� � ����Ǿ������ Ȯ��
		CheckTheConnect(x, y, gemType);

	// 3�� �̻��̸� ����
	if (connectedGems.size() >= REMOVE_COUNT)
	{
		// hint�� ����� ���� �� �ʱ�ȭ
		for (list<Sprite*>::iterator iter = hints.begin(); iter != hints.end(); ++iter)
		{
			auto hint = *iter;
			this->removeChild(*iter);
		}
		hints.clear();
		isReceivedHint = false;
		hintTime = 0;

		playSoundEffect(gemType);

		for (Vector<int>::iterator iter = connectedGems.begin(); iter != connectedGems.end(); ++iter)
		{
			if (connectedGems.size() >= BOMB_COUNT && ((*iter) == idx) && crystals[*iter].gemType != BOMB)
			{
				// ��ź image�� �ҷ��´�.
				Vec2 position = crystals[*iter].image->getPosition();
				removeChild(crystals[idx].image);
				crystals[*iter].image = Sprite::create("CrystalCraze/GameScene/bomb.png");
				crystals[*iter].image->setTag((*iter));
				crystals[*iter].image->setScale(0.3f);
				crystals[*iter].image->setPosition(position);
				crystals[*iter].gemType = BOMB;
				addChild(crystals[*iter].image);
			}
			else
				RemoveGem(*iter);
		}

		// ���� �� ���� 
		char score[50];
		int addtionalScore = connectedGems.size() > 3 ? connectedGems.size() - 2 : 1;
		gameScore += connectedGems.size() * addtionalScore * 100;
		sprintf(score, "%d", gameScore);
		auto scoreLabel = (LabelBMFont*)this->getChildByTag(SCORE);
		scoreLabel->setString(score);
	}

	// ����� ���Ľ�Ų��.
	sortGems();

	// ����
	FillGems();

	// ������ �ʱ�ȭ
	connectedGems.clear();

	// ��ġ �Է��� �޵��� �Ѵ�.
	isTouching = false;

	return true;
}

void GameScene::sortGems()
{
	for (std::vector<int>::iterator iter = connectedGems.begin(); iter != connectedGems.end(); ++iter)
	{
		int minValue = NOT_EXIST;
		int x = (*iter) / 10;

		for (int y = 0; y < BOARD_HEIGHT; ++y)
		{
			int idx = IDX(x, y);

			if (crystals[idx].isExist && minValue == NOT_EXIST)
				continue;
			else if (!crystals[idx].isExist && minValue == NOT_EXIST)
				minValue = idx;
			else if (crystals[idx].isExist && minValue != NOT_EXIST)
			{
				MoveGem(idx, minValue);
				y = minValue % 10;
				minValue = NOT_EXIST;
			}
		}
	}
}

void GameScene::MoveGem(int previousIdx, int currentIdx)
{
	// action���� �ش� image ��ġ�̵�, image�� tag�� �����´�.
	int positionX = currentIdx / 10 * GEMSIZE + MARGIN;
	int positionY = currentIdx % 10 * GEMSIZE + MARGIN;
	auto act = MoveTo::create(0.3f, Vec2(positionX, positionY));
	this->getChildByTag(previousIdx)->runAction(act);

	// �� ����
	crystals[currentIdx].image = crystals[previousIdx].image;
	crystals[currentIdx].image->setTag(currentIdx);
	crystals[currentIdx].gemType = crystals[previousIdx].gemType;
	crystals[currentIdx].isExist = crystals[previousIdx].isExist;
	crystals[currentIdx].speed = crystals[previousIdx].speed;

	// �ʱ�ȭ
	crystals[previousIdx].image = NULL;
	crystals[previousIdx].gemType = NOT_EXIST;
	crystals[previousIdx].speed = NOT_EXIST;
	crystals[previousIdx].isExist = false;
}

void GameScene::onUpdate(float t)
{
	if (gameTime >= GAMETIME)
	{ 
		this->unscheduleAllSelectors();
		EndGame();
	}
	// update gameTimer
	gameTime++;
	 
	if (hintTime == 3 && !isReceivedHint)
		GetHint();
	else if(!isReceivedHint)
		hintTime++;

	// reduce scrollbar size per second.
	auto timer = (Sprite*)this->getChildByTag(TIMER);
	timer->setPositionX(timer->getPositionX() - positionXPerSecond);
	timer->setTextureRect(Rect(0, 0, timer->getTextureRect().size.width - reduceWidthPerSecond, timer->getTextureRect().size.height));	

}

void GameScene::RemoveGem(int idx)
{

	removeChild(crystals[idx].image);
	crystals[idx].image = NULL;
	crystals[idx].gemType = NOT_EXIST;
	crystals[idx].speed = NOT_EXIST;
	crystals[idx].isExist = false;
}

void GameScene::RunBomb(int idx)
{
	int positionY = idx % 10;

	for (int i = 0; i < BOARD_WIDTH; ++i)
	{
		
		int removePos = i * 10 + positionY;
		if (removePos != idx)
			connectedGems.push_back(removePos);
	}

	int positionX = idx / 10 * 10;
	for (int i = 0; i < BOARD_HEIGHT; ++i)
	{
		int removePos = positionX + i;
		connectedGems.push_back(removePos);
	}
}

void GameScene::GetHint()
{
	for (int width = 0; width < BOARD_WIDTH; width++)
	{ 
		for (int height = 0; height < BOARD_HEIGHT; height++)
		{ 
			int idx = width * 10 + height;
			auto gemType = crystals[idx].gemType;
			CheckTheConnect(width, height, gemType);

			if (connectedGems.size() >= 3)
			{
				for (Vector<int>::iterator iter = connectedGems.begin(); iter != connectedGems.end(); ++iter)
				{
					// hint image�� �ҷ��´�.
					Vec2 position = crystals[*iter].image->getPosition();
					auto hint = Sprite::create("CrystalCraze/GameScene/hint.png");
					hint->setScale(0.3f);
					hint->setPosition(position);
					hints.push_back(hint);
					addChild(hint,2);
				}
				isReceivedHint = true;
				connectedGems.clear();
				return;
			}
			else
				connectedGems.clear();
		}
	}
}

void GameScene::Start()
{
	auto go = (Sprite*)this->getChildByTag(GO_IMG);
	this->removeChild(go);

	// begin schedule on crystal moving.
	this->schedule(schedule_selector(GameScene::onUpdate), 1.0f);
}

void GameScene::playSoundEffect(int gemType)
{
	char soundFIlePath[100];
	
	switch (gemType)
	{
	case BOMB:
		sprintf(soundFIlePath, BOMBBGM);
		break;
	default:
		sprintf(soundFIlePath, GEMBGM, gemType);
		break;
	}

	SimpleAudioEngine::getInstance()->playEffect(soundFIlePath, false);
}

void GameScene::EndGame()
{
	/*_eventDispatcher->removeEventListenersForType(EventListener::Type::TOUCH_ONE_BY_ONE);*/
	SimpleAudioEngine::getInstance()->playEffect(ENDBGM, false);

	auto scoreLabel = (LabelBMFont*)this->getChildByTag(SCORE);
	UserDefault::getInstance()->setStringForKey("score", scoreLabel->getString());

	for (int i = 0; i < BOARD_WIDTH; i++)
	{
		for (int j = 0; j < BOARD_HEIGHT; j++)
		{
			int idx = IDX(i, j);
			auto sprite = crystals[idx].image;
			int rand = j % 2 == 0 ? (-random(1, 10) * 10) : (random(1, 10) * 10);

			Vec2 up = Vec2(rand, 100);
			Vec2 dowm = Vec2(rand, -500);
			auto action = Sequence::create(
				JumpBy::create(0.5f, up, 10.0f, 1),
				JumpBy::create(0.7f, dowm, 100.0f, 1),
				DelayTime::create(2.0f),
				nullptr);

			sprite->runAction(action);
		}
	}

	auto func = CallFunc::create(CC_CALLBACK_0(GameScene::onExit, this));

	this->runAction(Sequence::create(DelayTime::create(2.0f), func, nullptr));

}


