#pragma once
#include "Card.h"

class Cardthirteen:public Card
{static bool isinitialize;
	static int CardPrice; //the price of the card that the player should pay to buy it
	static int feesTopay; //the fees that the player who pass through the card that another player had bought should pay
 static bool bought;// to check if anyplayer bougth this cell
	static Player *owner;
public:
	public:
	Cardthirteen(const CellPosition & pos); // A Constructor takes card position

	  virtual void ReadCardParameters(Grid * pGrid); // Reads the parameters of CardTen which is: walletAmount
	  void setparameters();
	   virtual  void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of CardTen on the passed Player

	virtual ~Cardthirteen(); //virtual Destructor
	void Cardthirteen::Save(ofstream& OutFile, Type t,Grid*pGrid);
	virtual void Load(ifstream &InFile);
	};