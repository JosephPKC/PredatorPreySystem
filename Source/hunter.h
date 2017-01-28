#ifndef HUNTER_H
#define HUNTER_H
#include "predator.h"
class Hunter : public Predator{
public:
    Hunter() : Predator(0,0,HUNTERTYPE){}
    Hunter(int i, int j) : Predator(i,j,HUNTERTYPE){}

    Coord Move(Creature* grid[][MAXLENGTH + 2]);
    void Breed(Creature* grid[][MAXLENGTH + 2]);
    void Eat();
    void Die(Creature* grid[][MAXLENGTH + 2]);
private:
    void CreateOffspring(Creature*& newPos, Coord newCoord);
};

#endif // HUNTER_H
