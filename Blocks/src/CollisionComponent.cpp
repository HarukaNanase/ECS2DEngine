#include "CollisionComponent.h"

int CollisionComponent::GetTop()
{
	return Position.y;
}

int CollisionComponent::GetBottom()
{
	return Position.y + Height;
}

int CollisionComponent::GetLeft()
{
	return Position.x;
}

int CollisionComponent::GetRight()
{
	return Position.x + Width;
}

void CollisionComponent::SetTop(int _top)
{
	this->Position.y = _top;
}

void CollisionComponent::SetBottom(int _bottom)
{
	this->Position.y = _bottom + Height;
}

void CollisionComponent::SetLeft(int _left)
{
	this->Position.x = _left;
}

void CollisionComponent::SetRight(int _right)
{
	this->Position.x = _right - Width;
}
