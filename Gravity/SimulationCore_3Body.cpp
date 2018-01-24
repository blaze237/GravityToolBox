#include "SimulationCore_3Body.h"
#include <cmath>
#include <cstdio>

const double COLLISION_TOLLERANCE = 0.5;
const double SIMULATION_TIME_LIMIT = 30;

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
	FixedMass FM1(Vector2<double>(-1,0), 10);
	FixedMass FM2(Vector2<double>(1, 0), 10);

	//Setup point particle
	PointParticle particle(pmStartPos, pmStartVelocity);
	particle.setAcceleration(calcNewAcceleration(FM1, FM2, particle.getPosition()));
	
	//Get the total energy of the system.
	double energyInit = calcEnergy(FM1, FM2, particle);
	
	//We temp store the newly calculated accleration of the particle at its new postion each update before actualy setting it, as the velocity verlet calculation utilises the current and previous accleration values
	Vector2<double> accelerationNew;

	//Simulation limmiters
	int i = 0;
	double time = 0;

	while (!stop && time < SIMULATION_TIME_LIMIT)
	{
		time = i*timeStep;
		i++;

		//If the energy changes from initial value, then energy conservation has been violated, thus indicating a collision has occured.
		if (abs(calcEnergy(FM1, FM2, particle) - energyInit) > COLLISION_TOLLERANCE)
		{
			printf("\n\ncollision at iteration %d\n\n", i);
			break;

		}
		
		//Get the position
		particle.setPosition(calcNewPosition(particle));

		//Get the acceleration
		accelerationNew = calcNewAcceleration(FM1, FM2, particle.getPosition());

		//Get the velocity
		particle.setVelocity(calcNewVelocity(FM1, FM2, particle, accelerationNew));

		//Update the accleration value now the prior one is no longer needed
		particle.setAcceleration(accelerationNew);

		printf("%f: (%f , %f)\n", time, particle.getPosition().getX(), particle.getPosition().getY());
	}
}

double SimulationCore_3Body::calcEnergy(const FixedMass &FM1, const FixedMass &FM2, const PointParticle &particle)
{
	//Get kinetic energy of the particle, 0.5V^2
	double energyKinetic = 0.5 * pow(particle.getVelocity().getMagnitude(), 2);

	//Get potential energy of the particle GMm/r. Taking G and m to be 1
	double distToM1 = particle.getPosition().distanceTo(FM1.getPosition());
	double distToM2 = particle.getPosition().distanceTo(FM2.getPosition());
	double energyPotential = -(FM1.getMass() / distToM1) - (FM2.getMass() / distToM2);

	return energyKinetic + energyPotential;
}

Vector2<double> SimulationCore_3Body::calcNewPosition(const PointParticle &particle)
{
	//Get new position via SUVAT
	double xNew = particle.getPosition().getX() + (particle.getVelocity().getX() * timeStep) + (0.5 * particle.getAcceleration().getX() * pow(timeStep, 2));
	double yNew = particle.getPosition().getY() + (particle.getVelocity().getY() * timeStep) + (0.5 * particle.getAcceleration().getY() * pow(timeStep, 2));

	return Vector2<double>(xNew, yNew);
}


Vector2<double> SimulationCore_3Body::calcNewAcceleration(const FixedMass &FM1, const FixedMass &FM2, const Vector2<double> &position)
{
	//Determine the different distance metrics between point particle's position and each fixed mass
	double distToM1 = position.distanceTo(FM1.getPosition());
	double distToM2 = position.distanceTo(FM2.getPosition());
	double xDistToM1 = position.getX() - FM1.getPosition().getX();
	double yDistToM1 = position.getY() - FM1.getPosition().getY();
	double xDistToM2 = position.getX() - FM2.getPosition().getX();
	double yDistToM2 = position.getY() - FM2.getPosition().getY();

	//Use equation of motion to determine new acceleration of the point particle.
	double xAccelNew = -(FM1.getMass() * xDistToM1 * pow(distToM1, -3) + (FM2.getMass() * xDistToM2) * pow(distToM2, -3));
	double yAccelNew = -(FM1.getMass() * yDistToM1 * pow(distToM1, -3) + (FM2.getMass() * yDistToM2) * pow(distToM2, -3));

	return Vector2<double>(xAccelNew, yAccelNew);
}


Vector2<double> SimulationCore_3Body::calcNewVelocity(const FixedMass &FM1, const FixedMass &FM2, const PointParticle &particle, const Vector2<double> &accelerationNew)
{
	double xVelNew = particle.getVelocity().getX() + (0.5 * timeStep * (particle.getAcceleration().getX() + accelerationNew.getX()));
	double yVelNew = particle.getVelocity().getY() + (0.5 * timeStep * (particle.getAcceleration().getY() + accelerationNew.getY()));

	return Vector2<double>(xVelNew, yVelNew);
}






