#include "EndPoint.h"
#include "TransformComponent.h"
#include "CollisionComponent.h"
#include "World.h"
#include <iostream>
EndPoint::EndPoint(Vector2 _position)
{
	AddComponent<TransformComponent>(_position.x, _position.y, 32, 32);
	
}

void EndPoint::OnInitialize()
{
	auto& transform = GetComponent<TransformComponent>();
	AddComponent<CollisionComponent>(transform.GetPosition(), transform.GetSize(), *this);

	GetComponent<CollisionComponent>().OnCollisionEnter = [&](GameObject& _arg) { this->OnCollisionEnter(_arg); };



}

void EndPoint::OnCollisionEnter(GameObject& obj)
{
	if (obj.HasTag("cube")) {
		std::cout << "GG you lose" << std::endl;
		GetWorld()->SetIsRunning(false);
	}

}

