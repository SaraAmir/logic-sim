#include "OR.h"

OR::OR(const GraphicsInfo &r_GfxInfo, int r_FanOut) :Gate(2, r_FanOut)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
}


//void OR::Operate()
//{
//	//caclulate the output status as the ANDing of the two input pins
//
//	//Add you code here
//
//	int value = GetInputPinStatus(1) | GetInputPinStatus(2);
//	//m_InputPins = new InputPin[2]; // creating a new array of input pins with max num of pins = 2
//
//	if (value == 1)
//	{
//		setOutputPinStatus(HIGH); //then the output status is 1
//	}
//	else
//		setOutputPinStatus(LOW);
//}


// Function Draw
// Draws 2-input AND gate
void OR::Draw(Output* pOut)
{
	//Call output class and pass gate drawing info to it.
	pOut->DrawOR2(m_GfxInfo);
}

//returns status of outputpin
int OR::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
int OR::GetInputPinStatus(int n)
{
	return m_InputPins[n - 1].getStatus();	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void OR::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);
}

void OR::setOutputPinStatus(STATUS s)
{
	m_OutputPin.setStatus(s);
}

//functions to save and load 

void OR::Save(ofstream &OutFile)
{//lsa implementation
}

void OR::Load(ifstream &Infile) {// lsa implementation
}