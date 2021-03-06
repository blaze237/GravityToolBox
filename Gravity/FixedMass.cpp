#include "FixedMass.h"


FixedMass::FixedMass(Vector2<double> pos, double mass)
:position(pos), mass(mass)
{
}


FixedMass::~FixedMass()
{
}

Vector2<double> FixedMass::getPosition() const
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

void FixedMass::setPosition(Vector2<double> position){
	this->position = position;
}