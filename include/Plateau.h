#ifndef PLATEAU_H
#define PLATEAU_H
#include <ostream>
#include "Case.h"
#include "Pion.h"
using namespace std;

class Plateau
{
    public:
        Plateau();
        virtual ~Plateau();
        const int defaultSize = 4;
        void addPion(int, int, Pion*);
        Pion* getPion(int, int);


        friend std::ostream& operator<<(std::ostream&, const Plateau&);

    private:
        Case plateau[4][4];

};

#endif // PLATEAU_H
