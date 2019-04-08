#ifndef BUTTON_H
#define BUTTON_H
#include <string>
#include <SFML/Graphics.hpp>
#include "TextureHandler.h"

class Button
{
    public:
        Button(std::string);
        virtual ~Button();
        void draw();
        void move(sf::Vector2f*);
        bool onClick(sf::Event*);

        void setPosition(sf::Vector2f*);
        void setRenderWindow(sf::RenderWindow*);

        const sf::Vector2u& getSize();
        const sf::Vector2f& getPosition();

    private:
        sf::Vector2f *position;
        sf::RectangleShape *rectangle;
        sf::RenderWindow *window;
        sf::Text *sfmltext;
        std::string text;
};

#endif // BUTTON_H
