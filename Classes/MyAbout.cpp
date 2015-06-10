//
//  MyAbout.cpp
//  BeatIt
//
//  Created by OurEDA on 14-4-1.
//
//

#include "MyAbout.h"
#include "MyMenu.h"
using namespace cocos2d;
CCScene * MyAbout::scene(){
    CCScene *scene = CCScene::create();
    MyAbout *layer = MyAbout::create();
    scene->addChild(layer);
    return scene;
}

bool MyAbout::init(){
    if(!CCLayer::init())
        return false;
    CCSize size=CCDirector::sharedDirector()->getWinSize();
    
    CCSprite *maback = CCSprite::create("aboutcq.png");
    maback->setPosition(ccp(size.width*0.5, size.height*0.5));
    maback->setScale(1.5);
    
    this->addChild(maback);
    
    CCLabelTTF *back = CCLabelTTF::create("Back", "MarkerFelt-Thin",50);
    back->setColor(ccc3(170, 200, 0));
    CCMenuItemLabel *menuLabel = CCMenuItemLabel::create(back, this, menu_selector(MyAbout::backMenu));
    menuLabel->setPosition(ccp(0, -200));
    CCMenu *menu = CCMenu::create(menuLabel,NULL);
    this->addChild(menu);
    return true;
}

void MyAbout::backMenu(){
    CCDirector::sharedDirector()->replaceScene(CCTransitionPageTurn::create(1, MyMenu::scene(), true));
}

