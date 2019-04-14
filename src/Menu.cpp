#include "Menu.h"
#include <iostream>

Menu::Menu(sf::RenderWindow* win)
{
    window = win;
    initcomponents();
}

Menu::~Menu()
{
    //dtor
}

int Menu::onClick(sf::Event *event){
    if(joueur->onClick(event))
        return 1;
    if(ordi->onClick(event))
        return 2;
    if(quitter->onClick(event))
        window->close();
}

void Menu::initcomponents(){
    joueur = new Button("P vs P");
    joueur->setRenderWindow(window);
    joueur->setPosition(new sf::Vector2f(390 - 70,0 + 140));

    ordi = new Button("P vs IA");
    ordi->setRenderWindow(window);
    ordi->setPosition(new sf::Vector2f(390 - 70,70 + 140));

    quitter = new Button("quitter");
    quitter->setRenderWindow(window);
    quitter->setPosition(new sf::Vector2f(390 - 70,140 + 140));
}

void Menu::displayView(){
    joueur->draw();
    ordi->draw();
    quitter->draw();
}
