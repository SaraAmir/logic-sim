#include "Output.h"

Output::Output()
{
	//Initialize user interface parameters

	UI.AppMode = DESIGN;	//Design Mode is the startup mode

							//Initilaize interface colors
	UI.DrawColor = BLACK;
	UI.SelectColor = YELLOW;
	UI.ConnColor = RED;
	UI.MsgColor = VIOLET;
	UI.BkGrndColor = SKYBLUE;

	//Create the drawing window
	pWind = CreateWind(UI.width, UI.height, UI.wx, UI.wy);
	ChangeTitle("Logic Gates Project");

	CreateDesignToolBar();	//Create the desgin toolbar
	CreateStatusBar();		//Create Status bar

}

Input* Output::CreateInput() const
{
	//Create an Input Object & assign it to the Same Window
	Input* pIn = new Input(pWind);
	return pIn;
}


//======================================================================================//
//								Interface Functions										//
//======================================================================================//

window* Output::CreateWind(int wd, int h, int x, int y) const
{
	return new window(wd, h, x, y);
}
//////////////////////////////////////////////////////////////////////////////////
void Output::ChangeTitle(string Title) const
{
	pWind->ChangeTitle(Title);
}
//////////////////////////////////////////////////////////////////////////////////
void Output::CreateStatusBar() const
{
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.height - UI.StatusBarHeight, UI.width, UI.height - UI.StatusBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////
void Output::PrintMsg(string msg) const
{
	ClearStatusBar();	//Clear Status bar to print message on it
						// Set the Message offset from the Status Bar
	int MsgX = 25;
	int MsgY = UI.StatusBarHeight - 10;

	// Print the Message
	pWind->SetFont(20, BOLD | ITALICIZED, BY_NAME, "Arial");
	pWind->SetPen(UI.MsgColor);
	pWind->DrawString(MsgX, UI.height - MsgY, msg);
}
//////////////////////////////////////////////////////////////////////////////////
void Output::ClearStatusBar()const
{
	// Set the Message offset from the Status Bar
	int MsgX = 25;
	int MsgY = UI.StatusBarHeight - 10;

	//Overwrite using bachground color to erase the message
	pWind->SetPen(UI.BkGrndColor);
	pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(MsgX, UI.height - MsgY, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
//Clears the drawing (degin) area
void Output::ClearDrawingArea() const
{
	pWind->SetPen(RED, 1);
	pWind->SetBrush(WHITE);
	pWind->DrawRectangle(0, UI.ToolBarHeight, UI.width, UI.height - UI.StatusBarHeight);

}
//////////////////////////////////////////////////////////////////////////////////////////
//Draws the menu (toolbar) in the Design mode
void Output::CreateDesignToolBar() const
{
	UI.AppMode = DESIGN;	//Design Mode

							//You can draw the tool bar icons in any way you want.

							//First prepare List of images for each menu item
	string MenuItemImages[ITM_DSN_CNT];
	MenuItemImages[ITM_AND_2] = "images\\Menu\\AND_GATE.jpg";
	MenuItemImages[ITM_AND_3] = "images\\Menu\\AND_GATE3.jpg";
	MenuItemImages[ITM_OR_2] = "images\\Menu\\OR_GATE.jpg";
	MenuItemImages[ITM_INV_2] = "images\\Menu\\NOT_GATE.jpg";
	MenuItemImages[ITM_BUFF] = "images\\Menu\\BUFFER.jpg";/////me7taga tetzabat
	MenuItemImages[ITM_NOR_2] = "images\\Menu\\NOR_GATE.jpg";
	MenuItemImages[ITM_NOR_3] = "images\\Menu\\NOR_GATE3.jpg";
	MenuItemImages[ITM_XOR_2] = "images\\Menu\\XOR_GATE.jpg";
	MenuItemImages[ITM_XOR_3] = "images\\Menu\\XOR_GATE3.jpg";
	MenuItemImages[ITM_NAND_2] = "images\\Menu\\NAND_GATE.jpg";

	MenuItemImages[ITM_LED] = "images\\Menu\\LED.jpg";
	MenuItemImages[ITM_SWITCH] = "images\\Menu\\SWITCH.jpg";
	MenuItemImages[ITM_CONNECTION] = "images\\Menu\\CONNECTION.jpg";

	MenuItemImages[ITM_SAVE] = "images\\Menu\\SAVE.jpg";
	MenuItemImages[ITM_DELET] = "images\\Menu\\DELETE.jpg";
	MenuItemImages[ITM_REDO] = "images\\Menu\\REDO.jpg";
	MenuItemImages[ITM_UNDO] = "images\\Menu\\UNDO.jpg";
	MenuItemImages[ITM_SAVE] = "images\\Menu\\SAVE.jpg";

	MenuItemImages[ITM_SELECT] = "images\\Menu\\SELECT.jpg";
	MenuItemImages[ITM_MOVE] = "images\\Menu\\MOVE.jpg";
	MenuItemImages[ITM_LOAD] = "images\\Menu\\LOAD.jpg";
	MenuItemImages[ITM_SIMU] = "images\\Menu\\SIMULATION.jpg";

	MenuItemImages[ITM_EXIT] = "images\\Menu\\Menu_Exit.jpg";

	//TODO: Prepare image for each menu item and add it to the list

	//Draw menu item one image at a time
	for (int i = 0; i < ITM_DSN_CNT; i++)
		pWind->DrawImage(MenuItemImages[i], i*UI.ToolItemWidth, 0, UI.ToolItemWidth, UI.ToolBarHeight);


	//Draw a line under the toolbar
	pWind->SetPen(BLACK, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);
	//pWind->DrawLine(0, UI.ToolBarHeight+60, UI.width, UI.ToolBarHeight+60);
}
//////////////////////////////////////////////////////////////////////////////////////////
//Draws the menu (toolbar) in the simulation mode
void Output::CreateSimulationToolBar() const
{
	UI.AppMode = SIMULATION;	//Simulation Mode
	pWind->SetPen(RED, 1);
	pWind->SetBrush(WHITE);
	pWind->DrawRectangle(0, 0, UI.width, UI.ToolItemWidth);
	string MenuItemImages[ITM_SIM_CNT];

	MenuItemImages[ITM_SAVE2] = "images\\Menu\\SAVE.jpg";
	MenuItemImages[ITM_LOAD2] = "images\\Menu\\LOAD.jpg";
	MenuItemImages[ITM_VALIDATE] = "images\\Menu\\valid.jpg";
	MenuItemImages[ITM_RUN] = "images\\Menu\\RUN.jpg";
	MenuItemImages[ITM_TRUTH] = "images\\Menu\\TRUTH_TABLE.jpg";
	MenuItemImages[ITM_DESIGN] = "images\\Menu\\design.jpg";
	MenuItemImages[ITM_EXIT2] = "images\\Menu\\Menu_Exit.jpg";

	//TODO: Prepare image for each menu item and add it to the list

	//Draw menu item one image at a time
	for (int i = 0; i < ITM_SIM_CNT; i++)
		pWind->DrawImage(MenuItemImages[i], i*UI.ToolItemWidth, 0, UI.ToolItemWidth, UI.ToolBarHeight);


	//Draw a line under the toolbar
	pWind->SetPen(BLACK, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);
	pWind->DrawLine(0, UI.ToolBarHeight + 60, UI.width, UI.ToolBarHeight + 60);


}

//======================================================================================//
//								Components Drawing Functions							//
//======================================================================================//


//Draw AND2 Gate at Gfx_Info (1st corner)
//Set the Image Width & Height by AND2 Image Parameter in UI_Info
void Output::DrawAND2(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\AND_GATE_HI.jpg";
	else
		GateImage = "Images\\Gates\\AND_GATE.jpg";


	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}

void Output::DrawNAND2(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\NAND_GATE_HI.jpg";
	else
		GateImage = "Images\\Gates\\NAND_GATE.jpg";


	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.NAND2_Width, UI.NAND2_Height);
}

void Output::DrawAND3(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\AND_GATE3.jpg";
	else
		GateImage = "Images\\Gates\\AND_GATE3.jpg";


	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND3_Width, UI.AND3_Height);
}
//void Output:: DrawOR(GraphicsInfo r_GfxInfo, bool selected = false) const
//{
//	string GateImage;
//	if (selected)	//use image in the highlighted case
//		GateImage = "Images\\Gates\\OR_GATE_HI.jpg";
//	else
//		GateImage = "Images\\Gates\\OR_GATE.jpg";
//
//	
//	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.OR2_Width, UI.OR2_Height);
//}

//TODO: Add similar functions to draw all components

void Output::DrawOR2(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\OR_GATE_HI.jpg";
	else
		GateImage = "Images\\Gates\\OR_GATE.jpg";

	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.OR2_Width, UI.OR2_Height);
}

