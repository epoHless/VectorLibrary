#pragma once
#include "GameObject.h"

class Bomb : public GameObject
{
public:
	~Bomb() {};

	virtual void onClick() const override
	{
		std::cout << "Bomb" << std::endl;
	}

	virtual sf::CircleShape spawn(sf::RenderWindow& window, unsigned short rad) override
	{
		sf::CircleShape circle(rad, 3);
		circle.setPosition(Utilities::Random(window.getSize().x), Utilities::Random(window.getSize().y));
		circle.setFillColor(sf::Color::Red);
		return circle;
	}
};