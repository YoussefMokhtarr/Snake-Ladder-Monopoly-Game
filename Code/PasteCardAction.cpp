#include "PasteCardAction.h"
#include "Output.h"
#include "Input.h"
#include "Grid.h"
#include "CutCardAction.h"
#include "CopyCardAction.h"
PasteCardAction::PasteCardAction(ApplicationManager* pApp) :Action(pApp)
{
}
void PasteCardAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pOut->PrintMessage("Click where you want to paste the card");
}
void PasteCardAction::Execute()
{
	ReadActionParameters();
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	C = pIn->GetCellClicked();
	if (pGrid->GetGameObject(C) != NULL)
	{
		pGrid->PrintErrorMessage("Card can not be pasted as cell has another GameObject. Click to contiune");
		return;
	}
	else if (pGrid->GetClipboard() == NULL)
	{
		pGrid->PrintErrorMessage("No card is present in the cell clicked.Click to contiune");
		return;
	}
	else
	{
		GameObject* P = pGrid->GetClipboard();
		pGrid->AddObjectToCell(P);
	}
}
PasteCardAction::~PasteCardAction()
{
}