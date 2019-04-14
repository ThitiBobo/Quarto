#include "Game.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>

Game::Game(bool computer)
{
    board = new Grid();
    reserve = new Grid();
    pionPlayed = NULL;
    pionSelected = NULL;
    init();
    ia = computer;
    tour = 0;
    if(ia)
        intelligence = new IA(1);
}

Game::~Game()
{
    delete board;
    delete reserve;
    delete pionPlayed;
    delete pionSelected;
}

void Game::playPion(int x, int y){
    if(pionSelected == NULL)
        throw new string("Erreur: Aucune case séléctioné");
    if(board->getPion(x,y) != NULL)
        throw new string("Erreur: la case n'est pas vide");
    pionPlayed = new int[2]{x,y};
    board->addPion(pionPlayed[0],pionPlayed[1],reserve->removePion(pionSelected[0],pionSelected[1]));
    pionSelected = NULL;
    tour++;
}

void Game::selectPion(int x, int y){
    if(reserve->getPion(x,y) == NULL){
        throw new string("Erreur: la case est vide");
    }
    pionSelected = new int[2]{x,y};
}

bool Game::isFinish(){
    if(pionPlayed == NULL)
        return false;
    return board->checkVictory(pionPlayed[0],pionPlayed[1]) || tour >= 16;
}

Grid* Game::getBoard(){
    return board;
}

Grid* Game::getReserve(){
    return reserve;
}

int* Game::getCoordsSelected(){
    return pionSelected;
}

int* Game::getCoordsPlayed(){
    return pionPlayed;
}

void Game::init(){
    int number[16][4] ={
        {0,0,0,0},
        {0,0,0,1},
        {0,0,1,0},
        {0,0,1,1},
        {0,1,0,0},
        {0,1,0,1},
        {0,1,1,0},
        {0,1,1,1},
        {1,0,0,0},
        {1,0,0,1},
        {1,0,1,0},
        {1,0,1,1},
        {1,1,0,0},
        {1,1,0,1},
        {1,1,1,0},
        {1,1,1,1}
         };

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            Pion* pion = new Pion(
                (Pion::Couleur)number[i * 4 + j][0],
                (Pion::Taille)number[i * 4 + j][3],
                (Pion::Forme)number[i * 4 + j][2],
                (Pion::Surface)number[i * 4 + j][1]);
            reserve->addPion(i,j,pion);
        }
    }
}

void Game::restart(){
    delete board;
    delete reserve;
    board = new Grid();
    reserve = new Grid();
    pionPlayed = NULL;
    pionSelected = NULL;
    tour = 0;
    init();
}

bool Game::getIA(){return ia;}

int* Game::playPionIA(){
    if(pionSelected == NULL)
        throw new string("Erreur: Aucune case séléctioné");

    intelligence->play(board,reserve,pionSelected[0],pionSelected[1]);


    int x = intelligence->getPlay()[0];
    int y = intelligence->getPlay()[1];

    pionPlayed = new int[2]{x,y};
    board->addPion(pionPlayed[0],pionPlayed[1],reserve->removePion(pionSelected[0],pionSelected[1]));
    pionSelected = NULL;
    tour++;
    return new int[2]{x,y};
}

int* Game::selectPieceIA(){

    int x;
    int y;
    do{
        x = rand()%4;
        y = rand()%4;
    }while(reserve->getPion(x,y) == NULL);
    //int x = intelligence->getSelect()[0];
    //int y = intelligence->getSelect()[1];
    pionSelected = new int[2]{x,y};
    return new int[2]{x,y};
}

