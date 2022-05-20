#pragma once
#include "GameObject.h"
class Snake : public GameObject
{
	CellPosition endCellPos;
public:
	Snake(const CellPosition& ,const CellPosition&);
		virtual void Draw(Output*pOut)const;
		virtual void Apply(Grid*,Player*);
			CellPosition GetEndPosition() const;
			virtual bool  IsOverLapping(GameObject* newObj) const;
			virtual void Save(ofstream& OutFile, Type t);// Saves the snake parameters to the file
			virtual void Load(ifstream& InFile);// Loads the snake parameters to the file
		~Snake();
};