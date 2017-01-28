#include "hunter.h"

Coord Hunter::Move(Creature* grid[][MAXLENGTH + 2]){
    int numOfCells = 0;
    Coord* listOfPrey = CheckAroundNotWall(grid,numOfCells);
    if(numOfCells < 1){
        delete[] listOfPrey;
        return Creature::Move(grid);
    }
    else{
        Coord newPos = PickCell(listOfPrey,numOfCells);
        delete grid[newPos.i][newPos.j];
        MoveCreature(grid[newPos.i][newPos.j], grid[GetPosition().i][GetPosition().j],newPos);
        Eat();
    }
    delete[] listOfPrey;
    return GetPosition();
}

void Hunter::Breed(Creature* grid[][MAXLENGTH + 2]){
    if(CanBreed(HUNTERBREED)){
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

void Hunter::Eat(){
    Creature::Eat();
}

void Hunter::Die(Creature* grid[][MAXLENGTH + 2]){
    if(HasDied(HUNTERSTARVE)){
        int i = GetPosition().i, j = GetPosition().j;
        Delete(grid[i][j]);
    }
    else
        IncrementDeath();
}

void Hunter::CreateOffspring(Creature*& newPos, Coord newCoord){
    int i = newCoord.i, j = newCoord.j;
    delete newPos;
    newPos = new Hunter(i,j);
    SetBreedStatus(0);
}
