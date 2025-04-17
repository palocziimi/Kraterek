#include <iostream>
#include "Krater.h";
#include "KraterKezelo.h"

using namespace std;

int main() {

    //1.
    KraterKezelo kraterKezelo ("./Files/felszin_tpont.txt");

    //2.
    cout << "2. feladat" << endl << "A kráterek száma: " << kraterKezelo.getKraterek().size() << endl;

    //3.
    cout << "3. feladat" << endl;
    kraterKezelo.kraterKereso();

    //4.
    cout << "4. feladat" << endl;
    cout << "A legnagyobb kráter neve és sugara: " << kraterKezelo.legnagyobbKrater() << endl;

    //6.
    cout << "6. feladat" << endl;
    kraterKezelo.AtFedesek();

    //7.
    cout << "7. feladat" << endl;
    kraterKezelo.Tartalmaz();

    //8.
    kraterKezelo.Teruletek();

    return 0;
}