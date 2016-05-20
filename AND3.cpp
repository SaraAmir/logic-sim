#include "AND3.h"

AND3::AND3(const GraphicsInfo &r_GfxInfo, int r_FanOut) :Gate(3, r_FanOut)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
}


//void AND3::Operate()
//{
//	//caclulate the output status as the ANDing of the two input pins
//
//	//Add you code here
//	int value = GetInputPinStatus(1) & GetInputPinStatus(2) & GetInputPinStatus(3);
//	//m_InputPins = new InputPin[2]; // creating a new array of input pins with max num of pins = 2
//
//	if (value == 1) //if the input is 1 , 1
//	{
//		setOutputPinStatus(HIGH); //then the output status is 1
//	}
//	else
//		setOutputPinStatus(LOW);
//
//}


// Function Draw
// Draws 2-input AND gate
void AND3::Draw(Output* pOut)
{
	//Call output class and pass gate drawing info to it.
	pOut->DrawAND3(m_GfxInfo);
}

//returns status of outputpin
int AND3::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}
//returns status of Inputpin #n
int AND3::GetInputPinStatus(int n)
{
	return m_InputPins[n - 1].getStatus();	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void AND3::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);
}

void AND3::setOutputPinStatus(STATUS s)
{
	m_OutputPin.setStatus(s);

}

//functions to save and load 

void AND3::Save(ofstream &OutFile)
{//lsa implementation
}

void AND3::Load(ifstream &Infile) {// lsa implementation
}