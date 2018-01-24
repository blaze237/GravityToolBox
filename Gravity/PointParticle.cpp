#include "PointParticle.h"


PointParticle::PointParticle(Vector2<double> position, Vector2<double> velocity, Vector2<double> acceleration)
: position(position), velocity(velocity), acceleration(acceleration)
{
}

PointParticle::PointParticle(Vector2<double> position, Vector2<double> velocity)
: position(position), velocity(velocity), acceleration(0,0)
{
}

PointParticle::PointParticle(Vector2<double> position)
: position(position), velocity(0, 0), acceleration(0,0)
{
}

PointParticle::PointParticle()
: position(0, 0), velocity(0, 0), acceleration(0, 0)
{
}


Vector2<double> PointParticle::getPosition() const
{
	return position;
}

Vector2<double> PointParticle::getVelocity() const
{
	return velocity;
}

Vector2<double> PointParticle::getAcceleration() const
{
	return acceleration;
}

void PointParticle::setPosition(Vector2<double> posNew)
{
	position = posNew;
}

void PointParticle::setVelocity(Vector2<double> velNew)
{
	velocity = velNew;
}

void PointParticle::setAcceleration(Vector2<double> accelNew)
{
	acceleration = accelNew;
}
