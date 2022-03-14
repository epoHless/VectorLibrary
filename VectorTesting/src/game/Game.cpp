#pragma once
#include "Game.h"
#include <iomanip>

Game::Game()
{
	this->initVariables();
	this->initWindow();
}

Game::~Game()
{
	delete this->window;
}

const bool Game::running() const
{
	return this->window->isOpen();
}

void Game::pollEvents()
{
	while (this->window->pollEvent(this->ev))
	{
        switch (this->ev.type)
        {

        case sf::Event::Closed:
            this->window->close();
            break;

        case sf::Event::MouseMoved:
            mousePos.x = sf::Mouse::getPosition().x - this->window->getPosition().x;
            mousePos.y = sf::Mouse::getPosition().y - this->window->getPosition().y;

            xString = "X: " + std::to_string(mousePos[VectorAxis::AXIS_X]);
            yString = "Y: " + std::to_string(mousePos[VectorAxis::AXIS_Y]);

            //VectorConsole::print_vector(mousePos);
            break;
        case sf::Event::KeyPressed:
            if (this->ev.key.code == sf::Keyboard::Escape)
                this->window->close();
            break;
        default:
            break;
        }
	}
}

#pragma region Updates

void Game::update()
{
	this->pollEvents();
    this->updateMousePosition();
    this->updateEnemies();
}

void Game::updateEnemies()
{
    if (this->enemies.size() < this->maxEnemies)
    {
        if (this->spawnTimer >= this->spawnTimerMax) 
        {
            this->SpawnGameobject();
            this->spawnTimer = 0.f;    
        }
        else
            this->spawnTimer += 6.f;
    }
    
}

void Game::updateMousePosition()
{
    this->mousePosWindow = sf::Mouse::getPosition(*this->window);
    this->mousePosView = this->window->mapPixelToCoords(this->mousePosWindow);
}

#pragma endregion

#pragma region Renders

void Game::render()
{
    this->window->clear();
 
    this->renderUI();
    //this->renderMouse();
    this->renderEnemies();

    this->window->display();
}

void Game::renderUI()
{
    this->window->draw(tx_lives);
    this->window->draw(tx_clicks);
}

void Game::renderEnemies()
{
    for (int i = 0; i < this->enemies.size(); i++)
    {
        this->window->draw(this->enemies[i]);

        //Check if clicked on
        
        /*if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            this->clicks++;

            if (this->enemies[i].getGlobalBounds().contains(this->mousePosView))
            {
                if (enemies[i].getPointCount() < 10 )
                {
                    this->lives--;
                    tx_lives.setString("Lives: " + std::to_string(this->lives));
                }
                else
                {
                    this->targetClicks++;
                }
                this->enemies.erase(this->enemies.begin() + i);
                break;
            }

            this->tx_clicks.setString("Accuracy: " + std::to_string((this->targetClicks / this->clicks) * 100));

            std::cout << clicks << " , " << targetClicks << std::endl;
        }*/

        enemies[i].setScale(enemies[i].getScale().x - 0.003, enemies[i].getScale().y - 0.003);

        if (enemies[i].getScale().x < 0)
        {
            this->enemies.erase(this->enemies.begin() + i);
        }
    }

    
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        if (!this->mouseHeld)
        {
            this->mouseHeld = true;
            bool deleted = false;
            this->clicks++;

            for (size_t i = 0; i < this->enemies.size() && deleted == false; i++)
            {
                if (this->enemies[i].getGlobalBounds().contains(this->mousePosView))
                {
                    if (enemies[i].getPointCount() < 10)
                    {
                        this->lives--;
                        tx_lives.setString("Lives: " + std::to_string(this->lives));
                    }
                    else
                        this->targetClicks++;


                    deleted = true;
                    this->enemies.erase(this->enemies.begin() + i);
                    break;
                }
            }

            this->tx_clicks.setString("Accuracy: " + std::to_string(static_cast<int>((this->targetClicks / this->clicks) * 100)));
        }
    }
    else this->mouseHeld = false;
    
}

void Game::renderMouse()
{
    tx_mousePosX.setString(xString);
    tx_mousePosY.setString(yString);
    this->window->draw(tx_mousePosX);
    this->window->draw(tx_mousePosY);
}

#pragma endregion

#pragma region Inits

void Game::initVariables()
{
	this->window = nullptr;
    
    initFont("C:\\Users\\kevin\\Documents\\Programming\\Visual Studio\\VS Projects\\VectorLib\\Fonts\\Ikkle 4.ttf");

    initText(this->tx_mousePosX, sf::Color::Red, this->font);
    this->tx_mousePosX.setPosition(sf::Vector2f(10, 10));

    initText(this->tx_mousePosY, sf::Color::Green, this->font);
    this->tx_mousePosY.setPosition(sf::Vector2f(10, 25));

    initText(this->tx_lives, sf::Color::Yellow, this->font);
    this->tx_lives.setPosition(sf::Vector2f(10, 10));

    initText(this->tx_clicks, sf::Color::Yellow, this->font);
    this->tx_clicks.setPosition(sf::Vector2f(10, 25));

    this->tx_lives.setString("Lives: " + std::to_string(this->lives));
    this->tx_clicks.setString("Accuracy: " + std::to_string(static_cast<int>((this->targetClicks / this->clicks) * 100)));
    

    this->spawnTimerMax = 1000.f;
    this->spawnTimer = this->spawnTimerMax;
    this->maxEnemies = 10;
    this->mouseHeld = false;
}

void Game::initWindow()
{
	this->videoMode.height = 1000;
	this->videoMode.width = 1000;
	this->window = new sf::RenderWindow(this->videoMode, "Get Mouse Position", sf::Style::Close | sf::Style::Close);
    this->window->setFramerateLimit(144);
}

void Game::initText(sf::Text& tx, sf::Color cl, sf::Font font)
{
    tx.setFont(this->font);
    tx.setCharacterSize(10);
    tx.setFillColor(cl);
}

void Game::initFont(const char* path)
{
    if (!this->font.loadFromFile(path))
    {
        std::cout << "Couldn't load the desired font" << std::endl;
    }
}

#pragma endregion

void Game::SpawnGameobject()
{
    int rand = Utilities::Random(100);

    if (rand > 50)
    {
        this->Creator = new BombCreator();
        this->enemies.push_back(this->Creator->FactoryMethod()->spawn(*this->window, 20));
    }
    else
    {
        this->Creator = new TargetCreator();
        this->enemies.push_back(this->Creator->FactoryMethod()->spawn(*this->window, 20));
    }    
}


