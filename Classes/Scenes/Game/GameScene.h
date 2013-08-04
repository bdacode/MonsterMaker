#ifndef __GAMESCENE_H__
#define __GAMESCENE_H__

#include "cocos2d.h"

/********************************************************************

	created:	2013/07/13 23:51
	filename: 	D:\gitdev\projectmarble\MonsterMaker\Classes\GameScene.h
	file path:	D:\gitdev\projectmarble\MonsterMaker\Classes
	author:		Ryu
	
	purpose:	게임 메인화면
	A 자원 레이어
	A 달력 레이어

*********************************************************************/

namespace MonsterMaker{ namespace Scenes { namespace Game {

	/************************************************************************/
	/* Game Scene Class                                                                
	/************************************************************************/

	class GameScene : public cocos2d::Scene{
	public:
		GameScene(){};
		~GameScene(){};
		bool init();
	}; 
	
	CREATE_FUNC(GameScene);

	/************************************************************************/
	/* Game Layer Class will be delete                                                         
	/************************************************************************/

	class GameLayer : public cocos2d::Layer
	{
	public:

		virtual bool init();
		CREATE_FUNC(GameLayer);

		void menuSceneTransitionCallback(cocos2d::Object *pSender);
	
	private:
		
	};


	/************************************************************************/
	/* Calender Node Class
	/************************************************************************/
	
	class CalendarNode : public cocos2d::Node{
	public:
		CalendarNode(){};
		~CalendarNode(){};
		bool init();
		CREATE_FUNC(CalendarNode);

	private:
		cocos2d::LabelTTF * pYearLabel, *pMonthLabel , *pDayLabel,*pWeekLabel;	// 날짜 관련 레이블
	};
	

}}}
#endif // !__GAMESCENE_H__