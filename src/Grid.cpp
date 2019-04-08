#include "Grid.h"
#include <iostream>

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

Pion* Grid::removePion(int x, int y){
    return grid[x][y].removePion();
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

int** Grid::checkVictory(int x, int y){
    int** patern = new int*[4];

    // check la verticale
    for (int i = 0; i < 4; i++){
        patern[i] = new int[2]{x,i};
    }
    if(checkPatern(patern))
        return patern;

    // check l'horizontale
    for (int i = 0; i < 4; i++){
        patern[i] = new int[2]{i,y};
    }
    if(checkPatern(patern))
        return patern;
    //check diagonale droit
    if(x == y){
        for (int i = 0; i < 4; i++){
            patern[i] = new int[2]{i,i};
        }
        if(checkPatern(patern))
            return patern;
    }

    //check diagonale inversé
    if(x == 3 - y){
        for (int i = 0; i < 4; i++){
            patern[i] = new int[2]{i,3 - i};
        }
        if(checkPatern(patern))
            return patern;
    }

    return NULL;
}

bool Grid::checkPatern(int** patern){
    int size = 4;
    // check si la ligne a au moins des pièces
    for(int i = 0; i < size; i++){
        if(grid[patern[i][0]][patern[i][1]].getPion() == NULL)
            return false;
    }

    // récupère les attributs des pièces
    bool ** attributs = new bool*[size];
    for(int i = 0; i < size; i++){
        attributs[i] = grid[patern[i][0]][patern[i][1]].getPion()->getAllAttributes();
    }

    // vérifie TOUT
    for(int i = 0; i < 4; i++){
        bool flag = false;
        int j = 1;
        while(j < 4 && !flag){

            if(attributs[j][i] != attributs[j-1][i])
                flag = true;
            j++;
        }
        // si quatre identique
        if(!flag) return true;
    }

    return false;

}
