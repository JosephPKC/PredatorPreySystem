#include "coord.h"

ostream& operator <<(ostream& out, const Coord& OutCoord){
    out << "(" << OutCoord.i << "," << OutCoord.j << ")";
    return out;
}

bool operator ==(const Coord& LS, const Coord& RS){
    return LS.i == RS.i && LS.j == RS.j ? true : false;
}
