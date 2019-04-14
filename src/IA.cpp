#include "IA.h"
#include <iostream>

IA::IA(int dificult){
    dificult = dificult;
    profondeur = 2;
    playCoords = new int[2]{0,0};
    selectCoords = new int[2]{0,0};
}

IA::~IA()
{
    //dtor
}

void IA::play(Grid* board, Grid* reserve, int x, int y){
    int rdomx;
    int rdomy;
    do{
        rdomx = rand()%4;
        rdomy = rand()%4;
    }while(board->getPion(rdomx,rdomy) != NULL);

    do{
        selectCoords[0] = rand()%4;
        selectCoords[1] = rand()%4;
    }while(reserve->getPion(selectCoords[0],selectCoords[1]) == NULL);

    playCoords[0] = rdomx;
    playCoords[1] = rdomy;
    decisionMinMax(board,reserve,x,y);
    std::cout<<playCoords[0]<<":"<<playCoords[1] << "   " <<selectCoords[0]<<":"<<selectCoords[1] << std::endl;

}

int IA::calcul(Grid* board, Grid* reserve, int x, int y, bool myTurn){
    int score = 0;
    if(board->checkVictory(x,y) != NULL)
        myTurn ? score = 100 : score = -100;
    return score;
}

void IA::decisionMinMax(Grid* board, Grid* reserve, int reserveX, int reserveY){
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
                    playCoords[0] = boardX;
                    playCoords[1] = boardY;
                }
            }
        }
    }
}

int IA::valeurMinMax(Grid* board, Grid* reserve,bool myTurn, int x, int y, int profond){
    if(profond <= 0){
        return calcul(board,reserve,x,y,!myTurn);
    }
    if(board->checkVictory(x,y) != NULL){
        if(!myTurn)
            return 100;
        return -100;
    }
    int val = 0;

    for(int boardX = 0; boardX < 4; boardX++){
        for(int boardY = 0; boardY < 4; boardY++){
            // si la case est vide
            if(board->getPion(boardX,boardY) == NULL){
                for(int reserveX = 0; reserveX < 4; reserveX++){
                    for(int reserveY = 0; reserveY < 4; reserveY++){
                        if(reserve->getPion(reserveX,reserveY) != NULL){

                            // ajout virtuel de la pièce
                            board->addPion(boardX,boardY,reserve->removePion(reserveX,reserveY));
                            int v = valeurMinMax(board,reserve,!myTurn,boardX,boardY,profond - 1);
                            reserve->addPion(reserveX,reserveY,board->removePion(boardX,boardY));
                            // fin virtualisation

                            // si c'est mon tour, je maximise
                            // sinon je minimise
                            if(v > val){
                                val = v;
                                playCoords[0] = boardX;
                                playCoords[1] = boardY;
                                selectCoords[0] = reserveX;
                                selectCoords[1] = reserveY;
                            }
                        }
                    }
                }
            }
        }
    }
    return val;

}

int* IA::getPlay(){
    return playCoords;
}

int* IA::getSelect(){
    return selectCoords;
}
