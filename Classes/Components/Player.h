#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "User.h"

/********************************************************************

	created:	2013/08/04 3:38
	filename: 	D:\work\cocos2d-x-3.0alpha0-pre\projects\MonsterMaker\Classes\Components\Player.h
	file path:	D:\work\cocos2d-x-3.0alpha0-pre\projects\MonsterMaker\Classes\Components
	author:		Ryu
	
	purpose:	사용자 정보 객체
*********************************************************************/

namespace MonsterMaker { namespace Components { namespace Players{
	
	class Player : public Users::UserEntity
	{
	public:
		Player(std::string _name, uint64_t _id);
		~Player();
		// Json 
		virtual void Serialize( CSJson::Value& root );		// Data -> Json
		virtual void Deserialize( const CSJson::Value & root ); // json -> data

	
	private:
		Player();

		uint16_t m_iGold;		// 골드
		uint16_t m_iCrystal;	// 크리스탈
		uint16_t m_iHeart;		// 하트
	};

	// 싱글톤 관련
	extern Player* g_Instance;
	Player* getInstance();
	Player* getInstance(const Player &_player);
	void Release();

}}}

namespace NPLAYER = MonsterMaker::Components::Players;

#endif