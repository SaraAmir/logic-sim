#include "AND2.h"

AND2::AND2(const GraphicsInfo &r_GfxInfo, int r_FanOut):Gate(2, r_FanOut)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
}


//void AND2::Operate()
//{
//	//caclulate the output status as the ANDing of the two input pins
//
//	//Add you code here
//	int value = GetInputPinStatus(1) & GetInputPinStatus(2);
//	//m_InputPins = new InputPin[2]; // creating a new array of input pins with max num of pins = 2
//
//	if (value== 1) //if the input is 1 , 1
//	{
//		setOutputPinStatus(HIGH); //then the output status is 1
//	}
//	else
//		setOutputPinStatus(LOW);
//
//}


// Function Draw
// Draws 2-input AND gate
void AND2::Draw(Output* pOut)
{
	//Call output class and pass gate drawing info to it.
	pOut->DrawAND2(m_GfxInfo);
}

//returns status of outputpin
int AND2::GetOutPinStatus()	
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
int AND2::GetInputPinStatus(int n)	
{
	return m_InputPins[n-1].getStatus();	//n starts from 1 but array index starts from 0.
}

//Set status of an input  pin ot HIGH or LOW
void AND2::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n-1].setStatus(s);
}

//void AND2::setOutputPinStatus(STATUS s) 
//{
//	m_OutputPin.setStatus(s);
//
//}

//functions to save and load 

void AND2 :: Save(ofstream &OutFile)
{
//	//lsa implementation
//	OutFile << "SmplAssign     " << ID;
//
//
//	string x = "         ";
//	string y;
//	y = to_string(ID);
//	x.resize(x.size() - y.size());
//
//
//	OutFile << x;
//	OutFile << LeftCorner.x;
//
//
//	x = "      ";
//	y = to_string(LeftCorner.x);
//	x.resize(x.size() - y.size());
//
//
//	OutFile << x;
//	OutFile << LeftCorner.y;
//
//
//	x = "      ";
//	y = to_string(LeftCorner.y);
//	x.resize(x.size() - y.size());
//
//	OutFile << x;
//	OutFile << LHS;
//
//
//	x = "         ";
//	x.resize(x.size() - LHS.size());
//
//
//	OutFile << x;
//	OutFile << RHS;
//
//	
//	x = "               ";
//	y = to_string(RHS);
//	x.resize(x.size() - y.size());
//
//	OutFile << x;
//	OutFile << "“" << Comment << "”";
//	OutFile << "\n";
//
}

void AND2 ::Load(ifstream &Infile)
{
	// lsa implementation
}