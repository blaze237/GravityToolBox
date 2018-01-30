//#include <stdio.h>
//#include "SimulationCore_3Body.h"
//#include "Vector2.h"
//#include <string>
//#include "MathHelper.h"
//using namespace std;
//
//int main(int argc, char* argv[])
//{
//	double timeStep = 0.00015;
//
//	Vector2<double> pos(5, -3.41);
//	Vector2<double> vel(0.18, 2);
//
//	SimulationCore_3Body simulation(timeStep);
//	simulation.mainLoop(pos, vel);
//
//	printf("Press ENTER/RETURN key to end...");
//	while (getchar() != '\n')
//
//
//	return 0;
//}

//#include <SDL.h>
//#include <stdio.h>
//
////Screen dimension constants
//const int SCREEN_WIDTH = 640;
//const int SCREEN_HEIGHT = 480;
//
//int main(int argc, char* args[])
//{
//	//The window we'll be rendering to
//	SDL_Window* window = NULL;
//
//	//The surface contained by the window
//	SDL_Surface* screenSurface = NULL;
//
//	//Initialize SDL
//	if (SDL_Init(SDL_INIT_VIDEO) < 0)
//	{
//		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
//	}
//	else
//	{
//		//Create window
//		window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
//		if (window == NULL)
//		{
//			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
//		}
//		else
//		{
//			//Get window surface
//			screenSurface = SDL_GetWindowSurface(window);
//
//			//Fill the surface white
//			SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));
//
//			//Update the surface
//			SDL_UpdateWindowSurface(window);
//
//			//Wait two seconds
//			SDL_Delay(2000);
//		}
//	}
//
//	//Destroy window
//	SDL_DestroyWindow(window);
//
//	//Quit SDL subsystems
//	SDL_Quit();
//
//	return 0;
//}