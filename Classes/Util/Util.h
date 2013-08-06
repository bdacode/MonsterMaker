#ifndef __UTIL_H__
#define __UTIL_H__
#include "cocos2d.h"


#define POS(__x__,__y__) MonsterMaker::Utils::pos(__x__,__y__)
//#define POS(__x__,__y__) Point(__x__,__y__)
#define FONT_SIZE(Num)  (cocos2d::EGLView::getInstance()->getDesignResolutionSize().height / mediumResource.size.height * Num)

namespace MonsterMaker{ namespace Utils {
	extern cocos2d::Point origin;	   //visible origin
	extern cocos2d::Size  viewSize;			// visible size
	
	// multiresolution좌표계 수정
	cocos2d::Point pos(const float _x, const float _y);

	// anchor point
	const cocos2d::Point anchorLeftTop = cocos2d::Point(0,1);
	const cocos2d::Point anchorRightTop = cocos2d::Point(1,1);
	const cocos2d::Point anchorLeftBottom = cocos2d::Point(0,0);
	const cocos2d::Point anchorRightBottom = cocos2d::Point(1,0);
	const cocos2d::Point anchorCenter = cocos2d::Point(0.5f,0.5f);;
	const cocos2d::Point anchorCenterTop = cocos2d::Point(0.5f,1.0f);

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

// 노드는 앵커 0,0임
// 레이어는 앵커 0.5,0.5
// 사이즈는 디자인 레솔루션으로 바뀜
// 좌표계가 문제임
#endif