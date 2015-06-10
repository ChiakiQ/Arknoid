//
//  MyCar.h
//  BeatIt
//
//  Created by OurEDA on 14-4-2.
//
//

#ifndef __BeatIt__MyCar__
#define __BeatIt__MyCar__

#include <iostream>
#include "cocos2d.h"
#endif /* defined(__BeatIt__MyCar__) */
using namespace cocos2d;
class MyCar :public CCSprite,public CCTouchDelegate{
public:
    static MyCar* create(const char *fileName);
    void carinit(const char *fileName);
private:
    //touch functions~
    virtual bool ccTouchBegan(CCTouch *myTouch,CCEvent *myEvent);
    virtual void ccTouchMoved(CCTouch *myTouch,CCEvent *myEvent);
    virtual void ccTouchEnded(CCTouch *myTouch, CCEvent *myEvent);
    void onEnter();
    void onExit();
};