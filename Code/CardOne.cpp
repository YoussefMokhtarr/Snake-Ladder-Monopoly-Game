#include "CardOne.h"

CardOne::CardOne(const CellPosition & pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 1; // set the inherited cardNumber data member with the card number (1 here)
}

CardOne::~CardOne(void)
{
}

void CardOne::ReadCardParameters(Grid * pGrid)
{
	
	//pGrid->GetInput()->GetInteger(pGrid->GetOutput());
	
	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) (numbered below) to implement this function ==

	Output*pout=pGrid->GetOutput();
	Input*pin=pGrid->GetInput();
	pout->PrintMessage("New Cardone:enter its wallet amount...");
	walletAmount=pin->GetInteger(pout);	
	
	pout->ClearStatusBar();
	
	// 1- Get a Pointer to the Input / Output Interfaces from the Grid

	// 2- Read an Integer from the user using the Input class and set the walletAmount parameter with it
	//    Don't forget to first print to a descriptive message to the user like:"New CardOne: Enter its wallet amount ..."
	
	// [ Note ]:
	// In CardOne, the only parameter of CardOne is the "walletAmount" value to decrease from player
	// Card parameters are the inputs you need to take from the user in the time of adding the Card in the grid
	// to be able to perform his Apply() action

	// 3- Clear the status bar

}

void CardOne::Apply(Grid* pGrid, Player* pPlayer)
{
		
	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below
	

	// == Here are some guideline steps (numbered below) (numbered below) to implement this function ==

	// 1- Call Apply() of the base class Card to print the message that you reached this card number
	Card::Apply(pGrid,pPlayer);
	if (pPlayer->GetWallet()>=walletAmount)
		{
		pPlayer->SetWallet(pPlayer->GetWallet()-walletAmount);// 2- Decrement the wallet of pPlayer by the walletAmount data member of CardOne
		}
		else
		{
			pPlayer->setnoroll(1);

}
}
void CardOne::Edit(Grid* pGrid) {
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	pOut->PrintMessage("Enter a new  value of money  to be reduced from wallet ");
	int amount = pIn->GetInteger(pOut);
	if (amount <= 0) {
		pGrid->PrintErrorMessage("Invalid value .");
		return;
	}
	walletAmount = amount;

	pOut->ClearStatusBar();
}
void CardOne::Save(ofstream& OutFile, Type t,Grid*pGrid)	// Saves the GameObject parameters to the file
{

	Card::Save(OutFile, t,pGrid);
		OutFile << this->walletAmount;
		OutFile << "\t ";
}

void CardOne::Load(ifstream &InFile) //Loads the cardone parameters
{
	int wallet;
	InFile>>wallet;
	this->walletAmount=wallet;
}

bool CardOne::Validate() {
	if (walletAmount <= 0) 
		return false;

}
