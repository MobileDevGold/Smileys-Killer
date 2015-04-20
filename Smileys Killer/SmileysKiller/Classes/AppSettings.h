//
//  AppSettings.h
//  Daimond_Beans
//
//  Created by MiniMac on 9/13/13.
//
//
#ifndef __APPSETTINGS__
#define __APPSETTINGS__
#include "cocos2d.h"
#include <iostream>
using namespace cocos2d;
using namespace std;

class AppSettings:public CCSprite{


public:
    
    AppSettings();
    
     
    void setGamestate();
    void LoadGameData();
    
    void setBgSound(bool state);
    bool getBgSound();
    void seteffectSound(bool state);
    bool geteffectSound();
    void setHeighScore(int score);
    void playBgm();
    void playEffect(const char* file);
    void stopBgm();
    int getHighScore();
    void superType(int number);
    int getSuperType();
    
    void setLevel(int nLevel);
    int getLevel();
    
    
     
    CCDictionary* m_pValueDict;
private:
    vector<string> m_defaultSearchPathArray;
    vector<string> m_defaultResolutionsOrderArray;

private:
      
    bool m_nbg;
    bool m_neffect;
  
    int m_nscore;
    
    CREATE_FUNC(AppSettings);
};

#endif /* defined(__Daimond_Beans__AppSettings__) */