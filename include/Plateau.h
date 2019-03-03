#ifndef PLATEAU_H
#define PLATEAU_H


#include <stdlib.h>
#include "Case.h"
#include "Pion.h"


class Plateau
{
    public:
        Plateau();
        virtual ~Plateau();
        const int defaultSize = 4;

    protected:

    private:
        Case plateau[4][4];

};

#endif // PLATEAU_H
