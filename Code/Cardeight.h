#pragma once
#include "Card.h"
class Cardeight :public Card
{
	int n;
public:

	Cardeight(const CellPosition& pos);
	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of CardOne on the passed Player
													  // by decrementing the player's wallet by the walletAmount data member

	virtual ~Cardeight(); // A Virtual Destructor

};