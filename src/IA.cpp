#include "IA.h"
#include <iostream>

IA::IA(int dificult){
    dificult = dificult;
    profondeur = 1;
    playCoords = new int[2]{0,0};
}

IA::~IA()
{
    //dtor
}

void IA::play(Grid* board, Grid* reserve, int x, int y){
    int* coords = decisionMinMax(board,reserve,x,y);
    playCoords[0] = coords[0];
    playCoords[1] = coords[1];
}

int IA::calcul(Grid* board, Grid* reserve, int x, int y){
    if(board->checkVictory(x,y) != NULL)
        return 1;
    return 0;
}

int* IA::decisionMinMax(Grid* board, Grid* reserve, int reserveX, int reserveY){
    int x;
    int y;
    do{
        x = rand()%4;
        y = rand()%4;
    }while(board->getPion(x,y) != NULL);

    int* coup = new int[2]{x,y};
    int val = 0;
    // pour toutes les cases du plateau
    for(int boardX = 0; boardX < 4; boardX++){
        for(int boardY = 0; boardY < 4; boardY++){
            // si la case est vide
            if(board->getPion(boardX,boardY) == NULL){
                // ajout virtuel de la pièce
                board->addPion(boardX,boardY,reserve->removePion(reserveX,reserveY));
                int v = valeurMinMax(board,reserve,false,boardX,boardY,profondeur - 1);
                reserve->addPion(reserveX,reserveY,board->removePion(boardX,boardY));
                // fin virtualisation
                if(v > val){
                    val = v;
                    coup[0] = boardX;
                    coup[1] = boardY;
                }
            }
        }
    }
    return coup;
}

int IA::valeurMinMax(Grid* board, Grid* reserve,bool myTurn, int x, int y, int profond){
    if(profond <= 0){
        return calcul(board,reserve,x,y);
    }
}

int* IA::getPlay(){
    return playCoords;
}

int* IA::getSelect(){
    return selectCoords;
}
