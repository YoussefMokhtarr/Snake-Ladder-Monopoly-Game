#pragma once
#include "Card.h"
class Cardseven :
	public Card
{
public:
	Cardseven(const CellPosition& pos);
	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of CardOne on the passed Player
													  // by decrementing the player's wallet by the walletAmount data member

	virtual ~Cardseven(); // A Virtual Destructor


	 virtual void Load(ifstream &InFile);





};