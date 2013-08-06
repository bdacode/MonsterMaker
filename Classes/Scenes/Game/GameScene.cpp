#include "GameScene.h"
#include "Resources/Resource.h"
#include "Util/Util.h"

USING_NS_CC;

namespace MonsterMaker{ namespace Scenes { namespace Games{ 
	/************************************************************************/
	/* GameScene 구현부                                                                    
	/************************************************************************/

	bool GameScene::init()		// 게임씬 초기화 및 Layer 위치 배치
	{
		if( Scene::init() )
		{
			CCLOG("Game Scene Initialize");

			auto pLayer = GameLayer::create();
			this->addChild(pLayer,0);

			/*
		 	 *	달력 레이어 배치
			 */

			auto *pCalenderNode = CalendarNode::create();
			pCalenderNode->setAnchorPoint(Utils::anchorLeftTop);		// 좌측상단을 기준점으로 한다.
			pCalenderNode->setPosition(Utils::posLeftTop(10,10));		// 여백을 지정한다.
			this->addChild(pCalenderNode,1);
			
		
			

			/*
			 *	메뉴 노드 배치
			 */

			auto *pMenuNode = MenuNode::create();
			pMenuNode->setPosition(POS(0,0));
			this->addChild(pMenuNode,1);
			
			/*
			 *	리소스 노드 배치
			 */

			auto *pResourceNode = ResourceNode::create();
			pResourceNode->setAnchorPoint(Utils::anchorRightTop);		// 앵커 포인트 우상단
			pResourceNode->setPosition(Utils::posRightTop());		// 위치 및 여백지정
			this->addChild(pResourceNode,1);


			return true;
		}
		else
		{
			return false;
		}
	}

	/************************************************************************/
	/* GameLayer 구현부                                                                    
	/************************************************************************/

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
			pBack->setPosition(POS(layerSize.width/2,layerSize.height/2));
			CC_BREAK_IF(!pBack);
			this->addChild(pBack,0);

			Sprite *pBackTop = Sprite::create(NBACKGROUND::CaveUp);
			pBackTop->setPosition(POS(layerSize.width/2,layerSize.height-pBackTop->getContentSize().height/2));
			CC_BREAK_IF(!pBackTop);
			this->addChild(pBackTop,5);

			Sprite *pBackBottom = Sprite::create(NBACKGROUND::CaveDown);
			pBackBottom->setPosition(POS(layerSize.width/2,pBackTop->getContentSize().height/2));
			CC_BREAK_IF(!pBackBottom);
			this->addChild(pBackBottom,1);
			//

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
	/* ClanderLayer 구현부                                                        
	/************************************************************************/

