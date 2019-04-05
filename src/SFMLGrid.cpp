#include "SFMLGrid.h"
#include <iostream>
#include <stdexcept>

int SFMLGrid::distance = 80;

void SFMLGrid::setRenderWindow(sf::RenderWindow* window){
    this->window = window;
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            cases[i][j]->setRenderWindow(window);
        }
    }
}

void SFMLGrid::setPosition(sf::Vector2f* position){
    this->position = position;
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            cases[i][j]->setPosition(new sf::Vector2f(position->x + i * distance,position->y + j * distance));
        }
    }
}

SFMLCase* SFMLGrid::getCase(int x, int y){
    return cases[x][y];
}

SFMLPion* SFMLGrid::getPion(int x, int y){
    return cases[x][y]->getPion();
}

SFMLGrid::SFMLGrid(bool soft)
{
    position = new sf::Vector2f(0,0);
    cases = new SFMLCase**[4];
    int type = 0;
    for(int i = 0; i < 4; i++){
        cases[i] = new SFMLCase*[4];
        for(int j = 0; j < 4; j++){
            type++;
            type = (type) % 2;
            cases[i][j] = new SFMLCase(type,soft);
            cases[i][j]->setPosition(new sf::Vector2f(i * distance,j * distance));
        }
        type++;
        type = (type) % 2;
    }
}

SFMLGrid::~SFMLGrid()
{
    //dtor
}

void SFMLGrid::draw(){
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            cases[i][j]->draw();
        }
    }
}

void SFMLGrid::addPion(int x,int y,SFMLPion *pion){
    if(cases[x][y]->getPion() != NULL)
        throw string("Erreur: La case contient déjà une autre instance de Pion");
    cases[x][y]->addPion(pion);
}

SFMLPion* SFMLGrid::removePion(int x,int y){
    if(cases[x][y]->getPion() == NULL)
        throw string("Erreur: La case est vide");
    return cases[x][y]->removePion();
}

void SFMLGrid::colorCase(int x, int y){
    cases[x][y]->color();
}

void SFMLGrid::discolorCase(int x, int y){
    cases[x][y]->discolor();
}

int* SFMLGrid::onClick(sf::Event* event){
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            if(cases[i][j]->onClick(event)){
                int *tab = new int[2];
                tab[0] = i;
                tab[1] = j;
                return tab;
            }
        }
    }
    return NULL;
}
