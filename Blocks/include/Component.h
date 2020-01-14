#pragma once

#include "IDManager.h"


typedef Id ComponentID;



class Component
{
	ComponentID Id;
	class GameObject* Owner;
public:
	virtual ~Component();

	GameObject* GetOwner();
	void SetOwner(GameObject* _owner);

	virtual void Destroy();
	virtual void Initialize();
};


template<class T>
ComponentID ComponentId() {
	return IDManager<Component>::GetId<T>();
}