void Output::DrawNOR2(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\NOR_GATE_HI.jpg";
	else
		GateImage = "Images\\Gates\\NOR_GATE.jpg";

	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.NOR2_Width, UI.NOR2_Height);
}

void Output::DrawNOR3(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\NOR_GATE3_HI.jpg";
	else
		GateImage = "Images\\Gates\\NOR_GATE3.jpg";

	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.NOR3_Width, UI.NOR3_Height);
}

void Output::DrawXOR2(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\XOR_GATE_HI.jpg";
	else
		GateImage = "Images\\Gates\\XOR_GATE.jpg";

	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.XOR2_Width, UI.XOR2_Height);
}

void Output::DrawXOR3(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\XOR_GATE3_HI.jpg";
	else
		GateImage = "Images\\Gates\\XOR_GATE3.jpg";

	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.XOR3_Width, UI.XOR3_Height);
}
void Output::DrawXNOR2(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\XNOR_GATE_HI.jpg";
	else
		GateImage = "Images\\Gates\\XNOR_GATE.jpg";

	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.XOR2_Width, UI.XOR2_Height);
}

void Output::DrawINV(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\NOT_GATE_HI.jpg";
	else
		GateImage = "Images\\Gates\\NOT_GATE.jpg";

	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.INV2_Width, UI.INV2_Height);
}

