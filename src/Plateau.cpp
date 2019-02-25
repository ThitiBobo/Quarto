#include "Plateau.h"

Plateau::Plateau()
{
    int nbCase = defaultSize * defaultSize;
    plateau = (Case*) malloc(sizeof(Case) * nbCase);
    Case *c;
    for (int i = 0; i < nbCase; i++){
        c = new Case;
        plateau[i] = *c;
    }
}

Plateau::~Plateau()
{
    //dtor
}
