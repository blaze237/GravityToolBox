#include "SimulationEngine.h"


SimulationEngine::SimulationEngine()
{
}


SimulationEngine::~SimulationEngine()
{
}


int SimulationEngine::init(const char* windowCaption, int screenWidth, int screenHeight)
{
	mScreenheight = screenWidth;
	mScreenWidth = screenWidth;

	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("Unable to init SDL! Error code: %s\n", SDL_GetError());
		return SDL_INIT_ERROR;
	}

	// Register SDL_Quit to be called at exit
	atexit(SDL_Quit);

	//Create window
	mWindow = SDL_CreateWindow(windowCaption, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, mScreenWidth, mScreenheight, SDL_WINDOW_SHOWN);
	if (mWindow == NULL)
	{
		printf("Unable to create window! Error code: %s\n", SDL_GetError());
		return SDL_INIT_ERROR;
	}


	mRenderer = SDL_CreateRenderer(mWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (mRenderer == NULL)
	{
		printf("Unable to create renderer! Error Code: %s\n", SDL_GetError());
		return SDL_INIT_ERROR;
	}

	//Draw the background. What this means is up to you. Could set it to a colour or a texture etc
	rerenderBackground();

	//Enable PNG support by initialising SDL_Image
	if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG))
	{
		printf("Could not initialize SDL_Image! Error Code: %s\n", IMG_GetError());
		return SDL_INIT_ERROR;
	}


	return SDL_INIT_SUCCESS;
}

void SimulationEngine::mainLoop()
{

}

void SimulationEngine::addObject(const SimulationObject &obj)
{

}
void SimulationEngine::addObjects(const std::vector<SimulationObject> &objs)
{

}
void SimulationEngine::discardObjects()
{

}
std::vector<SimulationObject>& SimulationEngine::getObjects()
{
	return objects;
}

void SimulationEngine::simulationRender()
{

}
void SimulationEngine::simulationLogic()
{

}

void SimulationEngine::rerenderBackground()
{
	//By default just set it to be white
	SDL_SetRenderDrawColor(mRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderClear(mRenderer);

}
void SimulationEngine::unrenderObjects()
{

}
void SimulationEngine::unrenderGUI()
{

}

void SimulationEngine::renderObjects()
{

}
void SimulationEngine::renderGui()
{

}