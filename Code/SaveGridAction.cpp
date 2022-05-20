#include "SaveGridAction.h"
#include <fstream>
#include "Snake.h"

SaveGridAction::SaveGridAction(ApplicationManager *pApp) : Action(pApp)
{
}
void SaveGridAction::ReadActionParameters()
{
 Grid *pGrid= this->pManager->GetGrid();
 Output* pOut = pGrid->GetOutput(); 
 Input* pIn = pGrid->GetInput();
 pOut->PrintMessage("Enter Filename (e.g. myFile.txt) ..."); 
 filename= pIn->GetSrting(pOut); 
 return; 
}


void SaveGridAction::Execute()
{
	Grid* pGrid = this->pManager->GetGrid();
	ReadActionParameters(); 
	ofstream outputFile; 
	outputFile.open(filename, ios::out);
	int l=0,s=0,c=0;
	l=pGrid->countLadder();
	outputFile<<l<<endl;
	pGrid->Saveall(outputFile, LadderType);
	s=pGrid->countSnake();
	outputFile<<s<<endl;
	pGrid->Saveall(outputFile, SnakeType);
	c=pGrid->countCard();
	outputFile<<c<<endl;
	pGrid->Saveall(outputFile, CardType);
}
SaveGridAction::~SaveGridAction(){
}
