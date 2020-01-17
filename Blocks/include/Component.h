#pragma once

#include "IDManager.h"


typedef Id ComponentID;



class Component
{
	ComponentID Id;
	class GameObject* Owner;
	bool Enabled = true;
public:
	virtual ~Component();

	GameObject* GetOwner();
	void SetOwner(GameObject* _owner);

	virtual void Destroy();
	virtual void Initialize();
	bool IsEnabled();
	void SetIsEnabled(bool _enabled);
};


template<class T>
ComponentID ComponentId() {
	return IDManager<Component>::GetId<T>();
}

