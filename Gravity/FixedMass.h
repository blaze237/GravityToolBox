#pragma once
#include "Point.h"
class FixedMass
{
public:
	FixedMass(Point<double> pos, double mass);
	~FixedMass();


	Point<double> getPos();
	double getMass();

	//These are really just here for fun.
	//As the class name suggests, fixed masses are just that, fixed
	//but changing them on the fly can have fun, if non realistic results.
	void setMass(double mass);
	void setPos(Point<double> position);


private:
	double mass;
	Point<double> position;
	
};

