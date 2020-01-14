#pragma once
#include "System.h"
#include "CollisionComponent.h"
class CollisionSystem : public System
{
	virtual void OnObjectAdded(GameObject& _object) override;
	virtual void OnObjectRemoved(GameObject& _object) override;
	bool CheckCollision(CollisionComponent& _collider1, CollisionComponent& _collider2);
public:

	CollisionSystem();

	virtual void Initialize() override;

	virtual void Update(float _deltaTime) override;

	virtual void Destroy() override;

};

