#include "Case.h"
#include <stdexcept>

Case::Case()
{
    vide=true;
}

Case::~Case()
{
    //dtor
}

void Case:: addPion(Pion p)
{

       pion = p;
       vide=false;


     throw 1; //range_error("La case n'est pas vide!");
}


    Pion Case::getPion()
    {
        return pion;
    }

    void Case::setPion(Pion pion)
    {
        this->pion=pion;
    }
