#include "SFMLGame.h"

SFMLGame::SFMLGame()
{
    window  = new sf::RenderWindow(sf::VideoMode(790, 410), "Quarto Game");
    initcomponents();
}

SFMLGame::~SFMLGame()
{
    //dtor
}

void SFMLGame::lunch(){
    while (window->isOpen())
    {
        sf::Event event;
        while (window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window->close();
        }
        window->clear();
        board->draw();
        reserve->draw();
        window->display();
    }
}

void SFMLGame::initcomponents(){

    //board
    board = new SFMLGrid();
    board->setRenderWindow(window);
    board->setPosition(new sf::Vector2f(0 + 40,0 + 40));

    //reserve
    reserve = new SFMLGrid();
    reserve->setRenderWindow(window);
    reserve->setPosition(new sf::Vector2f(332 + 80,0 + 40));
}


