//
//  MyBeat.h
//  BeatIt
//
//  Created by OurEDA on 14-4-2.
//
//

#ifndef __BeatIt__MyBeat__
#define __BeatIt__MyBeat__

#include <iostream>
#include "cocos2d.h"
#include "MyBall.h"
#include "MyCar.h"
#endif /* defined(__BeatIt__MyBeat__) */
using namespace cocos2d;
class MyBeat :public CCLayer{
public:
    static CCScene *scene();
    static MyBeat *sharedWorld();
    MyBall *getBall();
    MyCar *getCar();
    CCArray *getArrayForBlock();
    void loseGame();
    void winGame();
    CCMotionStreak *streak;

private:
    int time;
    int minTime;
    virtual bool init();
    CREATE_FUNC(MyBeat);
    CCArray *arrayBlock;
    void addTime();
    void autoCreateBlock();
    void backMenu();
    virtual ~MyBeat();
};


