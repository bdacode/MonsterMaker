#ifndef __USER_H__
#define __USER_H__

#include <string>
#include "AppMacros.h"
#include "Library/Serializer.h"
#include "cocos2d.h"

/********************************************************************

	created:	2013/08/04 6:58
	filename: 	D:\work\cocos2d-x-3.0alpha0-pre\projects\MonsterMaker\Classes\Components\User.h
	author:		Ryu
	
	purpose:	사용자 정보 관련 객체
*********************************************************************/

namespace MonsterMaker { namespace Components { namespace Users{
	class UserEntity : public Library::Serial::IJsonSerializable, public cocos2d::Object
	{
	public:
		UserEntity(std::string _name, uint64_t _id);

		virtual void Serialize( CSJson::Value& root );
		virtual void Deserialize( const CSJson::Value& root);


		std::string getName(){return m_sName;}
		uint64_t getID(){return m_ID;}
		
		~UserEntity();
	private:
		std::string m_sName;
		uint64_t m_ID;

	};



}}}

#endif