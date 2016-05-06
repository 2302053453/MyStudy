#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "Box2D\Box2D.h"
#include <GLES-Render.h>

#define PTM_RATIO 32

USING_NS_CC;

class HelloWorld : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);

	bool createBox2dWorld(bool debug);
	~HelloWorld();
	void HelloWorld::draw(Renderer *renderer, const Mat4 &transform, uint32_t flags);
	void HelloWorld::onDraw(const Mat4 &transform, uint32_t flags);

	virtual void onEnter();
	virtual void onExit();
	virtual bool onTouchBegan(Touch* touch, Event* event);
	virtual void onTouchMoved(Touch* touch, Event* event);
	virtual void onTouchEnded(Touch* touch, Event* event);
	void tick(float t);
	b2Body* AddNewSprite(Vec2 point, Size size, b2BodyType bodyType, const char* spriteName, int type);
	b2Body* GetBodyAtTab(Vec2 p);


	Size winSize;
	Texture2D* texture;
	b2World* _world;

	// For Debugging
	GLESDebugDraw* m_debugDraw;

protected:
	bool bDrag;
	b2MouseJoint *mouseJoint;
	b2Body *dragBody;
	b2Body *gBody;
	bool isForeced = false;
	CustomCommand _customCmd;

};

#endif // __HELLOWORLD_SCENE_H__
