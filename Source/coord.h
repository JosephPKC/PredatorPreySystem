#ifndef COORD_H
#define COORD_H
#include <iostream>
using namespace std;
struct Coord{
    Coord() : i(0), j(0){}
    Coord(int newI, int newJ) : i(newI), j(newJ){}
    friend ostream& operator <<(ostream& out, const Coord& OutCoord);
    friend bool operator ==(const Coord& LS, const Coord& RS);

    int i;
    int j;
};

#endif // COORD_H
