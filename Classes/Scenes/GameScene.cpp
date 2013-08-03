#include "GameScene.h"
#include "Resources/Resource.h"
#include "Components/Player.h"
//#include "GameMenuNode.h"	// Game Menu Layer
//#include "CalenderNode.h"	// Calender Node
//#include "ResourceNode.h"	// Resource Node

USING_NS_CC;

namespace MonsterMaker{ namespace Scenes { namespace Game{ 

	bool GameLayer::init(){

		bool bRet = false;
		do{
			/************************************************************************/
			/* Super Init First
			/************************************************************************/
			// Super Init & Content Size Init
			CC_BREAK_IF(!Layer::init());
			CCLOG("Game Layer Initialize");

			Size layerSize = Director::getInstance()->getVisibleSize();
			Point origin = Director::getInstance()->getVisibleOrigin();
			this->setContentSize(layerSize);

			//*************************************************************************/
			//* 배경 불러오기                                                                    
			//*************************************************************************/
			
			Sprite *pBack = Sprite::create(NBACKGROUND::CaveBackground);
			pBack->setPosition(Point(layerSize.width/2,layerSize.height/2));
			CC_BREAK_IF(!pBack);
			this->addChild(pBack,0);
			
			Sprite *pBackTop = Sprite::create(NBACKGROUND::CaveUp);
			pBackTop->setPosition(Point(layerSize.width/2,layerSize.height-pBackTop->getContentSize().height/2));
			CC_BREAK_IF(!pBackTop);
			this->addChild(pBackTop,5);

			Sprite *pBackBottom = Sprite::create(NBACKGROUND::CaveDown);
			pBackBottom->setPosition(Point(layerSize.width/2,pBackTop->getContentSize().height/2));
			CC_BREAK_IF(!pBackBottom);
			this->addChild(pBackBottom,1);
			//

			/////************************************************************************/
			/////* Calender Node Loading                                                                 
			/////************************************************************************/
			//CalenderNode *pCalLayer = CalenderNode::create();
			//pCalLayer->setPosition(ccp(10,winSize.height-pCalLayer->getContentSize().height-10));
			//this->addChild(pCalLayer, 5);


			/////************************************************************************/
			/////* Menu Node Loading                                                                 
			/////************************************************************************/
			//GameMenuNode *pMenuLayer = GameMenuNode::create();
			//pMenuLayer->setPosition(ccp(0,0));
			//this->addChild(pMenuLayer,5);

			/////************************************************************************/
			/////* Resource Node Loading                                                                    
			/////************************************************************************/
			//ReesourceNode *pResourceNode = ReesourceNode::create();
			//pResourceNode->setPosition(ccp(0,winSize.height));
			//this->addChild(pResourceNode,5);

			bRet = true;

		} while (0);

		return bRet;
	}

	void GameLayer::menuSceneTransitionCallback( Object *pSender )
	{
		CCLOG("-- Menu Castle Call Back");
	}


	bool GameScene::init()
	{
		if( Scene::init() )
		{
			auto *pLayer = GameLayer::create();
			this->addChild(pLayer);

			return true;
		}
		else
		{
			return false;
		}
	}

}}}