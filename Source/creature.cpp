 #include "creature.h"

Coord Creature::Move(Creature* grid[][MAXLENGTH + 2]){
    //Creatures only move to a random NULL cell around it
    int numOfCells = 0;
    Coord* validCells = CheckAroundNull(grid,numOfCells); //Checks for null cells around it
    if(numOfCells > 0){ //If there are any cells available
        Coord newPos = PickCell(validCells,numOfCells); //Picks a random cell
        MoveCreature(grid[newPos.i][newPos.j],grid[position.i][position.j],newPos); //Moves the creature, deleting whatever was there before, and updating its position on grid
    }
    delete[] validCells; //Delete the list, no longer needed
    return position; //This is its new position for the world to use
}


void Creature::Breed(Creature *grid[][MAXLENGTH + 2]){
    if(CanBreed(CREATUREBREED)){ //Checks if it can breed
        int numOfCells = 0;
        Coord* validCells = CheckAroundNull(grid,numOfCells); //Checks for null cells
        if(numOfCells > 0){ //If there are cells available
            Coord newPos = PickCell(validCells,numOfCells); //Picks a random cell
            CreateOffspring(grid[newPos.i][newPos.j], newPos); //Creates a new creature of the same type at that cell
        }
        delete[] validCells; //delete the list
    }
    else
        IncrementBreed(); //Increment counter
}

void Creature::Eat(){
    //Auto Eats
    //Generally unused
    deathCount = 0; //Resets deathCount
}

void Creature::Die(Creature* grid[][MAXLENGTH + 2]){
    if(HasDied(CREATURELIFE)){
        int i = position.i, j = position.j;
        Delete(grid[i][j]);
    }
    else
        IncrementDeath();
}

Coord* Creature::CheckAroundNull(Creature* grid[][MAXLENGTH + 2], int& numOfCells){
    Coord* listOfCells = GetSurroundings(grid,numOfCells);
    Coord* validList = new Coord[8];//Will be deleted in Action Functions
    Creature* cell;
    int num = 0;
    for(int n = 0; n < numOfCells; n++){ //Goes through each index in the listOfCells
        cell = grid[listOfCells[n].i][listOfCells[n].j];
        if(IsNull(cell)){ //Checks if the cell is null, and if it is so, it places that cell into a new list
            validList[num++] = Coord(listOfCells[n].i,listOfCells[n].j);
        }
    }
    numOfCells = num; //The true number of valid cells
    delete[] listOfCells; //Delete the original listOfCells, no longer needed
    return validList;
}

Coord* Creature::CheckAroundCreature(Creature* grid[][MAXLENGTH + 2], int& numOfCells){
    Coord* listOfCells = GetSurroundings(grid,numOfCells);
    Coord* validList = new Coord[8];
    Creature* cell;
    int num = 0;
    for(int n = 0; n < numOfCells; n++){
        cell = grid[listOfCells[n].i][listOfCells[n].j];
        if(!IsNull(cell) && cell -> GetType() != WALLTYPE){
            validList[num++] = Coord(listOfCells[n].i,listOfCells[n].j);
        }
    }
    numOfCells = num;
    delete[] listOfCells;
    return validList;
}

Coord* Creature::CheckAroundNotWall(Creature* grid[][MAXLENGTH + 2], int& numOfCells){
    Coord* listOfCells = GetSurroundings(grid,numOfCells);
    Coord* validList = new Coord[8];
    Creature* cell;
    int num = 0;
    for(int n = 0; n < numOfCells; n++){
        cell = grid[listOfCells[n].i][listOfCells[n].j];
        if(!IsNull(cell) && cell -> GetType() != WALLTYPE)
            validList[num++] = Coord(listOfCells[n].i,listOfCells[n].j);
    }
    numOfCells = num;
    delete[] listOfCells;
    return validList;
}

Coord* Creature::CheckAroundType(Creature* grid[][MAXLENGTH + 2], int& numOfCells, char type){
    Coord* listOfCells = GetSurroundings(grid,numOfCells);
    Coord* validList = new Coord[8];
    Creature* cell;
    int num = 0;
    for(int n = 0; n < numOfCells; n++){
        cell = grid[listOfCells[n].i][listOfCells[n].j];
        if(!IsNull(cell) && cell -> GetType() == type)
            validList[num++] = Coord(listOfCells[n].i,listOfCells[n].j);
    }
    numOfCells = num;
    delete[] listOfCells;
    return validList;
}

Coord* Creature::CheckAroundNotType(Creature* grid[][MAXLENGTH + 2], int& numOfCells, char type){
    Coord* listOfCells = GetSurroundings(grid,numOfCells);
    Coord* validList = new Coord[8];
    Creature* cell;
    int num = 0;
    for(int n = 0; n < numOfCells; n++){
        cell = grid[listOfCells[n].i][listOfCells[n].j];
        if(!IsNull(cell) && cell -> GetType() != WALLTYPE && cell -> GetType() != type)
            validList[num++] = Coord(listOfCells[n].i,listOfCells[n].j);
    }
    numOfCells = num;
    delete[] listOfCells;
    return validList;
}

Coord* Creature::GetSurroundings(Creature* grid[][MAXLENGTH + 2], int& numOfCells){
    Coord* listOfCells = new Coord[8]; //Will be deleted in CheckAbout functions
    for(int i = position.i - 1; i <= position.i + 1; i++){ //Goes through each of the 9 cells around it(including itself)
        for(int j = position.j - 1; j <= position.j + 1; j++){
            if(IsNull(grid[i][j]))
                listOfCells[numOfCells++] = Coord(i,j);
            else if(!IsSamePos(this,grid[i][j])) //Only puts in the 8 cells around it
                listOfCells[numOfCells++] = Coord(i,j);
        }
    }
    return listOfCells;
}

Coord Creature::PickCell(Coord* listOfCells, int numOfCells){
    int thisCell = getRand(0,numOfCells - 1); //Picks random cell
    return listOfCells[thisCell];
}

void Creature::MoveCreature(Creature*& newPos, Creature*& oldPos, Coord newCoord){
    position = newCoord; //Updates position on creature
    newPos = this; //Updates the position on the grid
    oldPos = NULL;
    SetMoveStatus(true); //Updates the moved status
}

void Creature::CreateOffspring(Creature*& newPos, Coord newCoord){
    int i = newCoord.i, j = newCoord.j;
    delete newPos;
    newPos = new Creature(i,j,CREATURETYPE); //Creates a new creature
    SetBreedStatus(0); //Resets breed count
}

void Creature::Delete(Creature*& cell){
    delete cell;
    cell = NULL;
}

bool Creature::CanBreed(int breedNum){
    return breedCount == breedNum ? true : false; //Checks if count has reached its required number
}

bool Creature::HasDied(int deathNum){
    return deathCount == deathNum ? true : false; //Checks if count has reached its required number
}

bool Creature::IsNull(Creature* cell){
    return !cell ? true : false; //Checks if cell is null
}

bool Creature::IsSamePos(Creature* cellOne, Creature* cellTwo){
    return cellOne -> GetPosition() == cellTwo -> GetPosition() ? true : false; //Checks if the two coords are the same
}

ostream& operator <<(ostream& out, const Creature& outC){
    out << outC.type; //Outputs the type
    return out;
}


