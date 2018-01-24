#include "FixedMass.h"


FixedMass::FixedMass(Vector2<double> pos, double mass)
:position(pos), mass(mass)
{
}


FixedMass::~FixedMass()
{
}

Vector2<double> FixedMass::getPos() const
{
	return position;
}

double FixedMass::getMass() const
{
	return mass;
}

void FixedMass::setMass(double mass){
	this->mass = mass;
}

void FixedMass::setPos(Vector2<double> position){
	this->position = position;
}