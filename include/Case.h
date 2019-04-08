#ifndef CASE_H
#define CASE_H
#include <ostream>
#include "Pion.h"
using namespace std;

class Case
{
    public:
        Case();
        virtual ~Case();

        void addPion(Pion*);
        Pion* removePion();
        bool isEmpty();
        Pion* getPion();

        friend std::ostream& operator<<(std::ostream&, const Case&);

    private:
        Pion *pion;
};

#endif // CASE_H
