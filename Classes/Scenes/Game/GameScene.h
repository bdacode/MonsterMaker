#ifndef __GAMESCENE_H__
#define __GAMESCENE_H__

#include "cocos2d.h"

/********************************************************************

created:	2013/07/13 23:51
filename: 	D:\gitdev\projectmarble\MonsterMaker\Classes\GameScene.h
file path:	D:\gitdev\projectmarble\MonsterMaker\Classes
author:		Ryu

purpose:	Game Main Scene

*********************************************************************/

namespace MonsterMaker{ namespace Scenes { namespace Games {

	/************************************************************************/
	/* Game Scene Class                                                                
	/************************************************************************/

	class GameScene : public cocos2d::Scene{
	public:
		GameScene(){};
		~GameScene(){};
		bool init();
	}; 

	class GameLayer : public cocos2d::Layer
	{
	public:

		virtual bool init();
		CREATE_FUNC(GameLayer);

		void menuSceneTransitionCallback(cocos2d::Object *pSender);

	private:

	};

	/*---------------------------------------------------------------
	CalenderNode Class Description
	created:	2013/08/05 4:15
	namespace : MonsterMaker::Scenes::Game	
	author:		Ryu

	purpose:	현재 날짜를 표시하는 달력 노드 입니다.
				게임의 시간을 표현하고 현재 몬스터가 진행중인 스케줄을 표시합니다.
	---------------------------------------------------------------*/
	class CalendarNode : public cocos2d::Node{
	public:
		CalendarNode(){};
		~CalendarNode(){};
		virtual bool init();
		CREATE_FUNC(CalendarNode);

	private:
		cocos2d::LabelTTF * pYearLabel, *pMonthLabel , *pDayLabel,*pWeekLabel;	// 날짜 관련 레이블
	};


	/********************************************************************
	MenuNode Class Description
	@created	2013/08/05 4:12
	@namespace  MonsterMaker::Scenes::Game	
	@author  	Ryu

	@purpose	GameScene의 화면 아래에 표시되는 메뉴입니다.
				친구목록, 수행, 투기장, 창고, 외출기능있습니다.
	*********************************************************************/

	class MenuNode : public cocos2d::Node{
	public:
		MenuNode(){};
		~MenuNode(){};
		virtual bool init();
		CREATE_FUNC(MenuNode);

	private:

	};


	/*---------------------------------------------------------------
	ResourceLayer Class Description
	@created	2013/08/05 10:54
	@namespace  MonsterMaker::Scenes::Games	
	@author		Ryu

	@purpose 	리소스를 보여주는 레이어입니다. 
				
	@골드		게임내 화폐입니다.
	@크리스탈	현금으로 결제하여 사용하는 사용하는 자원입니다.
	@하트		하트를 소모함으로서 대결, 수행등을 수행할수 있습니다.
	---------------------------------------------------------------*/


	class ResourceNode : public cocos2d::Node
	{
	public:
		ResourceNode(){};	
		~ResourceNode(){};	
		virtual bool init();	//초기화
		CREATE_FUNC(ResourceNode);
	private:
		// Sprite
		cocos2d::Sprite *m_pHeartSpr[6];	// 하트 스프라이트
		
		// Label
		LabelTTF *pCrystalLabel;	// 크리스탈 레이블
		LabelTTF *pGoldLabel;		// 골드 레이블

		virtual void onEnterTransitionDidFinish();		// 씬 들어올때 효과
		virtual void onExitTransitionDidStart();		// 종료할때 효과
		virtual void update( float delta );				// 각종 Label 및 Sprite 갱신

	};

	CREATE_FUNC(GameScene);

}}}
#endif // !__GAMESCENE_H__