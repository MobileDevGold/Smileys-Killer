//
//  AppSettings.cpp
//  Daimond_Beans
//
//  Created by MiniMac on 9/13/13.
//
//

#include "AppSettings.h"
#include "cocos2d.h"
#include "SimpleAudioEngine.h"
#include "Global.h"
//#include "GameSettings.h"
using namespace cocos2d;
using namespace CocosDenshion;
using namespace std;
AppSettings::AppSettings(){
    
    m_nbg = false;
    m_neffect = false;
     
    
}
void AppSettings::setGamestate(){
   
    
    CCDictionary *root = CCDictionary::create();
    CCString *string = CCString::create("data");
    root->setObject(string, "data_key");
    
    CCDictionary *dictInArray = CCDictionary::create();
    dictInArray->setObject(CCString::create("name"), "player_Name");
   
    char content[100] = {0};
    sprintf(content, "%d" ,g_nGameHighScore);
    dictInArray->setObject(CCString::create(content), "game_highscore");
    sprintf(content, "%d" ,g_nGameScore);
    dictInArray->setObject(CCString::create(content), "game_score");
    sprintf(content, "%d" ,g_nGameLevel);
    dictInArray->setObject(CCString::create(content), "game_level");
    
    root->setObject(dictInArray, "data");
   
    std::string writablePath = CCFileUtils::sharedFileUtils()->getWritablePath();
    std::string fullPath = writablePath + "Setting.plist";
    if(root->writeToFile(fullPath.c_str()))
        CCLog("see the plist file at %s", fullPath.c_str());
    else
        CCLog("write plist file failed");
    
 }
void AppSettings::LoadGameData(){
   
     
    std::string writablePath = CCFileUtils::sharedFileUtils()->getWritablePath();
    std::string fullPath = writablePath + "Setting.plist";
    CCLog("see the plist file at %s", fullPath.c_str());
    
    CCDictionary* root = CCDictionary::createWithContentsOfFile(fullPath.c_str());
    CCDictionary* dic = (CCDictionary*)root->objectForKey("data");
     
    
    g_nGameHighScore = atoi(dic->valueForKey("game_highscore")->getCString());
    g_nGameScore = atoi(dic->valueForKey("game_score")->getCString());
    g_nGameLevel = atoi(dic->valueForKey("game_level")->getCString());
    
    CCLOG("g_nGameHighScore == %d" , g_nGameHighScore);
    CCLOG("g_nGameScore === %d" ,g_nGameScore);
    CCLOG("g_nGameLevel ===%d", g_nGameLevel );
 
 
}

void AppSettings:: setLevel(int number){
    
    CCUserDefault::sharedUserDefault()->setIntegerForKey("level", number);
}
int AppSettings:: getLevel(){
    
    return CCUserDefault::sharedUserDefault()->getIntegerForKey("level");
}

void AppSettings::setBgSound(bool state){
   
    CCUserDefault::sharedUserDefault()->setBoolForKey("bgm", state);
   
}
bool AppSettings::getBgSound(){
    bool state = CCUserDefault::sharedUserDefault()->getBoolForKey("bgm");
    return state;
}
void AppSettings::seteffectSound(bool state){
    
    CCUserDefault::sharedUserDefault()->setBoolForKey("effect", state);

}
bool AppSettings::geteffectSound(){
    bool state = CCUserDefault::sharedUserDefault()->getBoolForKey("effect");
    return state;
}

void AppSettings::setHeighScore(int score){
 
    CCUserDefault::sharedUserDefault()->setIntegerForKey("highscore", score);
    
}

int AppSettings::getHighScore(){
 
    return 0;
}

void AppSettings::playBgm(){
    
     
    if (getBgSound()){
         SimpleAudioEngine::sharedEngine()->playBackgroundMusic("loop.wav", true);
    }else{
          SimpleAudioEngine::sharedEngine()->stopBackgroundMusic();
    }
    SimpleAudioEngine::sharedEngine()->setBackgroundMusicVolume(0.3f);
    
}
void AppSettings:: stopBgm(){
    SimpleAudioEngine::sharedEngine()->stopBackgroundMusic();
}
void AppSettings::playEffect(const char* file){
     
    if (!geteffectSound()) {
        SimpleAudioEngine::sharedEngine()->playEffect("bullet.wav"); 
    }else{
        SimpleAudioEngine::sharedEngine()->stopAllEffects();
    }

     SimpleAudioEngine::sharedEngine()->setEffectsVolume(10.0f);
}
 