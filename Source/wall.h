#ifndef WALL_H
#define WALL_H
#include "creature.h"
class Wall : public Creature{
public:
    Wall() : Creature(0,0,WALLTYPE){}
    Wall(int i, int j) : Creature(i,j,WALLTYPE){}
};

#endif // WALL_H
