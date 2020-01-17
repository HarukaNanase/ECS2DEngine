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
	TransformComponent(int x = 0, int y = 0);
	TransformComponent(int x = 0, int y = 0, int w = 0, int h = 0);
    Vector2& GetPosition();
	Vector2& GetSize();
	SDL_FRect GetTransform();
	void SetTransform(Vector2 _position);
};

