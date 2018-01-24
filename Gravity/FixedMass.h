#pragma once
#include "Vector2.h"

class FixedMass
{
public:
	FixedMass(Vector2<double> pos, double mass);
	~FixedMass();


	Vector2<double> getPosition() const;
	double getMass() const;

	//These are really just here for fun.
	//As the class name suggests, fixed masses are just that, fixed
	//but changing them on the fly can have fun, if non realistic results.
	void setMass(double mass);
	void setPosition(Vector2<double> position);


private:
	double mass;
	Vector2<double> position;
	
};

