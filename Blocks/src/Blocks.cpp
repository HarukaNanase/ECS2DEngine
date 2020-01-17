// Blocks.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "SDL.h"
#include "SDL_image.h"
#include "Engine.h"
#include <memory>
#include "GameObject.h"
#include "Component.h"
#include "InputComponent.h"
#include "TransformComponent.h"

#include "World.h"
#include "Blocks.h"

auto engine = std::make_unique<Engine>();
int clicks = 0;
void ResizeWindow(World* world, const SDL_Event& _event) {
	if (_event.window.event == SDL_WINDOWEVENT_RESIZED) {
		world->GetCamera2D().SetResolution(world->GetSystem<RenderSystem>().GetWindowWidth(), world->GetSystem<RenderSystem>().GetWindowHeight());

	}
}

int main(int argc, char* args[])
{
	
//	World world;
//	world.AddSystem<RenderSystem>();
//	world.AddSystem<EventSystem>();
//	world.AddSystem<CollisionSystem>();
//	world.AddSystem<InputSystem>();
//	world.AddSystem<AudioSystem>();
//	auto& audioSystem = world.GetSystem<AudioSystem>();
//	audioSystem.RequiresComponent<SoundComponent>();
//	audioSystem.GetSoundManager().LoadResource("cratehit", "assets\\audio\\crate.wav");
//	audioSystem.Play2DSound("Electronic Fantasy.ogg", true);
//	auto& renderSystem = world.GetSystem<RenderSystem>();
//	std::cout << "Render system requires Sprite Component? " << renderSystem.UsesComponent<SpriteComponent>() << std::endl;
//
//	renderSystem.RequiresComponent<SpriteComponent>();
//	world.GetSystem<CollisionSystem>().RequiresComponent<CollisionComponent>();
//	world.GetSystem<InputSystem>().RequiresComponent<InputComponent>();
//	//renderSystem.RequiresComponent<TransformComponent>();
//	
//	std::cout << "Render system requires Sprite Component? " << renderSystem.UsesComponent<SpriteComponent>() << std::endl;
//	world.GetSystem<InputSystem>().RegisterWorldEvent(&world, SDL_QUIT, std::function([](World* _world, const SDL_Event& _event) { _world->SetIsRunning(false); }));
//	world.GetSystem<InputSystem>().RegisterWorldEvent(&world, SDL_WINDOWEVENT, &ResizeWindow);
//
//	TextureManager& texM = world.GetSystem<RenderSystem>().GetTextureManager();
//
//	world.GetSystem<RenderSystem>().GetTextureManager().LoadResource("crate", "assets\\sprites\\crate.png");
//	world.GetSystem<RenderSystem>().GetTextureManager().LoadResource("background", "assets\\sprites\\naturebackground.png");
//	GameObject& background = world.CreateGameObject();
//	background.AddComponent<SpriteComponent>(world.GetSystem<RenderSystem>().GetTextureManager().Get("background"), Color{ 0xff, 0xff, 0xff, 0xff });
//	GameObject& crate = world.CreateGameObject();
//	crate.AddComponent<InputComponent>();
//	auto& crateSC = crate.AddComponent<SpriteComponent>(world.GetSystem<RenderSystem>().GetTextureManager().Get("crate"), Color{ 0xff, 0xff, 0xff, 0xff });
//	crate.AddComponent<TransformComponent>(0, 0, 64, 64);
//	GameObject& crate2 = world.CreateGameObject();
//	crate2.AddComponent<SpriteComponent>(world.GetSystem<RenderSystem>().GetTextureManager().Get("crate"), Color{ 0xff, 0xff, 0xff, 0xff });
//	crate2.AddComponent<TransformComponent>(100, 100, 64, 64);
//	crate.AddComponent<SoundComponent>();
//	//crate2.AddComponent<CollisionComponent>(crate2.GetComponent<TransformComponent>().GetPosition(), crate2.GetComponent<TransformComponent>().GetSize());
//	/*crate.AddComponent<CollisionComponent>(crate.GetComponent<TransformComponent>().GetPosition(),
//		crate.GetComponent<TransformComponent>().GetSize(),
//		std::function([&crate](GameObject& _collidedWith) { 
//		crate.GetComponent<SoundComponent>().Play2DSound("cratehit"); 
//		_collidedWith.GetComponent<SpriteComponent>().SetColor(Color{ 0xff, 0x00,0x00, 0xff });
//		_collidedWith.Disable();
//		
//	}),
//		std::function([](GameObject& _collidedWith) { _collidedWith.GetComponent<SpriteComponent>().SetColor(Color{ 0xff, 0xff,0xff, 0xff }); }));
//	*/
//
//	//crateSC.SetTexture(engine->GetTextureManager().Get("background"));
//	//crateSC.SetColor(Color{ 0xff, 0xff, 0xff, 0xff });
//	auto& input = crate.GetComponent<InputComponent>();
//	crate.GetComponent<InputComponent>().AddBinding("A", std::function([](GameObject& _object) { _object.GetComponent<TransformComponent>().GetPosition().x -= 0.5f * _object.GetWorld()->GetDeltaTime(); }));
//	crate.GetComponent<InputComponent>().AddBinding("D", std::function([](GameObject& _object) { _object.GetComponent<TransformComponent>().GetPosition().x += 0.5f * _object.GetWorld()->GetDeltaTime(); }));
//	crate.GetComponent<InputComponent>().AddBinding("W", std::function([](GameObject& _object) { _object.GetComponent<TransformComponent>().GetPosition().y -= 0.5f * _object.GetWorld()->GetDeltaTime(); }));
//	crate.GetComponent<InputComponent>().AddBinding("S", std::function([](GameObject& _object) { _object.GetComponent<TransformComponent>().GetPosition().y += 0.5f * _object.GetWorld()->GetDeltaTime(); }));
//	crate.GetComponent<InputComponent>().AddBinding("MOUSE_LEFT", std::function([](GameObject& _object) { std::cout << "Clicked on object with id: " << _object.GetObjectId() << "Click Number: " << ++clicks << std::endl;
//}));
//	
//
//	
//	world.RegisterAllObjects();
//
//	while(world.IsRunning()) {
//		
//		world.Update(0);
//
//	}
//
//	return 0;
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
