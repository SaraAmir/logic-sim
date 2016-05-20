#ifndef _ADD_OR_GATE_H
#define _ADD_OR_GATE_H

#include "Actions\Action.h"
#include "OR.h"

class AddORgate : public Action
{
private:
	//Parameters for rectangular area to be occupied by the gate
	int Cx, Cy;	//Center point of the gate
	int x1, y1, x2, y2;	//Two corners of the rectangluar area
public:
	AddORgate(ApplicationManager *pApp);
	virtual ~AddORgate(void);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();


};

#endif