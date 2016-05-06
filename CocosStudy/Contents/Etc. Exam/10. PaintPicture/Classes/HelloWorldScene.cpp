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

	// content 영역 init
	contentLayer = Layer::create();

	// 색칠대상 image
	auto image = Sprite::create("Images/image01.png");
	image->setTag(IMAGE_TAG);
	image->setPosition(Vec2(240, 160));
	contentLayer->addChild(image,2);
	
	// 윈도우 사이즈 구하기
	auto winSize = Director::getInstance()->getWinSize();

	// render Texture 만들기
	target = RenderTexture::create(winSize.width,
		winSize.height,
		Texture2D::PixelFormat::RGBA8888);

	target->retain();
	target->setPosition(Vec2(winSize.width / 2, winSize.height / 2));
	
	contentLayer->addChild(target, 1);
	this->addChild(contentLayer,1);

	// Control 영역 init
	controlLayer = Layer::create();

	//crayon Table
	TableView* paintTable = TableView::create(this, Size(480, 60));
	paintTable->setContentSize(Size(900, 60));
	paintTable->setPosition(20, 20);
	paintTable->setDirection(ScrollView::Direction::HORIZONTAL);
	// tableCellClick 받도록
	paintTable->setDelegate(this);
	controlLayer->addChild(paintTable,1);
	paintTable->reloadData();

	this->addChild(controlLayer,2);
	
    return true;
}

void HelloWorld::onEnter()
{
	Layer::onEnter();
	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = CC_CALLBACK_2(HelloWorld::onTouchBegan, this);
	listener->onTouchMoved = CC_CALLBACK_2(HelloWorld::onTouchMoved, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
}

void HelloWorld::onExit() 
{
	_eventDispatcher->removeEventListenersForType(EventListener::Type::TOUCH_ONE_BY_ONE);

	Layer::onExit();
}

bool HelloWorld::onTouchBegan(Touch * touch, Event * event)
{
	return true;
}

void HelloWorld::onTouchMoved(Touch* touch, Event* event)
{
	auto touchEndPoint = touch->getLocation();
	auto touchStartPoint = touch->getPreviousLocation();

	// touch의 범위가 image 내부가 아닌 경우 return;
	auto image = (Sprite*)contentLayer->getChildByTag(IMAGE_TAG);
	if (image == NULL || !image->getBoundingBox().containsPoint(touchEndPoint))
		return;

	// for extra points, we/ll draw this sloothly from the last position and vary the sprite's 
	// scal/rotation/offset
	float distance = touchStartPoint.getDistance(touchEndPoint);
	target->begin();

	if (distance > 1)
	{
		int d = (int)distance;
		brushes.clear();

		for (int i = 0; i < d; ++i)
		{
			Sprite* sprite = Sprite::create("Images/brush.png");
			sprite->setColor(selectedColor);

			// 부드럽게 처리
			//sprite->setOpacity(20);
			//sprite->setOpacity(150);
			brushes.pushBack(sprite);
		}
		for (int i = 0; i < d; ++i)
		{
			float difx = touchEndPoint.x - touchStartPoint.x;
			float dify = touchEndPoint.y - touchStartPoint.y;
			float delta = (float)i / distance;

			brushes.at(i)->setPosition(Vec2(touchStartPoint.x + (difx * delta), touchStartPoint.y + (dify * delta)));
			brushes.at(i)->setRotation(rand() % 360);

			float r = (float)(rand() % 50 / 50.f) + 0.25f;

			brushes.at(i)->setScale(r);

			// Call visit to draw the brush, dont'call draw...
			brushes.at(i)->visit();
		}
	}
	target->end();
}

void HelloWorld::tableCellTouched(TableView* table, TableViewCell* cell)
{
	// 선택한 cell의 idx는 내부의 sprite의 tag와 동일하다.
	// Click한 색깔로 변경
	int tag = cell->getIdx();
	auto crayon = (Sprite*)cell->getChildByTag(tag);
	selectedColor = GetCrayonColor(crayon->getTag());
}

Size HelloWorld::tableCellSizeForIndex(TableView* table, ssize_t idx)
{
		return Size(60, 60);
}

TableViewCell * HelloWorld::tableCellAtIndex(TableView * table, ssize_t idx)
{
	auto string = String::createWithFormat("%1d", idx);
	TableViewCell *cell = table->cellAtIndex(idx);

	if (!cell)
	{
		cell = new TableViewCell();
		cell->autorelease();
		cell->setIdx(idx);
		auto sprite = Sprite::create(GetCrayonPath(idx));
		sprite->setAnchorPoint(Vec2::ZERO);
		sprite->setPosition(Vec2(0, 0));
		sprite->setTag(idx);
		sprite->setScale(0.7f);
		cell->addChild(sprite);

		auto label = LabelTTF::create(string->getCString(), "Helvetica", 20.0);
		label->setPosition(Vec2::ZERO);
		label->setAnchorPoint(Vec2::ZERO);
		label->setTag(123);
		label->setColor(Color3B::BLACK);
		cell->addChild(label);
	}
	//else
	//{
	//	auto label = (LabelTTF*)cell->getChildByTag(123);
	//	label->setString(string->getCString());
	//}

	return cell;
}

ssize_t HelloWorld::numberOfCellsInTableView(TableView * table)
{
	return 13;
}

std::string HelloWorld::GetCrayonPath(int idx)
{
	switch (idx)
	{
	case 0:
		return "Images/crayon_01.png";
	case 1:
		return "Images/crayon_02.png";
	case 2:
		return "Images/crayon_03.png";
	case 3:
		return "Images/crayon_04.png";
	case 4:
		return "Images/crayon_05.png";
	case 5:
		return "Images/crayon_06.png";
	case 6:
		return "Images/crayon_07.png";
	case 7:
		return "Images/crayon_08.png";
	case 8:
		return "Images/crayon_09.png";
	case 9:
		return "Images/crayon_10.png";
	case 10:
		return "Images/crayon_11.png";
	case 11:
		return "Images/crayon_12.png";
	case 12:
		return "Images/crayon_13.png";
	default:
		break;
	}

	return "";
}

Color3B HelloWorld::GetCrayonColor(int idx)
{
	switch (idx)
	{
	case 0:
		return Color3B::RED;
	case 1:
		return Color3B::ORANGE;
	case 2:
		return Color3B::YELLOW;
	case 3:
		return Color3B::GREEN;
	case 4:
		return Color3B::BLUE;
	case 5:
		return Color3B::MAGENTA;
	case 6:
		return VIOLET;
	case 7:
		return Color3B::WHITE;
	case 8:
		return Color3B::BLACK;
	case 9:
		return Color3B::GRAY;
	case 10:
		return BROWN;
	case 11:
		return BASIC;
	case 12:
		return INCARNADINE;
	default:
		break;
	}


	return Color3B();
}


