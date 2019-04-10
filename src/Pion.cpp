#include "Pion.h"

// constructor de Pion avec les caractéristiques de la pièce
Pion::Pion(Couleur couleur, Taille taille, Forme forme, Surface surface)
{
	this->couleur = couleur;
	this->taille = taille;
	this->forme = forme;
	this->surface = surface;
}

// dtor
Pion::~Pion()
{}

// Obtient la couleur de la pièce
Pion::Couleur Pion::getCouleur()
{
    return (Couleur)this->couleur;
}

// Obtient la taille de la pièce
Pion::Taille Pion::getTaille()
{
   return (Taille)this->taille;
}

// Obtient le forme de la pièce
Pion::Forme Pion::getForme()
{
    return (Forme)this->forme;
}

// Obtient la caractéristique de la
// surface (plat ou percée) de la pièce
Pion::Surface Pion::getSurface()
{
    return (Surface)this->surface;
}

// Obtient tout les attributs de la pièce dans un tableau de booleans
// de la façons suivante [couleur,taille,forme,surface]
bool* Pion::getAllAttributes(){
    bool *attributes = new bool[4]{couleur,taille,forme,surface};
    return attributes;
}

// surcharge de l'opérateur <<
std::ostream& operator<<(std::ostream &strm, const Pion &pion){
    return strm << "Pion[Couleur = " << pion.couleur
        << ", Taille = " << pion.taille
        << ", Forme = " << pion.forme
        << ", Surface = " << pion.surface
        << "]";
}


