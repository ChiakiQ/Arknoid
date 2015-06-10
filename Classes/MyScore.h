//
//  MyScore.h
//  BeatIt
//
//  Created by OurEDA on 14-4-1.
//
//

#ifndef __BeatIt__MyScore__
#define __BeatIt__MyScore__

#include <iostream>
#include "cocos2d.h"
using namespace cocos2d;
#endif /* defined(__AirBeat__MyScore__) */
class MyScore : public CCLayer{
public:
    virtual bool init();
    static CCScene  *scene();
    CREATE_FUNC(MyScore);
private:
    void backMenu();
    
};