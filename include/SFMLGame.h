#ifndef SFMLGAME_H
#define SFMLGAME_H
#include <SFML/Graphics.hpp>
#include "SFMLPion.h"
#include "SFMLCase.h"
#include "SFMLGrid.h"

class SFMLGame
{
    public:
        SFMLGame();
        virtual ~SFMLGame();
        void lunch();

    private:
        void initcomponents();
        sf::RenderWindow* window;
        SFMLGrid* board;
        SFMLGrid* reserve;

        //a revoir
        int* currentCoords;
        int* reserveCoords;
        int* boardCoords;
};

#endif // SFMLGAME_H
