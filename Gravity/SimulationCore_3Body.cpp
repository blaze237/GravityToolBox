#include "SimulationCore_3Body.h"
#include <cmath>
#include <cstdio>

const double COLLISION_TOLLERANCE = 0.5;

SimulationCore_3Body::SimulationCore_3Body(double timeStep)
:timeStep(timeStep)
{
}


SimulationCore_3Body::~SimulationCore_3Body()
{
}

void SimulationCore_3Body::pausePlay()
{
	running = !running;
}

void SimulationCore_3Body::stopSimulation()
{
	stop = true;
}

void SimulationCore_3Body::mainLoop(const Vector2<double> &pmStartPos, const Vector2<double> &pmStartVelocity)
{
	//Set up the fixed masses
	FixedMass FM1(Vector2<double>(-1.0,0.0), 10);
	FixedMass FM2(Vector2<double>(1.0, 0.0), 10);

	//Initialise point particle properties
	Vector2<double> position = pmStartPos;
	Vector2<double> velocity = pmStartVelocity;
	Vector2<double> acceleration = calcAcceleration(FM1, FM2, position);
	//Get the total energy of the system.
	double energyInit = calcEnergy(FM1, FM2, position, velocity);

	Vector2<double> accelerationNew;
	int i = 0;

	while (!stop)
	{
		i++;
		//If the energy changes from initial value, then energy conservation has been violated, thus indicating a collision has occured.
		if (abs(calcEnergy(FM1, FM2, position, velocity) - energyInit) > COLLISION_TOLLERANCE)
		{
			printf("\n\ncollision at iteration %d\n\n", i);
			break;

		}
		
		//Get the position
		position = calcPosition(position, velocity, acceleration);

		//Get the acceleration
		accelerationNew = calcAcceleration(FM1, FM2, position);

		//Get the velocity
		velocity = calcVelocity(FM1, FM2, acceleration, accelerationNew, velocity);

		acceleration = accelerationNew;

		printf("Position: (%.2f , %.2f)\n", position.getX(), position.getY());
	}
}

double SimulationCore_3Body::calcEnergy(const FixedMass &FM1, const FixedMass &FM2, const Vector2<double> &position, const Vector2<double> &velocity)
{
	//Get kinetic energy of the particle, 0.5V^2
	double energyKinetic = 0.5 * pow(velocity.getLength(), 2);

	//Get potential energy of the particle GMm/r. Taking G and m to be 1
	double distToM1 = position.distanceTo(FM1.getPos());
	double distToM2 = position.distanceTo(FM2.getPos());
	double energyPotential = -(FM1.getMass() / distToM1) - (FM2.getMass() / distToM2);

	return energyKinetic + energyPotential;
}

Vector2<double> SimulationCore_3Body::calcPosition(const Vector2<double> &posPrev, const Vector2<double> &velocity, const Vector2<double> &acceleration)
{
	//Get new position via SUVAT
	double xNew = posPrev.getX() + (velocity.getX() * timeStep) + (0.5 * acceleration.getX() * pow(timeStep, 2));
	double yNew = posPrev.getY() + (velocity.getY() * timeStep) + (0.5 * acceleration.getY() * pow(timeStep, 2));

	return Vector2<double>(xNew, yNew);
}


Vector2<double> SimulationCore_3Body::calcAcceleration(const FixedMass &FM1, const FixedMass &FM2, const Vector2<double> &position)
{
	//Determine the different distance metrics between point particle's position and each fixed mass
	double distToM1 = position.distanceTo(FM1.getPos());
	double distToM2 = position.distanceTo(FM2.getPos());
	double xDistToM1 = position.getX() - FM1.getPos().getX();
	double yDistToM1 = position.getY() - FM1.getPos().getY();
	double xDistToM2 = position.getX() - FM1.getPos().getX();
	double yDistToM2 = position.getY() - FM1.getPos().getY();

	//Use equation of motion to determine new acceleration of the point particle.
	double xAccelNew = -((FM1.getMass() * xDistToM1) * pow(distToM1, -3) + (FM2.getMass() * xDistToM2) * pow(distToM2, -3));
	double yAccelNew = -((FM1.getMass() * yDistToM1) * pow(distToM1, -3) + (FM2.getMass() * yDistToM2) * pow(distToM2, -3));

	return Vector2<double>(xAccelNew, yAccelNew);
}


Vector2<double> SimulationCore_3Body::calcVelocity(const FixedMass &FM1, const FixedMass &FM2, const Vector2<double> &accelerationPrev, const Vector2<double> &accelerationNew, const Vector2<double> &velocityPrev)
{
	double xVelNew = velocityPrev.getX() + (0.5 * timeStep * (accelerationPrev.getX() + accelerationNew.getX()));
	double yVelNew = velocityPrev.getY() + (0.5 * timeStep * (accelerationPrev.getY() + accelerationNew.getY()));

	return Vector2<double>(xVelNew, yVelNew);
}






