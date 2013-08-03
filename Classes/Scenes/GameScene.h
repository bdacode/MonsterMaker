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
	/* 게임 주축 레이어                                                                    
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
	/* 씬 배치                                                                    
	/************************************************************************/
	class GameScene : public cocos2d::Scene{
	public:
		GameScene(){};
		~GameScene(){};
		bool init();
	};

	CREATE_FUNC(GameScene);


}}}
#endif // !__GAMESCENE_H__