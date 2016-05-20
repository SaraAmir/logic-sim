#include "GUI\Input.h"
#include "GUI\Output.h"
#include <iostream>
//
////This is a test code to test the Input and Output classes
//
//////PHASEONE TESTCODE
//int main()
//{
//	int x, y;      ///define a point on screen
//	
//			
//	
//	   //Create Input and Output objects to test
//	Output *pOut = new Output();
//	Input *pIn = pOut->CreateInput();
//	//Starting the test
//	pOut->PrintMsg("This demo is to test input and output classes, Click anywhere to start the test");
//	pIn->GetPointClicked(x, y);	//Wait for any click
//	
//
//								///////////////////////////////////////////////////////////////////////////////////
//								// TEST 1:	Create The FULL Tool bar, the drawing area and the status bar	
//								//			This has already been done through the constrcutor of class Output
//								///////////////////////////////////////////////////////////////////////////////////
//
//	pOut->PrintMsg("TEST1: Tool bar CHECK and Status bar CHECK , Click anywhere to continue");
//	pIn->GetPointClicked(x, y);	//Wait for any click
//
//
//								///////////////////////////////////////////////////////////////////////////////////
//								// TEST 2:	Drawing all the Components with all possible states: Normal, highlighted
//								//			
//								///////////////////////////////////////////////////////////////////////////////////
//
//	pOut->PrintMsg("TEST2: Now we will show that Output class can draw any Component in any state, Click anywhere to continue");
//	pIn->GetPointClicked(x, y);	//Wait for any click
//
//	GraphicsInfo GfxInfo;  //to be used with draw function of the class Ouput
//
//						   /// 2.1- AND2 Gate test
//	pOut->PrintMsg("Drawing 2-input AND gate, Normal and Highlighted,  Click to continue");
//
//	//Drawing Normal AND2 gate
//	GfxInfo.x1 = 100;	GfxInfo.y1 = 100;
//	pOut->DrawAND2(GfxInfo);
//
//	//Drawing Highlighted AND2 gate
//	GfxInfo.x1 = 100;	GfxInfo.y1 = 200;
//	pOut->DrawAND2(GfxInfo, true);
//
//	pIn->GetPointClicked(x, y);	//Wait for any click
//	pOut->ClearDrawingArea();
//	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//	/// 2.2- NAND2 Gate test
//	pOut->PrintMsg("Drawing 2-input NAND gate, Normal and Highlighted,  Click to continue");
//
//	///TODO: Add code to draw 2-input NAND gate, Normal and Highlighted
//	GfxInfo.x1 = 100;	GfxInfo.y1 = 100;
//	pOut->DrawNAND2(GfxInfo);
//
//	//Drawing Highlighted AND2 gate
//	GfxInfo.x1 = 100;	GfxInfo.y1 = 200;
//	pOut->DrawNAND2(GfxInfo, true);
//
//	pIn->GetPointClicked(x, y);	//Wait for any click
//	pOut->ClearDrawingArea();
//	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//	/// 2.3- OR2 and NOR2 Gates test
//	pOut->PrintMsg("Drawing 2-input OR and NOR gates, Normal and Highlighted,  Click to continue");
//	//Drawing Normal OR gate
//	GfxInfo.x1 = 100;	GfxInfo.y1 = 100;
//	pOut->DrawOR2(GfxInfo);
//	//OR Gate HI
//	GfxInfo.x1 = 100;	GfxInfo.y1 = 200;
//	pOut->DrawOR2(GfxInfo, true);
//	/////////////
//
//	//Drawing Normal NOR2 gate
//	GfxInfo.x1 = 100;	GfxInfo.y1 = 300;
//	pOut->DrawNOR2(GfxInfo);
//
//	//NOR2 Gate HI
//	GfxInfo.x1 = 100;	GfxInfo.y1 = 400;
//	pOut->DrawNOR2(GfxInfo, true);
//	pIn->GetPointClicked(x, y);	//Wait for any click
//	pOut->ClearDrawingArea();
//
//	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//	///  XOR2 and XNOR2 Gates test
//	pOut->PrintMsg("Drawing 2-input XOR and XNOR gates, Normal and Highlighted,  Click to continue");
//
//	//Drawing Normal XOR2 gate
//	GfxInfo.x1 = 100;	GfxInfo.y1 = 100;
//	pOut->DrawXOR2(GfxInfo);
//
//	//XOR2 Gate HI
//	GfxInfo.x1 = 100;	GfxInfo.y1 = 200;
//	pOut->DrawXOR2(GfxInfo, true);
//	//Drawing Normal XOR2 gate
//	GfxInfo.x1 = 100;	GfxInfo.y1 = 300;
//	pOut->DrawXNOR2(GfxInfo);
//
//	//XOR2 Gate HI
//	GfxInfo.x1 = 100;	GfxInfo.y1 = 400;
//	pOut->DrawXNOR2(GfxInfo, true);
//	pIn->GetPointClicked(x, y);	//Wait for any click
//	pOut->ClearDrawingArea();
//	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//
//	/// Buffer and Inverter Gates test
//	pOut->PrintMsg("Drawing Buffer and Inverter Gates, Normal and Highlighted,  Click to continue");
//
//	//Drawing Normal BUFFER gate
//	GfxInfo.x1 = 100;	GfxInfo.y1 = 100;
//	pOut->DrawBUFF(GfxInfo);
//
//
//	//BUFFER Gate HI
//	GfxInfo.x1 = 100;	GfxInfo.y1 = 200;
//	pOut->DrawBUFF(GfxInfo, true);
//
//	//////////////
//	//Drawing Normal INVERTER gate
//	GfxInfo.x1 = 100;	GfxInfo.y1 = 300;
//	pOut->DrawINV(GfxInfo);
//
//
//	//NINVERTER Gate HI
//	GfxInfo.x1 = 100;	GfxInfo.y1 = 400;
//	pOut->DrawINV(GfxInfo, true);
//	pIn->GetPointClicked(x, y);	//Wait for any click
//	pOut->ClearDrawingArea();
//	/////////////////////////////////////////////////////////////////////
//	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//	/// AND3, NOR3, and XOR3 Gates test
//	pOut->PrintMsg("Drawing 3-input AND, NOR, XOR Gates, Normal and Highlighted,  Click to continue");
//
//	//Drawing Normal AND3 gate
//	GfxInfo.x1 = 100;	GfxInfo.y1 = 100;
//	pOut->DrawAND3(GfxInfo);
//
//	//AND3 Gate HI
//	GfxInfo.x1 = 100;	GfxInfo.y1 = 200;
//	pOut->DrawAND3(GfxInfo, true);
//
//	///////////////
//	//Drawing Normal NOR3 gate
//	GfxInfo.x1 = 200;	GfxInfo.y1 = 100;
//	pOut->DrawNOR3(GfxInfo);
//
//	//NOR3 Gate HI
//	GfxInfo.x1 = 200;	GfxInfo.y1 = 200;
//	pOut->DrawNOR3(GfxInfo, true);
//
//	///////////////
//	//Drawing Normal XOR3 gate
//	GfxInfo.x1 = 300;	GfxInfo.y1 = 100;
//	pOut->DrawXOR3(GfxInfo);
//
//	//XOR3 Gate HI
//	GfxInfo.x1 = 300;	GfxInfo.y1 = 200;
//	pOut->DrawXOR3(GfxInfo, true);
//	pIn->GetPointClicked(x, y);	//Wait for any click
//	pOut->ClearDrawingArea();
//	/////////////////////////////////////////////////////
//
//	/// Switch and LED test
//	pOut->PrintMsg("Drawing Switch and LED, Normal and Highlighted,  Click to continue");
//
//	//Drawing LED_ON
//	GfxInfo.x1 = 100;	GfxInfo.y1 = 100;
//	pOut->DrawLED_ON(GfxInfo);
//
//
//	//LED_ON HI
//	GfxInfo.x1 = 100;	GfxInfo.y1 = 200;
//	pOut->DrawLED_ON(GfxInfo, true);
//
//	/////////////
//	//Drawing LED_OFF
//	GfxInfo.x1 = 100;	GfxInfo.y1 = 300;
//	pOut->DrawLED_OFF(GfxInfo);
//
//
//	//LED_OFF HI
//	GfxInfo.x1 = 100;	GfxInfo.y1 = 400;
//	pOut->DrawLED_OFF(GfxInfo, true);
//
//	/////////////
//	//Drawing SWITCH_ON
//	GfxInfo.x1 = 200;	GfxInfo.y1 = 100;
//	pOut->DrawSWITCH_ON(GfxInfo);
//
//
//	//SWITCH_ON HI
//	GfxInfo.x1 = 200;	GfxInfo.y1 = 200;
//	pOut->DrawSWITCH_ON(GfxInfo, true);
//
//	//////////
//	//Drawing SWITCH_OFF
//	GfxInfo.x1 = 200;	GfxInfo.y1 = 300;
//	pOut->DrawSWITCH_OFF(GfxInfo);
//
//
//	//SWITCH_OFF HI
//	GfxInfo.x1 = 200;	GfxInfo.y1 = 400;
//	pOut->DrawSWITCH_OFF(GfxInfo, true);
//	pIn->GetPointClicked(x, y);	//Wait for any click
//	pOut->ClearDrawingArea();
//
//	///////////////////////////////////////////////////////////////////////////////////////////
//	/// 2.8- Connections
//	pOut->PrintMsg("Drawing connections, Normal, Highlighted, straight, and broken,  Click to continue");
//
//
//	GfxInfo.x1 = 100;	GfxInfo.y1 = 100;
//	GfxInfo.x2 = 200;	GfxInfo.y2 = 100;
//	pOut->DrawConnection(GfxInfo, true);
//	GfxInfo.x1 = 250;	GfxInfo.y1 = 300;
//	GfxInfo.x2 = 250;	GfxInfo.y2 = 100;
//	pOut->DrawConnection(GfxInfo);
//
//	GfxInfo.x1 = 300;	GfxInfo.y1 = 400;
//	GfxInfo.x2 = 500;	GfxInfo.y2 = 550;
//	pOut->DrawConnection(GfxInfo);
//
//	GfxInfo.x1 = 780;	GfxInfo.y1 = 500;
//	GfxInfo.x2 = 670;	GfxInfo.y2 = 300;
//	pOut->DrawConnection(GfxInfo, true);
//	///TODO: Add code to draw connections, Normal, Highlighted, straight, and broken (all combinations) 
//
//	pIn->GetPointClicked(x, y);	//Wait for any click
//	pOut->ClearDrawingArea();
//
//
//
//
//
//
//	///////////////////////////////////////////////////////////////////////////////////
//	// TEST 3: Read strings from the user
//	///////////////////////////////////////////////////////////////////////////////////
//	pOut->PrintMsg("TEST3: Now Time to test class Input, Click anywhere to continue");
//	pIn->GetPointClicked(x, y);	//Wait for any click
//
//	pOut->PrintMsg("Testing Input ability to read strings Write any TEXT");
//	pOut->PrintMsg("text YOU WROTE IS { " + pIn->GetSrting(pOut) + "}");
//	///TODO: Add code here to 
//	// 1- Read a string from the user on the status bar and print it inside the drawing area
//
//
//	pIn->GetPointClicked(x, y);	//Wait for any click
//	pOut->ClearDrawingArea();
//
//
//	////////////////////////////////////////////////////////////////////////////////////////////////
//
//
//
//	///////////////////////////////////////////////////////////////////////////////////
//	// TEST 4: Check for the user action
//	///////////////////////////////////////////////////////////////////////////////////
//	pOut->PrintMsg("TEST4: Testing Input ability to detect User Action, click anywhere");
//
//	ActionType ActType;
//	ActionType ActType2 = DSN_TOOL;
//
//	///TODO:  You must add a case for each action
//	//Add cases for the missing actions below
//	do
//	{
//		ActType = pIn->GetUserAction();
//
//		switch (ActType)
//		{
//		case ADD_AND_GATE_2:
//			pOut->PrintMsg("Action: add 2-input AND gate , Click anywhere");
//			ActType2 = ADD_AND_GATE_2;
//
//			break;
//		case ADD_AND_GATE_3:
//			pOut->PrintMsg("Action: add 3-input AND gate , Click anywhere");
//			ActType2 = ADD_AND_GATE_3;
//
//
//			break;
//		case ADD_OR_GATE_2:
//			pOut->PrintMsg("Action: add 2-input OR gate , Click anywhere");
//			ActType2 = ADD_OR_GATE_2;
//
//
//			break;
//		case ADD_INV:
//			pOut->PrintMsg("Action: add an inverter gate , Click anywhere");
//			ActType2 = ADD_INV;
//
//			break;
//		case ADD_BUFF:
//			pOut->PrintMsg("Action: add a buffer gate , Click anywhere");
//			ActType2 = ADD_BUFF;
//
//			break;
//
//		case ADD_NOR_GATE_2:
//			pOut->PrintMsg("Action: add 2-input NOR gate , Click anywhere");
//			ActType2 = ADD_NOR_GATE_2;
//
//
//			break;
//		case ADD_NOR_GATE_3:
//			pOut->PrintMsg("Action: add 3-input NOR gate , Click anywhere");
//			ActType2 = ADD_NOR_GATE_3;
//
//
//			break;
//
//
//		case ADD_NAND_GATE_2:
//			pOut->PrintMsg("Action: add 2-input NAND gate , Click anywhere");
//			ActType2 = ADD_NAND_GATE_2;
//
//			break;
//
//
//
//		case ADD_XOR_GATE_2:
//			pOut->PrintMsg("Action: add 2-input XOR gate , Click anywhere");
//			ActType2 = ADD_XOR_GATE_2;
//
//
//			break;
//		case ADD_XOR_GATE_3:
//			pOut->PrintMsg("Action: add 3-input XOR gate , Click anywhere");
//			ActType2 = ADD_XOR_GATE_3;
//
//			break;
//		case ADD_Switch:
//			pOut->PrintMsg("Action: add SWITH , Click anywhere");
//			ActType2 = ADD_Switch;
//
//			break;
//		case ADD_LED:
//			pOut->PrintMsg("Action: add LED , Click anywhere");
//			ActType2 = ADD_LED;
//
//			break;
//		case ADD_CONNECTION:
//			pOut->PrintMsg("Action: add Connection , Click anywhere (start Point )");
//			pIn->GetPointClicked(x, y);
//			GfxInfo.x1 = x;	GfxInfo.y1 = y;
//			pOut->PrintMsg("Action: add Connection , Click anywhere (End Point )");
//			pIn->GetPointClicked(x, y);
//			GfxInfo.x2 = x;	GfxInfo.y2 = y;
//			pOut->DrawConnection(GfxInfo);
//			break;
//		case SAVE:
//			pOut->PrintMsg("Action: SAVE , Click anywhere");
//			break;
//		case DEL:
//			pOut->PrintMsg("Action: DEL , Click anywhere");
//			pOut->ClearDrawingArea();
//			break;
//		case SELECT:
//			pOut->PrintMsg("Action: a SELECT, Click anywhere");
//			break;
//		case MOVE:
//			pOut->PrintMsg("Action: a MOVE, Click anywhere");
//			break;
//		case LOAD:
//			pOut->PrintMsg("Action: a LOAD, Click anywhere");
//			break;
//		case UNDO:
//			pOut->PrintMsg("Action: a UNDO, Click anywhere");
//			break;
//		case REDO:
//			pOut->PrintMsg("Action: a REDO, Click anywhere");
//			break;
//		case STATUS_BAR:
//			pOut->PrintMsg("Action: a click on the Status Bar, Click anywhere");
//			break;
//		case DRAW:
//			pOut->PrintMsg("Action: a click on the drawing area, Click anywhere");
//			switch (ActType2)
//			{
//			case ADD_AND_GATE_2:
//				GfxInfo.x1 = x;	GfxInfo.y1 = y;
//				pOut->DrawAND2(GfxInfo);
//				pOut->PrintMsg("Done Click anywhere");
//				ActType2 = DRAW;
//				break;
//			case ADD_AND_GATE_3:
//				GfxInfo.x1 = x;	GfxInfo.y1 = y;
//				pOut->DrawAND3(GfxInfo);
//				pOut->PrintMsg("Done Click anywhere");
//				ActType2 = DRAW;
//				break;
//			case ADD_OR_GATE_2:
//				GfxInfo.x1 = x;	GfxInfo.y1 = y;
//				pOut->DrawOR2(GfxInfo);
//				pOut->PrintMsg("Done Click anywhere");
//				ActType2 = DRAW;
//				break;
//			case ADD_INV:
//				GfxInfo.x1 = x;	GfxInfo.y1 = y;
//				pOut->DrawINV(GfxInfo);
//				pOut->PrintMsg("Done Click anywhere");
//				ActType2 = DRAW;
//				break;
//			case ADD_BUFF:
//				GfxInfo.x1 = x;	GfxInfo.y1 = y;
//				pOut->DrawBUFF(GfxInfo);
//				pOut->PrintMsg("Done Click anywhere");
//				ActType2 = DRAW;
//				break;
//
//			case ADD_NOR_GATE_2:
//				GfxInfo.x1 = x;	GfxInfo.y1 = y;
//				pOut->DrawNOR2(GfxInfo);
//				pOut->PrintMsg("Done Click anywhere");
//				ActType2 = DRAW;
//				break;
//			case ADD_NOR_GATE_3:
//				GfxInfo.x1 = x;	GfxInfo.y1 = y;
//				pOut->DrawNOR3(GfxInfo);
//				pOut->PrintMsg("Done Click anywhere");
//				ActType2 = DRAW;
//				break;
//
//
//			case ADD_NAND_GATE_2:
//				GfxInfo.x1 = x;	GfxInfo.y1 = y;
//				pOut->DrawNAND2(GfxInfo);
//				pOut->PrintMsg("Done Click anywhere");
//				ActType2 = DRAW;
//				break;
//
//
//
//			case ADD_XOR_GATE_2:
//				GfxInfo.x1 = x;	GfxInfo.y1 = y;
//				pOut->DrawXOR2(GfxInfo);
//				pOut->PrintMsg("Done Click anywhere");
//				ActType2 = DRAW;
//				break;
//			case ADD_XOR_GATE_3:
//				GfxInfo.x1 = x;	GfxInfo.y1 = y;
//				pOut->DrawXOR3(GfxInfo);
//				pOut->PrintMsg("Done Click anywhere");
//				ActType2 = DRAW;
//				break;
//			case ADD_Switch:
//				GfxInfo.x1 = x;	GfxInfo.y1 = y;
//				pOut->DrawSWITCH_OFF(GfxInfo);
//				pOut->PrintMsg("Done Click anywhere");
//				ActType2 = DRAW;
//				break;
//			case ADD_LED:
//				GfxInfo.x1 = x;	GfxInfo.y1 = y;
//				pOut->DrawLED_OFF(GfxInfo);
//				pOut->PrintMsg("Done Click anywhere");
//				ActType2 = DRAW;
//				break;
//
//			default:
//				break;
//			}
//			break;
//		case DSN_TOOL:
//			pOut->PrintMsg("Action: a click on empty area in the Design Tool Bar, Click anywhere");
//			break;
//
//		case SIM_MODE:
//			pOut->PrintMsg("Action: Switch to Simulation Mode, creating simualtion tool bar");
//			pOut->CreateSimulationToolBar();
//			break;
//
//		case DSN_MODE:
//			pOut->PrintMsg("Action: Switch to Design Mode, creating Design tool bar");
//			pOut->CreateDesignToolBar();
//			break;
//		case VALIDATE:
//			pOut->PrintMsg("Action: Validate , Click anywhere ");
//			break;
//		case RUN:
//			pOut->PrintMsg("Action: RUN , Click anywhere ");
//			break;
//
//		case Create_TruthTable:
//			pOut->PrintMsg("Action: Create truth table , Click anywhere ");
//			break;
//		case EXIT:
//			break;
//		}
//	} while (ActType != EXIT);
//
//
//	/// Exiting
//	pOut->PrintMsg("Action: EXIT, test is finished, click anywhere to exit");
//	pIn->GetPointClicked(x, y);
//
//
//	delete pIn;
//	delete pOut;
//	return 0;
//}
//


#include <iostream>
#include <sstream>
#include <cmath>

#include "ApplicationManager.h"

int main()
{

	ActionType ActType;
	//Create an object of ApplicationManager
	ApplicationManager AppManager;

	do
	{		
		//Read user action
		ActType = AppManager.GetUserAction();
		
		//Exexute the action
		AppManager.ExecuteAction(ActType);

		//Update the drawing window
		AppManager.UpdateInterface();
	

	}while(ActType != EXIT);
		
	return 0;
}

