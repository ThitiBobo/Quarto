#include "Plateau.h"

Plateau::Plateau()
{}

Plateau::~Plateau()
{
    //dtor
}

void Plateau::addPion(int x, int y, Pion* pion){
    plateau[x][y].addPion(pion);
}

Pion* Plateau::getPion(int x, int y){
    return plateau[x][y].getPion();
}

std::ostream& operator<<(std::ostream &strm, const Plateau &obj){
    strm << "Plateau[";
    for (int i = 0; i < obj.defaultSize; i++){
        for (int j = 0; j < obj.defaultSize; j++){
            strm << obj.plateau[i][j];
        }
    }
    return strm << "]";
}
