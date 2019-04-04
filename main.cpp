#include <SFML/Graphics.hpp>
#include "SFMLPion.h"
#include "SFMLCase.h"

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

        SFMLCase *tile = new SFMLCase(1,0);
        tile->setRenderWindow(&window);
        tile->setPosition(new sf::Vector2f(50.f, 50.f));


        SFMLPion *pion = new SFMLPion(1,1,0,1,1);
        pion->setRenderWindow(&window);
        tile->addPion(pion);


        tile->setCenterPosition(new sf::Vector2f(60.f, 50.f));

        SFMLPion *pion2 = new SFMLPion(0,1,0,0,1);
        pion2->setRenderWindow(&window);
        //pion2->setCenterPosition(new sf::Vector2f(*pion->getCenterPosition()));
        //pion->move(new sf::Vector2f(10.f, 50.f));
        pion2->draw();


        tile->draw();
        pion->draw();
        window.display();


    }

    return 0;
}
