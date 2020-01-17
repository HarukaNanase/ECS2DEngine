#pragma once
#include <vector>
#include "GameObject.h"
#include "IDManager.h"
#include <bitset>
#include "Component.h"
typedef Id SystemID;

class BasicSystem 
{
	
	virtual void OnObjectAdded(GameObject& _object) = 0;
	virtual void OnObjectRemoved(GameObject& _object) = 0;
	virtual void OnUpdate(GameObject& _object) = 0;
	virtual void OnInitialize() = 0;
	
	void SetWorld(class World& world);
	class World* TheWorld;
	std::vector<GameObject*> GameObjects;
	std::bitset<MAX_NUM_COMPONENTS> RequiredComponents;
	
public:
	BasicSystem() {};
	BasicSystem(World* _world);
	virtual ~BasicSystem();
	virtual void Initialize();
	virtual void Destroy();
	class World* GetWorld();
	void SetWorld(World* _world);
	const std::vector<GameObject*> GetGameObjects();
	virtual void Update(float _deltaTime);
	void AddGameObject(GameObject& _object);

	void RemoveGameObject(GameObject& _object);
	template<typename T>
	void RequiresComponent() {
		if (std::is_base_of<Component, T>().value) {
			this->RequiredComponents.set(ComponentId<T>());
		}
	}

	template<typename T>
	bool UsesComponent() {
		return this->RequiredComponents[ComponentId<T>()];
	}

	std::bitset<MAX_NUM_COMPONENTS> GetComponentMask();


};
template<typename T>
SystemID SystemId() {
	return IDManager<BasicSystem>::GetId<T>();
};