#ifndef CASE_H
#define CASE_H
#include "Pion.h"


class Case
{
    public:
        Case();
        virtual ~Case();
        bool addPion(Pion);
        bool isEmpty();
        Pion getPion();
        void setPion(Pion);



    protected:

    private:
        Pion pion;
};

#endif // CASE_H
