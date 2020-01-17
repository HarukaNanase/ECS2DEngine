#pragma once


#include "SDL.h"
#include "TextureManager.h"
#include "AudioManager.h"
#include "RenderSystem.h"
#include "AudioSystem.h"
#include "CollisionSystem.h"
#include "SpriteComponent.h"
#include "EventSystem.h"
#include "InputSystem.h"
class Engine
{
private:
	//RenderSystem Renderer;
	//EventSystem Events;
	
	bool ShouldRun = true;

public:
	bool InitEngine();
	void Cleanup();
	Engine();
	~Engine();

	void SetIsRunning(bool _state);
	
	bool isRunning();

protected:

	





};

