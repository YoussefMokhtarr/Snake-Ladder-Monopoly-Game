#pragma once
#include"Card.h"
#include"Action.h"
#include"Grid.h"
class EditCardAction : public Action
{   int CardNumber;// 1- the card number
	CellPosition cardPosition;// [Action Parameters]
    // Note: These parameters should be read in ReadActionParameters()
Card*pCard;//pointer of type card
public:
	EditCardAction(ApplicationManager*pApp);// A Constructor
	void ReadActionParameters();// Reads EditCardAction action parameters (cardNumber, cardPosition)
	void Execute();// Creates a new Card Object of the specific Card Number
	                        // and Reads the Parameters of This Card Number (if any)
	                        // then Sets this Card Object to GameObject Pointer of its Cell
	
	~EditCardAction();// A Virtual Destructor



};