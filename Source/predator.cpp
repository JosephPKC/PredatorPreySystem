#include "predator.h"

Coord Predator::Move(Creature* grid[][MAXLENGTH + 2]){
    int numOfCells = 0;
    Coord* listOfPrey = CheckAroundType(grid,numOfCells,PREYTYPE);
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

void Predator::Eat(){
    Creature::Eat();
}

void Predator::Die(Creature* grid[][MAXLENGTH + 2]){
    if(HasDied(PREDATORSTARVE)){
        int i = GetPosition().i, j = GetPosition().j;
        Delete(grid[i][j]);
    }
    else
        IncrementDeath();
}

void Predator::Breed(Creature *grid[][MAXLENGTH + 2]){
    if(CanBreed(PREDATORBREED)){
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

void Predator::CreateOffspring(Creature*& newPos, Coord newCoord){
    int i = newCoord.i, j = newCoord.j;
    delete newPos;
    newPos = new Predator(i,j);
    SetBreedStatus(0);
}
