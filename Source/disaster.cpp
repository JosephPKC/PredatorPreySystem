#include "disaster.h"

Coord Disaster::Move(Creature *grid[][MAXLENGTH + 2]){
    //Default disasters don't move
}

void Disaster::Eat(){
    //Default disasters do not consume substance
}


void Disaster::Die(Creature* grid[][MAXLENGTH + 2]){
//    cout << "death " << GetStarveCount() << endl;
    if(HasStarved(FIRELIFE))
        Creature::Die(grid);
    else
        IncrementStarve();
}

void Disaster::Breed(Creature *grid[][MAXLENGTH + 2]){
    if(CanBreed(FIRESPREAD)){
        int numOfCells = 0, newI, newJ, randNum;
        Coord* list = CheckSurroundingsWall(grid,numOfCells);
        for(int n = 0; n < numOfCells; n++){
            randNum = getRand(0,100);
            if(randNum < FIRESPREADCHANCE){
                newI = list[n].x;
                newJ = list[n].y;
                if(CheckCell(grid[newI][newJ])){
                    grid[newI][newJ] = new Disaster(newI,newJ);
                    grid[newI][newJ] -> SetMoveStatus(true);
                    grid[newI][newJ] -> SetBreedCount(GetBreedCount() + 1);
                    if(GetStarveCount() == FIRELIFE)
                        grid[newI][newJ] -> SetStarveCount(GetStarveCount());
                    else
                        grid[newI][newJ] -> SetStarveCount(GetStarveCount() + 1);

                }
                else if(grid[newI][newJ] -> GetType() != DISASTERTYPE){
                    delete grid[newI][newJ];
                    grid[newI][newJ] = new Disaster(newI,newJ);
                    grid[newI][newJ] -> SetMoveStatus(true);
                    grid[newI][newJ] -> SetBreedCount(GetBreedCount() + 1);
                    if(GetStarveCount() == FIRELIFE)
                        grid[newI][newJ] -> SetStarveCount(GetStarveCount());
                    else
                        grid[newI][newJ] -> SetStarveCount(GetStarveCount() + 1);

                }
            }
        }
        delete[] list;
        SetBreedCount(0);
    }
    else
        IncrementBreed();



//    if(CanBreed(DISASTERSPREAD)){
//        int numOfCells = 0, newI, newJ;
//        Coord* list = CheckSurroundingsWall(grid,numOfCells);
//        for(int n = 0; n < numOfCells; n++){
//            newI = list[n].x;
//            newJ = list[n].y;
//            if(CheckCell(grid[newI][newJ])){
//                grid[newI][newJ] = new Disaster(newI,newJ);
//                grid[newI][newJ] -> SetMoveStatus(true);
//                grid[newI][newJ] -> SetBreedCount(GetBreedCount() + 1);
//                if(GetStarveCount() == DISASTERLIFE)
//                    grid[newI][newJ] -> SetStarveCount(GetStarveCount());
//                else
//                    grid[newI][newJ] -> SetStarveCount(GetStarveCount() + 1);

//            }
//            else if(grid[newI][newJ] -> GetType() != DISASTERTYPE){
//                delete grid[newI][newJ];
//                grid[newI][newJ] = new Disaster(newI,newJ);
//                grid[newI][newJ] -> SetMoveStatus(true);
//                grid[newI][newJ] -> SetBreedCount(GetBreedCount() + 1);
//                if(GetStarveCount() == DISASTERLIFE)
//                    grid[newI][newJ] -> SetStarveCount(GetStarveCount());
//                else
//                    grid[newI][newJ] -> SetStarveCount(GetStarveCount() + 1);

//            }
//        }
//        delete[] list;
//        SetBreedCount(0);
//    }
//    else
//        IncrementBreed();


//    randNum = getRand(0,num - 1);
//    Coord newPos = list[randNum];
//    grid[newPos.x][newPos.y] = new Disaster(newPos.x,newPos.y);
}

