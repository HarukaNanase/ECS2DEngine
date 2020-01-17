#pragma once
#include <vector>
#include "GameObject.h"
#include <algorithm>
#include <memory>
#include <unordered_map>
#include "IDManager.h"
#include "System.h"
#include "Camera2D.h"
class World
{
	typedef IDManager<System> SystemIDManager;
	
private:
	struct SystemDestructor {
		void operator()(System* _system) {
			_system->Destroy();
		}
	};

	Camera2D Camera;

	bool Running = true;
	std::vector<std::shared_ptr<GameObject>> GameObjects;
	unsigned int CurrentEntityId;
	std::unordered_map <SystemID, std::unique_ptr<System>> Systems;
	float DeltaTime = 0.0;
	Uint64 LastTime = 0.0, Now = 0.0;
	
public:
	World();
	GameObject& CreateGameObject();

	template<typename TObject>
	TObject& AddGameObject(TObject& _object);
	void RemoveGameObject(GameObject& _object);

	virtual void Update(float _deltaTime);
    //std::vector<std::shared_ptr<GameObject>> GetGameObjects();
	template<class TSys>
	TSys& AddSystem();
	float GetDeltaTime();
	template<class TSys>
	TSys& GetSystem();
	Camera2D& GetCamera2D();
	void RegisterObject(GameObject& _object);
	void RegisterAllObjects();
	bool IsRunning();
	void SetIsRunning(bool _running);
	
};

template<typename TObject>
TObject& World::AddGameObject(TObject& _object)
{
	// first create a sharedptr to _object
	//make sure its a base of GameObject
	if (std::is_base_of<GameObject, TObject>().value) {
		auto object = std::make_shared<TObject>(_object);
		object->SetObjectId(CurrentEntityId);
		object->SetWorld(this);
		object->OnInitialize();
		CurrentEntityId++;
		GameObjects.push_back(object);
		//RegisterObject(*object)
		return *object;
	}

}

template<class TSys>
inline TSys& World::AddSystem()
{
	auto newSystem = std::make_unique<TSys>();
	newSystem->SetWorld(this);
	newSystem->Initialize();
	this->Systems.emplace(SystemId<TSys>(), std::move(newSystem));
	return static_cast<TSys&>(*this->Systems[SystemId<TSys>()]);

}

template<class TSys>
inline TSys& World::GetSystem() {
	if (std::is_base_of<System, TSys>().value) {
		return static_cast<TSys&>(*this->Systems[SystemId<TSys>()]);
	}
}