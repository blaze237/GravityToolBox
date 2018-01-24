#pragma once
#include "FixedMass.h"
#include "PointParticle.h"
class SimulationCore_3Body
{
public:
	SimulationCore_3Body(double timeStep);
	~SimulationCore_3Body();

	//The main simulation loop
	void mainLoop(const Vector2<double> &pmStartPos, const Vector2<double> &pmStartVelocity);

	void pausePlay();
	void stopSimulation();


private:
	//Calculate the current energy of the system. This is used to check for violations in energy conservation, thus indicating a collision has occured.
	double calcEnergy(const FixedMass &FM1, const FixedMass &FM2, const PointParticle &particle);

	//Calculate current position of the point particle, based on its previous position , acceleration and velocity.
	Vector2<double> calcNewPosition(const PointParticle &particle);

	//Calculate the current acceleration of the point particle at its newly determined position
	Vector2<double> calcNewAcceleration(const FixedMass &FM1, const FixedMass &FM2, const Vector2<double> &position);

	//Calculate the new velocity of the point particle at its newly determined position
	Vector2<double> calcNewVelocity(const FixedMass &FM1, const FixedMass &FM2, const PointParticle &particle, const Vector2<double> &accelerationNew);


	


private:
	double timeStep = 0;
	bool running = true;
	bool stop = false;

	//Position cur and prior

	//accek cur and prior

	//velocity x and y

	
};

