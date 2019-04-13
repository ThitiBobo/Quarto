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

bool Menu::onClick(sf::Event *event){
    return start->onClick(event);
}

void Menu::initcomponents(){
    start = new Button("Start");
    start->setRenderWindow(window);
    start->setPosition(new sf::Vector2f(50,50));
}

void Menu::displayView(){
    std::cout << "draw" << std::endl;
    start->draw();
}
