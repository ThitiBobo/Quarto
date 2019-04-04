#include "SFMLGrid.h"

SFMLGrid::SFMLGrid(int size)
{
    this->size = size;
    Cases = new vector<SFMLCase>(size * size);
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            Cases[i * size + j] = SFMLCase(0,0);
        }
    }
}

SFMLGrid::~SFMLGrid()
{
    //dtor
}

void SFMLGrid::draw(){
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){

        }
    }
}
