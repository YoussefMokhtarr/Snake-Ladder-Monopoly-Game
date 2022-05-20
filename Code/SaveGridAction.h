#pragma once
#include "Action.h"
#include <fstream>
#include"Grid.h"
#include<string>
class SaveGridAction :
	public Action
{private:
	string filename;
public:
	SaveGridAction(ApplicationManager* pApp);
	void  ReadActionParameters();
	void Execute();
	virtual ~SaveGridAction();  // Virtual Destructor
};

