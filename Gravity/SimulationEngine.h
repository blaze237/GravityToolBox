#pragma once
#include "SimulationObject.h"
#include <vector>
class SimulationEngine
{
public:
	SimulationEngine();
	~SimulationEngine();

	/*
	gonna have a main sdl loop which will be handling everything, so now, simulations will be run every update of the engine, rather than every .
	simulation will maintain its own internal timestep.

	may want to only update the simulation every fixed update vs every frame, this way can agjust the speed at which simulation is being calculated/displayed 
	
	Go with scene manager as before, so that engine just calls currentScene->foo

	then, each scene manager can have its own simulation and gui logic. Put simulation code in scene, to make it easy to translate a virtual particle into a displayable object, it can all be the same thing (maybe, depends if internal position cooridantes are simply mapped to display ones)

	*/



	//Main loop
		//Call simulation loop on the objects
		//Call render
	//

	//Render 
		//if(Whole screen redraw)
		//Copy Background
		//Draw objects
		//Draw GUI
	//Else
		//Undraw objects
		//undraw gui
		//Draw objects
		//Draw GUI





	//Initalise SDL subsytems and create the window. Non zero return indicates an error has occured.
	int init();

	//The main engine loop, from which rendering, simulation and input is handled.
	void mainLoop();


	//Store a new SimulationObject in the engines internal array.
	void addObject(const SimulationObject &obj);
	//Store a collection of simulation objects in the engines internal array.
	void addObjects(const std::vector<SimulationObject> &objs);
	//Discard all current objects
	void discardObjects();
	//Return referenced to the object vector
	std::vector<SimulationObject>& getObjects();

private:

	
	//Handle the drawing and undrawing of elements such as objects and strings to the screen
	void simulationRender();
	//Handle the actual logic of the simulation, such as uodating new object positions for current iteration. Just a pass through the simulation object, passes no paramters as we dont know What specific object types each simulation will want
	void simulationLogic();

	//Redraw the background whenever a whole screen redraw is needed
	void rerenderBackground();
	//Tell each SimulationObject to unrender itself(i.e copy the background back over their old position on the screen). DONT REDRAW UNLESS YOU NEED TO. HAVE A FLAG FOR IF POSITION OR APPEARNCE CHNAGED
	void unrenderObjects();
	//Undraw any gui elements that have changed since last loop iteration
	void unrenderGUI();

	//Tell each SimulationObject to render itself
	void renderObjects();
	void renderGui();



	//Handle input

	//Update simulation by one tick

	//Draw particles

	//Draw GUI
};

