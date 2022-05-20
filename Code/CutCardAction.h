#pragma once
#include "Action.h"
#include"CopyCardAction.h"
class CutCardAction : public Action
{
	Card* card;
public:
	CutCardAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	virtual ~CutCardAction();
};