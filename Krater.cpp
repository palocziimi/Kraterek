#include "Krater.h"
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

Krater::Krater(double x, double y, double sugar, const string& nev)
    : x(x), y(y), sugar(sugar), nev(nev) {}

double Krater::getX() const { return x; }
double Krater::getY() const { return y; }
double Krater::getSugar() const { return sugar; }
string Krater::getName() const { return nev; }

vector<Krater> Krater::Read(const string& filename) {
    vector<Krater> kraterek;
    ifstream file(filename);
    string line;

    if (!file.is_open()) {
        cerr << "Unable to open file: " << filename << endl;
        return kraterek;
    }

    while (getline(file, line)) {
        stringstream ss(line);
        double x, y, sugar;
        string nev;

        ss >> x >> y >> sugar;
        getline(ss >> ws, nev);

        while (!nev.empty() && isspace(nev.back())) {
            nev.pop_back();
        }
        kraterek.emplace_back(x, y, sugar, nev);
    }
    return kraterek;
}


