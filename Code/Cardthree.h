#pragma once
#include "Card.h"
class Cardthree :
	public Card
{public:
	Cardthree(const CellPosition& pos);
	//virtual void ReadCardParameters(Grid* pGrid);
	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of CardOne on the passed Player
													  // by decrementing the player's wallet by the walletAmount data member


	virtual void Load(ifstream &InFile);

	virtual ~Cardthree(); // A Virtual Destructor

	



};

