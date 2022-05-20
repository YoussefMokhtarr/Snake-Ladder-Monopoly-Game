#include "NewGameAction.h"

#include"Grid.h"
#include"Player.h"


NewGameAction::NewGameAction(ApplicationManager* pApp) : Action(pApp)
{


}

void NewGameAction::ReadActionParameters()
{
}
void NewGameAction::ResetPlayers() // Return players to first tile 
{								  // and resets turnCount and Current player
	CellPosition C1(8, 0);
	Grid* pGrid = pManager->GetGrid();
	for (int i = 0; i < MaxPlayerCount; i++)
	{
		Player* pPlayer = pGrid->GetCurrentPlayer();
		pGrid->UpdatePlayerCell(pPlayer, C1);
		pPlayer->SetTurnCount();
		pGrid->AdvanceCurrentPlayer();
		pPlayer->SetWallet(100);
		pGrid->GetEndGame();
	}
}
void NewGameAction::Execute() {


	Grid* pGrid = pManager->GetGrid();
	pGrid->PrintErrorMessage("New Game will  start");
	pGrid->SetEndGame(false);
	pGrid->SetCurrentPlayerNum(0); 
	this->ResetPlayers();
	



}


NewGameAction::~NewGameAction(void)
{
}