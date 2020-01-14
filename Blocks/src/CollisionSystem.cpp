#include "CollisionSystem.h"
#include <iostream>
void CollisionSystem::OnObjectAdded(GameObject& _object)
{



}

void CollisionSystem::OnObjectRemoved(GameObject& _object)
{
}

bool CollisionSystem::CheckCollision(CollisionComponent& _collider1, CollisionComponent& _collider2)
{
	if (_collider1.GetLeft() < _collider2.GetRight() &&
		_collider1.GetRight() > _collider2.GetLeft() &&
		_collider1.GetTop() < _collider2.GetBottom() &&
		_collider1.GetBottom() > _collider2.GetTop())
		return true;

	return false;
}

CollisionSystem::CollisionSystem()
{
}

void CollisionSystem::Initialize()
{
}

void CollisionSystem::Update(float _deltaTime)
{
	auto& objects = this->GetGameObjects();
	for (auto it = objects.begin(); it != objects.end(); ++it){
		for (auto it2 = it + 1; it2 != objects.end(); it2++) {
			auto& collider1 = (*it)->GetComponent<CollisionComponent>();
			auto& collider2 = (*it2)->GetComponent<CollisionComponent>();
			if (CheckCollision(collider1, collider2)) {
				collider1.Callback(**it2);
			}

		}
}


}

void CollisionSystem::Destroy()
{
}
