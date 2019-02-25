#ifndef CASE_H
#define CASE_H
#include "Pion.h"


class Case
{
    public:
        Case();
        virtual ~Case();
        void addPion(Pion);
        bool isEmpty();
        Pion getPion();
        void setPion(Pion);



    protected:

    private:
        Pion pion;
        bool vide;
};

#endif // CASE_H
