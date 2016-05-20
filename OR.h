#ifndef _OR_H
#define _OR_H

/*
Class OR
-----------
represent the OR gate
*/

#include "Components\Gate.h"

class OR : public Gate
{
public:
	OR(const GraphicsInfo &r_GfxInfo, int r_FanOut);
	virtual void Operate();	//Calculates the output of the OR gate
	virtual void Draw(Output* pOut);	//Draws OR gate

	virtual int GetOutPinStatus();	//returns status of outputpin if LED, return -1
	virtual int GetInputPinStatus(int n);	//returns status of Inputpin # n if SWITCH, return -1

	virtual void setInputPinStatus(int n, STATUS s);	//set status of Inputpin # n, to be used by connection class.


														//save & load
	virtual void Save(ofstream &OutFile);
	virtual void Load(ifstream &Infile);

};

#endif