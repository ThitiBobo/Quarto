#ifndef CASE_H
#define CASE_H
#include "Pion.h"


class Case
{
    public:
        Case();
        virtual ~Case();

        void addPion(Pion*);
        bool isEmpty();
        Pion* getPion();

    private:
        Pion *pion;
};

#endif // CASE_H
