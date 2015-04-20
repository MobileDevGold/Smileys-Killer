//
//  SmileysKillerAppDelegate.cpp
//  SmileysKiller
//
//  Created by TaiMing on 10/14/13.
//  Copyright __MyCompanyName__ 2013. All rights reserved.
//

#include "AppDelegate.h"
#include <vector>
#include <string>
#include "TitleScene.h"
#include "AppMacros.h"
#include "Global.h"
#include "cocos2d.h"
#include "SimpleAudioEngine.h"
 

USING_NS_CC;
using namespace std;
using namespace CocosDenshion;

AppDelegate::AppDelegate()
{

}

AppDelegate::~AppDelegate()
{
}

bool AppDelegate::applicationDidFinishLaunching()
{
    // initialize director
    CCDirector* pDirector = CCDirector::sharedDirector();
    CCEGLView* pEGLView = CCEGLView::sharedOpenGLView();
    
    pDirector->setOpenGLView(pEGLView);
    
    // Set the design resolution
    pEGLView->setDesignResolutionSize(designResolutionSize.width, designResolutionSize.height, kResolutionNoBorder);
    
	CCSize frameSize = pEGLView->getFrameSize();
    
    vector<string> searchPath;
    
   if (frameSize.width == smallResource.size.width) {
       
       sprintf(g_deviceType, "");sprintf(g_deviceType_, "");g_fScaleX_ = 0.5f;g_fScalX = 0.5f;
       
    }else if(frameSize.width == middleResource.size.width){
       
        sprintf(g_deviceType, "-hd");sprintf(g_deviceType_, "@2x");g_fScaleX_ = 0.5f;g_fScalX = 1.0f;
        
    }else if(frameSize.width == fullResource.size.width){
       
        sprintf(g_deviceType, "-568");sprintf(g_deviceType_, "@2x");g_fScaleX_ = 0.5f;g_fScalX = 1.0f;
        
    }else if(frameSize.width == mediumResource.size.width){
      
        sprintf(g_deviceType, "-ipad");sprintf(g_deviceType_, "@2x");g_fScaleX_ = 0.5f;g_fScalX = 1.0f;
        
    }else if(frameSize.width == largeResource.size.width){
      
        sprintf(g_deviceType, "-ipad");sprintf(g_deviceType_, "@2x");g_fScaleX_ =0.5f;g_fScalX = 1.0f;
        
    }else{
        
          sprintf(g_deviceType, "-ipad");sprintf(g_deviceType_, "@2x");g_fScaleX_ =0.5f;g_fScalX = 1.0f;
    }

    
	if (frameSize.height > mediumResource.size.height)
	{
        searchPath.push_back(largeResource.directory);
        pDirector->setContentScaleFactor(2.0f);
        
	}
    // if the frame's height is larger than the height of small resource size, select medium resource.
    else if (frameSize.height > smallResource.size.height)
    {
        searchPath.push_back(mediumResource.directory);
        pDirector->setContentScaleFactor(2.0f);
         
    }
    // if the frame's height is smaller than the height of medium resource size, select small resource.
	else
    {
        searchPath.push_back(smallResource.directory);
        pDirector->setContentScaleFactor(1.0f);
         
    }
    
    CCLOG("FrameSizeWidth == %f , FrameSize Height == %f" , frameSize.width , frameSize.height);
    
    // set searching path
    CCFileUtils::sharedFileUtils()->setSearchPaths(searchPath);
	
    // turn on display FPS
    pDirector->setDisplayStats(true);
    
    // set FPS. the default value is 1.0/60 if you don't call this
    pDirector->setAnimationInterval(1.0 / 60);
     
    
    // create a scene. it's an autorelease object
    CCScene *pScene = Title::scene();
    
    // run
    pDirector->runWithScene(pScene);
    
    return true;

}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground()
{
    CCDirector::sharedDirector()->stopAnimation();
    SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
    SimpleAudioEngine::sharedEngine()->pauseAllEffects();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground()
{
    CCDirector::sharedDirector()->startAnimation();
    SimpleAudioEngine::sharedEngine()->resumeBackgroundMusic();
    SimpleAudioEngine::sharedEngine()->resumeAllEffects();
}
