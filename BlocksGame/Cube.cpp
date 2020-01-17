#include "Cube.h"
#include "InputComponent.h"
#include "SpriteComponent.h"
#include "SoundComponent.h"	
#include "TransformComponent.h"
#include "CollisionComponent.h"
#include "World.h"
#include <functional>
#include <iostream>


Cube::Cube(Texture& _tex, const Vector2& _position)
{
	AddComponent<InputComponent>();
	AddComponent<SpriteComponent>(_tex, Color{ 0xFF, 0xFF, 0xFF, 0xFF });
	AddComponent<TransformComponent>(_position.x, _position.y, 32, 32);
	AddComponent<SoundComponent>();
	this->AddTag("cube");
}

void Cube::OnInitialize()
{
	//AddComponent<CollisionComponent>(GetComponent<TransformComponent>().GetPosition(),
	//	GetComponent<TransformComponent>().GetSize(), *this, [&](GameObject& _arg) { this->OnCollisionEnter(_arg); }, [&](GameObject& _arg) { this->OnCollisionExit(_arg); }
	//	);

	GetComponent<InputComponent>().AddBinding("A", std::function<void(GameObject & _object)>([this](GameObject& _object) { _object.GetComponent<TransformComponent>().GetPosition().x -= 0.5f * _object.GetWorld()->GetDeltaTime(); }));
	GetComponent<InputComponent>().AddBinding("D", std::function<void(GameObject & _object)>([this](GameObject& _object) { _object.GetComponent<TransformComponent>().GetPosition().x += 0.5f * _object.GetWorld()->GetDeltaTime(); }));
	GetComponent<InputComponent>().AddBinding("W", std::function<void(GameObject & _object)>([this](GameObject& _object) { _object.GetComponent<TransformComponent>().GetPosition().y += 0.5f * _object.GetWorld()->GetDeltaTime(); }));
	GetComponent<InputComponent>().AddBinding("S", std::function<void(GameObject & _object)>([this](GameObject& _object) { _object.GetComponent<TransformComponent>().GetPosition().y -= 0.5f * _object.GetWorld()->GetDeltaTime(); }));
	GetComponent<InputComponent>().AddBinding("MOUSE_LEFT", std::function<void(GameObject & _object)>([this](GameObject& _object) {
		std::cout << "Cube id: " << GetObjectId() << " : ARRIVEDERCI!" << std::endl;
		this->Destroy(); 

	}));



}

void Cube::OnDestroy()
{

}

void Cube::OnUpdate()
{
	//if (IsFalling) {
	//	GetComponent<TransformComponent>().GetPosition().y -= 0.05f * GetWorld()->GetDeltaTime();
	//}
	//GetComponent<TransformComponent>().GetPosition().x -= 0.05f * GetWorld()->GetDeltaTime();
}

void Cube::OnCollisionEnter(GameObject& _collidedWith)
{
	auto otherComp = _collidedWith.GetComponent<TransformComponent>();
	auto myComp = GetComponent<TransformComponent>();
	if (otherComp.GetPosition().y < myComp.GetPosition().y) {
		std::cout << "Cube " << this->GetObjectId() << " going to fall." << std::endl;
		IsFalling = false;
		this->GetComponent<TransformComponent>().GetPosition().y = otherComp.GetPosition().y + otherComp.GetSize().y / 2 + myComp.GetSize().y/2;
	}
	
}

void Cube::OnCollisionExit(GameObject& _collided)
{
	auto otherComp = _collided.GetComponent<TransformComponent>();
	if (otherComp.GetPosition().y < this->GetComponent<TransformComponent>().GetPosition().y && _collided.HasTag("cube")) {
		IsFalling = true;
	}
}
