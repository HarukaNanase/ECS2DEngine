#include "RenderSystem.h"
#include "World.h"
#include <iostream>
#include <TransformComponent.h>
#define WINDOW_TITLE "Miniclip Challenge - Blocks"


const void RenderSystem::Draw(SpriteComponent& _spriteToDraw, SDL_FRect* _transform)
{
	SDL_SetTextureColorMod(_spriteToDraw.GetTexture().GetTex(), _spriteToDraw.GetColor().r, _spriteToDraw.GetColor().g, _spriteToDraw.GetColor().b);
	SDL_RenderCopyF(this->Renderer, _spriteToDraw.GetTexture().GetTex(), NULL, _transform);
}


const void RenderSystem::Draw(World& _world)
{
	this->ClearScreen();

	for (auto& renderable : GetGameObjects()) {
		auto& spriteComponent = renderable->GetComponent<SpriteComponent>();
		if (spriteComponent.IsEnabled()) {
			if (renderable->HasComponent<TransformComponent>()) {
				TransformComponent& transform = renderable->GetComponent<TransformComponent>();
				Camera2D& camera = GetWorld()->GetCamera2D();
				SDL_FRect target = transform.GetTransform();
				auto& position = transform.GetPosition();
				auto& size = transform.GetSize();
				target.x = (position.x + (camera.Size.x / 2) - camera.Position.x - size.x/2);
				target.y = (-position.y + (camera.Size.y / 2) - camera.Position.y - size.y/2);
				target.w = size.x;
				target.h = size.y;
				Draw(renderable->GetComponent<SpriteComponent>(), &target);

			}
			else {
				Draw(renderable->GetComponent<SpriteComponent>(), nullptr);
			}
		}
			
	}
	

	this->RenderToScreen();
}

bool RenderSystem::InitWindow(const char* _WindowTitle, int _x, int _y, int _width, int _height, Uint32 flags)
{

	WindowHandle = SDL_CreateWindow(WINDOW_TITLE, 100, 100, GetWorld()->GetCamera2D().Size.x, GetWorld()->GetCamera2D().Size.y, flags );
	return WindowHandle != nullptr;
}

bool RenderSystem::InitRenderer(int _DriverIndex, Uint32 _flags)
{
	Renderer = SDL_CreateRenderer(WindowHandle, _DriverIndex, _flags);
	return Renderer != nullptr;
}

void RenderSystem::RenderToScreen()
{
	SDL_RenderPresent(Renderer);
}

const void RenderSystem::ClearScreen()
{
	SDL_RenderClear(Renderer);
}

const int RenderSystem::GetWindowWidth()
{
	return SDL_GetWindowSurface(this->WindowHandle)->w;
}

const int RenderSystem::GetWindowHeight()
{
	return SDL_GetWindowSurface(this->WindowHandle)->h;

}


RenderSystem::RenderSystem()
{

}

RenderSystem::~RenderSystem()
{
	Destroy();
}

SDL_Renderer* RenderSystem::GetSDLRenderer()
{
	return Renderer;
}

SDL_Window* RenderSystem::GetWindowHandle()
{
	return WindowHandle;
}

const Camera2D& RenderSystem::GetCamera2D()
{
	return GetWorld()->GetCamera2D();
}

TextureManager& RenderSystem::GetTextureManager()
{
	return TexManager;
}

void RenderSystem::Initialize()
{

	Camera2D& camera = GetWorld()->GetCamera2D();
	if (!InitWindow("Miniclip Challenge - Blocks", 100, 100, camera.Size.x, camera.Size.y, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE | SDL_WINDOW_ALLOW_HIGHDPI | SDL_WINDOW_OPENGL)) {
		std::cout << "Error creating SDL Window: " << SDL_GetError() << std::endl;
	}

	if (!InitRenderer(-1, SDL_RENDERER_ACCELERATED )) {
		std::cout << "Error creating SDL Renderer: " << SDL_GetError() << std::endl;;
	}
	TexManager.SetRenderer(GetSDLRenderer());

	SDL_RendererInfo rendererInfo = {};
	SDL_GetRenderDriverInfo(0, &rendererInfo);
	std::cout << "Running on: " << rendererInfo.name << std::endl;
	SDL_SetHint(SDL_HINT_RENDER_BATCHING, "1");
	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");
	
	SDL_RenderSetLogicalSize(GetSDLRenderer(), camera.Size.x, camera.Size.y);



}

void RenderSystem::Update(float _deltaTime)
{
	Draw(*this->GetWorld());
}

void RenderSystem::Destroy()
{
	SDL_DestroyRenderer(this->Renderer);
	SDL_DestroyWindow(this->WindowHandle);
	Renderer = nullptr;
	WindowHandle = nullptr;
	SDL_Quit();

}
