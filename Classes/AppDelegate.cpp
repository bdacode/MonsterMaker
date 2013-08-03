#include "AppDelegate.h"
#include "Scenes/MainScene.h"
#include "AppMacros.h"

#include <vector>
#include <string>
using namespace std;

USING_NS_CC;


AppDelegate::AppDelegate() {

}

AppDelegate::~AppDelegate() 
{
}

bool AppDelegate::applicationDidFinishLaunching() {
	// initialize director
	Director* pDirector = Director::getInstance();
	EGLView* pEGLView = EGLView::getInstance();

	pDirector->setOpenGLView(pEGLView);


	// Set the design resolution
	pEGLView->setDesignResolutionSize(designResolutionSize.width, designResolutionSize.height,ResolutionPolicy::NO_BORDER);
	Size frameSize = pEGLView->getFrameSize();
	vector<string> searchPath;

	// set Global Size
	static cocos2d::Size g_visibleSize = Size(cocos2d::Director::getInstance()->getVisibleSize());
	static cocos2d::Point g_origin	 =  Point(cocos2d::Director::getInstance()->getVisibleOrigin());



	if (frameSize.height > mediumResource.size.height)
	{
		//XLarge
		if(frameSize.width > largeResource.size.width){
			searchPath.push_back(xlargeResource.directory);
			pDirector->setContentScaleFactor(MIN(xlargeResource.size.height/designResolutionSize.height, xlargeResource.size.width/designResolutionSize.width));
		}
		// Large
		else {
			searchPath.push_back(largeResource.directory);
			pDirector->setContentScaleFactor(MIN(largeResource.size.height/designResolutionSize.height, largeResource.size.width/designResolutionSize.width));
		}
	}
	//Medium
	else if (frameSize.height > smallResource.size.height)
	{
		searchPath.push_back(mediumResource.directory);
		pDirector->setContentScaleFactor(MIN(mediumResource.size.height/designResolutionSize.height, mediumResource.size.width/designResolutionSize.width));
	}
	// small
	else
	{
		searchPath.push_back(smallResource.directory);
		pDirector->setContentScaleFactor(MIN(smallResource.size.height/designResolutionSize.height, smallResource.size.width/designResolutionSize.width));
	}

	// set searching path
	FileUtils::getInstance()->setSearchPaths(searchPath);

	// turn on display FPS
	pDirector->setDisplayStats(true);

	// set FPS. the default value is 1.0/60 if you don't call this
	pDirector->setAnimationInterval(1.0 / 60);

	// create a scene. it's an autorelease object
	Scene *pScene = MonsterMaker::Scenes::Main::create();

	// run
	pDirector->runWithScene(pScene);

    return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground() {
    Director::getInstance()->stopAnimation();

    // if you use SimpleAudioEngine, it must be pause
    // SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() {
    Director::getInstance()->startAnimation();

    // if you use SimpleAudioEngine, it must resume here
    // SimpleAudioEngine::sharedEngine()->resumeBackgroundMusic();
}
