#include "Cardseven.h"
Cardseven::Cardseven(const CellPosition& pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 7; // set the inherited cardNumber data member with the card number (1 here)
}

Cardseven::~Cardseven(void)
{
}
void Cardseven::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply( pGrid,  pPlayer);
	pGrid->SetCurrentPlayerNum((pGrid->GetCurrentPlayerNum()) -1);
	//pPlayer->Move(pGrid, pPlayer->Getjustrolled);
	//pPlayer->Move(pGrid, pPlayer-);

	
}

void Cardseven::Load(ifstream &InFile)
	{
	}