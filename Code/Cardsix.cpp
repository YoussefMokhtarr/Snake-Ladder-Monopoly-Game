#include "Cardsix.h"
Cardsix::Cardsix(const CellPosition& pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 6; // set the inherited cardNumber data member with the card number (1 here)
}

Cardsix::~Cardsix(void)
{
}
void Cardsix::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid, pPlayer);
	int x = pPlayer->Getjustrolled();
	CellPosition c1;
	c1 = pPlayer->GetCell()->GetCellPosition();
	c1.AddCellNum(-x);
	pGrid->UpdatePlayerCell(pPlayer, c1);
	pGrid->PrintErrorMessage("");
	//if (pPlayer->GetCell()->GetGameObject())
	//{
	//	pPlayer->GetCell()->GetGameObject()->Apply(pGrid, pPlayer);
	//}

	


}

void Cardsix::Load(ifstream &InFile)
	{
	}