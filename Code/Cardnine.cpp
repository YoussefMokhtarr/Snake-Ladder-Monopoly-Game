#include "Cardnine.h"
Cardnine::Cardnine(const CellPosition& pos) : Card(pos)
{
	cardNumber = 9;
}
void Cardnine::ReadCardParameters(Grid* pGrid) {
	pGrid->PrintErrorMessage("Enter the Cell number you would likea player to move to");

	movecell = pGrid->GetInput()->GetInteger(pGrid->GetOutput());

}


void Cardnine::Apply(Grid* pGrid, Player* pPlayer) {

	CellPosition move(movecell);
	Card::Apply(pGrid, pPlayer);
	pGrid->PrintErrorMessage("Player will move to cell " + to_string(movecell) + ".Click anywhere to Continue");
	pGrid->UpdatePlayerCell(pPlayer, move);

}

void Cardnine::Edit(Grid* pGrid) {

	pGrid->GetOutput()->PrintMessage("Enter the cell number you would like to move to.");
	int m = pGrid->GetInput()->GetInteger(pGrid->GetOutput());
	if (m >= 1 && m <= 99) movecell = m;
	else {
		pGrid->PrintErrorMessage("Invalid Entry for Cell Number no movemrnt " + to_string(movecell));
	}

}


bool Cardnine::Validate() {

	return (movecell >= 1 && movecell <= 99) ? true : false;
}
void Cardnine::Save(ofstream& OutFile, Type t,Grid*pGrid)	// Saves the GameObject parameters to the file
{
	Card::Save(OutFile, t,pGrid);
	OutFile << this->movecell;
	OutFile << "\t ";
}
void Cardnine::Load(ifstream &InFile)
{
	int movcell;
	InFile>>movcell;
	this->movecell=movcell;
}

Cardnine::~Cardnine()
{
}
