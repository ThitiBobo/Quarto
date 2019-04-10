#include "Button.h"
#include <iostream>

void Button::setPosition(sf::Vector2f* position){
    this->position = position;
    rectangle->setPosition(*position);
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
    rectangle = new sf::RectangleShape(sf::Vector2f(120.f, 50.f));
    rectangle->setFillColor(sf::Color(163, 137, 137));
    rectangle->setPosition(sf::Vector2f(0,0));

    sf::Font font;
    if (!font.loadFromFile("./arial.ttf")){ std::cout << "erreur";}
    sfmltext = new sf::Text();
    sfmltext->setFont(font);
    sfmltext->setString("text");
    sfmltext->setCharacterSize(24);
    sfmltext->setPosition(sf::Vector2f(0,0));
    sfmltext->setColor(sf::Color::Red);



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
    std::cout << sfmltext << std::endl;
    //window->draw(*sfmltext);
}

bool Button::onClick(sf::Event* event){
    sf::Vector2f* size = new sf::Vector2f(rectangle->getTexture()->getSize());
        //vérif
    if(event->mouseButton.x >= position->x &&
        event->mouseButton.x <= position->x + size->x &&
        event->mouseButton.y >= position->y &&
        event->mouseButton.y <= position->y + size->y){
        return true;
    }else
        return false;
}

