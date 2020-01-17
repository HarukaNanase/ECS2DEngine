#include "CubeColumn.h"
#include "World.h"
#include "TransformComponent.h"
CubeColumn::CubeColumn(Texture& _cubeTexture, Vector2 _positionFirstCube) : CubeTexture(_cubeTexture)
{
	
	this->PositionFirstCube = _positionFirstCube;
}

void CubeColumn::OnInitialize()
{
	for (int i = 0; i < sizeof(Cubes)/sizeof(Cube); i++) {
		auto nextPosition = Vector2(PositionFirstCube.x, PositionFirstCube.y + (i * 32));
		auto cube = Cube(CubeTexture, nextPosition);
		auto color = Colors[rand() % Colors.size()];
		cube.GetComponent<SpriteComponent>().SetColor(color);
		Cubes[i] = GetWorld()->AddGameObject(cube);
	}
}

void CubeColumn::OnUpdate()
{
	for (auto cube : Cubes) {
		cube.GetComponent<TransformComponent>().GetPosition().x -= 0.05f * GetWorld()->GetDeltaTime();
	}
}

