#include "FixedMass.h"


FixedMass::FixedMass(Point<double> pos, double mass)
:position(pos), mass(mass)
{
}


FixedMass::~FixedMass()
{
}

Point<double> FixedMass::getPos(){
	return position;
}

double FixedMass::getMass(){
	return mass;
}

void FixedMass::setMass(double mass){
	this->mass = mass;
}

void FixedMass::setPos(Point<double> position){
	this->position = position;
}