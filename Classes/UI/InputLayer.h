#ifndef __InputLayer__H__
#define __InputLayer__H__

#include <string>
#include "cocos2d.h"

using namespace cocos2d;


namespace MonsterMaker { namespace UI { namespace Inputs{



	//////////////////////////////////////////////////////////////////////////
	// KeyboardNotificationLayer for test IME keyboard notification.
	//////////////////////////////////////////////////////////////////////////

	class KeyboardNotificationLayer : public Layer, public IMEDelegate
	{
	public:
		KeyboardNotificationLayer();

		virtual void onClickTrackNode(bool bClicked) = 0;

		virtual void registerWithTouchDispatcher();
		virtual void keyboardWillShow(IMEKeyboardNotificationInfo& info);

		// CCLayer
		virtual bool ccTouchBegan(Touch *pTouch, Event *pEvent);
		virtual void ccTouchEnded(Touch *pTouch, Event *pEvent);

	protected:
		Node * m_pTrackNode;
		Point  m_beginPos;
	};

	

	//////////////////////////////////////////////////////////////////////////
	// TextFieldTTFActionTest
	//////////////////////////////////////////////////////////////////////////

	class InputLayer : public KeyboardNotificationLayer, public TextFieldDelegate
	{
		TextFieldTTF *    m_pTextField;
		Action *          m_pTextFieldAction;
		bool                m_bAction;
		int                 m_nCharLimit;       // the textfield max char limit

	public:
		virtual bool init();

		std::string getText();;
		void callbackRemoveNodeWhenDidAction(Node * pNode);

		// KeyboardNotificationLayer
		virtual void onClickTrackNode(bool bClicked);

		// CCLayer
		virtual void onEnter();
		virtual void onExit();

		// CCTextFieldDelegate
		virtual bool onTextFieldAttachWithIME(TextFieldTTF * pSender);
		virtual bool onTextFieldDetachWithIME(TextFieldTTF * pSender);
		virtual bool onTextFieldInsertText(TextFieldTTF * pSender, const char * text, int nLen);
		virtual bool onTextFieldDeleteBackward(TextFieldTTF * pSender, const char * delText, int nLen);
		virtual bool onDraw(TextFieldTTF * pSender);

		

	};


	CREATE_FUNC(InputLayer);

}}}

#endif