#include "Grid.h"
#include <iostream>

// ctor
Grid::Grid()
{}

// ctor
Grid::~Grid()
{}

// méthode qui ajoute un pion à la case (x,y) si elle n'est pas déjà occupé,
// sinon renvoie une erreur
void Grid::addPion(int x, int y, Pion* pion){
    grid[x][y].addPion(pion);
}

// Obtient l'instance du pion à la case (x,y)
Pion* Grid::getPion(int x, int y){
    return grid[x][y].getPion();
}

// Obtient et retire la pion de la case (x,y) si elle n'est pas vide,
// sinon renvoie une erreur.
Pion* Grid::removePion(int x, int y){
    return grid[x][y].removePion();
}

// surcharge de l'opérateur <<
std::ostream& operator<<(std::ostream &strm, const Grid &obj){
    strm << "Plateau[";
    for (int i = 0; i < obj.defaultSize; i++){
        for (int j = 0; j < obj.defaultSize; j++){
            strm << obj.grid[i][j];
        }
    }
    return strm << "]";
}

// Permet de vérifier si le coup joué au coords (x,y) est gagant,
// retourne la ligne, colonne ou diagonale si elle est gagnante,
// sinon retourne NULL
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
    // pas gagnant
    return NULL;
}

// vérifie si la pattern aligne quatre pièces gagnantes,
// retourne true si c'est vérifié, sinon false
bool Grid::checkPatern(int** patern){
    int size = 4;
    // check si la ligne a au moins 4 pièces
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
    // pour chaque attributs
    for(int i = 0; i < 4; i++){
        bool flag = false;
        int j = 1;
        // vérifie les quatres pièces
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
