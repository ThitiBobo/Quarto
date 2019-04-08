#include "SFMLGame.h"
#include <iostream>

SFMLGame::SFMLGame(sf::RenderWindow* win, Game* g)
{
    window = win;
    this->game = g;
    initcomponents();
}

SFMLGame::~SFMLGame()
{
    delete board;
    delete reserve;
}

void SFMLGame::onClick(sf::Event *event){
if (event->mouseButton.button == sf::Mouse::Left)
    {
        // récupére les coordonnées du clic
        int *coords = reserve->onClick(event);
        // sur la reserve ?
        if(coords != NULL){
            try{
                game->selectPion(coords[0],coords[1]);
                colorePion(coords[0],coords[1],reserve);
            }catch (string *e){
            }

        }
        else{
            coords = board->onClick(event);
            if(coords != NULL){
                try{
                    int * selectedPion = game->getCoordsSelected();
                    game->playPion(coords[0],coords[1]);
                    colorePion(coords[0],coords[1],board);
                    board->addPion(
                        coords[0],
                        coords[1],
                        reserve->removePion(selectedPion[0],selectedPion[1]));
                    victory(game->getBoard()->checkVictory(coords[0],coords[1]));
                }catch (string *e){
                }

            }
        }
    }
}

void SFMLGame::initcomponents(){

    //board
    board = new SFMLGrid(1);
    board->setRenderWindow(window);
    board->setPosition(new sf::Vector2f(0 + 40,0 + 40));

    //reserve
    reserve = new SFMLGrid(1);
    reserve->setRenderWindow(window);
    reserve->setPosition(new sf::Vector2f(332 + 80,0 + 40));

    //pion
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            Pion* pion = game->getReserve()->getPion(i,j);
            SFMLPion* sfmlPion = new SFMLPion(
                pion->getCouleur(),
                pion->getTaille(),
                pion->getSurface(),
                pion->getForme(),
                1);
            sfmlPion->setRenderWindow(window);
            reserve->addPion(i,j,sfmlPion);
        }
    }
}

void SFMLGame::displayView(){
    board->draw();
    reserve->draw();
}

void SFMLGame::colorePion(int x, int y, SFMLGrid* grid){
    grid->discolorAllCase();
    grid->colorCase(x,y);
}

void SFMLGame::victory(int** patern){
    if(patern == NULL)
        return;
    board->discolorAllCase();
    for(int i = 0; i < 4; i++){
        board->colorCase(patern[i][0],patern[i][1]);
    }
}


