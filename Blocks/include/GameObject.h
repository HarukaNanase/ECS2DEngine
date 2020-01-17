#pragma once
#include "Component.h"

#include "SpriteComponent.h"
#include "SoundComponent.h"
#include <unordered_map>
#include <bitset>
#include <assert.h>
#define MAX_NUM_COMPONENTS 8

class GameObject
{
	unsigned int ObjectId;
	class World* TheWorld;	
	bool IsRegistered = false;
	
	struct ComponentDestructor {
		void operator()(Component* _component) {
			_component->Destroy();
		}
	};

	void RegisterComponents();
	void Initialize();
	std::unordered_map<ComponentID, std::shared_ptr<Component>> ObjectComponents;
	std::bitset<MAX_NUM_COMPONENTS> ExistingComponents;
	std::vector<std::string> Tags;
public:
	~GameObject();
	void AddTag(const std::string& _tag);
	void RemoveTag(const std::string& _tag);
	bool HasTag(const std::string& _tag);
	bool IsActive;
	GameObject();
	GameObject(unsigned int _id);
	GameObject(unsigned int _id, World* _world);
	virtual void Update();
	virtual void OnUpdate();
	virtual void OnInitialize();
	virtual void OnDestroy();


	unsigned int GetObjectId();
	void SetObjectId(unsigned int _id);
	class World* GetWorld();
	void SetWorld(World* _world);

	void Register();
	void Destroy();
	void Disable();
	std::bitset<MAX_NUM_COMPONENTS> GetComponentMask();
	//std::unordered_map <ComponentID, std::unique_ptr<Component>> ObjectComponents;

	template<typename T, typename... Args>
	T& AddComponent(Args&&... args);

	template<typename T>
	void RemoveComponent();

	template<typename T>
	T& GetComponent();

	template<typename T>
	bool HasComponent();
	
};

template<typename T, typename ...Args>
inline T& GameObject::AddComponent(Args&& ...args)
{
	//static_assert(ComponentId<T>() < MAX_NUM_COMPONENTS, "Max number of components exceeded.");
	auto component = std::make_shared<T>(std::forward<Args>(args)...);
	this->ObjectComponents.emplace(ComponentId<T>() , component);
	//this->ObjectComponents[ComponentId<T>()] = std::make_shared<T>(std::forward<Args>(args)...);;
	this->ExistingComponents[ComponentId<T>()] = true;
	return *component;

	
}

template<typename T>
inline void GameObject::RemoveComponent()
{
	if (HasComponent<T>()) {
		ObjectComponents.erase(ComponentId<T>());
		ExistingComponents[ComponentId<T>()] = false;
	}
	
}

template<typename T>
inline T& GameObject::GetComponent()
{
	if (std::is_base_of<Component, T>().value) 
		return static_cast<T&>(*(ObjectComponents[ComponentId<T>()]));
}

template<typename T>
inline bool GameObject::HasComponent()
{
	return ExistingComponents[ComponentId<T>()];

}
