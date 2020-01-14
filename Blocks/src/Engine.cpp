#include "Engine.h"
#include "SDL_image.h"
#include <iostream>






bool Engine::InitEngine()
{
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0) {
		std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
		return false;
	}

	Collision.Initialize();

	SoundManager = AudioManager(Audio.GetSoundEngine());
	
	
	SoundManager.LoadResource("BackgroundMusic", "assets\\audio\\Electronic Fantasy.ogg");
	Audio.Play2DSoundFromMemory(SoundManager, "BackgroundMusic", true);

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

	SoundManager = AudioManager(Audio.GetSoundEngine());
}


Engine::~Engine()
{
}



//TextureManager& Engine::GetTextureManager()
//{
	//return GetRenderSystem().GetTextureManager();
//}

//RenderSystem& Engine::GetRenderSystem()
//{
	//return Renderer;
//}

CollisionSystem& Engine::GetCollisionSystem()
{
	return Collision;
}

EventSystem& Engine::GetEventSystem()
{
	return Events;
}



void Engine::SetIsRunning(bool _state)
{
	ShouldRun = _state;
}




double Engine::GetDeltaTime()
{
	return 0;
}



bool Engine::isRunning()
{
	return ShouldRun;
}

