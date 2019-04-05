#include "SFMLCase.h"
#include <stdexcept>

void SFMLCase::setPosition(sf::Vector2f* position){
    this->position = position;
    sf::Vector2f* centerCoords = localCenterPosition();
    this->centerPosition = new sf::Vector2f(
        position->x + centerCoords->x,
        position->y + centerCoords->y
        );
    sprite->setPosition(*position);
    if(pion != NULL)
        pion->setCenterPosition(centerPosition);
}

void SFMLCase::setCenterPosition(sf::Vector2f* position){
    this->centerPosition = position;
    sf::Vector2f* centerPosition = localCenterPosition();
    this->position = new sf::Vector2f(
        position->x - centerPosition->x,
        position->y - centerPosition->y
        );
    sprite->setPosition(*this->position);
    pion->setCenterPosition(this->centerPosition);
}

void SFMLCase::setRenderWindow(sf::RenderWindow* window){
    this->window = window;
}

const sf::Vector2u& SFMLCase::getSize(){
    return sprite->getTexture()->getSize();
}

const sf::Vector2f& SFMLCase::getPosition(){
    return sprite->getPosition();
}

// marche pas
sf::Vector2f* SFMLCase::getCenterPosition(){
    return this->centerPosition;
}

SFMLPion* SFMLCase::getPion(){
    return pion;
}

SFMLCase::SFMLCase(bool type, bool soft)
{
    pion = NULL;
    !soft ? TextureHandler::setSoftV1() : TextureHandler::setSoftV2();
    if(type)
        texture = TextureHandler::getTextureTileLigth();
    else
        texture = TextureHandler::getTextureTileDark();
    sprite = new sf::Sprite(*texture);
    texture->setSmooth(true);
    setPosition(new sf::Vector2f(0,0));
}

SFMLCase::~SFMLCase()
{
    delete pion;
    delete sprite;
    delete texture;
    delete position;
    delete centerPosition;
    delete window;
}

void SFMLCase::move(sf::Vector2f* position){
    sprite->move(*position);
    setPosition(new sf::Vector2f(sprite->getPosition()));
    pion->setCenterPosition(this->centerPosition);
}

void SFMLCase::draw(){
    this->window->draw(*sprite);
    if(pion != NULL)
        this->pion->draw();
}

void SFMLCase::addPion(SFMLPion* pion){
    if (this->pion != NULL)
        throw string("Erreur: La case contient déjà une autre instance de Pion");
    this->pion = pion;
    pion->setCenterPosition(this->centerPosition);
}

SFMLPion* SFMLCase::removePion(){
    if (this->pion == NULL)
        throw string("Erreur: La case est vide");
    SFMLPion *pion = this->pion;
    this->pion = NULL;
    return pion;
}

sf::Vector2f* SFMLCase::localCenterPosition(){
    int x = texture->getSize().x;
    int y = texture->getSize().y;
    if(x > y)
        return new sf::Vector2f(y / 2, y / 2);
    else
        return new sf::Vector2f(x / 2, x / 2);
}

void SFMLCase::color(){
    sprite->setColor(sf::Color(255, 255, 0));
}

void SFMLCase::discolor(){
    sprite->setColor(sf::Color(255, 255, 255));
}

bool SFMLCase::onClick(sf::Event* event){
    sf::Vector2f* size = new sf::Vector2f(sprite->getTexture()->getSize());
    // calcule pour eviter de cliquer sur le relief
    if(size->x > size->y)
        size->y = size->x;
    else
        size->x = size->y;

    //vérif
    if(event->mouseButton.x >= position->x &&
        event->mouseButton.x <= position->x + size->x &&
        event->mouseButton.y >= position->y &&
        event->mouseButton.y <= position->y + size->y){
        return true;
    }else
        return false;


}
