#pragma once
#include "Vector2.h"
#include "Component.h"
#include <functional>
class CollisionComponent : public Component
{

private:
	
public:
	//CollisionComponent() { Position = Vector2(); Height = 0;  Width = 0; };
	//CollisionComponent(Vector2 _position, Vector2 _size) :Position(_position), Width(_size.x), Height(_size.y) {};

	CollisionComponent(Vector2& _position, Vector2& _size, std::function<void(GameObject& _collidedWith)> _callback) : Position(_position), Width(_size.x), Height(_size.y), Callback(_callback) {};
	std::function<void(GameObject & _collidedWith)> Callback;
	Vector2& Position;
	int Width;
	int Height;
	int GetTop();
	int GetBottom();
	int GetLeft();
	int GetRight();
	void SetTop(int _top);
	void SetBottom(int _bottom);
	void SetLeft(int _left);
	void SetRight(int _right);
};

