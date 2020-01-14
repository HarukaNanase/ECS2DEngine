#include "SpriteComponent.h"
#include "RenderSystem.h"
#include "GameObject.h"


SpriteComponent::SpriteComponent(Texture* _tex, Color _color)
{
	this->Tex = _tex;
	this->SpriteColor = _color;

}

const Color& SpriteComponent::GetColor()
{
	// TODO: insert return statement here
	return this->SpriteColor;
}


Texture* SpriteComponent::GetTexture()
{
	return this->Tex;
}



GameObject* SpriteComponent::GetGameObject()
{
	return Component::GetOwner();
}

void SpriteComponent::SetGameObject(GameObject* _owner)
{
	Component::SetOwner(_owner);
}

void SpriteComponent::SetTexture(Texture* _tex)
{
	Tex = _tex;
}

void SpriteComponent::SetColor(Color _color)
{
	SpriteColor = _color;
}

