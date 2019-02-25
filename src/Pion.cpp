#include "Pion.h"
/*#define "Pion::getCouleur()"
#define "Pion::getTaille()"
#define "Pion::getForme()"
#define "Pion::getTrou()"*/


Pion::~Pion()
{
    //dtor
}

Pion::Pion(bool couleur, bool taille, bool forme, bool trou)
{
	this->couleur = couleur;
	this->taille = taille;
	this->forme = forme;
	this->trou = trou;
}

Pion::getCouleur()
{
   // bool blue;
  //if(couleur == blue)
  if(couleur)
  {
    return true;
  }
  else return false;
}

Pion::getTaille()
{
   // bool tall;
  //if(taille == tall)
  if (taille)
  {
    return true;
  }
  else return false;
}

Pion::getForme()
{
  //bool circle;
  //if(forme == circle)
  if (forme)
  {
    return true;
  }
  else return false;
}

Pion::getTrou()
{
   // bool trou;
  //if(trou == trou)
  if(trou)
  {
    return true;
  }
  else return false;
}


