#include "World.h"
#include "memory.h"
#include <iostream>
#include <AudioSystem.h>
#include <InputSystem.h>
#include <CollisionSystem.h>
#include <RenderSystem.h>
#include "Vector2.h"
#include "sdl.h"
World::World()
{
	auto position = Vector2(0, 0);
	auto size = Vector2(640, 360);
	Camera = Camera2D(position, size);
	LastTime = SDL_GetPerformanceCounter();
	Now = LastTime;
}
GameObject& World::CreateGameObject()
{
	auto object = std::make_shared<GameObject>(CurrentEntityId, this); 
	CurrentEntityId++;
	GameObjects.push_back(object);
	return *object;
}




void World::RemoveGameObject(GameObject& _object)
{
	
	for (auto& systemPair : this->Systems) {
		auto& system = systemPair.second;
		system->RemoveGameObject(_object);
	}

	GameObjects.erase(std::remove_if(GameObjects.begin(), GameObjects.end(), [&](std::shared_ptr<GameObject> _obj) {
		return _object.GetObjectId() == _obj->GetObjectId();
	}), GameObjects.end());

	//std::cout << "Object to remove: " << (*objectIt)->GetObjectId() << " repositioned to end" << std::endl;

	}

void World::Update(float _deltaTime)
{
	LastTime = Now;
	for (auto& object : GameObjects)
		object->Update();

	this->GetSystem<InputSystem>().Update(this->DeltaTime);
	this->GetSystem<AudioSystem>().Update(this->DeltaTime);
//	this->GetSystem<CollisionSystem>().Update(this->DeltaTime);
	this->GetSystem<RenderSystem>().Update(this->DeltaTime);
	
	Now = SDL_GetPerformanceCounter();
	this->DeltaTime = (double)((Now - LastTime) * 1000) / (double)SDL_GetPerformanceFrequency();

}

Camera2D& World::GetCamera2D()
{
	return Camera;
}



float World::GetDeltaTime()
{
	return this->DeltaTime;
}

void World::RegisterObject(GameObject& _object)
{
	
	auto objectComponents = _object.GetComponentMask();
	for (auto& systemPair : Systems) {
		auto systemComponents = systemPair.second->GetComponentMask();
		if ((systemComponents & objectComponents) == systemComponents) {
			systemPair.second->AddGameObject(_object);
		}
	}
}

void World::RegisterAllObjects()
{
	for (auto& obj : GameObjects) {
		RegisterObject(*obj);
	}
}



bool World::IsRunning()
{
	return Running;
}

void World::SetIsRunning(bool _running)
{
	Running = _running;
}


