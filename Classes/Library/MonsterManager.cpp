#include "MonsterManager.h"

namespace GameLib { namespace Monsters{

	MonsterManager::MonsterManager()
	{
		m_dVersion = 0.0;
	}

	MonsterManager::~MonsterManager()
	{

	}


	MonsterManager* MonsterManager::m_sMonsterManager = NULL;

	MonsterManager * MonsterManager::getInstance()
	{
		if(!m_sMonsterManager){
			m_sMonsterManager = new MonsterManager();
		}

		return m_sMonsterManager;
	}

	void MonsterManager::release()
	{
		if(m_sMonsterManager !=  NULL){
			delete m_sMonsterManager;
		}
		m_sMonsterManager = NULL;
	}


	bool MonsterManager::containMonster( string _name )
	{
		map<string,Monster>::iterator itr;
		itr=m_Monsters.find(_name);
		if (itr != m_Monsters.end()) {
			return true;
		}
		else{
			return false;
		}
	}


	Monster* MonsterManager::getMonster( string _name )	// 몬스터 가져오기
	{
		map<string,Monster>::iterator itr;
		itr=m_Monsters.find(_name);
		if (itr != m_Monsters.end()) {
			return &itr->second;
		}
		else{
			return NULL;
		}
	}


	void MonsterManager::addMonster( Monster _monster )
	{
		map<string,Monster>::iterator itr;
		itr=m_Monsters.find(_monster.getName());
		if (itr != m_Monsters.end()) {
			m_Monsters.insert(pair<string,Monster>(_monster.getName(),_monster));
		}
	}

	vector<string> MonsterManager::getMonsterKeys()
	{
		vector<string> monsterKeys;
		map<string,Monster>::iterator itr;
		for(itr=m_Monsters.begin();itr!=m_Monsters.end();itr++){
			monsterKeys.push_back(itr->first);
		}
		return monsterKeys;
	}


	double MonsterManager::getVersion()
	{
		return m_dVersion;
	}

	void MonsterManager::setVersion( double _version )
	{
		m_dVersion  =_version;
	}

	void MonsterManager::Serialize( Json::Value& root )
	{
		throw std::exception("본 클래스는 시리얼라이즈 하지 않음");
	}

	void MonsterManager::Deserialize( Json::Value& root )
	{
		m_dVersion = root.get("Version",0.0).asDouble();
		Json::Value dataValue = root["Data"];
		for(Json::Value elem : dataValue){
			Monster monster;
			monster.Deserialize(elem);
			this->addMonster(monster);
		}

	}




}}