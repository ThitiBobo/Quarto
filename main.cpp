// include controller
#include "SFMLGame.h"
#include "Menu.h"
#include <SFML/Graphics.hpp>
#include <iostream>

void jouer(sf::RenderWindow* window, Game* model){

    SFMLGame *controller = new SFMLGame(window,model);

    while (window->isOpen()) {
        sf::Event event;
        while (window->pollEvent(event)) {
            switch (event.type) {
                case sf::Event::Closed:
                    window->close();
                    break;

                case sf::Event::MouseButtonPressed:
                    if(controller->onClick(&event))
                        return;
                    break;

                default:
                    break;
            }
        }

        window->clear();
        controller->displayView();
        window->display();
    }
}

int main() {

    constexpr int width = 780;
    constexpr int height = 500;

    sf::RenderWindow window(sf::VideoMode(width, height), "Quarto Game",
                            sf::Style::Titlebar | sf::Style::Close);

    sf::Image icon;
    if(!icon.loadFromFile("./images/icon.png"))
        EXIT_FAILURE;

    window.setIcon(159,170,icon.getPixelsPtr());

    window.setFramerateLimit(60);
    Menu *menu = new Menu(&window);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            switch (event.type) {
                case sf::Event::Closed:
                    window.close();
                    break;

                case sf::Event::MouseButtonPressed:
                    switch(menu->onClick(&event)){
                        case 1:
                        jouer(&window,new Game(0));
                        break;
                        case 2:
                        jouer(&window,new Game(1));
                        break;
                    }
                    break;

                default:
                    break;
            }
        }
        window.clear();
        menu->displayView();
        window.display();
    }
}
