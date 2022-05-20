#pragma once
#include "Action.h"
#include "Grid.h"
class DeleteGameObjectAction : public Action
{
	CellPosition ObjectCellPosition;
public:
	DeleteGameObjectAction(ApplicationManager *pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	~DeleteGameObjectAction(void);
};