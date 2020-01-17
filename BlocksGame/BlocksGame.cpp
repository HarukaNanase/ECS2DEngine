// BlocksGame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "BlocksGame.h"
#include "RenderSystem.h"
#include "AudioSystem.h"
#include "InputSystem.h"
#include "CollisionSystem.h"
#include "Cube.h"
#include "GameObject.h"
#include "CubeColumn.h"
#include "EndPoint.h"
#include "Grid.h"
#include "World.h"
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

void ResizeWindow(World* world, const SDL_Event& _event) {
	if (_event.window.event == SDL_WINDOWEVENT_RESIZED) {
		float scaleX, scaleY;
		int w, h;
		SDL_RenderGetScale(world->GetSystem<RenderSystem>().GetSDLRenderer(), &scaleX, &scaleY);
		world->GetCamera2D().SetScaleX(scaleX);
		world->GetCamera2D().SetScaleY(scaleY);
		world->GetCamera2D().SetResolution((round(world->GetCamera2D().Size.x * scaleX)),round(world->GetCamera2D().Size.y * scaleY));
		world->GetCamera2D().SetWindowSize(world->GetSystem<RenderSystem>().GetWindowWidth(), world->GetSystem<RenderSystem>().GetWindowHeight());

		std::cout << "Window Size:" << world->GetSystem<RenderSystem>().GetWindowWidth() << "x" << world->GetSystem<RenderSystem>().GetWindowHeight() << std::endl;
		std::cout << "External Resolution: " << world->GetCamera2D().Size.x * scaleX << "x" << world->GetCamera2D().Size.y * scaleY << std::endl;
		std::cout << "Virtual Resolution: " << world->GetCamera2D().Size.x << "x" << world->GetCamera2D().Size.y << std::endl;

	}
}

void BlocksGame::SetupWorldSystems()
{
	this->GameWorld.AddSystem<RenderSystem>().RequiresComponent<SpriteComponent>();
	this->GameWorld.AddSystem<CollisionSystem>().RequiresComponent<CollisionComponent>();
	this->GameWorld.AddSystem<InputSystem>().RequiresComponent<InputComponent>();
	this->GameWorld.AddSystem<AudioSystem>().RequiresComponent<SoundComponent>();
	auto& audioSystem = GameWorld.GetSystem<AudioSystem>();
	GameWorld.GetSystem<InputSystem>().RegisterWorldEvent(&GameWorld, SDL_QUIT, std::function<void(World*, const SDL_Event&)>([](World* _world, const SDL_Event& _event) { _world->SetIsRunning(false); }));
	GameWorld.GetSystem<InputSystem>().RegisterWorldEvent(&GameWorld, SDL_WINDOWEVENT, &ResizeWindow);
	audioSystem.Play2DSound("Electronic Fantasy.ogg", true);
}

void BlocksGame::SetupWorldObjects()
{
	TextureManager& TexManager = GameWorld.GetSystem<RenderSystem>().GetTextureManager();
	TexManager.LoadResource("crate", "assets\\sprites\\crate.png");
	TexManager.LoadResource("background", "assets\\sprites\\Background.png");
	AudioManager& SoundManager = GameWorld.GetSystem<AudioSystem>().GetSoundManager();
	SoundManager.LoadResource("cratehit", "assets\\audio\\crate.wav");
	GameObject& background = GameWorld.CreateGameObject();
	background.AddComponent<SpriteComponent>(TexManager.Get("background"), Color{ 0xff, 0xff, 0xff, 0xff });
	GameObject& groundCollider = GameWorld.CreateGameObject();
	groundCollider.AddComponent<TransformComponent>(0, -120, 680, 2);
	auto& transformComp = groundCollider.GetComponent<TransformComponent>();
	groundCollider.AddComponent<CollisionComponent>(
		transformComp.GetPosition(), transformComp.GetSize(), groundCollider
	);

	Grid _grid(&TexManager.Get("crate"));
	Grid& grid = GameWorld.AddGameObject(_grid);
	grid.SpawnColumn();
	GameWorld.AddGameObject(groundCollider);

	//CubeColumn column(TexManager.Get("crate"), Vector2(320, -119));
	//GameWorld.AddGameObject(column);
	EndPoint end = EndPoint(Vector2(0, -135));
	GameWorld.AddGameObject(end);


	GameWorld.RegisterAllObjects();

}

void BlocksGame::OnWorldUpdate()
{
	TimeElapsed += GameWorld.GetDeltaTime() * 0.001;
	if (TimeElapsed >= 3) {

	}
//	std::cout << "World Update!" << std::endl;

}
