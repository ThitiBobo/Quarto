#ifndef PION_H
#define PION_H


class Pion
{
    public:
        Pion();
        virtual ~Pion();
        Pion(bool, bool, bool, bool);

    protected:

    private:
        bool couleur;
        bool forme;
        bool trou;
        bool taille;
};

#endif // PION_H
