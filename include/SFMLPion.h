#ifndef SFMLPION_H
#define SFMLPION_H
#include "TextureHandler.h"
#include <SFML/Graphics.hpp>

class SFMLPion
{
    public:
        SFMLPion(bool,bool,bool,bool,bool);
        virtual ~SFMLPion();
        void draw();
        void move(sf::Vector2f*);

        void setPosition(sf::Vector2f*);
        void setCenterPosition(sf::Vector2f*);
        void setRenderWindow(sf::RenderWindow*);

        const sf::Vector2u& getSize();
        const sf::Vector2f& getPosition();
        sf::Vector2f* getCenterPosition();

    private:
        sf::Vector2f *position;
        sf::Vector2f *centerPosition;
        sf::Texture *texture;
        sf::Sprite *sprite;
        sf::RenderWindow *window;

        sf::Vector2f* localCenterPosition();
};

#endif // SFMLPION_H
