#ifndef __GLOBALDEFINITION_H__
#define __GLOBALDEFINITION_H__

#include "cocos2d.h"

#define NOT_EXIST -1
#define IDX(x,y) {x*10 +y}
#define REMOVE_COUNT 3
#define BOMB_COUNT 6
#define BOMB 5
#define TIMER 10
#define GO_IMG 200
#define GAMETIME 60
#define SCORE 100

#define MAINBGM "CrystalCraze/sounds/loop.mp3"
#define MISSBGM "CrystalCraze/sounds/miss.mp3"
#define BOMBBGM "CrystalCraze/sounds/powerup.mp3"
#define TIMERBGM "CrystalCraze/sounds/timer.mp3"
#define ENDBGM "CrystalCraze/sounds/endgame.mp3"

#define IDX(x,y) {x *10 + y}

using namespace std;

const int GEMSIZE = 40;
const int BOARD_WIDTH = 8;
const int BOARD_HEIGHT = 10;
const int NUM_TOTALGEMS = BOARD_WIDTH * BOARD_HEIGHT;
const int MARGIN = 20;
const int kTimeBetweenGemAdds = 8;
const int kTotalGameTime = 1000 * 60;
const int kIntroTime = 1800;
const int kNumRemovalFrames = 8;
const int kDelayBeforeHint = 3000;
const int kMaxTimeBetweenConsecutiveMoves = 1000;

const int kGameOverGemSpeed = 0.1;
const int kGameOverGemAcceleration = 0.005;

static const char* GEM_IMGPATH = "CrystalCraze/Common/Image/crystal/%d.png";
static const char* GEMBGM = "CrystalCraze/sounds/gem-%d.ogg";

static int score = 0;

typedef struct Gem
{
	int gemType;
	cocos2d::Sprite* image;
	double speed;
	bool isExist;
};


#endif // !1


