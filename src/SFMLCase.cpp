#include "SFMLCase.h"
#include <stdexcept>

// Modifie la position
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

// Modifie la position central de le case
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

// Configure l'instance de RenderWindow pour l'affichage
void SFMLCase::setRenderWindow(sf::RenderWindow* window){
    this->window = window;
}

// Obtient la taille de la case
const sf::Vector2u& SFMLCase::getSize(){
    return sprite->getTexture()->getSize();
}

// Obtient la position de la case
const sf::Vector2f& SFMLCase::getPosition(){
    return sprite->getPosition();
}

// marche pas
sf::Vector2f* SFMLCase::getCenterPosition(){
    return this->centerPosition;
}

// Obtient le pion de la case
SFMLPion* SFMLCase::getPion(){
    return pion;
}

// contruit uns instance de case avec sa couleur et son style
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

// dtor
SFMLCase::~SFMLCase()
{
    delete pion;
    delete sprite;
    delete texture;
    delete position;
    delete centerPosition;
}

// déplace la case par rapport à sa position actuelle
void SFMLCase::move(sf::Vector2f* position){
    sprite->move(*position);
    setPosition(new sf::Vector2f(sprite->getPosition()));
    pion->setCenterPosition(this->centerPosition);
}

// Dessine la case
void SFMLCase::draw(){
    this->window->draw(*sprite);
    if(pion != NULL)
        this->pion->draw();
}

// Ajoute une pion à la case
void SFMLCase::addPion(SFMLPion* pion){
    //if (this->pion != NULL)
    //    throw string("Erreur: La case contient déjà une autre instance de Pion");
    this->pion = pion;
    pion->setCenterPosition(this->centerPosition);
}

// Enlève le pion de la case
SFMLPion* SFMLCase::removePion(){
    //if (this->pion == NULL)
    //    throw string("Erreur: La case est vide");
    SFMLPion *pion = this->pion;
    this->pion = NULL;
    return pion;
}

// calcule la position central de la case
sf::Vector2f* SFMLCase::localCenterPosition(){
    int x = texture->getSize().x;
    int y = texture->getSize().y;
    if(x > y)
        return new sf::Vector2f(y / 2, y / 2);
    else
        return new sf::Vector2f(x / 2, x / 2);
}

// Clorie la case
void SFMLCase::color(){
    sprite->setColor(sf::Color(255, 255, 0));
}

// Décolorie la case
void SFMLCase::discolor(){
    sprite->setColor(sf::Color(255, 255, 255));
}

// Vérifie si la case a été cliquer
bool SFMLCase::onClick(sf::Event* event){
    sf::Vector2f* size = new sf::Vector2f(sprite->getTexture()->getSize());
    int diff;
    // calcule pour eviter de cliquer sur le relief
    if(size->x > size->y)
        size->x = size->y;
    else
        size->y = size->x;

    //vérif
    if(event->mouseButton.x >= position->x &&
        event->mouseButton.x <= position->x + size->x &&
        event->mouseButton.y >= position->y &&
        event->mouseButton.y <= position->y + size->y){
        return true;
    }else
        return false;
}
