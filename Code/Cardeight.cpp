#include "Cardeight.h"
Cardeight::Cardeight(const CellPosition& pos) :Card(pos)
{
	cardNumber = 8;
}
Cardeight::~Cardeight(void)
{

}
void Cardeight::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid, pPlayer);


	//pPlayer->setnoroll(1);
	Input* pIn = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();
	pOut->PrintMessage("Please Enter Number of Rolls to Freeze Other Players");
	n = pIn->GetInteger(pOut);
	for (int i = 0; i < n; i++)
	{
		
		pPlayer->Move(pGrid, pPlayer->Getjustrolled() );
		
	}





}