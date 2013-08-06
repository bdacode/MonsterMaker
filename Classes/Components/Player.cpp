#include "Player.h"

namespace MonsterMaker { namespace Components { namespace Players{
	Player *gInstance = NULL;

	void Player::Serialize( CSJson::Value& root )
	{
		// 부모 시리얼라이즈
		UserEntity::Serialize(root);

		// Player 시리얼라이즈
		root["Gold"] = m_iGold;
		root["Crystal"] = m_iCrystal;
		root["Heart"] = m_iHeart;
		
		
	}

	void Player::Deserialize( const CSJson::Value & root)
	{
		// 부모 디시리얼라이즈
		UserEntity::Deserialize(root);

		// Player 디시리얼라이즈
		m_iGold = root.get("Gold",0).asUInt();
		m_iCrystal = root.get("Crystal",0).asUInt();
		m_iHeart = root.get("Heart",0).asUInt();

	}

	/************************************************************************/
	/* 초기화                                                                    
	/************************************************************************/
	Player::Player( std::string _name, uint64_t _id ) : UserEntity(_name,_id)
	{
		m_iGold = 0;
		m_iCrystal = 0;
		m_iHeart = 0;
	}

	Player::~Player()
	{

	}

	//void Release()
	//{
	//	delete g_Instance;
	//	g_Instance = NULL;
	//}

	//Player* getInstance()
	//{
	//	if ( g_Instance == NULL ) {
	//		CCASSERT(g_Instance,"No Player Instance");
	//		return NULL;
	//	}
	//	return g_Instance;
	//}

	//Player* getInstance(const Player &_player )
	//{
	//	if ( g_Instance == NULL) {
	//		g_Instance = new Player(_player);
	//	}
	//	return g_Instance;
	//}

	
}}}