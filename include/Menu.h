#ifndef MENU_H
#define MENU_H
#include <SFML/Graphics.hpp>
#include "Button.h"

class Menu
{
    public:
        Menu(sf::RenderWindow*);
        virtual ~Menu();
        int onClick(sf::Event *event);
        void displayView();

    private:
        void initcomponents();

        sf::RenderWindow *window;
        Button* joueur;
        Button* ordi;
        Button* quitter;

};

#endif // MENU_H
