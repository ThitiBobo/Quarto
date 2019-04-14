#ifndef SFMLGAME_H
#define SFMLGAME_H
#include <SFML/Graphics.hpp>
#include "SFMLPion.h"
#include "SFMLCase.h"
#include "SFMLGrid.h"
#include "Game.h"
#include "Button.h"

class SFMLGame
{
    public:
        SFMLGame(sf::RenderWindow*,Game*);
        virtual ~SFMLGame();
        bool onClick(sf::Event *event);
        void displayView();
        void restart();

    private:
        void initcomponents();
        void colorePion(int,int,SFMLGrid*);
        void victory(int**);
        void playIA();
        sf::RenderWindow* window;
        SFMLGrid* board;
        SFMLGrid* reserve;

        Game* game;
        Button* btnRestart;
        Button* menu;
        bool joueurPlayed;


};

#endif // SFMLGAME_H
