#include "Cardtwelve.h"
#include<string>

int Cardtwelve::CardPrice=0;
int Cardtwelve::feesTopay=0;
Player* Cardtwelve::owner=NULL;
bool Cardtwelve::isinitialize=false;
bool Cardtwelve::bought=false;
Cardtwelve::Cardtwelve(const CellPosition & pos):Card(pos)
{
	cardNumber = 12; // set the inherited cardNumber data member with the card number (12 here)
}

void Cardtwelve::setparameters()
{
	isinitialize=false;
}


void Cardtwelve::ReadCardParameters(Grid * pGrid)
{


	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) (numbered below) to implement this function ==


	// 1- Get a Pointer to the Input / Output Interfaces from the Grid
	Input* pIn = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();

	// 2- Read an Integer from the user using the Input class and set the Card price and fees 
	//    Don't forget to first print to a descriptive message to the user like:"New CardTen: Please enter the CardPrice"
	if(isinitialize==false)
	{pOut->PrintMessage("New CardTwelve: Please enter the CardPrice");
	CardPrice =  pIn->GetInteger(pOut);
	pOut->PrintMessage("Please enter the Fees");
	feesTopay =  pIn->GetInteger(pOut);
	isinitialize=true;
	}
	while (CardPrice<0 || feesTopay<0)
	{
			pGrid->PrintErrorMessage("Invalid value. Enter postitve values ...");
			pOut->PrintMessage("Please enter the CardPrice");
			CardPrice =  pIn->GetInteger(pOut);
			pOut->PrintMessage("Please enter the Fees");
			feesTopay =  pIn->GetInteger(pOut);
	}
	// 3- Clear the status bar
	pOut->ClearStatusBar();
}

void Cardtwelve::Apply(Grid* pGrid, Player* pPlayer)
{

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) (numbered below) to implement this function ==

	// 1- Call Apply() of the base class Card to print the message that you reached this card number
	Card::Apply(pGrid,pPlayer);
	Input* pIn = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();
	// 2- pPlayer buys the card and CardTen;

	if(!bought)
	{
		pOut->PrintMessage("Do you want to buy this Cell?Y/N");
		string s=pIn->GetSrting(pOut);
		if((s=="Y"||"y")&&pPlayer->GetWallet()>CardPrice)
		{owner=pPlayer;
		pPlayer->SetWallet(pPlayer->GetWallet()-CardPrice);

		bought=true;

		}

		else if((s=="Y"||"y")&&pPlayer->GetWallet()<CardPrice)
		{	pOut->PrintMessage("Sorry You don't have enough money in your Wallet to buy the Cell");
		}
	}
	//3-pPlayer takes money from other players
	if(bought)
	{



		if (pPlayer->GetWallet()>=feesTopay&&pPlayer!=owner)
		{
			pPlayer->SetWallet(pPlayer->GetWallet()-feesTopay);
			owner->SetWallet(owner->GetWallet()+feesTopay);
		}
		else if(pPlayer->GetWallet()<=feesTopay&&pPlayer!=owner)
			pPlayer->setnoroll(1);
	}
}
void Cardtwelve::Save(ofstream& OutFile, Type t,Grid*pGrid)	// Saves the GameObject parameters to the file
{

	Card::Save(OutFile, t,pGrid);
	OutFile << this->CardPrice;
	OutFile << "\t ";
	OutFile << this->CardPrice;
	OutFile << "\t ";





}


void Cardtwelve::Load(ifstream &InFile)
{
	int cardprice,fees;
		InFile>>cardprice;
	this->CardPrice=cardprice;
	InFile>>fees;
	this->feesTopay=fees;
}








Cardtwelve::~Cardtwelve(void)
{
}