//
//  MyScore.cpp
//  BeatIt
//
//  Created by OurEDA on 14-4-1.
//
//

#include "MyScore.h"
#include "cocos2d.h"
#include "MyMenu.h"
using namespace cocos2d;

CCScene *MyScore::scene(){
    CCScene *scene = CCScene::create();
    MyScore *layer = MyScore::create();
    scene->addChild(layer);
    return scene;
}

bool MyScore::init(){
    if(!CCLayer::init())
        return false;
    CCSize size = CCDirector::sharedDirector()->getWinSize();
    CCSprite *scoreback = CCSprite::create("score.png");
    scoreback->setPosition(ccp(size.width*0.5, size.height*0.5));
    scoreback->setScale(1.5);
    addChild(scoreback);
    CCSprite *myCrown = CCSprite::create("score1.png");
    myCrown->setPosition(ccp(size.width/2-50, size.height/2+150));
    addChild(myCrown);
    
    std::string scoretext= "";
    //get the score
    std::string score= CCUserDefault::sharedUserDefault()->getStringForKey("user_bscore", "0").c_str();
    //have best?
    if(atoi(score.c_str())!=0){
        scoretext+=score;
    }
    else
        scoretext="0";
    
    CCLabelTTF *ttfscore = CCLabelTTF::create(score.c_str(),"MarkerFelt-Thin",60);
    ttfscore->setPosition(ccp(size.width*0.5-50, size.height*0.5+40));
    ttfscore->setColor(ccc3(118, 77, 57));
    addChild(ttfscore);
    
    CCLabelTTF *back = CCLabelTTF::create("Back", "MarkerFelt-Thin",50);
    back->setColor(ccc3(170, 138, 87));
    CCMenuItemLabel *menuLabel = CCMenuItemLabel::create(back, this, menu_selector(MyScore::backMenu));
    menuLabel->setPosition(ccp(0, -200));
    CCMenu *menu = CCMenu::create(menuLabel,NULL);
    this->addChild(menu);
    return true;
}

void MyScore::backMenu(){
    CCDirector::sharedDirector()->replaceScene(CCTransitionFadeBL::create(1, MyMenu::scene()));
}