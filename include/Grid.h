#ifndef GRID_H
#define GRID_H
#include <ostream>
#include "Case.h"
#include "Pion.h"
using namespace std;

class Grid
{
    public:
        Grid();
        virtual ~Grid();
        const int defaultSize = 4;
        void addPion(int, int, Pion*);
        Pion* getPion(int, int);
        Pion* removePion(int,int);
        int** checkVictory(int,int);
        bool checkPatern(int**);

        friend std::ostream& operator<<(std::ostream&, const Grid&);

    private:
        Case grid[4][4];

};

#endif // GRID_H
