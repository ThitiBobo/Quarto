#include "Grid.h"

Grid::Grid()
{}

Grid::~Grid()
{
    //dtor
}

void Grid::addPion(int x, int y, Pion* pion){
    grid[x][y].addPion(pion);
}

Pion* Grid::getPion(int x, int y){
    return grid[x][y].getPion();
}

std::ostream& operator<<(std::ostream &strm, const Grid &obj){
    strm << "Plateau[";
    for (int i = 0; i < obj.defaultSize; i++){
        for (int j = 0; j < obj.defaultSize; j++){
            strm << obj.grid[i][j];
        }
    }
    return strm << "]";
}
