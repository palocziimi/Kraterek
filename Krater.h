#ifndef KRATER_H
#define KRATER_H

#include <string>
#include <vector>
using namespace std;

class Krater {
    private:
        double x;
        double y;
        double sugar;
        string nev;
    public:
        Krater(double x, double y, double sugar, const string& nev);

        double getX() const;
        double getY() const;
        double getSugar() const;
        string getName() const;

        static vector<Krater> Read(const string& filename);
};

#endif //KRATER_H
