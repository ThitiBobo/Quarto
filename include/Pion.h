#ifndef PION_H
#define PION_H


class Pion
{
    public:
        virtual ~Pion();
        Pion(bool, bool, bool, bool);
        getCouleur();
        getTaille();
        getForme();
        getTrou();

    protected:

    private:
        bool couleur;
        bool taille;
        bool forme;
        bool trou;

};

#endif // PION_H
