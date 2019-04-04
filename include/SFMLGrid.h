#ifndef SFMLGRID_H
#define SFMLGRID_H
#include "SFMLPion.h"
#include "SFMLCase.h"
#include <SFML/Graphics.hpp>
#include <ostream>

class SFMLGrid
{
    public:
        static int distance;

        SFMLGrid();
        virtual ~SFMLGrid();
        void draw();
        void move(sf::Vector2f*);
        void addPion(int,int,SFMLPion*);
        SFMLPion* removePion(int,int);

        void setPosition(sf::Vector2f*);
        void setRenderWindow(sf::RenderWindow*);

        const sf::Vector2u& getSize();
        const sf::Vector2f& getPosition();
        SFMLPion* getPion(int,int);
        SFMLCase* getCase(int,int);

    private:
        SFMLCase*** cases;
        sf::Vector2f *position;
        sf::RenderWindow *window;
};

#endif // SFMLGRID_H
