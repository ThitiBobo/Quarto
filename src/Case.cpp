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

Pion* Case::removePion()
{
    if (pion == NULL)
        throw new string("Erreur: La case est vide");
    Pion* p = pion;
    pion = NULL;
    return p;
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


