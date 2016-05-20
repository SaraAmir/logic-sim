#ifndef UI_INFO_H
#define UI_INFO_H

#include "..\CMUgraphicsLib\CMUgraphics.h"
#include "..\Defs.h"

//User Interface information file.
//This file contains info that is needed by Input and Output classes to
//handle the user interface

__declspec(selectany) //This line to prevent "redefinition error"

struct UI_Info	//User Interface Info.
{
	MODE AppMode;		//Application Mode (design or simulation)

	static const int	width = 1350, height = 650,	//Window width and height
		wx = 0, wy = 0,			//Window starting coordinates
		StatusBarHeight = 50,	//Status Bar Height
		ToolBarHeight = 60,		//Tool Bar Height (distance from top of window to bottom line of toolbar)
		ToolItemWidth = 60;		//Width of each item in toolbar menu

	color DrawColor;		//Drawing color
	color SelectColor;		//Highlighting color
	color ConnColor;		//Connector color
	color MsgColor;			//Messages color
	color BkGrndColor;		//Back ground color


							//This should be calculated accurately because it will be used later to create connections between gates
							//For now, we will assume that rect width = 50 and height = 50
	static const int
		AND2_Width = 70,		//AND2 Gate Image default width
		AND2_Height = 30,       //AND2 Gate Image default height


		AND3_Width = 70,
		AND3_Height = 30,

		OR2_Width = 70,
		OR2_Height = 30,

		INV2_Width = 70,
		INV2_Height = 30,

		BUFF_Width = 70,
		BUFF_Height = 30,

		NOR2_Width = 70,
		NOR2_Height = 30,

		NOR3_Width = 70,
		NOR3_Height = 30,

		NAND2_Width = 70,
		NAND2_Height = 30,

		XOR2_Width = 70,
		XOR2_Height = 30,

		XOR3_Width = 70,
		XOR3_Height = 30,

		LED_Width = 70,
		LED_Height = 30,

		SWITCH_Width = 70,
		SWITCH_Height = 30,

		CONNECTION_Width = 50,
		CONNECTION_Height = 50,

		EXIT_Width = 70,
		EXIT_Height = 30,

		SAVE_Width = 70,
		SAVE_Height = 30,

		DELET_Width = 70,
		DELET_Height = 30,

		MOVE_Width = 70,
		MOVE_Height = 30,

		UNDO_Width = 70,
		UNDO_Height = 30,

		REDO_Width = 70,
		REDO_Height = 30,

		LOAD_Width = 70,
		LOAD_Height = 30,

		SELECT_Width = 70,
		SELECT_Height = 30,

		SIMU_Width = 70,
		SIMU_Height = 30;




}UI;	//create a single global object UI

struct Point
{
	int x, y;
	Point(int a = 0, int b = 0)	//constructor
	{
		x = a;	y = b;
	}
};


#endif

//#ifndef UI_INFO_H
//#define UI_INFO_H
//
//#include "..\CMUgraphicsLib\CMUgraphics.h"
//#include "..\Defs.h"
//
////User Interface information file.
////This file contains info that is needed by Input and Output classes to
////handle the user interface
//
//__declspec(selectany) //This line to prevent "redefinition error"
//
//struct UI_Info	//User Interface Info.
//{
//	MODE AppMode;		//Application Mode (design or simulation)
//	
//	static const int	width = 1000, height = 750,	//Window width and height
//						wx = 15 , wy = 15,			//Window starting coordinates
//						StatusBarHeight = 50,	//Status Bar Height
//						ToolBarHeight = 80,		//Tool Bar Height (distance from top of window to bottom line of toolbar)
//						ToolItemWidth = 80;		//Width of each item in toolbar menu
//
//	color DrawColor;		//Drawing color
//	color SelectColor;		//Highlighting color
//	color ConnColor;		//Connector color
//	color MsgColor;			//Messages color
//	color BkGrndColor;		//Back ground color
//
//
//	//This should be calculated accurately because it will be used later to create connections between gates
//	//For now, we will assume that rect width = 50 and height = 50
//	static const int	AND2_Width = 50,		//AND2 Gate Image default width
//						AND2_Height = 50;		//AND2 Gate Image default height
//	
//}UI;	//create a single global object UI
//
//#endif