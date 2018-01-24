#include <stdio.h>
#include "SimulationCore_3Body.h"
#include "Vector2.h"
#include <string>
#include "MathHelper.h"
using namespace std;

int main(int argc, char* argv[])
{
	double timeStep = 0.00015;

	Vector2<double> pos(5, -3.41);
	Vector2<double> vel(0.18, 2);

	SimulationCore_3Body simulation(timeStep);
	simulation.mainLoop(pos, vel);

	printf("Press ENTER/RETURN key to end...");
	while (getchar() != '\n')


	return 0;
}