#ifndef __MAINSCENE_H__
#define __MAINSCENE_H__

#include "cocos2d.h"

/********************************************************************

	created:	2013/07/13 8:49
	filename: 	D:\gitdev\projectmarble\MonsterMaker\Classes\MainScene.h
	file path:	D:\gitdev\projectmarble\MonsterMaker\Classes
	author:		Ryu
	
	purpose:	제일 처음 불러오는 씬	
	- 새로운 게임 시작하기
	- 게임 불러오기
				
*********************************************************************/

namespace MonsterMaker{ namespace Scenes{ namespace Mains {

	class MainLayer : public cocos2d::LayerColor
	{
	public:
		virtual bool init();
		CREATE_FUNC(MainLayer);
	private:

		void menuNewCallback(cocos2d::Object* pSender);	// Game Start callback Function
		void menuLoadCallback(cocos2d::Object* pSender);	// Game Load callback Function

	};
	
	class MainScene : public cocos2d::Scene{
	public:
		MainScene(){};
		~MainScene(){};
		bool init();
	};

	CREATE_FUNC(MainScene);

}}}

#endif // !__MAINSCENE_H__