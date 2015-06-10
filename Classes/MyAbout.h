//
//  MyAbout.h
//  BeatIt
//
//  Created by OurEDA on 14-4-1.
//
//

#ifndef __BeatIt__MyAbout__
#define __BeatIt__MyAbout__

#include <iostream>
#include"cocos2d.h"
using namespace cocos2d;
#endif /* defined(__AirBeat__MyAbout__) */
class MyAbout:public CCLayer{
public:
    virtual bool init();
    static CCScene * scene();
    CREATE_FUNC(MyAbout);
private:
    void backMenu();
};