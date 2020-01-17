#pragma once

#include "Game.h"


class BlocksGame : public Game
{
public:
	virtual void SetupWorldSystems() override;

	virtual void SetupWorldObjects() override;

	virtual void OnWorldUpdate() override;


};

