#include "BasicSystem.h"
#include "World.h"


void BasicSystem::AddGameObject(GameObject& _object)
{
	this->GameObjects.push_back(&_object);
	OnObjectAdded(_object);
}



void BasicSystem::RemoveGameObject(GameObject& _object)
{
	this->OnObjectRemoved(_object);
	this->GameObjects.erase(std::remove(GameObjects.begin(), GameObjects.end(), &_object), GameObjects.end());

}



void BasicSystem::SetWorld(World& _world)
{
	this->TheWorld = &_world;
}



BasicSystem::BasicSystem(World* _world)
{
	SetWorld(_world);
}

BasicSystem::~BasicSystem()
{
	Destroy();
}

void BasicSystem::Initialize()
{
	OnInitialize();
}

void BasicSystem::Destroy()
{
	
	this->TheWorld = nullptr;
}

World* BasicSystem::GetWorld()
{
	return TheWorld;
}

void BasicSystem::SetWorld(World* _world)
{
	this->TheWorld = _world;
}

const std::vector<GameObject*> BasicSystem::GetGameObjects()
{
	return this->GameObjects;
}

void BasicSystem::Update(float _deltaTime)
{
	for (auto& object : this->GameObjects) {
		OnUpdate(*object);
	}
}

std::bitset<MAX_NUM_COMPONENTS> BasicSystem::GetComponentMask()
{
	return RequiredComponents;
}

