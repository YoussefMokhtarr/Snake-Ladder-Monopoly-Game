#include "Snake.h"
Snake::Snake(const CellPosition & startCellPos, const CellPosition & endCellPos) : GameObject(startCellPos)
{
	this->endCellPos=endCellPos;
}
void Snake::Apply(Grid*pGrid,Player*pPlayer)
{
	pGrid->PrintErrorMessage("You have reached a Snake. Click to continue ...");
	pGrid->UpdatePlayerCell(pGrid->GetCurrentPlayer(),endCellPos);
}
void Snake::Draw(Output*pOut)const
{
	pOut->DrawSnake(position,endCellPos);
}
CellPosition Snake::GetEndPosition()const
{
	return endCellPos;
}

bool  Snake::IsOverLapping(GameObject* newObj) const
{
	Snake* pNewSnake = dynamic_cast<Snake*>(newObj);
	if (pNewSnake)
	{
		if ((pNewSnake->position.GetCellNum() >= this->position.GetCellNum()&& pNewSnake->endCellPos.GetCellNum() < this->position.GetCellNum()) || (pNewSnake->position.GetCellNum() >= this->endCellPos.GetCellNum()&& pNewSnake->position.GetCellNum() <= this->position.GetCellNum()))
		{
			return true;
		}
	}
	return false;
}

void Snake::Save(ofstream& OutFile, Type t)	// Saves the snake parameters to the file
{

	if (t != SnakeType) return;
	if (t == SnakeType)
	{
		OutFile << this->GetPosition().GetCellNum();
		OutFile << " ";
		OutFile << endCellPos.GetCellNum()<<endl;

		return;
	}

}
void Snake::Load(ifstream& InFile)	// Loads the snake parameters to the file
{
Snake*sna;
		int endCellPos,startCellPos;
		InFile>>endCellPos >>startCellPos;
		sna=new Snake(CellPosition(startCellPos),CellPosition(endCellPos));

}
Snake::~Snake()
{
}