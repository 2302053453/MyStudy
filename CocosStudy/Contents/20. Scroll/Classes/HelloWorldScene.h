#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "extensions/cocos-ext.h"

using namespace cocos2d;
using namespace extension;

class HelloWorld : public cocos2d::LayerColor, public ScrollViewDelegate
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);

	// 스크롤뷰를 사용할 때 사용하는 함수, 델리게이트 함수, 변수를 선언한다.
	void scrollViewDidScroll(ScrollView* view);
	void scrollViewDidZoom(ScrollView* view);

	ScrollView* scrollView;
};

#endif // __HELLOWORLD_SCENE_H__
