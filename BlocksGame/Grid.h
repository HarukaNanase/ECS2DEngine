#pragma once
#include "GameObject.h"
#include <map>
#include "Cube.h"

class Grid : public GameObject	
{
public:
	int GridHeight = 10;
	int GridWidth = 16;
	int MinimumCombo;
	int TileSize = 16;
	Texture* TexForCubes;
	
	std::map<unsigned int, std::vector<Cube>> grid;

	void SpawnColumn();
	

	Grid(Texture* _TexForCubes) : TexForCubes(_TexForCubes){};

	Grid();
	~Grid();
};

