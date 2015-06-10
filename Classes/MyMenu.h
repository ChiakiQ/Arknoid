//
//  MyMenu.h
//  BeatIt
//
//  Created by OurEDA on 14-4-1.
//
//

#ifndef __BeatIt__MyMenu__
#define __BeatIt__MyMenu__

#include <iostream>

#endif /* defined(__BeatIt__MyMenu__) */
#include "cocos2d.h"
USING_NS_CC;
class MyMenu :public CCLayer{
public:
    virtual bool init();
    static CCScene *scene();
    CREATE_FUNC(MyMenu);
private:
    //recall when play,about,score
    void playPressed();
    void aboutPressed();
    void scorePressed();
    void onEnter();
    
};