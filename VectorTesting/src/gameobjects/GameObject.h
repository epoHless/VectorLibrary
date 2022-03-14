#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"
#include "../utilities/Utilities.h"

class GameObject
{
public:
	virtual ~GameObject(){}

	virtual void onClick() const = 0;
	virtual sf::CircleShape spawn(sf::RenderWindow& window, unsigned short rad)
	{
		sf::CircleShape circle(rad, 4);
		circle.setPosition(Utilities::Random(window.getSize().x), Utilities::Random(window.getSize().y));		
		return circle;
	};
};
