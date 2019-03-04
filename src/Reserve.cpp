#include "Reserve.h"

Reserve::Reserve()
{
    //ctor
}

Reserve::~Reserve()
{
    //dtor
}

void Reserve::removePion(int x, int y, Pion* pion){
    reserve[x][y].removePion(pion);
}

Pion* Reserve::getPion(int x, int y){
    return reserve[x][y].getPion();
}

std::ostream& operator<<(std::ostream &strm, const Reserve &obj){
    strm << "Reserve[";
    for (int i = 0; i < obj.defaultSize; i++){
        for (int j = 0; j < obj.defaultSize; j++){
            strm << obj.reserve[i][j];
        }
    }
    return strm << "]";
}


