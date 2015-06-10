//
//  MyCar.cpp
//  BeatIt
//
//  Created by OurEDA on 14-4-2.
//
//


#include "MyBeat.h"
bool MyCar::ccTouchBegan(CCTouch *myTouch, CCEvent *myEvent){
    this->setPositionX(myTouch->getLocation().x);
    return true;
}
void MyCar::ccTouchMoved(CCTouch *myTouch, CCEvent *myEvent){
    this->setPositionX(myTouch->getLocation().x);
}

void MyCar::ccTouchEnded(CCTouch *myTouch,CCEvent *myEvent){
    
    this->setPositionX(myTouch->getLocation().x);
}

MyCar *MyCar::create(const char *fileName){
    MyCar *car = new MyCar();
    if(car&&car->initWithFile(fileName))
    {
        car->autorelease();
        car->carinit(fileName);
        return car;
    }
    CC_SAFE_DELETE(car);
    return NULL;
}
void MyCar::carinit(const char *fileName){
    CCSprite *car = CCSprite::create(fileName);
    car->setScale(4);

}
void MyCar::onEnter(){
    CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, 0, true);
    CCSprite::onEnter();
}
void MyCar::onExit(){
    CCDirector::sharedDirector()->getTouchDispatcher()->removeDelegate(this);
    CCSprite::onExit();
}