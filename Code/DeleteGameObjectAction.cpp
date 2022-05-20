#include "DeleteGameObjectAction.h"
#include "Output.h"
#include "Input.h"
#include "Grid.h"
DeleteGameObjectAction::DeleteGameObjectAction(ApplicationManager *pApp) : Action(pApp)
{
}
void DeleteGameObjectAction::ReadActionParameters()
{

}
void DeleteGameObjectAction::Execute()
{
	Grid *pGrid=pManager->GetGrid();
	Input *pIn=pGrid->GetInput();
	Output *pOut=pGrid->GetOutput();
	pOut->PrintMessage("Delete Game Object. Click on object to be deleted ...");
	ObjectCellPosition=pIn->GetCellClicked();
	pGrid->RemoveObjectFromCell(ObjectCellPosition);
	pOut->ClearStatusBar();
}
DeleteGameObjectAction::~DeleteGameObjectAction(void)
{
}