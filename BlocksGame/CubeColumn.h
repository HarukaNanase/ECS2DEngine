#pragma once

#include "GameObject.h"
#include "Cube.h"
#include <map>

class CubeColumn : public GameObject
{
	
private:
	std::map<unsigned int, Color> Colors = {
		{0,Color{0xFF, 0x00, 0x00, 0x00}},
		{1,Color{0x00, 0xFF, 0x00, 0x00}},
		{2,Color{0xFF, 0x00, 0xFF, 0x00}},
		{3,Color{0xFF, 0xFF, 0xFF, 0xFF}},
	};
	Texture& CubeTexture;
	Vector2 PositionFirstCube;
public:
	Cube Cubes[10];
	CubeColumn(Texture& _cubeTexture, Vector2 _positionFirstCube);
	virtual void OnInitialize() override;
	virtual void OnUpdate() override;

};

