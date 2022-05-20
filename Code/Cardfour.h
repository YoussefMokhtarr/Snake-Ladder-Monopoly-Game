#pragma once
#include "Card.h"
class Cardfour :public Card
{
public:
	Cardfour(const CellPosition& pos);
	//virtual void ReadCardParameters(Grid* pGrid);
	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of CardOne on the passed Player
													  // by decrementing the player's wallet by the walletAmount data member

	virtual ~Cardfour(); // A Virtual Destructor

	virtual void Load(ifstream &InFile);


};

