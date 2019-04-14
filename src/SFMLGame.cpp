#include "SFMLGame.h"
#include <iostream>

SFMLGame::SFMLGame(sf::RenderWindow* win, Game* g)
{
    window = win;
    this->game = g;
    initcomponents();
    joueurPlayed = false;
}

SFMLGame::~SFMLGame()
{
    delete board;
    delete reserve;
}

bool SFMLGame::onClick(sf::Event *event){
if (event->mouseButton.button == sf::Mouse::Left)
    {
        // récupére les coordonnées du clic
        int *coords = reserve->onClick(event);
        // sur la reserve ?
        if(coords != NULL){
            try{
                game->selectPion(coords[0],coords[1]);
                colorePion(coords[0],coords[1],reserve);
                joueurPlayed = true;
            }catch (string *e){
            }

        }
        else{
            coords = board->onClick(event);
            if(coords != NULL){
                if(!game->isFinish()){
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

        if(game->getIA()){
            if(joueurPlayed){
                if(!game->isFinish())
                    playIA();
            }
        }



        if(btnRestart->onClick(event)){
            restart();
        }

        if(menu->onClick(event)){
            return true;
        }
        return false;
    }
}

void SFMLGame::initcomponents(){

    //board
    board = new SFMLGrid(1);
    board->setRenderWindow(window);
    board->setPosition(new sf::Vector2f(0 + 40,100 + 40));

    //reserve
    reserve = new SFMLGrid(1);
    reserve->setRenderWindow(window);
    reserve->setPosition(new sf::Vector2f(332 + 80,100 + 40));

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

    //buttons
    btnRestart = new Button("Restart");
    btnRestart->setRenderWindow(window);
    btnRestart->setPosition(new sf::Vector2f(0 + 590,0 + 40));

    menu = new Button("Menu");
    menu->setRenderWindow(window);
    menu->setPosition(new sf::Vector2f(0 + 40,0 + 40));
}

void SFMLGame::displayView(){
    board->draw();
    reserve->draw();
    btnRestart->draw();
    menu->draw();
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

void SFMLGame::restart(){
    game->restart();
    delete board;
    delete reserve;
    delete btnRestart;
    delete menu;
    initcomponents();
}

void SFMLGame::playIA(){
    int* selectedPion = game->getCoordsSelected();
    int* playedpion = game->playPionIA();
    colorePion(playedpion[0],playedpion[1],board);
    board->addPion(
        playedpion[0],
        playedpion[1],
        reserve->removePion(selectedPion[0],selectedPion[1]));
    victory(game->getBoard()->checkVictory(playedpion[0],playedpion[1]));

    if(game->isFinish())
        return;
    int* coords = game->selectPieceIA();
    colorePion(coords[0],coords[1],reserve);
    joueurPlayed = false;
}




