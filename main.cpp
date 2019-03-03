#include <iostream>
#include "Case.h"
#include "Pion.h"

using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    Case myCase;
    bool var = myCase.isEmpty();
    var? cout << "vide": cout << "plein";

    myCase.addPion(new Pion(Pion::ROUGE,Pion::GRAND,Pion::CARRE,Pion::TROUE));

    var = myCase.isEmpty();
    var? cout << "vide": cout << "plein";

    return 0;
}
