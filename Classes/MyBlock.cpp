//
//  MyBlock.cpp
//  BeatIt
//
//  Created by OurEDA on 14-4-2.
//
//

#include "MyBlock.h"
#include "MyBeat.h"
using namespace cocos2d;
MyBlock* MyBlock::create(const char *fileName,int tType){
    MyBlock *block = new MyBlock();
    if(block&&block->initWithFile(fileName))
    {
        block->autorelease();
        block->blockinit(fileName,tType);
        return block;
    }
    CC_SAFE_DELETE(block);
    return NULL;
}

bool MyBlock::blockinit(const char * fileName,int tType){
    CCSprite *myblock = CCSprite::create(fileName);
    myblock->setScale(2);
    CCSize size = CCDirector::sharedDirector()->getWinSize();
    this->setPosition(ccp(int(CCRANDOM_0_1()*size.width/120)*100+100,size.height-2*this->getContentSize().height));
    type = tType;
    life = type;
    switch (type) {
        case 3:
            this->setColor(ccc3(200, 150, 170));
            break;
        case 2:
            this->setColor(ccc3(137, 190, 178));
            break;
        case 1:
            this->setColor(ccc3(240, 230, 104));
            break;
    }
    this->schedule(schedule_selector(MyBlock::update1),5);
    this->schedule(schedule_selector(MyBlock::update2), 0.01f);
    return true;
}

void MyBlock::changeLife(){
    MyBall *ball = (MyBall *)MyBeat::sharedWorld()->getBall();
    if(ball->boundingBox().intersectsRect(this->boundingBox())){
        ball->addScore(100);
        if(ball->score>=100000)
            MyBeat::sharedWorld()->winGame();
        if(life!=0)
            ball->speed.y=-ball->speed.y;
        this->life--;
        switch (life) {
            case 2:
                this->setColor(ccc3(137, 190, 178));
                break;
            case 1:
                this->setColor(ccc3(240, 230, 104));
                break;
            case 0:
            //maybe add sth?
                CCActionInterval *actionFade = CCScaleTo::create(0.5, 0);
                this->runAction(actionFade);
                
//                MyBeat::sharedWorld()->getArrayForBlock()->removeObject(this);
//                this->getParent()->removeChild(this,true);//????????????????????????????
                break;
    }
    }
}
void MyBlock::downScreen(){
    if(this->getPositionY()<CCDirector::sharedDirector()->getWinSize().height*0.15)
    {  MyBeat::sharedWorld()->getArrayForBlock()->removeObject(this);
            this->getParent()->removeChild(this,true);    }
}

void MyBlock::update1(float time){
    this->setPosition(ccpAdd(this->getPosition(), ccp(0, -120)));

}
void MyBlock::update2(float time){
    this->changeLife();
    this->downScreen();
}

void MyBlock::onEixt(){
    this->unscheduleAllSelectors();
    CCSprite::onExit();
}

