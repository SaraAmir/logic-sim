#include "NOR2.h"

NOR2::NOR2(const GraphicsInfo &r_GfxInfo, int r_FanOut) :Gate(3, r_FanOut)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
}


//void NOR2::Operate()
//{
//	//caclulate the output status as the ANDing of the two input pins
//
//	//Add you code here
//	int value = GetInputPinStatus(1) | GetInputPinStatus(2);
//	//m_InputPins = new InputPin[2]; // creating a new array of input pins with max num of pins = 2
//
//	if (value == 0)
//	{
//		setOutputPinStatus(HIGH); //then the output status is 1
//	}
//	else
//		setOutputPinStatus(LOW);
//}


// Function Draw
// Draws 2-input nor gate
void NOR2::Draw(Output* pOut)
{
	//Call output class and pass gate drawing info to it.
	pOut->DrawNOR2(m_GfxInfo);
}

//returns status of outputpin
int NOR2::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
int NOR2::GetInputPinStatus(int n)
{
	return m_InputPins[n - 1].getStatus();	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void NOR2::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);
}
void NOR2::setOutputPinStatus(STATUS s)
{
	m_OutputPin.setStatus(s);
}

//functions to save and load 

void NOR2::Save(ofstream &OutFile)
{//lsa implementation
}

void NOR2::Load(ifstream &Infile)
{// lsa implementation
}