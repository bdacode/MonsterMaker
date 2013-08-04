#ifndef __UTIL_H__
#define __UTIL_H__
#include "cocos2d.h"

#define POS(__x__,__y__) MonsterMaker::Util::pos(__x__,__y__)

namespace MonsterMaker{ namespace Util {
	extern cocos2d::Point origin;	   //visible origin
	extern cocos2d::Size  size;			// visible size
	
	// multiresolution좌표계 수정
	cocos2d::Point pos(const float _x, const float _y);

	// anchor point
	const cocos2d::Point anchorLeftTop = cocos2d::Point(0,1);
	const cocos2d::Point anchorRightTop = cocos2d::Point(1,1);
	const cocos2d::Point anchorLeftBottom = cocos2d::Point(0,0);
	const cocos2d::Point anchorRightBottom = cocos2d::Point(1,0);
	const cocos2d::Point anchorCenter = cocos2d::Point(0.5f,0.5f);;

	// 화면 모서리별 좌표 getter
	cocos2d::Point posLeftTop();
	cocos2d::Point posLeftBottom();
	cocos2d::Point posRightTop();
	cocos2d::Point posRightBottom();

	// 화면 모서리 여백 getter
	cocos2d::Point posLeftTop(float _marginX, float _marginY);
	cocos2d::Point posLeftBottom(float _marginX, float _marginY);
	cocos2d::Point posRightTop(float _marginX, float _marginY);
	cocos2d::Point posRightBottom(float _marginX, float _marginY);
}}
#endif