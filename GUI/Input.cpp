//#include "Input.h"
#include "Output.h"

Input::Input(window* pW)
{
	pWind = pW; //point to the passed window
}

void Input::GetPointClicked(int &x, int &y)
{
	pWind->WaitMouseClick(x, y);	//Wait for mouse click
}

string Input::GetSrting(Output *pOut)
{
	///TODO: Implement this Function
	//Read a complete string from the user until the user presses "ENTER".
	//If the user presses "ESCAPE". This function should return an empty string.
	//"BACKSPACE" should be also supported
	//User should see what he is typing at the status bar


	string Str;
	char Key;
	while (1)
	{
		pWind->WaitKeyPress(Key);
		if (Key == 27)	//ESCAPE key is pressed
			return "";	//returns nothing as user has cancelled label
		if (Key == 13)	//ENTER key is pressed
			return Str;
		if (Key == 8)	//BackSpace is pressed
		{
			if (Str.size()>0)
				Str.resize(Str.size() - 1);
		}
		else
			Str += Key;
		pOut->PrintMsg(Str);
	}

}

//This function reads the position where the user clicks to determine the desired action
ActionType Input::GetUserAction() const
{
	int x,y;
	//	pWind->WaitMouseClick(x, y);	//Get the coordinates of the user click

	pWind->WaitMouseClick(x, y);	//Get the coordinates of the user click

	if (UI.AppMode == DESIGN)	//application is in design mode
	{

		//[1] If user clicks on the Toolbar
		if (y >= 0 && y < UI.ToolBarHeight)
		{
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / UI.ToolItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
			case ITM_AND_2: return ADD_AND_GATE_2;
			case ITM_AND_3: return ADD_AND_GATE_3;
			case ITM_OR_2: return ADD_OR_GATE_2;
			case ITM_INV_2: return ADD_INV;
			case ITM_BUFF: return ADD_BUFF;
			case ITM_NAND_2: return ADD_NAND_GATE_2;
			case ITM_NOR_2: return ADD_NOR_GATE_2;
			case ITM_NOR_3: return ADD_NOR_GATE_3;
			case ITM_XOR_2: return ADD_XOR_GATE_2;
			case ITM_XOR_3: return ADD_XOR_GATE_3;

			case ITM_SWITCH: return ADD_Switch;
			case ITM_LED: return ADD_LED;
			case ITM_CONNECTION: return ADD_CONNECTION;
			case ITM_SAVE: return SAVE;
			case ITM_DELET: return DEL;
			case ITM_SELECT: return SELECT;
			case ITM_MOVE: return MOVE;
			case ITM_LOAD: return LOAD;
			case ITM_UNDO: return UNDO;
			case ITM_REDO: return REDO;
			case ITM_SIMU: return SIM_MODE;

			case ITM_EXIT: return EXIT;

			default: return DSN_TOOL;	//A click on empty place in desgin toolbar
			}
		}

		//[2] User clicks on the drawing area
		if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)     ///// net2kdd mn condition da 
		{
			return DRAW;	//user want to select/unselect a statement in the flowchart
		}

		//[3] User clicks on the status bar
		return STATUS_BAR;
	}
	else	//Application is in Simulation mode
	{

		if (y >= 0 && y < UI.ToolBarHeight)
		{
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / UI.ToolItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{



			case ITM_SAVE2: return SAVE;
			case ITM_LOAD2: return LOAD;
			case ITM_VALIDATE: return VALIDATE;
			case ITM_RUN: return RUN;
			case ITM_TRUTH: return Create_TruthTable;
			case ITM_DESIGN: return DSN_MODE;

			case ITM_EXIT2: return EXIT;

			default: return DSN_TOOL;	//A click on empty place in desgin toolbar
			}
		}

		//[2] User clicks on the drawing area
		if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)                   /////////////hnaa brdoo
		{
			return DRAW;	//user want to select/unselect a statement in the flowchart
		}
	}

}

////3shan el save
void Input::flush()
{
	pWind->FlushKeyQueue();  //akeni msh daysa ay key 3l keyboard // byfady memory bt3tha
	pWind->FlushMouseQueue();
}

Input::~Input()
{
}



//
////#include "Input.h"
//#include "Output.h"
//
//Input::Input(window* pW)
//{
//	pWind = pW; //point to the passed window
//}
//
//void Input::GetPointClicked(int &x, int &y)
//{
//	pWind->WaitMouseClick(x, y);	//Wait for mouse click
//}
//
//string Input::GetSrting(Output *pOut)
//{
//	///TODO: Implement this Function
//	//Read a complete string from the user until the user presses "ENTER".
//	//If the user presses "ESCAPE". This function should return an empty string.
//	//"BACKSPACE" should be also supported
//	//User should see what he is typing at the status bar
//
//	return NULL;
//}
//
////This function reads the position where the user clicks to determine the desired action
//ActionType Input::GetUserAction() const
//{	
//	int x,y;
//	pWind->WaitMouseClick(x, y);	//Get the coordinates of the user click
//
//	if(UI.AppMode == DESIGN )	//application is in design mode
//	{
//		//[1] If user clicks on the Toolbar
//		if ( y >= 0 && y < UI.ToolBarHeight)
//		{	
//			//Check whick Menu item was clicked
//			//==> This assumes that menu items are lined up horizontally <==
//			int ClickedItemOrder = (x / UI.ToolItemWidth);
//			//Divide x coord of the point clicked by the menu item width (int division)
//			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on
//
//			switch (ClickedItemOrder)
//			{
//			case ITM_AND2: return ADD_AND_GATE_2;
//			case ITM_OR2: return ADD_OR_GATE_2;
//			case ITM_EXIT: return EXIT;	
//			
//			default: return DSN_TOOL;	//A click on empty place in desgin toolbar
//			}
//		}
//	
//		//[2] User clicks on the drawing area
//		if ( y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
//		{
//			return SELECT;	//user want to select/unselect a statement in the flowchart
//		}
//		
//		//[3] User clicks on the status bar
//		return STATUS_BAR;
//	}
//	else	//Application is in Simulation mode
//	{
//		return SIM_MODE;	//This should be changed after creating the compelete simulation bar 
//	}
//
//}
//
//
//Input::~Input()
//{
//}
