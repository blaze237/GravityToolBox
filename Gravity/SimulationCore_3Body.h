#pragma once
#include "FixedMass.h"
class SimulationCore_3Body
{
public:
	SimulationCore_3Body(double timeStep);
	~SimulationCore_3Body();

	//The main simulation loop
	void mainLoop(const Vector2<double> &pmStartPos, const Vector2<double> &pmStart);

	void pausePlay();
	void stopSimulation();


private:
	//Calculate the current energy of the point particle. This is used to check for violations in energy conservation, thus indicating a collision has occured.
	double calcEnergy(const FixedMass &FM1, const FixedMass &FM2, const Vector2<double> &position, const Vector2<double> &velocity);

	//Calculate current position of the point particle, based on its previous position , acceleration and velocity.
	Vector2<double> calcPosition(const Vector2<double> &posPrev, const Vector2<double> &velocity, const Vector2<double> &acceleration);

	//Calculate the current acceleration of the point particle at its newly determined position
	Vector2<double> calcAcceleration(const FixedMass &FM1, const FixedMass &FM2, const Vector2<double> &position);

	//Calculate the new velocity of the point particle at its newly determined position
	Vector2<double> calcVelocity(const FixedMass &FM1, const FixedMass &FM2, const Vector2<double> &accelerationPrev, const Vector2<double> &accelerationNew, const Vector2<double> &velocityPrev);


	


private:
	double timeStep = 0;
	bool running = true;
	bool stop = false;

	//Position cur and prior

	//accek cur and prior

	//velocity x and y

	
};

