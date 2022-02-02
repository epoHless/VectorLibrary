#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode(500, 500), "Testing SFML");
    sf::RectangleShape shape(sf::Vector2f(0, 30));
    sf::RectangleShape rectangle(sf::Vector2f(0, 30));

    sf::CircleShape circle(200, 5);

    sf::String string = "Weird font choice uh";
    sf::Font font;

    if (!font.loadFromFile("resources/fonts/Little Comet Demo Version.otf"))
    {
        printf("error!");
    }

    sf::Text text(string, font, 50);
    text.setPosition(sf::Vector2f(0, window.getPosition().y / 2));
    sf::Texture texture;

    if (texture.loadFromFile("resources/texture/texture.jpg"));
    {
        shape.setTexture(&texture, false);
    }

    rectangle.setFillColor(sf::Color::Red);
    rectangle.setPosition(sf::Vector2f(shape.getSize().x, shape.getSize().y));


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
                printf("goodbye!\n");
            }


            if (event.type == sf::Event::KeyPressed)
            {
                printf("Key Pressed!\n");
            }

            if (event.type == sf::Event::Resized)
                text.setPosition(sf::Vector2f(0, window.getPosition().y / 2));

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            {
                if (event.KeyPressed)
                {
                    printf("Key Pressed!\n");
                }
            }
        }

        window.clear();

        window.draw(shape);
        window.draw(text);
        window.draw(rectangle);
        window.draw(circle);
        
        
        printf("X size: %f, Y size: %f\n", window.getView().getCenter().x, window.getView().getCenter().y);
        
        circle.setRotation(circle.getRotation() + .1);

        if (shape.getSize().x <= window.getSize().x)
        {
            shape.setSize(sf::Vector2f(shape.getSize().x + sf::Vector2f(.1, .1).x, shape.getSize().y));
            rectangle.setSize(sf::Vector2f(rectangle.getSize().x + sf::Vector2f(.1, .1).x, rectangle.getSize().y));
        }

        window.display();
    }

    return 0;
}