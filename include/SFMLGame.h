#ifndef SFMLGAME_H
#define SFMLGAME_H
#include <SFML/Graphics.hpp>
#include "SFMLPion.h"
#include "SFMLCase.h"
#include "SFMLGrid.h"
#include "Game.h"

class SFMLGame
{
    public:
        SFMLGame(sf::RenderWindow*,Game*);
        virtual ~SFMLGame();
        void onClick(sf::Event *event);
        void displayView();

    private:
        void initcomponents();
        void colorePion(int,int,SFMLGrid*);
        void victory(int**);
        sf::RenderWindow* window;
        SFMLGrid* board;
        SFMLGrid* reserve;

        Game* game;
};

#endif // SFMLGAME_H
