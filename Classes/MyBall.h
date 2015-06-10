//
//  MyBall.h
//  BeatIt
//
//  Created by OurEDA on 14-4-1.
//
//

#ifndef __BeatIt__MyBall__
#define __BeatIt__MyBall__

#include <iostream>
#include "cocos2d.h"
#endif /* defined(__BeatIt__MyBall__) */
using namespace cocos2d;
class MyBall :public CCSprite {
public:
    int blood;
    int score;
    bool isDead;
    CCPoint direction;
    CCPoint speed;
    static MyBall * createball(const char *fileName);
    CCPoint nextPosition();
    void bounce();
    void update(float time);
    void onExit();
    void addScore(int value);
    void changeLife();
    
private:
    void ballinit(const char *fileName);
    

};