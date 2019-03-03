#include <iostream>
#include "Case.h"
#include "Pion.h"
#include "Plateau.h"

using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    Case *myCase;
    myCase = new Case();
    bool var = myCase->isEmpty();
    var? cout << "vide": cout << "plein";
    cout << endl;

    cout << *myCase << endl;

    try{
        myCase->addPion(new Pion(Pion::ROUGE,Pion::GRAND,Pion::CARRE,Pion::TROUE));
    }catch(string const& erreur){
        cout << "erreur";
    }

    var = myCase->isEmpty();
    var? cout << "vide": cout << "plein";
    cout << endl;

    try{
        myCase->addPion(new Pion(Pion::ROUGE,Pion::GRAND,Pion::CARRE,Pion::TROUE));
    }catch(string erreur){
        cout << erreur << endl;
    }

    Pion* p;
    p = new Pion(Pion::ROUGE,Pion::GRAND,Pion::CARRE,Pion::TROUE);
    cout << *p << endl;
    cout << *myCase << endl;

    delete myCase;

    cout << endl;
    cout << endl;
    Plateau* plateau;
    plateau = new Plateau();

    plateau->addPion(0,0,new Pion(Pion::ROUGE,Pion::GRAND,Pion::CARRE,Pion::TROUE));
    plateau->addPion(3,3,new Pion(Pion::ROUGE,Pion::GRAND,Pion::CARRE,Pion::TROUE));
    cout << *plateau << endl;




    return 0;
}
