#pragma once
#include "GameObject.h"
#include "Vector2.h"
class EndPoint : public GameObject
{
private:

public:
	EndPoint(Vector2 _position);
	virtual void OnInitialize() override;

	void OnCollisionEnter(GameObject& obj);
};

