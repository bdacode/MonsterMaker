#include "GameScene.h"
#include "Resources/Resource.h"
#include "Util/Util.h"

USING_NS_CC;

namespace MonsterMaker{ namespace Scenes { namespace Games{ 
	/************************************************************************/
	/* GameScene ������                                                                    
	/************************************************************************/

	bool GameScene::init()		// ���Ӿ� �ʱ�ȭ �� Layer ��ġ ��ġ
	{
		if( Scene::init() )
		{
			CCLOG("Game Scene Initialize");

			auto pLayer = GameLayer::create();
			this->addChild(pLayer,0);

			/*
		 	 *	�޷� ���̾� ��ġ
			 */

			auto *pCalenderNode = CalendarNode::create();
			pCalenderNode->setAnchorPoint(Utils::anchorLeftTop);		// ��������� ���������� �Ѵ�.
			pCalenderNode->setPosition(Utils::posLeftTop(10,10));		// ������ �����Ѵ�.
			this->addChild(pCalenderNode,1);
			
		
			

			/*
			 *	�޴� ��� ��ġ
			 */

			auto *pMenuNode = MenuNode::create();
			pMenuNode->setPosition(POS(0,0));
			this->addChild(pMenuNode,1);
			
			/*
			 *	���ҽ� ��� ��ġ
			 */

			auto *pResourceNode = ResourceNode::create();
			pResourceNode->setAnchorPoint(Utils::anchorRightTop);		// ��Ŀ ����Ʈ ����
			pResourceNode->setPosition(Utils::posRightTop());		// ��ġ �� ��������
			this->addChild(pResourceNode,1);


			return true;
		}
		else
		{
			return false;
		}
	}

	/************************************************************************/
	/* GameLayer ������                                                                    
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
			//* ��� �ҷ�����                                                                    
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
	/* ClanderLayer ������                                                        
	/************************************************************************/

