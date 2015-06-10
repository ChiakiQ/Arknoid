//
//  MyBlock.h
//  BeatIt
//
//  Created by OurEDA on 14-4-2.
//
//

#ifndef __BeatIt__MyBlock__
#define __BeatIt__MyBlock__

#include <iostream>
#include "cocos2d.h"
#endif /* defined(__BeatIt__MyBlock__) */
using namespace cocos2d;
class MyBlock :public CCSprite{
public:
    static MyBlock *create(const char *fileName,int tType);
    CREATE_FUNC(MyBlock);
private:
    bool blockinit(const char * fileName,int tType);
    int life;
    int type;
    void changeLife();
    void update1(float time);
    void update2(float time);
    void downScreen();
    void onEixt();
};