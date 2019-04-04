#include <SFML/Graphics.hpp>
#include "SFMLPion.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();

        sf::Sprite tile;
        TextureHandler::setSoftV1();
        tile.setTexture(*TextureHandler::getTextureTileDark());
        tile.setPosition(sf::Vector2f(50.f, 50.f));
        window.draw(tile);

        SFMLPion *pion = new SFMLPion(1,1,0,1,1);
        pion->setRenderWindow(&window);
        pion->setCenterPosition(new sf::Vector2f(90.f, 90.f));
        //pion->move(new sf::Vector2f(10.f, 50.f));
        //pion->draw();

        SFMLPion *pion2 = new SFMLPion(0,1,0,0,1);
        pion2->setRenderWindow(&window);
        pion2->setCenterPosition(new sf::Vector2f(pion->getPosition()));
        //pion->move(new sf::Vector2f(10.f, 50.f));
        pion2->draw();

        window.display();


    }

    return 0;
}
