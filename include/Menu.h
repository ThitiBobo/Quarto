#ifndef MENU_H
#define MENU_H
#include <SFML/Graphics.hpp>
#include "Button.h"

class Menu
{
    public:
        Menu(sf::RenderWindow*);
        virtual ~Menu();
        bool onClick(sf::Event *event);
        void displayView();

    private:
        void initcomponents();

        sf::RenderWindow *window;
        Button* start;

};

#endif // MENU_H
