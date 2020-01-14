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
	AudioSystem Audio;
	CollisionSystem Collision;
	EventSystem Events;
	AudioManager SoundManager;
	bool ShouldRun = true;

public:
	bool InitEngine();
	void Cleanup();
	Engine();
	~Engine();

	//TextureManager& GetTextureManager();
	//RenderSystem& GetRenderSystem();
	CollisionSystem& GetCollisionSystem();
	EventSystem& GetEventSystem();

	void SetIsRunning(bool _state);
	double GetDeltaTime();
	bool isRunning();

protected:

	





};

