#include "AddSnakeAction.h"
#include "Input.h"
#include "Output.h"
#include "Snake.h"
AddSnakeAction::AddSnakeAction(ApplicationManager*pApp):Action(pApp)
{
}
AddSnakeAction::~AddSnakeAction()
{
}
void AddSnakeAction::ReadActionParameters()
{
	Grid*pGrid = pManager->GetGrid();
	Output*pOut = pGrid->GetOutput();
	Input*pIn = pGrid->GetInput();
	pOut->PrintMessage("New Snake: Click on its start cell ...");
	startPos=pIn->GetCellClicked();
	
	pOut->PrintMessage("New Snake: Click on its end cell ...");
	endPos=pIn->GetCellClicked();
	
	valid=pGrid->verticalcheck(startPos,endPos);
		if(endPos.VCell()<=startPos.VCell())
			valid=false;
	
	pOut->ClearStatusBar();
}
void AddSnakeAction::Execute()
{

	ReadActionParameters();


	
	if(valid)
	{
	Snake*pSnake=new Snake(startPos,endPos);
	Grid*pGrid=pManager->GetGrid();
	bool added=pGrid->AddObjectToCell(pSnake);
	if (!added)
	{
		pGrid->PrintErrorMessage("Error: Cell already has an object ! Click to continue ...");
	}
	}
	else
		pManager->GetGrid()->PrintErrorMessage("Can't add Snake");


}