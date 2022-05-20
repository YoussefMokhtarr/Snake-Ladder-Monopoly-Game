#pragma once
#include "Action.h"
#include "Card.h"
class CopyCardAction : public Action
{
protected:
	Card* card;
public:
	CopyCardAction(ApplicationManager* pApp);
	virtual void ReadActionParameters(); 
	virtual void Execute();
	virtual ~CopyCardAction();
};