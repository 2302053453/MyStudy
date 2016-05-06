//#ifndef __SpriteExtedxEx_Monster__
//#define __SpriteExtedxEx_Monster__

#include"cocos2d.h"

class Monster: public cocos2d::Sprite
{
public:
	Monster();

	void SetPriority(int fixelPriority);
	void SetPriorityWithThis(bool useNodePriority);

	void onEnter();
	void onExit();

private:
	cocos2d::EventListener* _listener;
	int _fixedPriority;
	bool _useNodePriority;
};

//#endif // !__SpriteExtedxEx_Monster__