	bool CalendarNode::init()	// 캘린더 노드 초기화
	{
		if(Node::init()){
			CCLOG("Calendernode Initialize");

			// Set Size 
			auto layerSize = Size(140.0f,80.0f);

			// 배경 불러오기
			Sprite *pBackground = Sprite::create(NSPRITE::Calender);
			pBackground->setPosition(Point(layerSize.width/2,layerSize.height/2));
			this->setContentSize(layerSize);
			this->addChild(pBackground,0);

			// 초기화
			pYearLabel	= LabelTTF::create("100",		NFONT::MENU_FONT1,	FONT_SIZE(20));
			pMonthLabel = LabelTTF::create("1",			NFONT::MENU_FONT1,	FONT_SIZE(20));
			pDayLabel	= LabelTTF::create("1",			NFONT::MENU_FONT1,	FONT_SIZE(20));
			pWeekLabel	= LabelTTF::create("월요일",	NFONT::MENU_FONT1,	FONT_SIZE(20));

			// 위치지정
			pYearLabel	->setPosition(Point(layerSize.width/2,	layerSize.height-15));
			pMonthLabel	->setPosition(Point(layerSize.width*0.2,	layerSize.height*0.5));
			pDayLabel	->setPosition(Point(layerSize.width*0.2,	layerSize.height*0.2));
			pWeekLabel	->setPosition(Point(layerSize.width*0.7,	layerSize.height*0.4));

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

	/************************************************************************/
	/* MenuNode 구현부                                                                    
	/************************************************************************/

	bool MenuNode::init()	// 메뉴 노드 초기화
	{
		if(Node::init()){
			CCLOG("MenuNode Init");
			/*
			 *	레이어 크기 지정
			 */
			Size layerSize = Size(Utils::viewSize.width,Utils::viewSize.height/8);
			this->setContentSize(layerSize);

			/*
			 *	버튼 초기화
			 */			

			MenuItemImage *item1 = MenuItemImage::create(NICON::Friend,	 NICON::Friend_s	);		// 친구목록
			MenuItemImage *item2 = MenuItemImage::create(NICON::Train,	 NICON::Train_s		);		// 수행
			MenuItemImage *item3 = MenuItemImage::create(NICON::Arena,	 NICON::Arena_s		);		// 투기장
			MenuItemImage *item4 = MenuItemImage::create(NICON::Storage, NICON::Storage_s	);		// 창고
			MenuItemImage *item5 = MenuItemImage::create(NICON::Castle,	 NICON::Castle_s	);		// 외출

			/*
			 *	메뉴 정렬을 위한 변수 설정
			 */
			float	itemWidth	= item1->getContentSize().width;
			float	itemHeight	= item1->getContentSize().height;
			int		iRows = 5;

			/*
			 *	메뉴 화면에 맞게 정렬
			 */
			Menu *pMenu = Menu::create(item1,item2,item3,item4,item5,NULL);
			pMenu->alignItemsHorizontallyWithPadding((layerSize.width-itemWidth*5)/iRows);
			pMenu->setPosition(layerSize.width/2,itemHeight);
			this->addChild(pMenu,1);

			/*
			 *	메뉴 텍스트 초기화
			 */
			LabelTTF *text1  = LabelTTF::create(NUITEXT::Friend,	NFONT::MENU_FONT1,	FONT_SIZE(20));
			LabelTTF *text2  = LabelTTF::create(NUITEXT::Train,		NFONT::MENU_FONT1,	FONT_SIZE(20));
			LabelTTF *text3  = LabelTTF::create(NUITEXT::Arena,		NFONT::MENU_FONT1,	FONT_SIZE(20));
			LabelTTF *text4  = LabelTTF::create(NUITEXT::Storage,	NFONT::MENU_FONT1,	FONT_SIZE(20));
			LabelTTF *text5  = LabelTTF::create(NUITEXT::Castle,	NFONT::MENU_FONT1,	FONT_SIZE(20));

			/*
			 *	텍스트를 메뉴 아이템 중앙 하단으로 붙이기
			 */

			Point textPos(Point(itemWidth/2,0)); // 테스트가 들어가야할 좌표를 구한다.

			text1->setAnchorPoint(Utils::anchorCenterTop);		// 텍스트의 앵커포인트를 중앙 상단으로 한다.
			text2->setAnchorPoint(Utils::anchorCenterTop);
			text3->setAnchorPoint(Utils::anchorCenterTop);
			text4->setAnchorPoint(Utils::anchorCenterTop);
			text5->setAnchorPoint(Utils::anchorCenterTop);
			
			text1->setPosition(textPos);
			text2->setPosition(textPos);
			text3->setPosition(textPos);
			text4->setPosition(textPos);
			text5->setPosition(textPos);
			
			/*
			 *	메뉴 아이템에 텍스트 addchild 하기
			 */

			item1->addChild(text1,1);
			item2->addChild(text2,1);
			item3->addChild(text3,1);
			item4->addChild(text4,1);
			item5->addChild(text5,1);	

			return true;
		}

		else{
			CCLOGERROR("MenuNode super Init failed");
			return false;
		}

	}

	/************************************************************************/
	/* ResourceNode 클래스 구현부                                                                    
	/************************************************************************/

	bool ResourceNode::init()	// 리소스 노드 초기화
	{
		if(Node::init()){
			CCLOG("ResourceNode Init");
			
			/*
			 *	레이어 크기 지정
			 */

			Size layerSize = Size(Utils::viewSize.width,Utils::viewSize.height/10);
			this->setContentSize(layerSize);

			/*
			 *	스프라이트를 초기화
			 */

			// 빈 하트 스프라이트를 생성 및 배치
			Sprite *pHeartBlankSpr[6];
			for(int i = 0; i < 6 ; i ++) {
				pHeartBlankSpr[i] = Sprite::create(NSPRITE::HeartBlank);
				pHeartBlankSpr[i]->setPosition(Point(layerSize.width*0.55+(pHeartBlankSpr[i]->getContentSize().width/2+20.0f)*i,layerSize.height/2));
				this->addChild(pHeartBlankSpr[i],1);
			}

			// 꽉찬 하트 아이콘을 생성 및 배치
			for(int i = 0; i < 6 ; i ++) {
				m_pHeartSpr[i] = CCSprite::create(NSPRITE::Heart);
				m_pHeartSpr[i]->setPosition(Point(layerSize.width*0.55+(m_pHeartSpr[i]->getContentSize().width/2+20.0f)*i,layerSize.height/2));
				m_pHeartSpr[i]->setVisible(false);
				CC_BREAK_IF(!m_pHeartSpr);
				this->addChild(m_pHeartSpr[i],2);
			}


			// 수정 스프라이트를 생성 및 배치
			Sprite *pCrystalSpr = Sprite::create(NSPRITE::Crystal);
			pCrystalSpr->setPosition(Point(layerSize.width/2.5, layerSize.height/2));
			this->addChild(pCrystalSpr,1);

			// 골드 스프라이트를 생성 및 배치
			Sprite *pGoldSpr = Sprite::create(NSPRITE::Gold);
			pGoldSpr->setPosition(Point(layerSize.width*0.9, 0));
			this->addChild(pGoldSpr,1);

			// 수정 숫자 레이블을 생성 및 배치
			pCrystalLabel = LabelTTF::create("0",NFONT::MENU_FONT1,FONT_SIZE(20));
			pCrystalLabel->setPosition(Point(layerSize.width/3+40.0f, layerSize.height/2));
			//this->addChild(pCrystalLabel,1);


			// 골드 숫자 레이블을 생성 및 배치
			pGoldLabel = LabelTTF::create("100",NFONT::MENU_FONT1,FONT_SIZE(20),Size(200,30),Label::HAlignment::RIGHT);
			pGoldLabel->setAnchorPoint(Point(1.0,0.5));
			pGoldLabel->setPosition(Point(pGoldSpr->getPositionX()-30,pGoldSpr->getPositionY()));
			this->addChild(pGoldLabel,1);

			// 이 레이어는 실시간 갱신
			this->scheduleUpdate();

			return true;
		}

		else {
			CCLOGERROR("ResourceNode Init Failed");
			return false;

		}
	}

	void ResourceNode::onEnterTransitionDidFinish()
	{
		
	}

	void ResourceNode::onExitTransitionDidStart()
	{
		
	}

	void ResourceNode::update( float delta ) // 자원 정보 실시간 갱신
	{
		//pCrystalLabel->setString();
		//pGoldLabel->setString();
	}

}}}