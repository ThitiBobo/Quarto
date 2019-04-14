#ifndef IA_H
#define IA_H
#include <Grid.h>

class IA
{
    public:
        IA(int);
        virtual ~IA();
        void play(Grid*,Grid*,int,int);
        int* getPlay();
        int* getSelect();

    private:

        int* playCoords;
        int* selectCoords;
        int dificult;
        int profondeur;

        int calcul(Grid*,Grid*,int,int);
        int* decisionMinMax(Grid*,Grid*,int,int);
        int valeurMinMax(Grid*,Grid*,bool,int,int,int);
};

#endif // IA_H
