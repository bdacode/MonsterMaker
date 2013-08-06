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

	purpose:	���� ��¥�� ǥ���ϴ� �޷� ��� �Դϴ�.
				������ �ð��� ǥ���ϰ� ���� ���Ͱ� �������� �������� ǥ���մϴ�.
	---------------------------------------------------------------*/
	class CalendarNode : public cocos2d::Node{
	public:
		CalendarNode(){};
		~CalendarNode(){};
		virtual bool init();
		CREATE_FUNC(CalendarNode);

	private:
		cocos2d::LabelTTF * pYearLabel, *pMonthLabel , *pDayLabel,*pWeekLabel;	// ��¥ ���� ���̺�
	};


	/********************************************************************
	MenuNode Class Description
	@created	2013/08/05 4:12
	@namespace  MonsterMaker::Scenes::Game	
	@author  	Ryu

	@purpose	GameScene�� ȭ�� �Ʒ��� ǥ�õǴ� �޴��Դϴ�.
				ģ�����, ����, ������, â��, �������ֽ��ϴ�.
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

	@purpose 	���ҽ��� �����ִ� ���̾��Դϴ�. 
				
	@���		���ӳ� ȭ���Դϴ�.
	@ũ����Ż	�������� �����Ͽ� ����ϴ� ����ϴ� �ڿ��Դϴ�.
	@��Ʈ		��Ʈ�� �Ҹ������μ� ���, ������� �����Ҽ� �ֽ��ϴ�.
	---------------------------------------------------------------*/


	class ResourceNode : public cocos2d::Node
	{
	public:
		ResourceNode(){};	
		~ResourceNode(){};	
		virtual bool init();	//�ʱ�ȭ
		CREATE_FUNC(ResourceNode);
	private:
		// Sprite
		cocos2d::Sprite *m_pHeartSpr[6];	// ��Ʈ ��������Ʈ
		
		// Label
		LabelTTF *pCrystalLabel;	// ũ����Ż ���̺�
		LabelTTF *pGoldLabel;		// ��� ���̺�

		virtual void onEnterTransitionDidFinish();		// �� ���ö� ȿ��
		virtual void onExitTransitionDidStart();		// �����Ҷ� ȿ��
		virtual void update( float delta );				// ���� Label �� Sprite ����

	};

	CREATE_FUNC(GameScene);

}}}
#endif // !__GAMESCENE_H__