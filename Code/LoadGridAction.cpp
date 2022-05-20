#include "Action.h"
#include <fstream>
#include"Grid.h"
#include<string>
#include"LoadGridAction.h"
#include "Snake.h"
#include "Ladder.h"
#include "Card.h"
#include "CardOne.h"
#include "Cardtwo.h"
#include "Cardthree.h"
#include "Cardfour.h"
#include "Cardfive.h"
#include "Cardsix.h"
#include "Cardseven.h"
#include "Cardeight.h"
#include "Cardnine.h"
#include "Cardten.h"
#include "Cardeleven.h"
#include "Cardtwelve.h"
#include "Cardthirteen.h"
#include "Cardfourteen.h"
#include "GameObject.h"

LoadGridAction::LoadGridAction(ApplicationManager *pApp) : Action(pApp)
{
	ifstream InFile;
	InFile>>filename;
}

void LoadGridAction::ReadActionParameters()
{
	ifstream InFile;
	InFile>>filename;
}
void LoadGridAction::Execute()
{
	ifstream InFile;
	InFile.open(filename,ios::app);
	int l=0,s=0,c=0;//Ladder,Snake, and card number
	InFile>>l;
	for(int i=0;i<l;i++){
		Ladder*lad;
		lad=NULL;
		lad->Load(InFile);
	}
	InFile>>s;
	for(int i=0;i<s;i++){
		Snake *sna;
		sna=NULL;
		sna->Load(InFile);
	}
	InFile>>c;
	for(int i=0;i<c;i++){
		Card *cd;
		cd=NULL;
		int num,pos;
		InFile>>num;
		switch (num)
		{
		case 1:
			InFile>>pos;
			cd=new CardOne(CellPosition(pos));
			break;

		case 2:
			InFile>>pos;
			cd=new Cardtwo(CellPosition(pos));
			break;

		case 3:
			InFile>>pos;
			cd=new Cardthree(CellPosition(pos));
			break;

		case 4:
			InFile>>pos;
			cd=new Cardfour(CellPosition(pos));
			break;

		case 5:
			InFile>>pos;
			cd=new Cardfive(CellPosition(pos));
			break;

		case 6:
			InFile>>pos;
			cd=new Cardsix(CellPosition(pos));
			break;

		case 7:
			InFile>>pos;
			cd=new Cardseven(CellPosition(pos));
			break;

		case 8:
			InFile>>pos;
			cd=new Cardeight(CellPosition(pos));
			break;

		case 9:
			InFile>>pos;
			cd=new Cardnine(CellPosition(pos));
			break;

		case 10:
			InFile>>pos;
			cd=new Cardten(CellPosition(pos));
			break;

		case 11:
			InFile>>pos;
			cd=new Cardeleven(CellPosition(pos));
			break;

		case 12:
			InFile>>pos;
			cd=new Cardtwelve(CellPosition(pos));
			break;

		case 13:
			InFile>>pos;
			cd=new Cardthirteen(CellPosition(pos));
			break;

		case 14:
			InFile>>pos;
			cd=new Cardfourteen(CellPosition(pos));
			break;
		}
		cd->Load(InFile);
	}
	InFile.close();
}
LoadGridAction::~LoadGridAction(){
}



