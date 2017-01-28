#ifndef PREDATOR_H
#define PREDATOR_H
#include "creature.h"
#include "prey.h"
class Predator : public Creature{
public:
    Predator() : Creature(0,0,PREDATORTYPE){}
    Predator(int i, int j) : Creature(i,j,PREDATORTYPE){}
    Predator(int i, int j, char type) : Creature(i,j,type){}

    Coord Move(Creature *grid[][MAXLENGTH + 2]);
    void Eat();
    void Die(Creature* grid[][MAXLENGTH + 2]);
    void Breed(Creature *grid[][MAXLENGTH + 2]);
private:
    void CreateOffspring(Creature *&newPos, Coord newCoord);
};

#endif // PREDATOR_H
