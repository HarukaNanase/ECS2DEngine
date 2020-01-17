#include "Grid.h"
#include "World.h"


void Grid::SpawnColumn()
{
	std::vector<Cube> column;
	for (int i = 0; i < GridHeight; i++) {
		Cube cube = Cube(*TexForCubes, Vector2(TileSize*grid.size(), 0 + i*TileSize));
		column.push_back(GetWorld()->AddGameObject(cube));
	}
	this->grid.emplace(grid.size(), column);

}

Grid::Grid()
{
}


Grid::~Grid()
{
}
