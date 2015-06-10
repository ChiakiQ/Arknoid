//
//  MyBall.cpp
//  BeatIt
//
//  Created by OurEDA on 14-4-1.
//
//


#include "MyBlock.h"
#include "MyBeat.h"
using namespace cocos2d;
MyBall * MyBall::createball(const char *fileName){
    MyBall *ball = new MyBall();
    if(ball&&ball->initWithFile(fileName))
    {
        ball->autorelease();
        ball->ballinit(fileName);
        return ball;
    }
    CC_SAFE_DELETE(ball);
    return NULL;
}
void MyBall::ballinit(const char *fileName){
    CCSprite *myBall = CCSprite::create(fileName);
    CCSize size = CCDirector::sharedDirector()->getWinSize();
    myBall->setPosition(ccp(size.width*0.5, size.height*0.5));
    blood = 3;
    isDead = false;
    score = 0;
    direction = CCPoint(5, 7);
    speed = CCPoint(8, 8);
    this->scheduleUpdate();
}
void MyBall::update(float time){
    if(this->blood == 0){
        this->isDead = true;
        MyBeat::sharedWorld()->loseGame();
    }
    if (!isDead) {
        this->setPosition(nextPosition());
        CCMotionStreak *streak = (CCMotionStreak *)MyBeat::sharedWorld()->getChildByTag(40);
        streak->setPosition(this->getPosition());
        bounce();
    }
}

CCPoint MyBall::nextPosition(){
    return CCPoint(this->getPosition().x+direction.x*speed.x, this->getPosition().y+direction.y*speed.y);
    
}
void MyBall::bounce(){
    MyCar *car = (MyCar *)MyBeat::sharedWorld()->getCar();
    CCSize size = CCDirector::sharedDirector()->getWinSize();
    if (this->getPosition().x<=size.width*0.075){
        speed.x=-speed.x+0.1;
        this->setPositionX(size.width*0.076);
    }
    if(this->getPosition().x+40>=size.width*0.96) {
        speed.x=-speed.x-0.1;
        this->setPositionX(size.width*0.95);
    }
    if(this->getPosition().y+45>=size.height*0.95){
        speed.y=-speed.y-0.1;
        this->setPositionY(size.height*0.94);
    }
    if(this->boundingBox().intersectsRect(car->boundingBox())){
        speed.y = -speed.y;
        this->setPositionY(getPositionY()+10);
    }

    if(this->getPositionY()<=-this->getContentSize().height)
    this->changeLife();

}
void MyBall::changeLife(){
    CCSize size = CCDirector::sharedDirector()->getWinSize();
    CCActionInterval *actionMoveTo = CCMoveTo::create(1.5, ccp(size.width/2, size.height/2));
    CCActionInterval *heartAction = CCFadeOut::create(1);
    CCSprite *heart;
    switch (blood) {
        case 0:
            this->isDead = true;
            MyBeat::sharedWorld()->loseGame();
            break;
        case 1:
            this->setColor(ccc3(120, 111, 111));
            this->runAction(actionMoveTo);
            this->blood--;
            this->speed.y=-this->speed.y;
            heart = (CCSprite*)MyBeat::sharedWorld()->getChildByTag(100);
            heart->runAction(heartAction);
            break;
        case 2:
        
            this->setColor(ccc3(0, 255, 255));
            this->runAction(actionMoveTo);
            this->speed.y=-this->speed.y;
            heart = (CCSprite*)MyBeat::sharedWorld()->getChildByTag(200);
            heart->runAction(heartAction);
            this->blood--;
            break;
       case 3:
            this->setColor(ccc3(102, 102, 224));
            this->runAction(actionMoveTo);
            this->blood--;
            this->speed.y=-this->speed.y;
            CCSprite *heart = (CCSprite*)MyBeat::sharedWorld()->getChildByTag(300);
            heart->runAction(heartAction);
            break;
        
    }
}

void MyBall::addScore(int value){
    score+=value;
    CCString *ns = CCString::createWithFormat("%d",score);
    std::string strScore = ns->m_sString;
    CCLabelTTF *ttf = (CCLabelTTF *)MyBeat::sharedWorld()->getChildByTag(9);
    ttf->setString(strScore.c_str());
    
    int oldScore = atoi(CCUserDefault::sharedUserDefault()->getStringForKey("user_bscore","0").c_str());
    if(oldScore>=0&&score>oldScore){
        CCUserDefault::sharedUserDefault()->setStringForKey("user_bscore", strScore);
        CCUserDefault::sharedUserDefault()->flush();
    }
}


void MyBall::onExit(){
    this->unscheduleUpdate();
    CCSprite::onExit();
}
