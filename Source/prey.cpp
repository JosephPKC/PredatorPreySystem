#include "prey.h"

Coord Prey::Move(Creature* grid[][MAXLENGTH + 2]){
    return Creature::Move(grid);
}

void Prey::Breed(Creature *grid[][MAXLENGTH + 2]){
    if(CanBreed(PREYBREED)){
        int numOfCells = 0;
        Coord* validCells = CheckAroundNull(grid,numOfCells);
        if(numOfCells > 0){
            Coord newPos = PickCell(validCells,numOfCells);
            CreateOffspring(grid[newPos.i][newPos.j],newPos);
        }
        delete[] validCells;
    }
    else
        IncrementBreed();
}

void Prey::Eat(){
    Creature::Eat();
}

void Prey::Die(Creature* grid[][MAXLENGTH + 2]){
    if(HasDied(PREYLIFE)){
        int i = GetPosition().i, j = GetPosition().j;
        Delete(grid[i][j]);
    }
    else
        IncrementDeath();
}

void Prey::CreateOffspring(Creature*& newPos, Coord newCoord){
    int i = newCoord.i, j = newCoord.j;
    delete newPos;
    newPos = new Prey(i,j);
    SetBreedStatus(0);
}
