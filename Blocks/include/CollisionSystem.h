#pragma once
#include "System.h"
#include "CollisionComponent.h"
#include <map>
class CollisionSystem : public System
{
	virtual void OnObjectAdded(GameObject& _object) override;
	virtual void OnObjectRemoved(GameObject& _object) override;
	std::vector<std::pair<unsigned int, unsigned int>> Colliding;	
	std::map<unsigned int, GameObject*> LookupMap;
	bool CheckCollision(CollisionComponent& _collider1, CollisionComponent& _collider2);

public:

	CollisionSystem();
	~CollisionSystem();
	virtual void Initialize() override;

	virtual void Update(float _deltaTime) override;

	virtual void Destroy() override;

};

