#include "GameObject.h"
#include "World.h"
void GameObject::RegisterComponents()
{
	GetWorld()->RegisterObject(*this);
}
void GameObject::Initialize()
{
	OnInitialize();
	RegisterComponents();
}
GameObject::GameObject()
{
}

GameObject::GameObject(unsigned int _id)
{
	this->ObjectId = _id;

}

GameObject::GameObject(unsigned int _id, World* _world)
{
	this->ObjectId = _id;
	this->TheWorld = _world;
}

void GameObject::Update(World& _world, float _deltaTime)
{
}

void GameObject::OnInitialize()
{
}

unsigned int GameObject::GetObjectId()
{
	return this->ObjectId;
}

void GameObject::SetObjectId(unsigned int _id)
{
	this->ObjectId = _id;
}


World* GameObject::GetWorld()
{
	return TheWorld;
}


void GameObject::SetWorld(World* _world) {
	TheWorld = _world;
}
void GameObject::Register()
{
	//TheWorld->RegisterObjectWithSystems(*this);
}

std::bitset<MAX_NUM_COMPONENTS> GameObject::GetComponentMask()
{
	return this->ExistingComponents;
}