void Output::DrawBUFF(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\BUFFER_HI.jpg";
	else
		GateImage = "Images\\Gates\\BUFFER.jpg";

	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.BUFF_Width, UI.BUFF_Height);
}

void Output::DrawLED_ON(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\LED_ON_HI.jpg";
	else
		GateImage = "Images\\Gates\\LED_ON.jpg";

	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.LED_Width, UI.LED_Height);
}

void Output::DrawLED_OFF(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\LED_OFF_HI.jpg";
	else
		GateImage = "Images\\Gates\\LED_OFF.jpg";

	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.LED_Width, UI.LED_Height);
}

void Output::DrawSWITCH_ON(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\SWITCH_ON_HI.jpg";   //highlighted
	else
		GateImage = "Images\\Gates\\SWITCH_ON.jpg";

	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.SWITCH_Width, UI.SWITCH_Height);
}

void Output::DrawSWITCH_OFF(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\SWITCH_OFF_HI.jpg";
	else
		GateImage = "Images\\Gates\\SWITCH_OFF.jpg";

	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.SWITCH_Width, UI.SWITCH_Height);
}






void Output::DrawConnection(GraphicsInfo r_GfxInfo, bool Selected) const
{
	if (Selected)	//if stat is selected, it should be highlighted
		pWind->SetPen(UI.SelectColor, 3);	//use highlighting color
	else
		pWind->SetPen(UI.DrawColor, 3);	//use normal color

										//Draw the statement block rectangle    /////////////////////////////////////?????????????????????????????
	if ((r_GfxInfo.x1 == r_GfxInfo.x2))
	{
		pWind->DrawLine(r_GfxInfo.x1, r_GfxInfo.y1, r_GfxInfo.x2, r_GfxInfo.y2);

	}

	if ((r_GfxInfo.y1 == r_GfxInfo.y2))
	{
		pWind->DrawLine(r_GfxInfo.x1, r_GfxInfo.y1, r_GfxInfo.x2, r_GfxInfo.y2);


	}
	else
	{
		pWind->DrawLine(r_GfxInfo.x1, r_GfxInfo.y1, r_GfxInfo.x2, r_GfxInfo.y1);
		pWind->DrawLine(r_GfxInfo.x2, r_GfxInfo.y1, r_GfxInfo.x2, r_GfxInfo.y2);

	}


}


Output::~Output()
{
	delete pWind;
}




