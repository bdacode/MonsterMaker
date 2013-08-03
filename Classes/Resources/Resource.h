#ifndef __RESOURCES_H__
#define __RESOURCES_H__
#include "AppMacros.h"


namespace MonsterMaker { namespace Resources { 
	/************************************************************************/
	/* 배경 그림                                                                    
	/************************************************************************/
	namespace Backgrounds{ 

		const char * const	CaveBackground	= "Background/CaveBackground.png";
		const char * const	CaveDown		= "Background/CaveDown.png";
		const char * const	CaveUp			= "Background/CaveUp.png";

	}
	/************************************************************************/
	/* 메뉴 아이콘                                                                    
	/************************************************************************/

	namespace Icons{
		const char * const	 Friend		=	"MenuIcon/HumanN.png";
		const char * const	 Friend_s	=	"MenuIcon/HumanS.png";
		const char * const	 Train		=	"MenuIcon/ClockN.png";
		const char * const	 Train_s	=	"MenuIcon/ClockS.png";
		const char * const	 Arena		=	"MenuIcon/MailN.png";
		const char * const	 Arena_s	=	"MenuIcon/MailS.png";
		const char * const	 Storage	=	"MenuIcon/BoxN.png";
		const char * const	 Storage_s	=	"MenuIcon/BoxS.png";
		const char * const	 Castle		=	"MenuIcon/DoorN.png";
		const char * const	 Castle_s	=	"MenuIcon/DoorS.png";
	}

	/************************************************************************/
	/* 스프라이트                                                                     
	/************************************************************************/

	namespace Sprites{
		const char * const  Calender	=	"Sprite/Calender.png";
		const char * const  Heart		=	"Sprite/Gold.png";
		const char * const  HeartBlank	=	"Sprite/HeartBlank.png";
		const char * const  Gold		=	"Sprite/Gold.png";
		const char * const  Crystal		=	"Sprite/Crystal.png";

	}
	/************************************************************************/
	/* UI TEXT                                                                    
	/************************************************************************/

	namespace UITexts{
		const char * const  Friend		=	"친  구";
		const char * const  Train		=	"수  행";
		const char * const  Arena		=	"투기장";
		const char * const  Storage		=	"창  고";
		const char * const  Castle		=   "외	 출";
		const char * const  InputName	=	"이름을 입력해 주세요.";
		const char * const  InputBirth	=	"당신의 생일을 알려주세요,";
		const char * const  Month		=	"월";
		const char * const  Day			=	"일";
		const char * const  Confirm		=   "확인";
	}

	/************************************************************************/
	/* 폰트 관련                                                                    
	/************************************************************************/

	namespace Fonts{
		const char * const  MENU_FONT1	=	"Font/NanumGothic.ttf";
	}

}}

namespace NBACKGROUND = MonsterMaker::Resources::Backgrounds;
namespace NICON = MonsterMaker::Resources::Icons;
namespace NUITEXT = MonsterMaker::Resources::UITexts;
namespace NFONT = MonsterMaker::Resources::Fonts;
namespace NSPRITE = MonsterMaker::Resources::Sprites;


#endif // __RESOURCE_H__
