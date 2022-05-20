#include "CutCardAction.h"
#include "Grid.h"
#include "DeleteGameObjectAction.h"
#include "Output.h"
#include "Input.h"
CutCardAction::CutCardAction(ApplicationManager* pApp) : Action(pApp)
{
}
void CutCardAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pOut->PrintMessage("Click on the card that you want to be cut");
}
void CutCardAction::Execute()
{
	ReadActionParameters();

	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	CellPosition C = pIn->GetCellClicked();	
	card = dynamic_cast<Card*>(pGrid->GetGameObject(C));
	if (card != NULL)
	{
		pGrid->SetClipboard(card);
		pGrid->RemoveObjectFromCell(card->GetPosition());
		pGrid->PrintErrorMessage("Card added to clipboard. Click to continue.");
	}
	else pGrid->PrintErrorMessage("No card is present in the cell clicked. Click to continue");
}
CutCardAction::~CutCardAction()
{
}