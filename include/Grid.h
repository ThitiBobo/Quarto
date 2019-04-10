#ifndef GRID_H
#define GRID_H
#include <ostream>
#include "Case.h"
#include "Pion.h"
using namespace std;

/*
    La classe Grid permet de représenter une instance
    d'un plateau de Quarto composé d'un tableau de
    Case de taille 4 sur 4.
*/
class Grid
{
    public:
        // ctor
        Grid();
        // dtor
        virtual ~Grid();
        // taille du plateau d'un jeu de Quarto (taille d'uncoté)
        const int defaultSize = 4;

        // méthode qui ajoute un pion a la case aux coordonnées (x,y)
        void addPion(int, int, Pion*);
        // Obtient le pion de la case (x,y)
        Pion* getPion(int, int);
        // Obtient et retire le pion de la case (x,y)
        Pion* removePion(int,int);
        // Permet de vérifier si le dernier coup aux coordonnées (x,y)
        // est gagnant, retourne la ligne gagnante.
        int** checkVictory(int,int);

        // surcharge de <<
        friend std::ostream& operator<<(std::ostream&, const Grid&);

    private:
        // tableau de Case de taille 4 x 4
        Case grid[4][4];
        // méthode vérifiant si le pattern en entrée est gagnant
        bool checkPatern(int**);

};

#endif // GRID_H
