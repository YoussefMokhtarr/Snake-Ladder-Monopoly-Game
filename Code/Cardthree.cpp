#include "Cardthree.h"
#include"Ladder.h"
Cardthree::Cardthree(const CellPosition& pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 3; // set the inherited cardNumber data member with the card number (1 here)
}

Cardthree::~Cardthree(void)
{
}
void Cardthree::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid,pPlayer);
	CellPosition pos;
	pos = pPlayer->GetCell()->GetCellPosition();

	Card::Apply(pGrid, pPlayer);
	Ladder* lad;
	lad = pGrid->GetNextLadder(pos);
	if (lad)
	{
		lad->Apply(pGrid, pPlayer);
		pGrid->PrintErrorMessage("player will reach next ladder");
	}


}
void Cardthree::Load(ifstream &InFile)
	{
	}