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
	std::unordered_map <SystemID, std::shared_ptr<System>> Systems;
public:
	World();
	GameObject& CreateGameObject();
	//void AddGameObject(GameObject _object);
	void RemoveGameObject(unsigned int _id);
	virtual void Update(float _deltaTime);
    std::vector<std::shared_ptr<GameObject>> GetGameObjects();
	template<class TSys>
	void AddSystem();

	template<class TSys>
	TSys& GetSystem();
	Camera2D& GetCamera2D();
	void AddSystem(SystemID _id, std::shared_ptr<System> _system);
	void RegisterObject(GameObject& _object);
	void RegisterAllObjects();
	bool IsRunning();
	void SetIsRunning(bool _running);
};

template<class TSys>
inline void World::AddSystem()
{
	auto newSystem = std::make_shared<TSys>();
	newSystem->SetWorld(this);
	newSystem->Initialize();
	this->AddSystem(SystemId<TSys>(), newSystem);

}

template<class TSys>
inline TSys& World::GetSystem() {
	if (std::is_base_of<System, TSys>().value) {
		return static_cast<TSys&>(*this->Systems[SystemId<TSys>()]);
	}
}