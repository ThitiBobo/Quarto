#ifndef PION_H
#define PION_H
#include <ostream>
using namespace std;

class Pion
{
    public:
        enum Couleur {ROUGE = false, BLEU  = true};
        enum Taille  {GRAND = false, PETIT = true};
        enum Forme   {ROND  = false, CARRE = true};
        enum Surface {TROUE = false, PLAT  = true};

        virtual ~Pion();
        Pion(Couleur, Taille, Forme, Surface);

        Couleur getCouleur();
        Taille getTaille();
        Forme getForme();
        Surface getSurface();

        friend std::ostream& operator<<(std::ostream&, const Pion&);

    protected:

    private:
        bool couleur;
        bool taille;
        bool forme;
        bool surface;

};

#endif // PION_H
