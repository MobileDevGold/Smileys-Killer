#ifndef __GLOBAL_H__
#define __GLOBAL_H__

#include "cocos2d.h"
//setting variable
extern float g_fScaleX_;
extern float g_fScaleY_;

extern float g_fScalX;
extern float g_fScalY;

extern bool g_bSoundEnable;
extern bool g_bIsExistGameScene;
extern float g_fSoundVolume;
extern float g_fInitStarPosY;
extern int g_nLifeNumber;
extern int g_nGameScore;
extern int g_nGameHighScore;
extern int g_nBestScore;
extern int g_nGameLevel;
extern int g_nGameCoinNum;
extern int g_nStageCoinNum;
extern int g_nLevelProgNum;
extern char highScore[100];
extern char gameScore[100];
extern char gameLevel[100];

extern int retina;
extern char             g_deviceType[0x20];
extern char             g_deviceType_[0x20];
 
#endif // __GLOBAL_H__
