#ifndef KRATERKEZELO_H
#define KRATERKEZELO_H

#include "Krater.h";
#include <string>
#include <vector>
using namespace std;

class KraterKezelo {
    private:
    vector<Krater> kraterek;
    public:
    KraterKezelo(const string& filename);

    const vector<Krater> getKraterek() const;

    void kraterKereso() const;
    string legnagyobbKrater() const;
    static double Tavolsag(double x1, double y1, double x2, double y2);
    void AtFedesek() const;
    void Tartalmaz() const;
    void Teruletek() const;

    static vector<string> split(const string& str, char delimiter);
};

#endif //KRATERKEZELO_H
