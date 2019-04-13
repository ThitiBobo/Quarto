#include "Button.h"
#include <iostream>

void Button::setPosition(sf::Vector2f* position){
    this->position = position;
    rectangle->setPosition(*position);
    sf::Vector2f* center = localCenterPosition();
    sf::Vector2f* pos = new sf::Vector2f(
            position->x + center->x - sfmltext->getLocalBounds().width / 2,
            position->y + center->y - sfmltext->getLocalBounds().height / 2 - 6); // à refaire
    sfmltext->setPosition(*pos);

}

void Button::setRenderWindow(sf::RenderWindow* window){
    this->window = window;
}

const sf::Vector2u& Button::getSize(){
    return rectangle->getTexture()->getSize();
}

const sf::Vector2f& Button::getPosition(){
    return rectangle->getPosition();
}


Button::Button(std::string text)
{
    TextureHandler::setSoftV1();
    rectangle = new sf::RectangleShape(sf::Vector2f(140.f, 50.f));
    rectangle->setFillColor(sf::Color(163, 137, 137));
    rectangle->setPosition(sf::Vector2f(0,0));


    font = new sf::Font();
    if (!font->loadFromFile("./arial.ttf")){ std::cout << "erreur";}
    sfmltext = new sf::Text();
    sfmltext->setFont(*font);
    sfmltext->setString(text);
    sfmltext->setCharacterSize(24);
    sfmltext->setPosition(sf::Vector2f(0,0));



    setPosition(new sf::Vector2f(0,0));
}

Button::~Button()
{
    delete rectangle;
    delete position;
}

void Button::move(sf::Vector2f* position){
    rectangle->move(*position);
    setPosition(new sf::Vector2f(rectangle->getPosition()));
}

void Button::draw(){
    window->draw(*rectangle);
    window->draw(*sfmltext);
}

bool Button::onClick(sf::Event* event){
    sf::Vector2f* dimension = new sf::Vector2f(rectangle->getSize());
        //vérif
    if(event->mouseButton.x >= position->x &&
        event->mouseButton.x <= position->x + dimension->x &&
        event->mouseButton.y >= position->y &&
        event->mouseButton.y <= position->y + dimension->y){
        return true;
    }else
        return false;
}

sf::Vector2f* Button::localCenterPosition(){
    int x = rectangle->getLocalBounds().width;
    int y = rectangle->getLocalBounds().height;
    return new sf::Vector2f(x / 2, y / 2);

}

