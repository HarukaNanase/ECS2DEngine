#include "TransformComponent.h"

TransformComponent::TransformComponent(int x, int y) : Position{x,y}
{

}

TransformComponent::TransformComponent(int x, int y, int w, int h) : Rect{x,y,w,h}, Position{x,y}, Size{ w, h}
{
	
}

Vector2& TransformComponent::GetPosition()
{
	return this->Position;
}

Vector2& TransformComponent::GetSize()
{
	return Size;
}

SDL_FRect TransformComponent::GetTransform()
{
	return { Position.x, Position.y, Size.x, Size.y };
}

void TransformComponent::SetTransform(Vector2 _position)
{
	Position = _position;
}
