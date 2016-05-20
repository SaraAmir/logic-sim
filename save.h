#ifndef SAVE_H
#define SAVE_H

#include <string>
#include "Actions\Action.h"
//#include "..\Statements/*"

using namespace std;

class save : public Action
{
private:
	std::string Name;	//Position where the user clicks to add the stat.

public:
	save(ApplicationManager *pAppManager);

	//Read Assignemt statements position
	virtual void ReadActionParameters();

	//Create and add an assignemnt statement to the list of statements
	virtual void Execute();

};

#endif