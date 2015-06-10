//
//  MyBeat.cpp
//  BeatIt
//
//  Created by OurEDA on 14-4-2.
//
//

#include "MyBeat.h"
#include "MyMap.h"
#include "MyBlock.h"
#include "MyMenu.h"
#include "time.h"
#include "SimpleAudioEngine.h"
using namespace cocos2d;
using namespace CocosDenshion;
static MyBeat *sh;//see if the Beat exist;
MyBeat* MyBeat::sharedWorld(){
    if (sh!=NULL) {
        return sh;
    }
    else
        return NULL;
}

CCScene* MyBeat::scene(){
    CCScene *scene = CCScene::create();
    MyBeat *layer = MyBeat::create();
    scene->addChild(layer);
    return scene;
}

bool MyBeat::init(){
    if(!CCLayer::init())
        return false;
    sh = this;
    time = 0;
    minTime = 0;
    SimpleAudioEngine::sharedEngine()->playBackgroundMusic("Loves You Yeah!.mp3", true);
    SimpleAudioEngine::sharedEngine()->setBackgroundMusicVolume(0.5);
    CCSize size = CCDirector::sharedDirector()->getWinSize();
    MyMap *map = MyMap::createMap("map2.jpg","map3.jpg");
    addChild(map,0,1);
    this->schedule(schedule_selector( MyBeat::autoCreateBlock ), 5);
    this->schedule(schedule_selector(MyBeat::addTime), 1);
    MyBall *ball = MyBall::createball("ball.png");
    ball->setPosition(ccp(size.width*0.5, size.height*0.5));
    addChild(ball,1,7);      //the ball is 7 in tag
    streak = CCMotionStreak::create(0.3, 0, 50, ccWHITE, "ball.png");
    streak->setPosition(ccp(size.width/2, size.height/2));
    addChild(streak,0,40);//?????????????????position
    
    arrayBlock = CCArray::create();
    CC_SAFE_RETAIN(arrayBlock);
    for(int i=0;i<3;i++){
        MyBlock* block = MyBlock::create("block.jpg",CCRANDOM_0_1()*3+1);
        arrayBlock->addObject(block);
        addChild(block,2,5);
    }
    
    //add score label
    CCLabelTTF *score = CCLabelTTF::create("score:", "MarkerFelt-Thin", 30);
    score->setPosition(ccp(size.width*0.8, size.height*0.1));
    score->setColor(ccc3(192, 168, 1));
    addChild(score,110,0);
    
    CCLabelTTF *strScore = CCLabelTTF::create("0", "MarkerFelt-Thin", 30);
    strScore->setPosition(ccp(size.width*0.9, size.height*0.1));
    strScore->setColor(ccc3(192, 168, 1));
    addChild(strScore,110,9);    //the score is 9 in tag

    //add time label
    CCLabelTTF *time = CCLabelTTF::create("time", "MarkerFelt-Thin", 30);
    time->setPosition(ccp(size.width*0.1,size.height*0.1 ));
    time->setColor(ccc3(192, 168, 1));
    addChild(time,110,0);
    
    CCLabelTTF *strTime = CCLabelTTF::create("0:00", "MatkerFelt-Thin", 30);
    strTime->setPosition(ccp(size.width*0.2, size.height*0.1));
    strTime->setColor(ccc3(192, 168, 1));
    addChild(strTime,110,10);       //the time is 10 in tag
    
    //make the car
    MyCar *car = MyCar::create("car.png");
    car->setPosition(ccp(CCDirector::sharedDirector()->getWinSize().width*0.5, CCDirector::sharedDirector()->getWinSize().height*0.15));
    addChild(car,2,6);     //the car is 6 in tag
    
    
    //add the heart
    CCSprite *heart1 = CCSprite::create("heart.png");
    heart1->setPosition(ccp(size.width/5, size.height-50));
    addChild(heart1,100,100);
    CCSprite *heart2 = CCSprite::create("heart.png");
    heart2->setPosition(ccp(size.width/5+50, size.height-50));
    CCSprite *heart3 = CCSprite::create("heart.png");
    heart3->setPosition(ccp(size.width/5+100, size.height-50));
    addChild(heart2,100,200);
    addChild(heart3,100,300);

    CCSprite *gameBroad = CCSprite::create("gameGround.png");
    gameBroad->setPosition(ccp(size.width*0.5,size.height*0.5));
    CCLabelTTF *broad = CCLabelTTF::create("-------------------------------------------", "MarkerFelt-Thin", 40);
    broad->setColor(ccc3(172, 196, 33));
    broad->setPosition(ccp(size.width*0.5, size.height*0.16));
    addChild(gameBroad,2,1);
    addChild(broad,0,1);
    return true;
}

