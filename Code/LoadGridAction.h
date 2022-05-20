#pragma once
#include "Action.h"
#include <fstream>
#include"Grid.h"
#include<string>
class LoadGridAction :
	public Action
{private:
	string filename;
public:
	LoadGridAction(ApplicationManager *pApp);
	void  ReadActionParameters();
	void Execute();
	virtual ~LoadGridAction();  // Virtual Destructor
};