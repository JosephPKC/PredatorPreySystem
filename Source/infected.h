#ifndef INFECTED_H
#define INFECTED_H
#include "creature.h"
class Infected : public Creature{
public:
    Infected() : Creature(0,0,INFECTEDTYPE){}
    Infected(int i, int j) : Creature(i,j,INFECTEDTYPE){}

    Coord Move(Creature* grid[][MAXLENGTH + 2]);
    void Breed(Creature* grid[][MAXLENGTH + 2]);
    void Eat();
    void Die(Creature* grid[][MAXLENGTH + 2]);
private:
    void CreateOffspring(Creature *&newPos, Coord newCoord);
};

#endif // INFECTED_H
