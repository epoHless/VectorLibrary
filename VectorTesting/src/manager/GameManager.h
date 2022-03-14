#ifndef GM_INCLUDES
#define GM_INCLUDES

#include <sstream>
#include "../game/Game.h"

class GameManager
{
protected:

	GameManager() {}
	static GameManager* instance;

public:
	GameManager(GameManager& other) = delete;
	void operator=(const GameManager&) = delete;
	static GameManager* GetInstance();

	static void Run();
};


#endif GM_INCLUDES