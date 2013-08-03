#ifndef __SERIALIZATION_H__
#define __SERIALIZATION_H__

#include <string>
#include "cocos-ext.h"
#include "CCArmature\external_tool\Json\lib_json\json_lib.h"

/**********#include "json.h"**********************************************************

	created:	2013/07/22 20:18
	filename: 	D:\gitdev\projectmarble\MonsterMaker\Classes\GameLib\Serialization.h
	file path:	D:\gitdev\projectmarble\MonsterMaker\Classes\GameLib
	author:		Ryu
	
	purpose:	�ø���������̼��� ���� �������̽��� �Լ� ����
*********************************************************************/


namespace MonsterMaker { namespace Library { namespace Serial{

	// �ø���������̼� �������̽�
	
	class IJsonSerializable
	{
	public:
		virtual ~IJsonSerializable( void ) {};
		virtual void Serialize( CSJson::Value& root ) =0;		// data -> json
		virtual void Deserialize( const CSJson::Value & root) =0;	// json -> data
	};

	bool Serialize( IJsonSerializable* pObj, std::string& output );
	bool Deserialize( IJsonSerializable* pObj, std::string& input );

}}}

#endif