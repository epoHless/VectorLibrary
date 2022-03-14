#pragma once
#include "GameObject.h"

class Target : public GameObject
{
public:
	~Target(){};

	virtual void onClick() const override 
	{
		std::cout << "Target" << std::endl;
	}

	virtual sf::CircleShape spawn(sf::RenderWindow& window, unsigned short rad) override
	{
		sf::CircleShape circle(rad, 20);
		circle.setPosition(Utilities::Random(window.getSize().x), Utilities::Random(window.getSize().y));
		circle.setFillColor(sf::Color::Green);
		return circle;
	}
};
