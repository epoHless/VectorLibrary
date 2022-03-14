#pragma once
#include "SFML/Graphics.hpp"
#include "VectorHelper.h"
#include "../gameobjects/GameObject.h"
#include "../creator/BombCreator.h"
#include "../creator/TargetCreator.h"

class Game
{
public:
	//Constructor / Decostructors
	Game();
	virtual ~Game();

	//Accessors
	const bool running() const;

	//Public functions
	void pollEvents();
	void update();
	void updateEnemies();
	void render();
	void renderUI();
	void renderEnemies();
	void renderMouse();

private:
	//Variables
	//Window
	sf::RenderWindow* window;
	sf::VideoMode videoMode;
	sf::Event ev;

	//Font
	sf::Font font;

	//Text
	sf::Text tx_mousePosX;
	sf::Text tx_mousePosY;
	sf::Text tx_lives;

	//Utilities
	sf::Vector2f mousePosView;
	sf::Vector2i mousePosWindow;
	Vector mousePos;
	std::string xString;
	std::string yString;

	//Game logic
	float spawnTimer;
	float spawnTimerMax;
	int maxEnemies;
	int lives = 3;

	//Gameobjects
	std::vector<sf::CircleShape> enemies;

	//Factory
	Creator* Creator = nullptr;

	//Private functions
	//Window
	void initText(sf::Text&, sf::Color, sf::Font);
	void initFont(const char*);
	void initVariables();
	void initWindow();

	void updateMousePosition();

	//Gameobjects
	void SpawnGameobject();

	void gameOver();
};