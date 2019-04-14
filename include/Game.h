#ifndef GAME_H
#define GAME_H
#include "Grid.h"
#include "Pion.h"
#include "IA.h"

class Game
{
    public:
        Game(bool);
        virtual ~Game();
        void selectPion(int,int);
        void playPion(int,int);
        bool isFinish();
        Grid* getReserve();
        Grid* getBoard();
        int* getCoordsSelected();
        int* getCoordsPlayed();
        void restart();

        bool getIA();
        int* playPionIA();
        int* selectPieceIA();

    private:
        void init();
        int* pionSelected;
        int* pionPlayed;
        Grid* board;
        Grid* reserve;
        IA* intelligence;
        bool ia;
        int tour;
};

#endif // GAME_H
