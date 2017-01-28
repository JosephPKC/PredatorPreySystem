#include "infected.h"

Coord Infected::Move(Creature* grid[][MAXLENGTH + 2]){
    return Creature::Move(grid);
}

void Infected::Breed(Creature* grid[][MAXLENGTH + 2]){
    if(CanBreed(INFECTEDSPREAD)){
        int numOfCells = 0;
        Coord* validCells = CheckAroundNotType(grid,numOfCells,INFECTEDTYPE);
        if(numOfCells > 0){
            Coord newPos = PickCell(validCells,numOfCells);
            int infectChance = getRand(0,100);
            if(infectChance < INFECTSPREADCHANCE)
                CreateOffspring(grid[newPos.i][newPos.j],newPos);
        }
        delete[] validCells;
    }
    else
        IncrementBreed();
}

void Infected::Die(Creature* grid[][MAXLENGTH + 2]){
    if(HasDied(INFECTEDLIFE)){
        int i = GetPosition().i, j = GetPosition().j;
        Delete(grid[i][j]);
    }
    else
        IncrementDeath();
}

void Infected::Eat(){
    Creature::Eat();
}

void Infected::CreateOffspring(Creature*& newPos, Coord newCoord){
    int i = newCoord.i, j = newCoord.j;
    delete newPos;
    newPos = new Infected(i,j);
    SetBreedStatus(0);
}
