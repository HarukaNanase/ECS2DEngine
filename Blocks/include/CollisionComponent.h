#pragma once
#include "Vector2.h"
#include "Component.h"
#include <functional>

using namespace std::placeholders;

typedef std::function<void(GameObject & _arg)> ObjectFunction;
class CollisionComponent : public Component
{

private:

public:

	CollisionComponent(Vector2& _position, Vector2& _size, GameObject& _owner, std::function<void(GameObject & _arg)> enterFunc = nullptr,
		std::function<void(GameObject & _arg)> exitFunc = nullptr);
	
	
	std::function<void(GameObject & _collidedWith)> OnCollisionEnter;
	std::function<void(GameObject & _collidedWith)> OnCollisionExit;
	Vector2& Position;
	int Width;
	int Height;
	float GetTop();
	float GetBottom();
	float GetLeft();
	float GetRight();
	void SetTop(int _top);
	void SetBottom(int _bottom);
	void SetLeft(int _left);
	void SetRight(int _right);
};