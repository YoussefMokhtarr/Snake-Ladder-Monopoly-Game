#include "Player.h"

#include "GameObject.h"
#include"CellPosition.h"

Player::Player(Cell * pCell, int playerNum) : stepCount(0), wallet(100), playerNum(playerNum)
{
	this->pCell = pCell;
	this->turnCount = 0;
	noroll = false;

	// Make all the needed initialization or validations
}

// ====== Setters and Getters ======
int Player::Getjustrolled()const
{
	return justRolledDiceNum;
}
int Player::Getstepcount()const
{
	return stepCount;
}
void Player::SetCell(Cell * cell)
{
	pCell = cell;
}

Cell* Player::GetCell() const
{
	return pCell;
}

void Player::SetWallet(int x)
{ if(x>0)
	this->wallet = x;
	// Make any needed validations
}

int Player::GetWallet() const
{
	return wallet;
}

int Player::GetTurnCount() const
{
	return turnCount;
}

// ====== Drawing Functions ======

void Player::Draw(Output* pOut) const
{
	color playerColor = UI.PlayerColors[playerNum];

	pOut->DrawPlayer(this->GetCell()->GetCellPosition(), this->playerNum, playerColor);
	///TODO: use the appropriate output function to draw the player with "playerColor"

}

void Player::ClearDrawing(Output* pOut) const
{
	color cellColor = pCell->HasCard() ? UI.CellColor_HasCard : UI.CellColor_NoCard;
	pOut->DrawPlayer(this->GetCell()->GetCellPosition(), this->playerNum, cellColor);

	///TODO: use the appropriate output function to draw the player with "cellColor" (to clear it)

}
void Player::SetTurnCount(int n)
{
	turnCount = n;
}

// ====== Game Functions ======
void Player::setnoroll(int x)
{
	noroll = x;
	return;

}

void Player::Move(Grid * pGrid, int diceNumber)
{
	if (noroll)
	{
		noroll = false;
		turnCount++;
		return;
	}

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below

	turnCount++;
	pGrid->PrintErrorMessage("Dice Roll : " + to_string(diceNumber));
	justRolledDiceNum=diceNumber;


// 2- Check the turnCount to know if the wallet recharge turn comes (recharge wallet instead of move)
//    If yes, recharge wallet and reset the turnCount and return from the function (do NOT move)
if (turnCount % 3==0) {
	this->SetWallet(this->GetWallet() + (diceNumber * 10));
	
	return;
}
//    Using the appropriate function of CellPosition class to update "pos"
if (this->wallet > 0) {
	CellPosition pos;
	pos = this->GetCell()->GetCellPosition();
	pos.AddCellNum(diceNumber);
	if (pos.IsValidCell()) { //Checks if the player rolls the right amount to land exactly on 100 tile
		pGrid->UpdatePlayerCell(this, pos);
		if (this->GetCell()->GetGameObject()) this->GetCell()->GetGameObject()->Apply(pGrid, this);
		// 7- Check if the player reached the end cell of the whole game, and if yes, Set end game with true: pGrid->SetEndGame(true)
		if (this->GetCell()->GetCellPosition().GetCellNum() == (NumHorizontalCells * NumVerticalCells)) {
			pGrid->SetEndGame(true);
		}
	}
	else pGrid->PrintErrorMessage("you can't move this number of dice numbers bu you won!!!!");
}
else pGrid->PrintErrorMessage("you must stay in this position as you have zero cins :(");


}
// 3- Set the justRolledDiceNum with the passed diceNumber

// 4- Get the player current cell position, say "pos", and add to it the diceNumber (update the position)

	// 5- Use pGrid->UpdatePlayerCell() func to Update player's cell POINTER (pCell) with the cell in the passed position, "pos" (the updated one)
	//    the importance of this function is that it Updates the pCell pointer of the player and Draws it in the new position

	
		// 6- Apply() the game object of the reached cell (if any)
		

void Player::AppendPlayerInfo(string & playersInfo) const
{
	playersInfo += "P" + to_string(playerNum) + "(" ;
	playersInfo += to_string(wallet) + ", ";
	playersInfo += to_string(turnCount) + ")";
}
