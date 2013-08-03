#include "InputLayer.h"

#define FONT_NAME                       "Thonburi"
#define FONT_SIZE                       36

namespace MonsterMaker { namespace UI { namespace Inputs{

CCRect getRect(Node * pNode)
{
	CCRect rc;
	rc.origin = pNode->getPosition();
	rc.size = pNode->getContentSize();
	rc.origin.x -= rc.size.width / 2;
	rc.origin.y -= rc.size.height / 2;
	return rc;
}

//////////////////////////////////////////////////////////////////////////
// implement KeyboardNotificationLayer
//////////////////////////////////////////////////////////////////////////

KeyboardNotificationLayer::KeyboardNotificationLayer()
	: m_pTrackNode(0)
{
	setTouchEnabled(true);
}

void KeyboardNotificationLayer::registerWithTouchDispatcher()
{
	CCDirector* pDirector = CCDirector::sharedDirector();
	pDirector->getTouchDispatcher()->addTargetedDelegate(this, 0, false);
}

void KeyboardNotificationLayer::keyboardWillShow(CCIMEKeyboardNotificationInfo& info)
{
	CCLOG("TextInputTest:keyboardWillShowAt(origin:%f,%f, size:%f,%f)",
		info.end.origin.x, info.end.origin.y, info.end.size.width, info.end.size.height);

	if (! m_pTrackNode)
	{
		return;
	}

	CCRect rectTracked = getRect(m_pTrackNode);
	CCLOG("TextInputTest:trackingNodeAt(origin:%f,%f, size:%f,%f)",
		rectTracked.origin.x, rectTracked.origin.y, rectTracked.size.width, rectTracked.size.height);

	// if the keyboard area doesn't intersect with the tracking node area, nothing need to do.
	if (! rectTracked.intersectsRect(info.end))
	{
		return;
	}

	// assume keyboard at the bottom of screen, calculate the vertical adjustment.
	float adjustVert = info.end.getMaxY() - rectTracked.getMinY();
	CCLOG("TextInputTest:needAdjustVerticalPosition(%f)", adjustVert);

	// move all the children node of KeyboardNotificationLayer
	CCArray * children = getChildren();
	Node * node = 0;
	int count = children->count();
	CCPoint pos;
	for (int i = 0; i < count; ++i)
	{
		node = (Node*)children->objectAtIndex(i);
		pos = node->getPosition();
		pos.y += adjustVert;
		node->setPosition(pos);
	}
}

// CCLayer function

bool KeyboardNotificationLayer::ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent)
{
	CCLOG("++++++++++++++++++++++++++++++++++++++++++++");
	m_beginPos = pTouch->getLocation();    
	return true;
}

void KeyboardNotificationLayer::ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent)
{
	if (! m_pTrackNode)
	{
		return;
	}

	CCPoint endPos = pTouch->getLocation();    

	float delta = 5.0f;
	if (::abs(endPos.x - m_beginPos.x) > delta
		|| ::abs(endPos.y - m_beginPos.y) > delta)
	{
		// not click
		m_beginPos.x = m_beginPos.y = -1;
		return;
	}

	// decide the trackNode is clicked.
	CCRect rect;
	CCPoint point = convertTouchToNodeSpaceAR(pTouch);
	CCLOG("KeyboardNotificationLayer:clickedAt(%f,%f)", point.x, point.y);

	rect = getRect(m_pTrackNode);
	CCLOG("KeyboardNotificationLayer:TrackNode at(origin:%f,%f, size:%f,%f)",
		rect.origin.x, rect.origin.y, rect.size.width, rect.size.height);

	this->onClickTrackNode(rect.containsPoint(point));
	CCLOG("----------------------------------");
}

//////////////////////////////////////////////////////////////////////////
// implement TextFieldTTFActionTest
//////////////////////////////////////////////////////////////////////////

void InputLayer::onClickTrackNode(bool bClicked)
{
	TextFieldTTF * pTextField = (TextFieldTTF*)m_pTrackNode;
	if (bClicked)
	{
		// TextFieldTTFTest be clicked
		CCLOG("TextFieldTTFActionTest:CCTextFieldTTF attachWithIME");
		pTextField->attachWithIME();
	}
	else
	{
		// TextFieldTTFTest not be clicked
		CCLOG("TextFieldTTFActionTest:CCTextFieldTTF detachWithIME");
		pTextField->detachWithIME();
	}
}

void InputLayer::onEnter()
{
	KeyboardNotificationLayer::onEnter();

	m_nCharLimit = 12;

	m_pTextFieldAction = CCRepeatForever::create(
		CCSequence::create(
		CCFadeOut::create(0.25),
		CCFadeIn::create(0.25),
		0
		));
	m_pTextFieldAction->retain();
	m_bAction = false;

	// add CCTextFieldTTF
	CCSize s = CCDirector::sharedDirector()->getWinSize();

	m_pTextField = TextFieldTTF::textFieldWithPlaceHolder("<click here for input>",
		FONT_NAME,
		FONT_SIZE);
	addChild(m_pTextField);

	m_pTextField->setDelegate(this);

//#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)    
//	// on android, CCTextFieldTTF cannot auto adjust its position when soft-keyboard pop up
//	// so we had to set a higher position
//	m_pTextField->setPosition(ccp(s.width / 2, s.height/2 + 50));
//#else
//	m_pTextField->setPosition(ccp(s.width / 2, s.height / 2));
//#endif
//
	m_pTrackNode = m_pTextField;
}

void InputLayer::onExit()
{
	KeyboardNotificationLayer::onExit();
	m_pTextFieldAction->release();
}

// CCTextFieldDelegate protocol
bool InputLayer::onTextFieldAttachWithIME(TextFieldTTF * pSender)
{
	if (! m_bAction)
	{
		m_pTextField->runAction(m_pTextFieldAction);
		m_bAction = true;
	}
	return false;
}

bool InputLayer::onTextFieldDetachWithIME(TextFieldTTF * pSender)
{
	if (m_bAction)
	{
		m_pTextField->stopAction(m_pTextFieldAction);
		m_pTextField->setOpacity(255);
		m_bAction = false;
	}
	return false;
}

bool InputLayer::onTextFieldInsertText(TextFieldTTF * pSender, const char * text, int nLen)
{
	// if insert enter, treat as default to detach with ime
	if ('\n' == *text)
	{
		return false;
	}

	// if the textfield's char count more than m_nCharLimit, doesn't insert text anymore.
	if (pSender->getCharCount() >= m_nCharLimit)
	{
		return true;
	}

	// create a insert text sprite and do some action
	CCLabelTTF * label = CCLabelTTF::create(text, FONT_NAME, FONT_SIZE);
	this->addChild(label);
	ccColor3B color = { 226, 121, 7};
	label->setColor(color);

	// move the sprite from top to position
	CCPoint endPos = pSender->getPosition();
	if (pSender->getCharCount())
	{
		endPos.x += pSender->getContentSize().width / 2;
	}
	CCSize  inputTextSize = label->getContentSize();
	CCPoint beginPos(endPos.x, CCDirector::sharedDirector()->getWinSize().height - inputTextSize.height * 2); 

	float duration = 0.5;
	label->setPosition(beginPos);
	label->setScale(8);

	Action * seq = CCSequence::create(
		CCSpawn::create(
		CCMoveTo::create(duration, endPos),
		CCScaleTo::create(duration, 1),
		CCFadeOut::create(duration),
		0),
		CCCallFuncN::create(this, callfuncN_selector(InputLayer::callbackRemoveNodeWhenDidAction)),
		0);
	label->runAction(seq);
	return false;
}

bool InputLayer::onTextFieldDeleteBackward(TextFieldTTF * pSender, const char * delText, int nLen)
{
	// create a delete text sprite and do some action
	CCLabelTTF * label = CCLabelTTF::create(delText, FONT_NAME, FONT_SIZE);
	this->addChild(label);

	// move the sprite to fly out
	CCPoint beginPos = pSender->getPosition();
	CCSize textfieldSize = pSender->getContentSize();
	CCSize labelSize = label->getContentSize();
	beginPos.x += (textfieldSize.width - labelSize.width) / 2.0f;

	CCSize winSize = CCDirector::sharedDirector()->getWinSize();
	CCPoint endPos(- winSize.width / 4.0f, winSize.height * (0.5 + (float)rand() / (2.0f * RAND_MAX)));

	float duration = 1;
	float rotateDuration = 0.2f;
	int repeatTime = 5; 
	label->setPosition(beginPos);

	Action * seq = CCSequence::create(
		CCSpawn::create(
		CCMoveTo::create(duration, endPos),
		CCRepeat::create(
		CCRotateBy::create(rotateDuration, (rand()%2) ? 360 : -360),
		repeatTime),
		CCFadeOut::create(duration),
		0),
		CCCallFuncN::create(this, callfuncN_selector(InputLayer::callbackRemoveNodeWhenDidAction)),
		0);
	label->runAction(seq);
	return false;
}

bool InputLayer::onDraw(TextFieldTTF * pSender)
{
	return false;
}

void InputLayer::callbackRemoveNodeWhenDidAction(Node * pNode)
{
	this->removeChild(pNode, true);
}

std::string InputLayer::getText()
{
	return m_pTextField->getString();
}

bool InputLayer::init()
{
	bool bRet = false;
	do{

	CC_BREAK_IF(!CCLayer::init());
	this->setTouchEnabled(true);

	bRet = true;
	}while(0);
	
	return bRet;
}

}}}