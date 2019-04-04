#ifndef SFMLGRID_H
#define SFMLGRID_H
#include "SFMLPion.h"
#include "SFMLCase.h"
#include <SFML/Graphics.hpp>
#include <vector>

class SFMLGrid
{
    public:
        SFMLGrid(int);
        virtual ~SFMLGrid();
        void draw();
        void move(sf::Vector2f*);
        void addPion(int,int,SFMLPion*);
        SFMLPion* removePion(int,int);

        void setPosition(sf::Vector2f*);
        void setCenterPosition(sf::Vector2f*);
        void setRenderWindow(sf::RenderWindow*);

        const sf::Vector2u& getSize();
        const sf::Vector2f& getPosition();
        sf::Vector2f* getCenterPosition();
        SFMLPion* getPion(int,int);
        SFMLCase* getCase(int,int);

    private:
        int size;
        SFMLCase[4,4] *Cases;
        sf::Vector2f *position;
        sf::Vector2f *centerPosition;
        sf::RenderWindow *window;

        sf::Vector2f* localCenterPosition();
};

#endif // SFMLGRID_H