//#include "Output.h"
//
//Output::Output()
//{
//	//Initialize user interface parameters
//
//	UI.AppMode = DESIGN;	//Design Mode is the startup mode
//
//	//Initilaize interface colors
//	UI.DrawColor = BLACK;
//	UI.SelectColor = BLUE;
//	UI.ConnColor = RED;
//	UI.MsgColor = BLUE;
//	UI.BkGrndColor = WHITE;
//	
//	//Create the drawing window
//	pWind = CreateWind(UI.width, UI.height, UI.wx, UI.wy);	
//	ChangeTitle("Programming Techniques Project");
//
//	CreateDesignToolBar();	//Create the desgin toolbar
//	CreateStatusBar();		//Create Status bar
//
//}
//
//Input* Output::CreateInput() const
//{
//	//Create an Input Object & assign it to the Same Window
//	Input* pIn = new Input(pWind);
//	return pIn;
//}
//
//
////======================================================================================//
////								Interface Functions										//
////======================================================================================//
//
//window* Output::CreateWind(int wd, int h, int x, int y) const
//{
//	return new window(wd, h, x, y);
//}
////////////////////////////////////////////////////////////////////////////////////
//void Output::ChangeTitle(string Title) const
//{
//	pWind->ChangeTitle(Title);
//}
////////////////////////////////////////////////////////////////////////////////////
//void Output::CreateStatusBar() const
//{
//	pWind->SetPen(RED,3);
//	pWind->DrawLine(0, UI.height-UI.StatusBarHeight, UI.width, UI.height-UI.StatusBarHeight);
//}
////////////////////////////////////////////////////////////////////////////////////
//void Output::PrintMsg(string msg) const
//{
//	ClearStatusBar();	//Clear Status bar to print message on it
//	// Set the Message offset from the Status Bar
//	int MsgX = 25;
//	int MsgY = UI.StatusBarHeight - 10;
//
//	// Print the Message
//    pWind->SetFont(20, BOLD | ITALICIZED, BY_NAME, "Arial"); 
//	pWind->SetPen(UI.MsgColor); 
//	pWind->DrawString(MsgX, UI.height - MsgY, msg);
//}
////////////////////////////////////////////////////////////////////////////////////
//void Output::ClearStatusBar()const
//{
//	// Set the Message offset from the Status Bar
//	int MsgX = 25;
//	int MsgY = UI.StatusBarHeight - 10;
//
//	//Overwrite using bachground color to erase the message
//	pWind->SetPen(UI.BkGrndColor);
//	pWind->SetBrush(UI.BkGrndColor);
//	pWind->DrawRectangle(MsgX, UI.height - MsgY, UI.width, UI.height);
//}
////////////////////////////////////////////////////////////////////////////////////////////
////Clears the drawing (degin) area
//void Output::ClearDrawingArea() const
//{
//	pWind->SetPen(RED, 1);
//	pWind->SetBrush(WHITE);
//	pWind->DrawRectangle(0, UI.ToolBarHeight, UI.width, UI.height - UI.StatusBarHeight);
//	
//}
////////////////////////////////////////////////////////////////////////////////////////////
////Draws the menu (toolbar) in the Design mode
//void Output::CreateDesignToolBar() const
//{
//	UI.AppMode = DESIGN;	//Design Mode
//
//	//You can draw the tool bar icons in any way you want.
//
//	//First prepare List of images for each menu item
//	string MenuItemImages[ITM_DSN_CNT];
//	MenuItemImages[ITM_AND2] = "images\\Menu\\Menu_AND2.jpg";
//	MenuItemImages[ITM_OR2]  = "images\\Menu\\Menu_OR2.jpg";
//	MenuItemImages[ITM_EXIT] = "images\\Menu\\Menu_Exit.jpg";
//
//	//TODO: Prepare image for each menu item and add it to the list
//
//	//Draw menu item one image at a time
//	for(int i=0; i<ITM_DSN_CNT; i++)
//		pWind->DrawImage(MenuItemImages[i],i*UI.ToolItemWidth,0,UI.ToolItemWidth, UI.ToolBarHeight);
//
//
//	//Draw a line under the toolbar
//	pWind->SetPen(RED,3);
//	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);	
//
//}
////////////////////////////////////////////////////////////////////////////////////////////
////Draws the menu (toolbar) in the simulation mode
//void Output::CreateSimulationToolBar() const
//{
//	UI.AppMode = SIMULATION;	//Simulation Mode
//
//	//TODO: Write code to draw the simualtion toolbar (similar to that of design toolbar drawing)
//
//
//}
//
////======================================================================================//
////								Components Drawing Functions							//
////======================================================================================//
//
//void Output::DrawAND2(GraphicsInfo r_GfxInfo, bool selected) const
//{
//	string GateImage;
//	if(selected)	//use image in the highlighted case
//		GateImage="Images\\Gates\\Gate_AND2_Hi.jpg";
//	else  
//		GateImage = "Images\\Gates\\Gate_AND2.jpg";
//
//	//Draw AND2 Gate at Gfx_Info (1st corner)
//	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
//	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
//}
//
////TODO: Add similar functions to draw all components
//
//
//void Output::DrawConnection(GraphicsInfo r_GfxInfo, bool selected) const
//{
//	//TODO: Add code to draw connection
//}
//
//
//Output::~Output()
//{
//	delete pWind;
//}
