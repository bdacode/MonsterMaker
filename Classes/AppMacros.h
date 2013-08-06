#ifndef __APPMACROS_H__
#define __APPMACROS_H__
#include "cocos2d.h"

// Android Base Resolution
/*
1. xSmall (240x320)
2. Small. (320x480)
3. Medium (480x800)
4. Large (720x1280)
5. xLarge (2048x1536)
*/


#define WORK_PLATFORM = CC_PLATFORM_ANDROID;		// Current work platform


#define ANDROID_RESOLUTION_320X480    0		// Galaxy S1		 small
#define ANDROID_RESOLUTION_480X800    1		// Galaxy S2		 medium
#define ANDROID_RESOLUTION_720X1280   2		// Galaxy S3		 large
//#define ANDROID_RESOLUTION_800X1280   3		// Galaxy Tab		 Xlarge

// Iphone Base Resolution
#define IPHONE_RESOLUTION_320X480	4		// Iphone1	
#define IPHONE_RESOLUTION_640X960	5		// Iphone_ret, iphone3
#define IPHONE_RESOLUTION_640X1136	6		// iphone5


#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS
	#define TARGET_DESIGN_RESOLUTION_SIZE  IPHONE_RESOLUTION_640X960		// iphone_ret Work
#elif CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
	#define TARGET_DESIGN_RESOLUTION_SIZE  ANDROID_RESOLUTION_480X800		// Galaxy S3 Design Work
#else	// Win32
	#define TARGET_DESIGN_RESOLUTION_SIZE  ANDROID_RESOLUTION_480X800		// Galaxy S3 Design Work
#endif

typedef struct tagResource
{
	cocos2d::Size size;
	char directory[100];
}Resource;

static Resource smallResource	=  { cocos2d::Size(320, 480),  "ASmall" };
static Resource mediumResource	=  { cocos2d::Size(480, 800),  "AMedium"   };
static Resource largeResource	=  { cocos2d::Size(720, 1280), "ALarge" };
static Resource xlargeResource	=  { cocos2d::Size(800, 1280), "AXLarge" };

#if (TARGET_DESIGN_RESOLUTION_SIZE == ANDROID_RESOLUTION_320X480)			
static cocos2d::CSize designResolutionSize = cocos2d::Size(320, 480);	
#elif (TARGET_DESIGN_RESOLUTION_SIZE == ANDROID_RESOLUTION_480X800)				
static cocos2d::Size designResolutionSize = cocos2d::Size(480, 800);
#elif (TARGET_DESIGN_RESOLUTION_SIZE == ANDROID_RESOLUTION_720X1280)
static cocos2d::Size designResolutionSize = cocos2d::Size(720, 1280);	
//#elif (TARGET_DESIGN_RESOLUTION_SIZE == ANDROID_RESOLUTION_800X1280)			
//static cocos2d::Size designResolutionSize = cocos2d::Size(800, 1280);	
#else
#error unknown target design resolution!
#endif


#endif /* __APPMACROS_H__ */
