#include "SFML/Graphics.hpp"
#include <iostream>
#include "VectorHelper.h"

int main() 
{
    sf::RenderWindow window(sf::VideoMode(1000, 1000), "Get Mouse Position");
    Vector mousePos(0,0,0);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::MouseMoved)
            {
                mousePos.x = sf::Mouse::getPosition().x - window.getPosition().x;
                mousePos.y = sf::Mouse::getPosition().y - window.getPosition().y;
            }
        }
        VectorConsole::print_vector(mousePos);
        window.clear();
        window.display();
    }

    return 0;

	return 0;
}