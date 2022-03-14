#include "GameManager.h"

GameManager* GameManager::instance = nullptr;

GameManager* GameManager::GetInstance()
{
	if (instance == nullptr)
	{
		instance = new GameManager();
	}
	return instance;
}

void GameManager::Run()
{
	Game game;
	//Vector mousePos(0, 0, 0);

	while (game.running())
	{
		game.update();
		game.render();
	}
}