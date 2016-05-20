#include"save.h"
#include "ApplicationManager.h"
//#include "..\GUI\Input.h"
//#include "..\GUI\Output.h"
//#include"..\GeneralFunctions.h"
//#include <sstream>

#include "GUI\Input.h"
#include "GUI\Output.h"

using namespace std;

//constructor: set the ApplicationManager pointer inside this action
save::save(ApplicationManager *pAppManager) :Action(pAppManager)
{
	//this->Name = "";
}



void save::ReadActionParameters()
{
	Input *pIn = pManager->GetInput();
	Output *pOut = pManager->GetOutput();

	pOut->PrintMsg( "PLEASE ENTER THE NAME OF FILE : ");
	pIn->flush();
	Name = pIn->GetSrting(pOut);
	pIn->flush();

	pOut->ClearStatusBar();
}

void save::Execute()
{
	ReadActionParameters();

	pManager->save(Name);
}

