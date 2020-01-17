#pragma once
#include "System.h"
#include "SDL.h"
#include "SpriteComponent.h"
#include "TransformComponent.h"
#include "TextureManager.h"
#include "Camera2D.h"
class RenderSystem : public System
{	
private:
	SDL_Window* WindowHandle;
	SDL_Renderer* Renderer;
	TextureManager TexManager;
	bool InitWindow(const char* _windowTitle, int _x, int _y, int _width, int _height, Uint32 flags);
	bool InitRenderer(int _driverIndex = -1, Uint32 _flags = SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	
public:
	RenderSystem();
	~RenderSystem();
	SDL_Renderer* GetSDLRenderer();
	SDL_Window* GetWindowHandle();
	const Camera2D& GetCamera2D();
	TextureManager& GetTextureManager();
	virtual void Initialize() override;
	virtual void Update(float _deltaTime) override;
	virtual void Destroy() override;
	const void Draw(SpriteComponent& _sprite, SDL_FRect* _component);
	const void Draw(class World& _world);
	void RenderToScreen();
	const void ClearScreen();
	const int GetWindowWidth();
	const int GetWindowHeight();
};

