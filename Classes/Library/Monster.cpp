#ifndef __MONSTER_H__
#define  __MONSTER_HH
#include "Monster.h"
#include "json.h"

namespace GameLib{ namespace Monsters{

	string Monster::getName()
	{
		return m_sName;
	}

	void Monster::Serialize( Json::Value& root )
	{
		throw std::exception("�� Ŭ������ �ø�������� ���� ����");

		/*	root["Name"] = m_sName;
		root["Dex"] = m_iDex;*/

	}

	void Monster::Deserialize( Json::Value& root )
	{
		m_sName = root.get("Name","Player").asString();
		m_iDex = root.get("Dex",0).asInt();
	}
}}

#endif