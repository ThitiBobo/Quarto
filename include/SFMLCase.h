#ifndef SFMLCASE_H
#define SFMLCASE_H
#include "TextureHandler.h"
#include "SFMLPion.h"
#include <SFML/Graphics.hpp>
#include <ostream>
using namespace std;

class SFMLCase
{
    public:
        SFMLCase(bool,bool);
        virtual ~SFMLCase();
        void draw();
        void move(sf::Vector2f*);
        void addPion(SFMLPion*);
        SFMLPion* removePion();
        void color();
        void discolor();
        bool onClick(sf::Event*);

        void setPosition(sf::Vector2f*);
        void setCenterPosition(sf::Vector2f*);
        void setRenderWindow(sf::RenderWindow*);

        const sf::Vector2u& getSize();
        const sf::Vector2f& getPosition();
        sf::Vector2f* getCenterPosition();
        SFMLPion* getPion();

    private:
        SFMLPion* pion;
        sf::Vector2f *position;
        sf::Vector2f *centerPosition;
        sf::Texture *texture;
        sf::Sprite *sprite;
        sf::RenderWindow *window;

        sf::Vector2f* localCenterPosition();
};

#endif // SFMLCASE_H