void MyBeat::autoCreateBlock(){
    arrayBlock = CCArray::create();
    CC_SAFE_RETAIN(arrayBlock);
    int randomCount = CCRANDOM_0_1()*7;
    for(int i=0;i<randomCount;i++){
        MyBlock* block = MyBlock::create("block.jpg",CCRANDOM_0_1()*3+1);
        arrayBlock->addObject(block);
        addChild(block,2,5);
    }

            
}

MyBall *MyBeat::getBall(){
    MyBall *ball = (MyBall *)MyBeat::sharedWorld()->getChildByTag(7);
    return ball;
}

MyCar *MyBeat::getCar(){
    MyCar *car = (MyCar *)MyBeat::sharedWorld()->getChildByTag(6);
    return car;
}

CCArray* MyBeat::getArrayForBlock(){
    return arrayBlock;
}


void MyBeat::loseGame(){
    CCSize size = CCDirector::sharedDirector()->getWinSize();
    CCSprite *label = CCSprite::create("lose.png");
    label->setPosition(ccp(size.width*0.5, size.height*0.6));
    CCLayerColor *layer = CCLayerColor::create(ccc4(0,0,0,200), size.width, size.height);
    layer->addChild(label);
    addChild(layer,100);
    CCLabelTTF *back = CCLabelTTF::create("Back", "MarkerFelt-Thin",60);
    CCMenuItemLabel *menuLabel = CCMenuItemLabel::create(back, this, menu_selector(MyBeat::backMenu));
    menuLabel->setPosition(ccp(0, -50));
    CCMenu *menu = CCMenu::create(menuLabel,NULL);
    this->addChild(menu,100);
    //CCDirector::sharedDirector()->pause();
            this->unscheduleAllSelectors();
}
void MyBeat::winGame(){
    SimpleAudioEngine::sharedEngine()->playEffect("win.wav", false);
    
    CCSize size = CCDirector::sharedDirector()->getWinSize();
    CCSprite *label = CCSprite::create("win.png");
    label->setPosition(ccp(size.width/2, size.height/2));
    CCLayerColor *layer = CCLayerColor::create(ccc4(0, 0, 0, 200), size.width, size.height);
    layer->addChild(label);
    addChild(layer,100);
    CCLabelTTF *back = CCLabelTTF::create("Back","MarkerFelt-Thin", 60);
    CCMenuItemLabel *menuLabel = CCMenuItemLabel::create(back, this, menu_selector(MyBeat::backMenu));
    menuLabel->setPosition(ccp(0, -100));
    CCMenu *menu = CCMenu::create(menuLabel,NULL);
    this->addChild(menu,100);
    CCDirector::sharedDirector()->pause();
    this->unscheduleAllSelectors();
}
void MyBeat::backMenu(){

    CCDirector::sharedDirector()->resume();
    CCDirector::sharedDirector()->replaceScene(MyMenu::scene());
}

void MyBeat::addTime(){
    time += 1;
    if(time>=60){
        minTime++;
        time -= 60;}
    CCString *ns = CCString::createWithFormat("%d :%2d",minTime,time);
    std::string strTime = ns->m_sString;
    CCLabelTTF *ttf = (CCLabelTTF *)getChildByTag(10);//????????????????
    ttf->setString(strTime.c_str());
}
MyBeat::~MyBeat(){
    CC_SAFE_DELETE(arrayBlock);
}


