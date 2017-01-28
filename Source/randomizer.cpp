//#include "randomizer.h"

//Coord Randomizer::Move(Creature *grid[][MAXLENGTH + 2]){
//    Coord newPos;
//    for(int n = 0; n < RANDOMIZERSTEPCOUNT; n++){
//        newPos = Creature::Move(grid);
//        SetMoveStatus(false);
//    }
//    SetMoveStatus(true);
//    return newPos;
//}

//void Randomizer::Eat(){
//    Creature::Eat();
//}

//void Randomizer::Die(Creature* grid[][MAXLENGTH + 2]){
//    //Does not die
//}

////Coord Randomizer::Sleep(Creature* grid[][MAXLENGTH + 2]){
////    if(sleepCount == RANDOMIZERSLEEP){
////        int randNum = getRand(0,100);
////        if(randNum <= SLEEPCHANCE){
////            Coord savePos = position;
////            delete grid[savePos.x][savePos.y];
////            grid[savePos.x][savePos.y] = NULL;
////            return Coord(saveI,saveJ);
////        }
////    }
////    else
////        sleepCount++;
////}

////void Randomizer::Wake(Creature* grid[][MAXLENGTH + 2], Coord oldPos){
////    if(wakeCount == RANDOMIZERWAKE){
////        int randNum = getRand(0,100);
////        if(randNum <= WAKECHANCE){
////            delete grid[oldPos.x][oldPos.y];
////            grid[oldPos.x][oldPos.y] = new Randomizer(oldPos.x,oldPos.y);
////        }
////    }
////    else
////        wakeCount++;
////}

//void Randomizer::Breed(Creature *grid[][MAXLENGTH + 2]){
//    int numOfCells = 0;
//    Coord* creatureCells = CheckSurroundingsCreature(grid,numOfCells);
//    if(numOfCells > 0){
//        int randNum = getRand(0,numOfCells - 1);
//        Coord newPos = creatureCells[randNum];
//        randNum = getRand(0,100);
//        if(randNum <= RANDOMCHANCE)
//            Randomize(grid[newPos.x][newPos.y]);
//    }
//}

//void Randomizer::Randomize(Creature* cell){
////    int randNum = getRand(0,4);
////    int i = cell -> GetPosition().x, j = cell -> GetPosition().y;
////    delete cell;
////    switch(randNum){
////    case 0:{
////        cell = NULL;
////        break;
////    }
////    case 1:{
////        cell = new Prey(i,j);
////        break;
////    }
////    case 2:{
////        cell = new Predator(i,j);
////        break;
////    }
////    case 3:{
////        cell = new Hunter(i,j);
////        break;
////    }
////    case 4:{
////        cell = new Infected(i,j);
////        break;
////    }
////    default:{
////        break;
////    }
////    }
//}

