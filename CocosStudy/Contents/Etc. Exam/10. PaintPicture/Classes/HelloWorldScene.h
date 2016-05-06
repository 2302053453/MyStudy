#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "extensions\cocos-ext.h"

#define IMAGE_TAG 20


using namespace cocos2d;
using namespace cocos2d::extension;

class HelloWorld :
	public cocos2d::LayerColor
	, public TableViewDataSource
	, public TableViewDelegate
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);

	void onEnter();
	void onExit();
	
	std::string GetCrayonPath(int idx);
	Color3B GetCrayonColor(int idx);

	virtual bool onTouchBegan(Touch* touch, Event* event);
	virtual void onTouchMoved(Touch* touch, Event* event);
	virtual void tableCellTouched(TableView* table, TableViewCell* cell);
	virtual Size tableCellSizeForIndex(TableView* table, ssize_t idx);
	virtual TableViewCell* tableCellAtIndex(TableView* table, ssize_t idx);
	virtual ssize_t numberOfCellsInTableView(TableView* table);

	const Color3B BROWN = Color3B(153, 56, 0);
	const Color3B BASIC = Color3B(255, 218, 162);
	const Color3B INCARNADINE = Color3B(255, 254, 198);
	const Color3B VIOLET =  Color3B(255, 221, 0);

private:
	Vector<Sprite*> brushes;
	RenderTexture* target;
	Color3B selectedColor;
	Layer* contentLayer;
	Layer* controlLayer;
};

#endif // __HELLOWORLD_SCENE_H__
