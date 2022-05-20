#pragma once
#include "Card.h"
class Cardtwo :
	public Card
{


	int walletAmount; // the wallet value to decrease from the player

public:
	Cardtwo(const CellPosition& pos); // A Constructor takes card position

	virtual void ReadCardParameters(Grid* pGrid); // Reads the parameters of CardOne which is: walletAmount

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of CardOne on the passed Player
													  // by decrementing the player's wallet by the walletAmount data member

	virtual ~Cardtwo(); // A Virtual Destructor
	virtual void Edit(Grid* pGrid);
	virtual void Save(ofstream& OutFile, Type t,Grid*pGrid);
	virtual void Load(ifstream &InFile);
	virtual bool Validate();

};

