#include "InputDiceAction.h"
#include "Grid.h"
#include "Player.h"
InputDiceAction::InputDiceAction(ApplicationManager *pApp) : Action(pApp)
{
}
void InputDiceAction::ReadActionParameters()
{
}
void InputDiceAction::Execute()
{
	Grid *pGrid=pManager->GetGrid();
	Output *pOut=pGrid->GetOutput();
	Input *pIn=pGrid->GetInput();
	if (pGrid->GetEndGame())
	{
		pGrid->PrintErrorMessage("Game ended. You can't roll dice...");
		return;
	}
	pOut->PrintMessage("Please enter a dice value between 1-6 ...");
	int DiceNumber=pIn->GetInteger(pOut);
	if (DiceNumber<0 || DiceNumber>6)
	{
		pGrid->PrintErrorMessage("Invalid dice number. Click to enter a value again ...");
		return;
	}
	Player *CurrentPlayer=pGrid->GetCurrentPlayer();
	CurrentPlayer->Move(pGrid,DiceNumber);
	pGrid->AdvanceCurrentPlayer();
}
InputDiceAction::~InputDiceAction(void)
{
}
