#pragma once
#include "GameObject.h"
#include "Texture.h"
#include "Vector2.h"
class Cube : public GameObject
{
public:
	Cube() {};
	bool IsFalling = false;
	
	Cube(Texture& _tex, const Vector2& _position);
	virtual void OnInitialize() override;
	virtual void OnDestroy() override;
	virtual void OnUpdate() override;
	void OnCollisionEnter(GameObject& _collidedWith);
	void OnCollisionExit(GameObject& _collided);
};

