#pragma once
#include "FixedMass.h"
class SimulationCore_3Body
{
public:
	SimulationCore_3Body(double timeStep);
	~SimulationCore_3Body();

	//The main simulation loop
	void mainLoop(const Vector2<double> &pmStartPos, const Vector2<double> &pmStart);

	//Calculate the current energy of the point particle. This is used to check for violations in energy conservation, thus indicating a collision has occured.
	double calcEnergy(const FixedMass &FM1, const FixedMass &FM2, const Vector2<double> &posPrev, const Vector2<double> &velocity);

	//Calculate current position of the point particle, based on its previous position , acceleration and velocity.
	double calPosition(const FixedMass &FM1, const FixedMass &FM2, const Vector2<double> &posPrev, const Vector2<double> &velocity, const Vector2<double> &accelerationXPrev, const Vector2<double> &accelerationYPrev);

private:
	double timeStep = 0;

	//Position cur and prior

	//accek cur and prior

	//velocity x and y

	
};

