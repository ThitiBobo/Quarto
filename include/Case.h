#ifndef CASE_H
#define CASE_H
#include <ostream>
#include "Pion.h"
using namespace std;

/*
    La classe Case représente une instance d'une case d'un jeu de
    de Quarto, composée ou non d'un pièce de Quarto (instance de Pion).
*/
class Case
{
    public:
        //ctor
        Case();
        //dtor
        virtual ~Case();

        // méthode qui ajoute un pion dans la case si elle
        // est n'est pas vide
        void addPion(Pion*);
        // méthode qui retire le pion de la case s'il
        // il y a déjà une pièce
        Pion* removePion();
        // permet de savoir si la case est vide
        bool isEmpty();
        // Obtient l'instance du pion de la case
        Pion* getPion();

        // surchage de <<
        friend std::ostream& operator<<(std::ostream&, const Case&);

    private:
        // instance du pion de la case
        Pion *pion;
};

#endif // CASE_H
