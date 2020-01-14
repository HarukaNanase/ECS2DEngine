#include "World.h"
#include "memory.h"
#include <iostream>
#include <AudioSystem.h>
#include <InputSystem.h>
#include <CollisionSystem.h>
#include <RenderSystem.h>
#include "Vector2.h"
World::World()
{
	auto position = Vector2(0, 0);
	auto size = Vector2(1280, 720);
	Camera = Camera2D(position, size);

}
GameObject& World::CreateGameObject()
{
	auto object = std::make_shared<GameObject>(CurrentEntityId, this); 
	CurrentEntityId++;
	GameObjects.push_back(object);
	return *object;
}


//
//void World::AddGameObject(GameObject _object)
//{
//	_object.SetObjectId(this->CurrentEntityId);
//	this->CurrentEntityId++;
//	this->GameObjects.push_back(_object);
//}

void World::RemoveGameObject(unsigned int _id)
{
	for (auto it = GameObjects.begin(); it != GameObjects.end(); ++it) {
		if ((*it)->GetObjectId() == _id) {
			for (auto& system : this->Systems) {
				;
			}
			GameObjects.erase(it);
			//delete obj;
			return;
		}
	}
	
}

void World::Update(float _deltaTime)
{
	this->GetSystem<InputSystem>().Update(_deltaTime);
	//this->GetSystem<AudioSystem>().Update(_deltaTime);
	this->GetSystem<CollisionSystem>().Update(_deltaTime);
	this->GetSystem<RenderSystem>().Update(_deltaTime);
	//for (auto& sys : Systems) {
		//sys.second->Update(_deltaTime);
	//}

}
std::vector < std::shared_ptr<GameObject> > World::GetGameObjects()
{
	return GameObjects;
}
//
//std::vector<GameObject> World::GetGameObjects()
//{
//	return this->GameObjects;
//}


Camera2D& World::GetCamera2D()
{
	return Camera;
}

void World::AddSystem(SystemID _id, std::shared_ptr<System> _system)
{
	std::cout << "System ID Registered: " << _id << std::endl;
	this->Systems.emplace(_id, _system);
	_system->SetWorld(this);
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
	for (auto obj : GameObjects) {
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
