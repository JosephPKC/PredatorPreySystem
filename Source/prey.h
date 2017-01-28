#ifndef PREY_H
#define PREY_H
#include "creature.h"
class Prey : public Creature{
public:
    Prey() : Creature(){}
    Prey(int i, int j) : Creature(i,j,PREYTYPE){}

    Coord Move(Creature* grid[][MAXLENGTH + 2]);
    void Breed(Creature* grid[][MAXLENGTH + 2]);
    void Eat();
    void Die(Creature* grid[][MAXLENGTH + 2]);
private:
    void CreateOffspring(Creature *&newPos, Coord newCoord);
};

#endif // PREY_H
