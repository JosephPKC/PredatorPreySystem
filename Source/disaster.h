#ifndef DISASTER_H
#define DISASTER_H
#include "creature.h"

class Disaster : public Creature{
public:
    Disaster() : Creature(0,0,DISASTERTYPE){}
    Disaster(int i, int j) : Creature(i,j,DISASTERTYPE){}

    Coord Move(Creature *grid[][MAXLENGTH + 2]);
    void Eat();
    void Die(Creature* grid[][MAXLENGTH + 2]);
    void Breed(Creature *grid[][MAXLENGTH + 2]);
};

#endif // DISASTER_H
