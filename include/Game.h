#ifndef GAME_H
#define GAME_H
#include "Grid.h"
#include "Pion.h"

class Game
{
    public:
        Game();
        virtual ~Game();
        void selectPion(int,int);
        void playPion(int,int);
        bool isFinish();
        Grid* getReserve();
        Grid* getBoard();
        int* getCoordsSelected();
        int* getCoordsPlayed();
        void restart();

    private:
        void init();
        int* pionSelected;
        int* pionPlayed;
        Grid* board;
        Grid* reserve;



};

#endif // GAME_H
