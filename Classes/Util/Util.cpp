#include "Util.h"

namespace MonsterMaker{ namespace Utils {
	cocos2d::Point origin = cocos2d::Point::ZERO;
	cocos2d::Size  viewSize = cocos2d::Size::ZERO;

	cocos2d::Point pos( const float _x, const float _y )
	{
		return cocos2d::Point(origin.x + _x, origin.y + _y);
	}

	cocos2d::Point posLeftTop()
	{
		return cocos2d::Point(origin.x,origin.y+viewSize.height);
	}

	cocos2d::Point posLeftTop( float _marginX, float _marginY )
	{
		return posLeftTop() + cocos2d::Point(_marginX,-_marginY);
	}

	cocos2d::Point posLeftBottom()
	{
		return cocos2d::Point(origin.x,origin.y);
	}

	cocos2d::Point posLeftBottom( float _marginX, float _marginY )
	{
		return posLeftBottom() + cocos2d::Point(_marginX,_marginY);
	}


	cocos2d::Point posRightTop()
	{
		return cocos2d::Point(origin.x+viewSize.width,origin.y+viewSize.height);
	}

	cocos2d::Point posRightTop( float _marginX, float _marginY )
	{
		return  posRightTop() + cocos2d::Point(-_marginX,-_marginY);
	}

	cocos2d::Point posRightBottom()
	{
		return cocos2d::Point(origin.x+viewSize.width,origin.y);
	}

	cocos2d::Point posRightBottom( float _marginX, float _marginY )
	{
		return  posRightBottom() + cocos2d::Point(-_marginX,_marginY);
	}

	

}}