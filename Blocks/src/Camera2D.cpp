#include "Camera2D.h"
#include "Vector2.h"
#include <iostream>
Camera2D::Camera2D()
{
}
Camera2D::Camera2D(Vector2 _position, Vector2 _size)
{
	this->Position = _position;
	this->Size = _size;
	this->scale = (float)_size.x / _size.y;
	this->Resolution = _size;
}
void Camera2D::SetCameraSize(int _x, int _y)
{
	this->Size.x = _x;
	this->Size.y = _y;
	this->scale = (float)_x / _y;
}



void Camera2D::SetCameraPosition(float _x, float _y)
{
	this->Position.x = _x;
	this->Position.y = _y;
}

const float& Camera2D::GetCameraScale()
{
	return scale;
}

const Vector2& Camera2D::GetResolution()
{
	return Resolution;
}

Vector2 Camera2D::ScreenToGameRaycast(int _x, int _y)
{
	int x = _x - (Resolution.x / 2) - Position.x;
	int y = _y - (Resolution.y / 2) - Position.y;
	std::cout << "Mouse input in world coordinates: x:" << x << " y:" << y << std::endl;
	return Vector2{ x, y };
}

void Camera2D::SetResolution(int _x, int _y)
{
	this->Resolution = Vector2{ _x, _y };
}

void Camera2D::SetScale(float _scale)
{
	this->scale = _scale;
}
