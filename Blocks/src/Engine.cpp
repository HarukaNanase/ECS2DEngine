#include "Engine.h"
#include "SDL_image.h"
#include <iostream>



bool Engine::InitEngine()
{
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0) {
		std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
		return false;
	}

	return true;

}

void Engine::Cleanup()
{
	SDL_Quit();
	//other cleanup code
}

Engine::Engine()
{
	if(!InitEngine()){
		Cleanup();
		std::cout << "Error initializing engine. Press any key to continue." << std::endl;
		exit(EXIT_FAILURE);
	}

}


Engine::~Engine()
{
}




void Engine::SetIsRunning(bool _state)
{
	ShouldRun = _state;
}


bool Engine::isRunning()
{
	return ShouldRun;
}

