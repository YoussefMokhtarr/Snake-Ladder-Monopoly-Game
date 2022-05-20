#pragma once
#include"Card.h"
class Cardnine:public Card
{


private:
	int movecell;
public:
	Cardnine(const CellPosition& pos);
	virtual void ReadCardParameters(Grid* pGrid);
	virtual void Apply(Grid* pGrid, Player* pPlayer);
	virtual void Edit(Grid* pGrid);
	virtual bool Validate();
	virtual void Save(ofstream& OutFile, Type t,Grid*pGrid);
	virtual void Load(ifstream &InFile);
	~Cardnine();
};

