#pragma once
#include"Action.h"
class NewGameAction : public Action
{
public:
	NewGameAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	void ResetPlayers();
	virtual void Execute();
	~NewGameAction(void);
};

