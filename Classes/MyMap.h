//
//  MyMap.h
//  BeatIt
//
//  Created by OurEDA on 14-4-2.
//
//

#ifndef __BeatIt__MyMap__
#define __BeatIt__MyMap__

#include <iostream>
#include "cocos2d.h"
using namespace cocos2d;
#endif /* defined(__BeatIt__MyMap__) */
class MyMap:public CCLayer{
public:
    static MyMap* createMap(const char* fileName1,const char *fileName2);
private:
    void mapInit(const char* fileName,const char *fileName2);
    void update(float time);
    virtual void onEixt();
    
};