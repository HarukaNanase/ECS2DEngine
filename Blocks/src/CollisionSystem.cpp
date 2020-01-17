#include "CollisionSystem.h"
#include <iostream>
#include <utility>
#include <algorithm>
void CollisionSystem::OnObjectAdded(GameObject& _object)
{

	this->LookupMap.emplace(_object.GetObjectId(), &_object);


}

void CollisionSystem::OnObjectRemoved(GameObject& _object)
{

	std::vector<unsigned int> collidingIds;
	for (auto entry = Colliding.begin(); entry != Colliding.end();) {
		if (entry->first == _object.GetObjectId()) {
			collidingIds.push_back(entry->second);
			entry = Colliding.erase(entry);
		}
		else if (entry->second == _object.GetObjectId()) {
			collidingIds.push_back(entry->first);
			entry = Colliding.erase(entry);
		}
		else
			entry++;
	}


	for (auto id : collidingIds) {
		if (LookupMap[id]->GetComponent<CollisionComponent>().OnCollisionExit != nullptr) {
			auto _callback = std::bind(LookupMap[id]->GetComponent<CollisionComponent>().OnCollisionExit, *LookupMap[_object.GetObjectId()]);
			_callback();
		}
	}

	LookupMap.erase(_object.GetObjectId());
	


}

bool CollisionSystem::CheckCollision(CollisionComponent& _collider1, CollisionComponent& _collider2)
{
	if (_collider1.GetLeft() <= _collider2.GetRight() &&
		_collider1.GetRight() >= _collider2.GetLeft() &&
		_collider1.GetTop() <= _collider2.GetBottom() &&
		_collider1.GetBottom() >= _collider2.GetTop())
		return true;

	return false;
}


CollisionSystem::CollisionSystem()
{
}

CollisionSystem::~CollisionSystem()
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
			if (collider1.IsEnabled() && collider2.IsEnabled()) {
				auto collidingPair = std::make_pair<>((*it)->GetObjectId(), (*it2)->GetObjectId());
				auto collidingPairIt = std::find(Colliding.begin(), Colliding.end(), collidingPair);
				if (collidingPairIt != Colliding.end()) {
					if (CheckCollision(collider1, collider2)) {
						//std::cout << "Still colliding" << std::endl;
						continue;
					}
					else {
						if (collider1.OnCollisionExit != nullptr) {
							collider1.OnCollisionExit(**it2);
						}
						if (collider2.OnCollisionExit != nullptr) {
							collider2.OnCollisionExit(**it);
						}
						std::cout << "Collision ended" << std::endl;
						Colliding.erase(std::remove(Colliding.begin(), Colliding.end(), collidingPair), Colliding.end());
					}
				}
				else if (CheckCollision(collider1, collider2)) {
					std::cout << "Collision Start" << std::endl;
					if (collider1.OnCollisionEnter != nullptr) {
						//call OnCollisionEnter
						collider1.OnCollisionEnter(**it2);
					}
					if (collider2.OnCollisionEnter != nullptr) {
						collider2.OnCollisionEnter(**it);
					}
					//add to existing collisions
					this->Colliding.push_back(std::make_pair<unsigned int, unsigned int>((*it)->GetObjectId(), (*it2)->GetObjectId()));
				}

			}
		}
}


}

void CollisionSystem::Destroy()
{
}
