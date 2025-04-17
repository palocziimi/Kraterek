#include "KraterKezelo.h"

#include <iostream>
#include <cmath>
#include <fstream>
#include <sstream>
using namespace std;

KraterKezelo::KraterKezelo(const string &filename) {
    kraterek = Krater::Read("./Files/felszin_tpont.txt");
}

const vector<Krater> KraterKezelo::getKraterek() const {
    return kraterek;
}

void KraterKezelo::kraterKereso() const {
    string input;
    cout << "Kérem egy kráter nevét: ";
    getline(cin >> ws, input);

    for (const Krater& krater : kraterek) {
        if (krater.getName() == input) {
            cout << "A(z) ";
            cout << krater.getName();
            cout << " középpontja X=";
            cout << krater.getX();
            cout << " Y=";
            cout << krater.getY();
            cout << " sugara R=";
            cout << krater.getSugar();
            cout << "." << endl;
            return;
        }
    }
    cout << "Nincs ilyen nevű kráter." << endl;
}

string KraterKezelo::legnagyobbKrater() const {
    const Krater* legnagyobb = &kraterek[0];
    for (const Krater& krater : kraterek) {
        if (krater.getSugar() > legnagyobb->getSugar()) {
            legnagyobb = &krater;
        }
    }
    return legnagyobb->getName() + " " + to_string(legnagyobb->getSugar());
}

double KraterKezelo::Tavolsag(double x1, double y1, double x2, double y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

void KraterKezelo::AtFedesek() const {
    string input;
    cout << "Kérem egy kráter nevét: ";
    getline(cin >> ws, input);

    bool talalt = false;
    const Krater* krater = &kraterek[0];
    for (const Krater& k : kraterek) {
        if (k.getName() == input) {
            krater = &k;
            talalt = true;
        }
    }
    if (!talalt) {
        return;
    }

    vector<Krater> nemfedikat;
    ostringstream oss;

    for (const Krater& k : kraterek) {
        if (Tavolsag(krater->getX(), krater->getY(), k.getX(), k.getY()) >= krater->getSugar() + k.getSugar()) {
            nemfedikat.push_back(k);
        }
    }
    cout << "Nincs közös része: ";
    for (size_t i = 0; i < nemfedikat.size(); i++) {
        if (i!= 0) oss << ", ";
        oss << nemfedikat[i].getName();
    }
    cout << oss.str() << endl;
}

void KraterKezelo::Tartalmaz() const {
    for (size_t i = 0; i < kraterek.size(); i++) {
        for (size_t j = 0; j < kraterek.size(); j++) {
            if (i == j) continue;

            const Krater& k1 = kraterek[i];
            const Krater& k2 = kraterek[j];

            double tav = Tavolsag(k1.getX(), k1.getY(), k2.getX(), k2.getY());

            if (k1.getSugar() > k2.getSugar()) {
                if (tav < (k1.getSugar() - k2.getSugar())) {
                    std::cout << "A(z) " << k1.getName() << " tartalmazza a(z) " << k2.getName() << " krátert." << std::endl;
                }
            }
        }
    }
}

void KraterKezelo::Teruletek() const {
    ofstream file("terulet.txt");

    if (!file.is_open()) {
        cerr << "Nem sikerült megnyitni a fájlt: \"terulet.txt\"" << endl;
        return;
    }
    const double PI = 3.14;

    for (const Krater& k : kraterek) {
        double terulet = PI * pow(k.getSugar(), 2);
        file << fixed << setprecision(2) << terulet << "\t" << k.getName() << endl;
    }
    file.close();
}

static vector<string> split(const string& str, char delimiter) {
    vector<string> result;
    string current;

    for (const char ch : str) {
        if (ch == delimiter) {
            result.push_back(current);
            current.clear();
        } else {
            current += ch;
        }
    }
    result.push_back(current);

    return result;
}


