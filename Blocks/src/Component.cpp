#include "Component.h"

Component::~Component()
{
}

GameObject* Component::GetOwner()
{
	return this->Owner;
}

void Component::SetOwner(GameObject* _owner)
{
	this->Owner = _owner;
}

void Component::Destroy()
{
	SetOwner(nullptr);
}

void Component::Initialize()
{
}

bool Component::IsEnabled()
{
	return Enabled;
}

void Component::SetIsEnabled(bool _enabled)
{
	this->Enabled = _enabled;
}
