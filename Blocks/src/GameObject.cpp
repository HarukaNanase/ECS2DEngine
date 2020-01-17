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

GameObject::~GameObject()
{
	this->ObjectComponents.clear();
}

void GameObject::AddTag(const std::string& _tag)
{
	this->Tags.push_back(_tag);
}

void GameObject::RemoveTag(const std::string& _tag)
{
	Tags.erase(std::remove(Tags.begin(), Tags.end(), _tag), Tags.end());
}

bool GameObject::HasTag(const std::string& _tag)
{
	return std::find(Tags.begin(), Tags.end(), _tag) != Tags.end();
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


void GameObject::Update()
{
	OnUpdate();
}

void GameObject::OnUpdate()
{

}

void GameObject::OnInitialize()
{
}

void GameObject::OnDestroy()
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

void GameObject::Destroy()
{
	this->OnDestroy();
	TheWorld->RemoveGameObject(*this);
}

void GameObject::Disable()
{
	for (auto& componentPair : this->ObjectComponents) {
		componentPair.second->SetIsEnabled(false);
	}
}

std::bitset<MAX_NUM_COMPONENTS> GameObject::GetComponentMask()
{
	return this->ExistingComponents;
}
