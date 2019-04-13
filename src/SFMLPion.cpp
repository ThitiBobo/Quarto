#include "SFMLPion.h"

// Modifie la position de la pièce
void SFMLPion::setPosition(sf::Vector2f* position){
    this->position = position;
    sf::Vector2f* centerPosition = localCenterPosition();
    this->centerPosition = new sf::Vector2f(
        position->x + centerPosition->x,
        position->y + centerPosition->y
        );
    sprite->setPosition(*position);
}

// Modifie la position de la position par rapport à son centre
void SFMLPion::setCenterPosition(sf::Vector2f* centerPosition){
    this->centerPosition = centerPosition;
    this->position = new sf::Vector2f(*centerPosition);
    sf::Vector2f* centerCoords = localCenterPosition();
    this->position->x -= centerCoords->x;
    this->position->y -= centerCoords->y;
    sprite->setPosition(*position);
}

// Paramètre l'instance de RenderWindow
void SFMLPion::setRenderWindow(sf::RenderWindow* window){
    this->window = window;
}

// Obtient la taille de la pièce
const sf::Vector2u& SFMLPion::getSize(){
    return sprite->getTexture()->getSize();
}

// Obtient la position de la pièce
const sf::Vector2f& SFMLPion::getPosition(){
    return sprite->getPosition();
}

// marche pas
sf::Vector2f* SFMLPion::getCenterPosition(){
    return this->centerPosition;
}

// construit une instance de SFMLPion avec ses attributs et son style
SFMLPion::SFMLPion(bool color,bool dimension,bool spec,bool shape,bool soft)
{
    !soft ? TextureHandler::setSoftV1() : TextureHandler::setSoftV2();
    texture = TextureHandler::getTexturePiece(color,dimension,spec,shape);
    sprite = new sf::Sprite(*texture);
    texture->setSmooth(true);
    setPosition(new sf::Vector2f(0,0));
}

// dtor
SFMLPion::~SFMLPion()
{
    delete sprite;
    delete texture;
    delete position;
    delete centerPosition;
}

// Déplace la pièce par rapport à sa position actuelle
void SFMLPion::move(sf::Vector2f* position){
    sprite->move(*position);
    setPosition(new sf::Vector2f(sprite->getPosition()));
}

// Dessine la pièce
void SFMLPion::draw(){
    this->window->draw(*sprite);
}

// Calcule la position central de la pièce de façon
// relatif à la pièce
sf::Vector2f* SFMLPion::localCenterPosition(){
    int x = texture->getSize().x;
    int y = texture->getSize().y;
    int diff;
    x > y ? diff = x - y : diff = y - x;
    if(x > y)
        return new sf::Vector2f(y / 2 + diff, y / 2);
    else
        return new sf::Vector2f(x / 2, x / 2 + diff);
}


