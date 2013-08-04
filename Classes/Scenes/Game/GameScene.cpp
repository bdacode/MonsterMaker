#include "GameScene.h"
#include "Resources/Resource.h"
#include "Util/Util.h"

USING_NS_CC;

namespace MonsterMaker{ namespace Scenes { namespace Game{ 

	bool GameScene::init()
	{
		if( Scene::init() )
		{
			CCLOG("Game Scene Initialize");

			auto pLayer = GameLayer::create();
			this->addChild(pLayer,0);
			

			// 달력 레이어 배치
			auto pCalenderNode = CalendarNode::create();
			this->addChild(pCalenderNode,1);
			pCalenderNode->setAnchorPoint(Util::anchorLeftTop);
			pCalenderNode->setPosition(Util::posLeftTop(10,10));
			return true;
		}
		else
		{
			return false;
		}
	}


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

	/************************************************************************/
	/* ClanderLayer Implement                                                                    
	/************************************************************************/

	bool CalendarNode::init()	// 초기화
	{
		if(Node::init()){
			CCLOG("Calender Layer Initialize");
			
			// Set Size 
			
			Size layerSize = Size(140.0f,80.0f);
			Point origin = Director::getInstance()->getVisibleOrigin();
			this->setContentSize(layerSize);

			// 배경 불러오기

			CCLOG("Calender Node Load background");
			Sprite *pBackground = Sprite::create(NSPRITE::Calender);
			pBackground->setPosition(POS(layerSize.width/2,layerSize.height/2));
			this->addChild(pBackground,0);


			// 초기화
			pYearLabel	= LabelTTF::create("100",		NFONT::MENU_FONT1,	FONT_SIZE(20));
			pMonthLabel = LabelTTF::create("1",		NFONT::MENU_FONT1,	FONT_SIZE(20));
			pDayLabel	= LabelTTF::create("1",		NFONT::MENU_FONT1,	FONT_SIZE(20));
			pWeekLabel	= LabelTTF::create("월요일",	NFONT::MENU_FONT1,	FONT_SIZE(20));

			// 위치지정
			pYearLabel	->setPosition(POS(layerSize.width/2,		layerSize.height-15));
			pMonthLabel	->setPosition(POS(layerSize.width*0.2,	layerSize.height*0.5));
			pDayLabel	->setPosition(POS(layerSize.width*0.2,	layerSize.height*0.2));
			pWeekLabel	->setPosition(POS(layerSize.width*0.7,	layerSize.height*0.4));

			// 노드 추가
			this->addChild(pYearLabel,1);
			this->addChild(pMonthLabel,1);
			this->addChild(pDayLabel,1);
			this->addChild(pWeekLabel,1);

			return true;
		}

		else{
			CCLOG("Calender Super Node Initialize failed");
			return false;
		}
	}

}}}