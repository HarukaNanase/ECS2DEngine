#include "Game.h"

void Game::Init()
{
	this->TheEngine.InitEngine();
	SetupWorldSystems();
	SetupWorldObjects();

}

void Game::Run()
{
	Init();
	while (GameWorld.IsRunning())
		GameWorld.Update(GameWorld.GetDeltaTime());
}
