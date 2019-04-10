#include "Case.h"
#include <stdexcept>

// contructor de la classe Case
Case::Case(){
    // initialise le pion a NULL
    pion = NULL;
}

// dtor
Case::~Case()
{
    // suprime le pion
    delete pion;
}

// méthode qui ajoute un pion à la case si elle est n'est
// pas déjà occupée, sinon renvoie une erreur.
void Case::addPion(Pion *p)
{
    if (pion != NULL)
        throw string("Erreur: La case contient déjà une autre instance de Pion");
    pion = p;
}

// Obtient l'instance du pion dans la case
Pion* Case::getPion()
{
    return pion;
}

// Obtient et retire le pion de la case si la case n'est pas vide,
// sinon renvoie une erreur
Pion* Case::removePion()
{
    if (pion == NULL)
        throw new string("Erreur: La case est vide");
    Pion* p = pion;
    pion = NULL;
    return p;
}

// Permet de savoir si la case est vide,
// retourne true si elle est vide, sinon false
bool Case::isEmpty(){
    return (pion == NULL);
}

// surcharge de l'opérateur <<
std::ostream& operator<<(std::ostream &strm, const Case &obj){
    if(obj.pion == NULL)
        return strm << "Case[Pion = Vide]";
    else
        return strm << "Case[Pion = "  << *obj.pion << "]" ;
}


