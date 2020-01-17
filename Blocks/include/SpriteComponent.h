#pragma once
#include "Color.h"
#include "Texture.h"
#include <memory>
#include "Component.h"


//A sprite represents a 2D object inside the engine. This couples the texture with a color and a transform

class SpriteComponent : public Component
{
private:
	Color SpriteColor;
	Texture& Tex;

public:
	SpriteComponent(Texture& _tex, Color _color);
	const Color& GetColor();
	Texture& GetTexture();
	GameObject* GetGameObject();
	void SetGameObject(GameObject* _owner);
	void SetTexture(Texture& _tex);
	void SetColor(Color _color);
};
