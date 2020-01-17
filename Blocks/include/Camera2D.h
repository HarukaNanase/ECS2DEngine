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
	Vector2 WindowSize;
	float ScaleX;
	float ScaleY;
	void SetScaleX(float _scaleX);
	void SetScaleY(float _scaleY);
	void SetCameraSize(int _sizeX, int _sizeY);
	void SetCameraPosition(float _x, float _y);
	//const float& GetCameraScale();
	const Vector2& GetResolution();
	const Vector2& GetWindowSize();
	void SetWindowSize(float _x, float _y);
	Vector2 ScreenToWorldRaycast(float _x, float _y);
	//Vector2 WorldToScreenRaycast(float _x, float _y);
	void SetResolution(int _x, int _y);
	//void SetScale(float _scale);
};

