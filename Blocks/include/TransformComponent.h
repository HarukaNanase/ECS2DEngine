#pragma once
#include "Vector2.h"
#include "Component.h"
#include "SDL.h"
class TransformComponent : public Component
{
	SDL_Rect Rect;
	Vector2 Position;
	Vector2 Size;

public:
	TransformComponent(int x, int y);
	TransformComponent(int x, int y, int w, int h);
    Vector2& GetPosition();
	Vector2& GetSize();
	SDL_Rect& GetTransform();
	void SetTransform(Vector2 _position);
};

