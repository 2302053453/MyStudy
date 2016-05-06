#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"]
#include "extensions/cocos-ext.h"
#include "CustomTableView.h"

using namespace cocos2d;
using namespace cocos2d::extension;

class HelloWorld 
	: public cocos2d::LayerColor
	, public TableViewDataSource
	,public TableViewDelegate
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);

	virtual void scrollViewDidScroll(ScrollView* scrollview);
	virtual void scrollViewDidZoom(ScrollView* scrollview);
	virtual void tableCellTouched(TableView* table, TableViewCell* cell);
	virtual Size tableCellSizeForIndex(TableView* table, ssize_t idx);
	virtual TableViewCell* tableCellAtIndex(TableView* table, ssize_t idx);
	virtual ssize_t numberOfCellsInTableView(TableView* table);
	
};

#endif // __HELLOWORLD_SCENE_H__
