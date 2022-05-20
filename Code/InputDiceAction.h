#pragma once
#include "Action.h"
class InputDiceAction : public Action
{
public:
	
	InputDiceAction(ApplicationManager *pApp);

	virtual void ReadActionParameters();

	virtual void Execute();

	~InputDiceAction(void);
};