//
//  MyMenu.cpp
//  BeatIt
//
//  Created by OurEDA on 14-4-1.
//
//

#include "MyMenu.h"
#include "MyAbout.h"
#include "MyScore.h"
#include "MyBeat.h"
#include "SimpleAudioEngine.h"
using namespace cocos2d;
using namespace CocosDenshion;
bool MyMenu::init(){
    if(!CCLayer::init()){
        return false;
    }
    SimpleAudioEngine::sharedEngine()->playBackgroundMusic("Loves You Yeah!.mp3", true);
    CCSize size = CCDirector::sharedDirector()->getWinSize();
    
    //add the background
    CCSprite *myGround = CCSprite::create("ground.jpg");
    //myGround->setScale(2);
    myGround->setPosition(ccp(size.width*0.5, size.height*0.5));
    addChild(myGround);

    
    //add play,about,score in menu
    CCMenuItemImage *myPlay = CCMenuItemImage::create("playUp.png", "playDown.png", this, menu_selector(MyMenu::playPressed));
    myPlay->setPosition(ccp(size.width*0.3,size.height*0.6 ));
    
    CCMenuItemImage *myAbout = CCMenuItemImage::create("aboutUp.png", "aboutDown.png", this, menu_selector(MyMenu::aboutPressed));
    myAbout->setPosition(ccp(size.width*0.6, size.height*0.5));

    CCMenuItemImage *myScore = CCMenuItemImage::create("scoreUp.png", "scoreDown.png", this, menu_selector(MyMenu::scorePressed));
    myScore->setPosition(ccp(size.width*0.3, size.height*0.3));

    CCMenu *menu = CCMenu::create(myPlay,myAbout,myScore,NULL);

    menu->setPosition(ccp(0, 0));
    addChild(menu,0,3);
    
    CCJumpBy *jump1 = CCJumpBy::create(1, CCPointZero,30,3);
    CCRotateBy *rot1 = CCRotateBy::create(1, 360);
    CCJumpBy *jump2 = ((CCJumpBy *)jump1->copy()->autorelease());
    CCTargetedAction *t1 = CCTargetedAction::create(myAbout, jump2);
    CCTargetedAction *t2 = CCTargetedAction::create(myScore, rot1);
    CCSequence *seq = CCSequence::create(jump1,t1,t2,NULL);
    myPlay->runAction(seq);
    
    
    return true;
}
CCScene *MyMenu::scene(){
    CCScene *scene = CCScene::create();
    MyMenu *layer = MyMenu::create();
    scene->addChild(layer);
    return scene;
}
void MyMenu::playPressed(){
    CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(1.5, MyBeat::scene()));
}

void MyMenu::aboutPressed(){
    CCDirector::sharedDirector()->replaceScene(CCTransitionPageTurn::create(1.5, MyAbout::scene(), false));
}
void MyMenu::scorePressed(){
    CCDirector::sharedDirector()->replaceScene(CCTransitionFadeBL::create(1.5, MyScore::scene()));
}

void MyMenu::onEnter(){
    CCLayer::onEnter();
}