	bool CalendarNode::init()	// Ķ���� ��� �ʱ�ȭ
	{
		if(Node::init()){
			CCLOG("Calendernode Initialize");

			// Set Size 
			auto layerSize = Size(140.0f,80.0f);

			// ��� �ҷ�����
			Sprite *pBackground = Sprite::create(NSPRITE::Calender);
			pBackground->setPosition(Point(layerSize.width/2,layerSize.height/2));
			this->setContentSize(layerSize);
			this->addChild(pBackground,0);

			// �ʱ�ȭ
			pYearLabel	= LabelTTF::create("100",		NFONT::MENU_FONT1,	FONT_SIZE(20));
			pMonthLabel = LabelTTF::create("1",			NFONT::MENU_FONT1,	FONT_SIZE(20));
			pDayLabel	= LabelTTF::create("1",			NFONT::MENU_FONT1,	FONT_SIZE(20));
			pWeekLabel	= LabelTTF::create("������",	NFONT::MENU_FONT1,	FONT_SIZE(20));

			// ��ġ����
			pYearLabel	->setPosition(Point(layerSize.width/2,	layerSize.height-15));
			pMonthLabel	->setPosition(Point(layerSize.width*0.2,	layerSize.height*0.5));
			pDayLabel	->setPosition(Point(layerSize.width*0.2,	layerSize.height*0.2));
			pWeekLabel	->setPosition(Point(layerSize.width*0.7,	layerSize.height*0.4));

			// ��� �߰�
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
	/* MenuNode ������                                                                    
	/************************************************************************/

	bool MenuNode::init()	// �޴� ��� �ʱ�ȭ
	{
		if(Node::init()){
			CCLOG("MenuNode Init");
			/*
			 *	���̾� ũ�� ����
			 */
			Size layerSize = Size(Utils::viewSize.width,Utils::viewSize.height/8);
			this->setContentSize(layerSize);

			/*
			 *	��ư �ʱ�ȭ
			 */			

			MenuItemImage *item1 = MenuItemImage::create(NICON::Friend,	 NICON::Friend_s	);		// ģ�����
			MenuItemImage *item2 = MenuItemImage::create(NICON::Train,	 NICON::Train_s		);		// ����
			MenuItemImage *item3 = MenuItemImage::create(NICON::Arena,	 NICON::Arena_s		);		// ������
			MenuItemImage *item4 = MenuItemImage::create(NICON::Storage, NICON::Storage_s	);		// â��
			MenuItemImage *item5 = MenuItemImage::create(NICON::Castle,	 NICON::Castle_s	);		// ����

			/*
			 *	�޴� ������ ���� ���� ����
			 */
			float	itemWidth	= item1->getContentSize().width;
			float	itemHeight	= item1->getContentSize().height;
			int		iRows = 5;

			/*
			 *	�޴� ȭ�鿡 �°� ����
			 */
			Menu *pMenu = Menu::create(item1,item2,item3,item4,item5,NULL);
			pMenu->alignItemsHorizontallyWithPadding((layerSize.width-itemWidth*5)/iRows);
			pMenu->setPosition(layerSize.width/2,itemHeight);
			this->addChild(pMenu,1);

			/*
			 *	�޴� �ؽ�Ʈ �ʱ�ȭ
			 */
			LabelTTF *text1  = LabelTTF::create(NUITEXT::Friend,	NFONT::MENU_FONT1,	FONT_SIZE(20));
			LabelTTF *text2  = LabelTTF::create(NUITEXT::Train,		NFONT::MENU_FONT1,	FONT_SIZE(20));
			LabelTTF *text3  = LabelTTF::create(NUITEXT::Arena,		NFONT::MENU_FONT1,	FONT_SIZE(20));
			LabelTTF *text4  = LabelTTF::create(NUITEXT::Storage,	NFONT::MENU_FONT1,	FONT_SIZE(20));
			LabelTTF *text5  = LabelTTF::create(NUITEXT::Castle,	NFONT::MENU_FONT1,	FONT_SIZE(20));

			/*
			 *	�ؽ�Ʈ�� �޴� ������ �߾� �ϴ����� ���̱�
			 */

			Point textPos(Point(itemWidth/2,0)); // �׽�Ʈ�� ������ ��ǥ�� ���Ѵ�.

			text1->setAnchorPoint(Utils::anchorCenterTop);		// �ؽ�Ʈ�� ��Ŀ����Ʈ�� �߾� ������� �Ѵ�.
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
			 *	�޴� �����ۿ� �ؽ�Ʈ addchild �ϱ�
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
	/* ResourceNode Ŭ���� ������                                                                    
	/************************************************************************/

	bool ResourceNode::init()	// ���ҽ� ��� �ʱ�ȭ
	{
		if(Node::init()){
			CCLOG("ResourceNode Init");
			
			/*
			 *	���̾� ũ�� ����
			 */

			Size layerSize = Size(Utils::viewSize.width,Utils::viewSize.height/10);
			this->setContentSize(layerSize);

			/*
			 *	��������Ʈ�� �ʱ�ȭ
			 */

			// �� ��Ʈ ��������Ʈ�� ���� �� ��ġ
			Sprite *pHeartBlankSpr[6];
			for(int i = 0; i < 6 ; i ++) {
				pHeartBlankSpr[i] = Sprite::create(NSPRITE::HeartBlank);
				pHeartBlankSpr[i]->setPosition(Point(layerSize.width*0.55+(pHeartBlankSpr[i]->getContentSize().width/2+20.0f)*i,layerSize.height/2));
				this->addChild(pHeartBlankSpr[i],1);
			}

			// ���� ��Ʈ �������� ���� �� ��ġ
			for(int i = 0; i < 6 ; i ++) {
				m_pHeartSpr[i] = CCSprite::create(NSPRITE::Heart);
				m_pHeartSpr[i]->setPosition(Point(layerSize.width*0.55+(m_pHeartSpr[i]->getContentSize().width/2+20.0f)*i,layerSize.height/2));
				m_pHeartSpr[i]->setVisible(false);
				CC_BREAK_IF(!m_pHeartSpr);
				this->addChild(m_pHeartSpr[i],2);
			}


			// ���� ��������Ʈ�� ���� �� ��ġ
			Sprite *pCrystalSpr = Sprite::create(NSPRITE::Crystal);
			pCrystalSpr->setPosition(Point(layerSize.width/2.5, layerSize.height/2));
			this->addChild(pCrystalSpr,1);

			// ��� ��������Ʈ�� ���� �� ��ġ
			Sprite *pGoldSpr = Sprite::create(NSPRITE::Gold);
			pGoldSpr->setPosition(Point(layerSize.width*0.9, 0));
			this->addChild(pGoldSpr,1);

			// ���� ���� ���̺��� ���� �� ��ġ
			pCrystalLabel = LabelTTF::create("0",NFONT::MENU_FONT1,FONT_SIZE(20));
			pCrystalLabel->setPosition(Point(layerSize.width/3+40.0f, layerSize.height/2));
			//this->addChild(pCrystalLabel,1);


			// ��� ���� ���̺��� ���� �� ��ġ
			pGoldLabel = LabelTTF::create("100",NFONT::MENU_FONT1,FONT_SIZE(20),Size(200,30),Label::HAlignment::RIGHT);
			pGoldLabel->setAnchorPoint(Point(1.0,0.5));
			pGoldLabel->setPosition(Point(pGoldSpr->getPositionX()-30,pGoldSpr->getPositionY()));
			this->addChild(pGoldLabel,1);

			// �� ���̾�� �ǽð� ����
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

	void ResourceNode::update( float delta ) // �ڿ� ���� �ǽð� ����
	{
		//pCrystalLabel->setString();
		//pGoldLabel->setString();
	}

}}}