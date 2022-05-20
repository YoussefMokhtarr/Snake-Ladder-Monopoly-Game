#include"EditCardAction.h"
#include"Grid.h"
#include"Card.h"
#include "Cardten.h"
#include "Cardeleven.h"
#include "Cardtwelve.h"
#include "Cardthirteen.h"
#include "Cardfourteen.h"

EditCardAction::EditCardAction(ApplicationManager* pApp): Action(pApp)
{
	pCard=NULL;
}

void EditCardAction::ReadActionParameters()
{
	Grid*pGrid= pManager->GetGrid();
	Output*pOut=pGrid->GetOutput();
	Input* pIn= pGrid->GetInput();
	pOut->PrintMessage("Edit Card: Click on the card that you want to edit...");
	cardPosition = pIn->GetCellClicked();

	if(!cardPosition.IsValidCell())
	{
		pGrid->PrintErrorMessage("Invalid Cell Position");
	}
	pGrid->CanBeEdited(pCard,cardPosition);
	if (pCard==NULL)
	{
		pGrid->PrintErrorMessage("The cell has no card to be edited");
	}
	else
	{
		CardNumber =pCard->GetCardNumber();
		if (CardNumber>=3 && CardNumber<= 8)
		{
			pGrid->PrintErrorMessage("This card can't be edited.");
			pCard=NULL;
		}
	}
}
void EditCardAction::Execute()	{
	Grid* pGrid =pManager->GetGrid();
	ReadActionParameters();
	if(pCard)
	{
		if (CardNumber==10)
		{
			Cardten *editcard = dynamic_cast<Cardten*>(pCard);
			editcard->setparameters();
			editcard->ReadCardParameters(pGrid);
		}
		else if(CardNumber==11)
		{
			Cardeleven *editcard = dynamic_cast<Cardeleven*>(pCard);
			editcard->setparameters();
			editcard->ReadCardParameters(pGrid);
		}
		else if(CardNumber==12)
		{
			Cardtwelve *editcard = dynamic_cast<Cardtwelve*>(pCard);
			editcard->setparameters();
			editcard->ReadCardParameters(pGrid);
		}
		else if(CardNumber==13)
		{
			Cardthirteen *editcard = dynamic_cast<Cardthirteen*>(pCard);
			editcard->setparameters();
			editcard->ReadCardParameters(pGrid);
		}
		else if(CardNumber==14)
		{
			Cardfourteen *editcard = dynamic_cast<Cardfourteen*>(pCard);
			editcard->setparameters();
			editcard->ReadCardParameters(pGrid);
		}
		else
			pCard->ReadCardParameters(pGrid);

		}
	}
	EditCardAction::~EditCardAction()
	{}