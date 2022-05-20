#include "AddCardAction.h"

#include "Input.h"
#include "Output.h"
#include "CardOne.h"
#include "Cardtwo.h"
#include "Cardthree.h"
#include "Cardfour.h"
#include "Cardfive.h"
#include "Cardsix.h"
#include "Cardseven.h"
#include "Cardeight.h"
#include "Cardnine.h"
#include "Cardten.h"
#include "Cardeleven.h"
#include "Cardtwelve.h"
#include "Cardthirteen.h"
#include "Cardfourteen.h"


AddCardAction::AddCardAction(ApplicationManager *pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}

AddCardAction::~AddCardAction()
{
}

void AddCardAction::ReadActionParameters() 
{	

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) to implement this function ==
	
	// 1- Get a Pointer to the Input / Output Interfaces
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	
	// 2- Read the "cardNumber" parameter and set its data member
	pOut->PrintMessage("NEW CARD:please enter the cardnumber......");
	cardNumber= pIn->GetInteger(pOut);

	if(cardNumber>14 || cardNumber<1)
	{
		pGrid->PrintErrorMessage("invalid card number please enter a value between 1 and 14 ! Click to continue ...");
		return;
	}
	
	// 3- Read the "cardPosition" parameter (its cell position) and set its data member
	pOut->PrintMessage("please select the position of the card");
    cardPosition = pIn->GetCellClicked();
	// 4- Make the needed validations on the read parameters
	

	// 5- Clear status bar
		pOut->ClearStatusBar();
}

void AddCardAction::Execute() 
{

	
	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) to implement this function ==

	// 1- The first line of any Action Execution is to read its parameter first
		ReadActionParameters();
	// 2- Switch case on cardNumber data member and create the appropriate card object type
	Card * pCard = NULL; // will point to the card object type
	switch (cardNumber)
	{
	case 1:
		pCard = new CardOne(cardPosition);
		break;
	case 2:
		pCard = new Cardtwo(cardPosition);
		break;
    case 3:
		pCard = new Cardthree(cardPosition);
		break;
	case 4:
		pCard = new Cardfour(cardPosition);
		break;
	case 5:
		pCard = new Cardfive(cardPosition);
		break;		
	case 6:
		pCard = new Cardsix(cardPosition);
		break;
	case 7:
		pCard = new Cardseven(cardPosition);
		break;
	case 8:
		pCard = new Cardeight(cardPosition);
		break;
	case 9:
		pCard = new Cardnine(cardPosition);
		break;
	case 10:
		pCard = new Cardten (cardPosition);
		break;
	case 11:
		pCard = new Cardeleven (cardPosition);
		break;
	case 12:
		pCard = new Cardtwelve (cardPosition);
		break;
	case 13:
		pCard = new Cardthirteen (cardPosition);
		break;
	case 14:
		pCard = new Cardfourteen (cardPosition);
		break;
		
		// A- Add the remaining cases

	}

	// 3- if pCard is correctly set in the switch case (i.e. if pCard is pointing to an object -- NOT NULL)

		if(!(cardPosition.IsValidCell()))
	{
		Grid *pGrid=pManager->GetGrid();
		pGrid->PrintErrorMessage("invalid cell! Click to continue ...");
		return;
	}

	if (pCard)
	{
		// A- We get a pointer to the Grid from the ApplicationManager
		Grid * pGrid = pManager->GetGrid(); 
		// B- Make the "pCard" reads its card parameters: ReadCardParameters(), It is virtual and depends on the card type
		pCard->ReadCardParameters(pGrid);
		// C- Add the card object to the GameObject of its Cell:
		bool added = pGrid->AddObjectToCell(pCard);
	// D- if the GameObject cannot be added in the Cell, Print the appropriate error message on statusbar
		if(!added)
		{
			pGrid->PrintErrorMessage("Error: Cell already has an object ! Click to continue ...");
		}

		
	}

	// Here, the card is created and added to the GameObject of its Cell, so we finished executing the AddCardAction

}
