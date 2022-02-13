#include "SFML/Graphics.hpp"
#include <iostream>
#include <sstream>
#include "VectorHelper.h"

int main() 
{
    sf::RenderWindow window(sf::VideoMode(1000, 1000), "Get Mouse Position");
    Vector mousePos(0,0,0);

    sf::Font font;
    if (!font.loadFromFile("C:/Users/kevin/Documents/VS Projects/VectorLib/Fonts/Ikkle 4.ttf"))
    {

    }

    sf::Text tx_mousePosX;
    tx_mousePosX.setFont(font);
    tx_mousePosX.setCharacterSize(10);
    tx_mousePosX.setFillColor(sf::Color::Red);
    tx_mousePosX.setPosition(sf::Vector2f(10, 10));
    sf::Text tx_mousePosY(tx_mousePosX);
    tx_mousePosY.setFillColor(sf::Color::Green);
    tx_mousePosY.setPosition(sf::Vector2f(10, 25));

    std::string xString;
    std::string yString;

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

                xString = "X: " + std::to_string(mousePos[VectorAxis::AXIS_X]);
                yString = "Y: " + std::to_string(mousePos[VectorAxis::AXIS_Y]);

                VectorConsole::print_vector(mousePos);
            }

            if (event.type == sf::Mouse::Left)
            {

            }
        }

        window.clear();
        tx_mousePosX.setString(xString);
        tx_mousePosY.setString(yString);
        window.draw(tx_mousePosX);
        window.draw(tx_mousePosY);
        window.display();
    }

    return 0;

	return 0;
}