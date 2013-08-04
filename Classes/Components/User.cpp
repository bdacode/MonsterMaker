#include "Player.h"
namespace MonsterMaker { namespace Components{ namespace Users{
	void UserEntity::Serialize( CSJson::Value& root )
	{
		root["Name"] = m_sName;
		root["ID"] = m_ID;
		
	}

	void UserEntity::Deserialize( const CSJson::Value& root )
	{
		m_sName = root.get("Name","NoName").asString();
		m_ID = root.get("ID",0).asUInt64();
	}

	UserEntity::UserEntity( std::string _name, uint64_t _id ) : m_sName(_name), m_ID(_id)
	{
		
	}

	UserEntity::~UserEntity()
	{
		CCLOG("UserEntity Destroy");
	}




}}}