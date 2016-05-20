#ifndef CONNECTOR_H
#define CONNECTOR_H

#include "GUI\UI_Info.h"
#include "GUI\Output.h"
#include "Components\Component.h"
class Component;

class Connector	//a connector that connects two statements (Source & Destination)
{
private:
	Component *source;	//The source statement of the connector
	Component *dest;	//The destination statement of the connector
	Point Start;	//Start point of the connector
	Point End;		//End point of the connector
	int Branch;
public:
	Connector(Component* Src, Component* Dst);

	void		setSrcStat(Component *Src);
	Component*	getSrcStat();

	void		setDstStat(Component *Dst);
	Component*	getDstStat();

	void setStartPoint(Point P);
	Point getStartPoint();

	void setEndPoint(Point P);
	Point getEndPoint();

	void	setBranch(int s);
	int		getBranch();
	void Set();
	void Draw(Output* pOut) const;
	void Save(ofstream &out);



};
#endif
