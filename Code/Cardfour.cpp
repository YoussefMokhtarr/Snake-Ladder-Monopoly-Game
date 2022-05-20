#include "Cardfour.h"
#include"Snake.h"
Cardfour::Cardfour(const CellPosition& pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 4; // set the inherited cardNumber data member with the card number (1 here)
}

Cardfour::~Cardfour(void)
{
}


void Cardfour::Apply(Grid* pGrid, Player* pPlayer)
{
	CellPosition pos;
	pos = pPlayer->GetCell()->GetCellPosition();

	Card::Apply(pGrid, pPlayer);
	Snake* sna;
	sna = pGrid->GetNextSnake(pos);
	if (sna)
		sna->Apply(pGrid, pPlayer);
	pGrid->PrintErrorMessage("player will go to next snake");

}

void Cardfour::Load(ifstream &InFile)
{
}