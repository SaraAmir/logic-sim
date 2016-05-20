#include "INV.h"

INV::INV(const GraphicsInfo &r_GfxInfo, int r_FanOut) :Gate(1, r_FanOut)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
}


//void INV::Operate()
//{
//	//caclulate the output status as the ANDing of the two input pins
//
//	//Add you code here
//	int value = GetInputPinStatus(1);
//
//
//	if (value == 0) //if the input is 1 , 1
//	{
//		setOutputPinStatus(HIGH); //then the output status is 1
//	}
//	else
//		setOutputPinStatus(LOW);
//
//}


// Function Draw
// Draws BUFF gate
void INV::Draw(Output* pOut)
{
	//Call output class and pass gate drawing info to it.
	pOut->DrawBUFF(m_GfxInfo);
}

//returns status of outputpin
int INV::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
int INV::GetInputPinStatus(int n)
{
	return m_InputPins[n - 1].getStatus();	//n starts from 1 but array index starts from 0.
}
void INV::setOutputPinStatus(STATUS s)
{
	m_OutputPin.setStatus(s);
}

//Set status of an input pin ot HIGH or LOW
void INV::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);
}


//functions to save and load 

void INV::Save(ofstream &OutFile)
{//lsa implementation
}

void INV::Load(ifstream &Infile) {// lsa implementation
}