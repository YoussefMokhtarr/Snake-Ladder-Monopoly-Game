#pragma once
#include "Card.h"
class Cardfive :
	public Card
{public:
	Cardfive(const CellPosition& pos);
	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of CardOne on the passed Player
													  // by decrementing the player's wallet by the walletAmount data member

	virtual ~Cardfive(); // A Virtual Destructor

	virtual void Load(ifstream &InFile);


};



