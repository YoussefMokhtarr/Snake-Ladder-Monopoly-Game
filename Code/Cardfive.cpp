#include "Cardfive.h"
Cardfive::Cardfive(const CellPosition& pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 5; // set the inherited cardNumber data member with the card number (1 here)
}

Cardfive::~Cardfive(void)
{
}
void Cardfive::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid, pPlayer);
	int x = pPlayer->Getjustrolled();
	CellPosition c1;
	c1 = pPlayer->GetCell()->GetCellPosition();
	c1.AddCellNum(x);
	pGrid->UpdatePlayerCell(pPlayer, c1);
	pGrid->PrintErrorMessage("player will move forward the same value");


	//if (pPlayer->GetCell()->GetGameObject())
	//{
	//	pPlayer->GetCell()->GetGameObject()->Apply(pGrid, pPlayer);
	//}

	
}
void Cardfive::Load(ifstream &InFile)
	{
	}