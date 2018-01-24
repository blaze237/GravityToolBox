#pragma once
#include "Vector2.h"
class PointParticle
{
public:
	PointParticle(Vector2<double> position, Vector2<double> velocity, Vector2<double> acceleration);
	PointParticle(Vector2<double> position, Vector2<double> velocity);
	PointParticle(Vector2<double> position);
	PointParticle();


	Vector2<double> getPosition() const;
	Vector2<double> getVelocity() const;
	Vector2<double> getAcceleration() const;

	void setPosition(Vector2<double> posNew);
	void setVelocity(Vector2<double> velNew);
	void setAcceleration(Vector2<double> accelNew);


private:
	Vector2<double> position;
	Vector2<double> velocity;
	Vector2<double> acceleration;
};

