#include "CopyCardAction.h"
#include "Input.h"
#include "Output.h"
#include "Grid.h"
CopyCardAction::CopyCardAction(ApplicationManager* pApp) :Action(pApp)
{
}
void CopyCardAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pOut->PrintMessage("Click on the card that you want to be copied");
}
void CopyCardAction::Execute()
{
	ReadActionParameters();
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	CellPosition c = pIn->GetCellClicked();
	card = dynamic_cast<Card*>(pGrid->GetGameObject(c));
	if (card != NULL)
	{
		pGrid->SetClipboard(card);
		pGrid->PrintErrorMessage("Card added to clipboard. Click to continue.");
	}
	else pGrid->PrintErrorMessage("No card is present in the cell clicked. Click to continue");
}
CopyCardAction::~CopyCardAction()
{
}