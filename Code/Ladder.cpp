#include "Ladder.h"

Ladder::Ladder(const CellPosition & startCellPos, const CellPosition & endCellPos) : GameObject(startCellPos)
{
	this->endCellPos = endCellPos;
	///TODO: Do the needed validation
}

void Ladder::Draw(Output* pOut) const
{
	pOut->DrawLadder(position, endCellPos);
}

void Ladder::Apply(Grid* pGrid, Player* pPlayer) 
{
	

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) to implement this function ==
	
	// 1- Print a message "You have reached a ladder. Click to continue ..." and wait mouse click
	pGrid->PrintErrorMessage("You have reached a Ladder. Click to contniue ...");
	// 2- Apply the ladder's effect by moving the player to the endCellPos
	pGrid->UpdatePlayerCell(pGrid->GetCurrentPlayer(),endCellPos);
	//    Review the "pGrid" functions and decide which function can be used for that
	
}

bool  Ladder::IsOverLapping(GameObject* newObj) const
{
	Ladder* pNewLadder = dynamic_cast<Ladder*>(newObj);
	if (pNewLadder)
	{
		if ((pNewLadder->position.GetCellNum() >= this->position.GetCellNum()&& pNewLadder->position.GetCellNum() <= this->endCellPos.GetCellNum()) || (pNewLadder->position.GetCellNum() <= this->position.GetCellNum()&& pNewLadder->endCellPos.GetCellNum() >= this->position.GetCellNum()))
		{
			return true;
		}
	}
	return false;
}

CellPosition Ladder::GetEndPosition() const
{
	return endCellPos;
}
void Ladder::Save(ofstream& OutFile , Type t)	// Saves the ladder parameters to the file
{

	if (t != LadderType) return; 
	if (t == LadderType)
	{
		OutFile << this->GetPosition().GetCellNum();
		OutFile << " ";
		OutFile << endCellPos.GetCellNum()<<endl;

		return;
	}
	}
void Ladder::Load(ifstream& InFile)// loads the ladder parameters to the file
{
      Ladder *lad;
		int endCellPos,startCellPos;
		InFile>>endCellPos >>startCellPos;
		lad=new Ladder(CellPosition(startCellPos),CellPosition(endCellPos));
}
Ladder::~Ladder()
{
}
