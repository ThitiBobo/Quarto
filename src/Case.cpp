#include "Case.h"
#include <stdexcept>

Case::Case(){
}

Case::~Case()
{
    delete pion;
}

void Case::addPion(Pion *p)
{
    if (pion != NULL)
        throw 1; //range_error("La case n'est pas vide!");
    pion = p;
}

Pion* Case::getPion()
{
    return pion;
}

bool Case::isEmpty(){
    return (pion == NULL);
}

