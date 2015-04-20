LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := game_shared

LOCAL_MODULE_FILENAME := libgame

LOCAL_SRC_FILES := hellocpp/main.cpp \
                   ../../Classes/AppDelegate.cpp \
                   ../../Classes/Global.cpp \
                   ../../Classes/AppSettings.cpp \
                    ../../Classes/Bullets.cpp \
                   ../../Classes/TitleScene.cpp \
                   ../../Classes/SettingScene.cpp \
                   ../../Classes/GameScene.cpp \
                   ../../Classes/Hero.cpp \
                   ../../Classes/Bee.cpp \
                   ../../Classes/VisibleRect.cpp \
                   ../../Classes/Monster.cpp \
                   ../../Classes/EnemyRobot.cpp \
                   ../../Classes/PlatForm.cpp \
                   ../../Classes/GameSuccess.cpp \
                   ../../Classes/GameOver.cpp \
                   
LOCAL_C_INCLUDES := $(LOCAL_PATH)/../../Classes                   

LOCAL_WHOLE_STATIC_LIBRARIES := cocos2dx_static cocosdenshion_static cocos_extension_static
            
include $(BUILD_SHARED_LIBRARY)

$(call import-module,CocosDenshion/android) \
$(call import-module,cocos2dx) \
$(call import-module,extensions)
