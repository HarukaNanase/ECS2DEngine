#pragma once

#include "Vector2.h"
class Camera2D
{
	
public:
	Camera2D();
	Camera2D(Vector2 Position, Vector2 Size);
	Vector2 Size;
	Vector2 Position;
	Vector2 Resolution;
	float scale;
	void SetCameraSize(int _x, int _y);
	void SetCameraPosition(float _x, float _y);
	const float& GetCameraScale();
	const Vector2& GetResolution();
	Vector2 ScreenToGameRaycast(int _x, int _y);
	void SetResolution(int _x, int _y);
	void SetScale(float _scale);
};

