#ifndef PION_H
#define PION_H
#include <ostream>
using namespace std;

/*
    La classe Pion permet de représenter une instance
    d'une pièce d'un jeu de Quarto avec ses quatre
    caractéristiques.
*/
class Pion
{
    public:
        // énumération pour les différentes caractéristiques
        // des pièces d'un jeu de Quarto
        enum Couleur {ROUGE = false, BLEU  = true};
        enum Taille  {GRAND = false, PETIT = true};
        enum Forme   {ROND  = false, CARRE = true};
        enum Surface {TROUE = false, PLAT  = true};

        // dtor
        virtual ~Pion();
        // ctor avec les caractéristiques
        Pion(Couleur, Taille, Forme, Surface);

        // méthodes permettants de récupérer les caractéristiques
        Couleur getCouleur();
        Taille getTaille();
        Forme getForme();
        Surface getSurface();
        // permet de récupérer tout les attributs de la pièce
        // dans un tableau de boolean
        bool *getAllAttributes();

        // surcharge de <<
        friend std::ostream& operator<<(std::ostream&, const Pion&);

    protected:

    private:
        // attributs de la pièce pour les caractéristiques d'une
        // pièce de Quarto
        bool couleur;
        bool taille;
        bool forme;
        bool surface;

};

#endif // PION_H
