#pragma once

#include "Game.h"

#include "CubeColumn.h"

class BlocksGame : public Game
{
public:
	float TimeElapsed = 0;

	virtual void SetupWorldSystems() override;

	virtual void SetupWorldObjects() override;

	virtual void OnWorldUpdate() override;


};

