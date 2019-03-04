#include "Case.h"
#include <stdexcept>

Case::Case(){
    pion = NULL;
}

Case::~Case()
{
    delete pion;
}

void Case::addPion(Pion *p)
{
    if (pion != NULL)
        throw string("Erreur: La case contient déjà une autre instance de Pion");
    pion = p;
}

Pion* Case::getPion()
{
    return pion;
}

bool Case::isEmpty(){
    return (pion == NULL);
}

std::ostream& operator<<(std::ostream &strm, const Case &obj){
    if(obj.pion == NULL)
        return strm << "Case[Pion = Vide]";
    else
        return strm << "Case[Pion = "  << *obj.pion << "]" ;
}


