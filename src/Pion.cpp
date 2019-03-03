#include "Pion.h"

Pion::Pion(Couleur couleur, Taille taille, Forme forme, Surface surface)
{
	this->couleur = couleur;
	this->taille = taille;
	this->forme = forme;
	this->surface = surface;
}

Pion::~Pion()
{
    //dtor
}

Pion::Couleur Pion::getCouleur()
{
    return (Couleur)this->couleur;
}

Pion::Taille Pion::getTaille()
{
   return (Taille)this->taille;
}

Pion::Forme Pion::getForme()
{
    return (Forme)this->forme;
}

Pion::Surface Pion::getSurface()
{
    return (Surface)this->surface;
}


