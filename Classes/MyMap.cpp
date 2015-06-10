//
//  MyMap.cpp
//  BeatIt
//
//  Created by OurEDA on 14-4-2.
//
//

#include "MyMap.h"
using namespace cocos2d;
MyMap* MyMap::createMap(const char *fileName1,const char *fileName2){
    MyMap *map = new MyMap;
    if(map&&map->create()){
        map->autorelease();
        map->mapInit(fileName1,fileName2);
        return map;
    }
    CC_SAFE_DELETE(map);
    return NULL;
}

void MyMap::mapInit(const char *fileName1,const char *fileName2){
    CCSprite *map =CCSprite::create(fileName1);
    map->setPosition(ccp(map->getContentSize().width*0.5, map->getContentSize().height*0.5));
    this->addChild(map,0,1);

    CCSprite *turnmap = CCSprite::create(fileName2);
    turnmap->setPosition(ccp(turnmap->getContentSize().width*0.5, turnmap->getContentSize().height*1.5-3));
    this->addChild(turnmap,0,2);
    this->scheduleUpdate();
    
    
}

void MyMap::update(float time){
    CCSprite *myFirst = (CCSprite *)this->getChildByTag(1);
    if(myFirst->getPositionY()-10<=-myFirst->getContentSize().height*0.5){
        myFirst->setPosition(ccp(myFirst->getContentSize().width*0.5,myFirst->getContentSize().height*1.5f-11));
    }
    else
        myFirst->setPosition(ccpAdd(myFirst->getPosition(), ccp(0,-3)));
    
    CCSprite *mySecond = (CCSprite *)this->getChildByTag(2);
    if(mySecond->getPositionY()-10<=-mySecond->getContentSize().height*0.5){
        mySecond->setPosition(ccp(mySecond->getContentSize().width*0.5, mySecond->getContentSize().height*1.5f-11));
    }
    else
        mySecond->setPosition(ccpAdd(mySecond->getPosition(), ccp(0, -3)));
}
void MyMap::onEixt(){
    this->unscheduleUpdate();
    CCLayer::onExit();
}