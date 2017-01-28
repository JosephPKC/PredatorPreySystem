//#ifndef RANDOMIZER_H
//#define RANDOMIZER_H
//#include "creature.h"
//#include "prey.h"
//#include "predator.h"
//#include "hunter.h"
//#include "infected.h"
//class Randomizer : public Creature{
//public:
//    Randomizer() : Creature(0,0,RANDOMIZERTYPE),sleepCount(0),wakeCount(0){}
//    Randomizer(int i, int j) : Creature(i,j,RANDOMIZERTYPE),sleepCount(0),wakeCount(0){}

//    Coord Move(Creature *grid[][MAXLENGTH + 2]);
//    void Eat();
//    void Die(Creature* grid[][MAXLENGTH + 2]);
//    void Breed(Creature *grid[][MAXLENGTH + 2]);
////    void Wake(Creature* grid[][MAXLENGTH + 2], Coord oldPos);
////    Coord Sleep(Creature* grid[][MAXLENGTH + 2]);


//    int GetSleep(){return sleepCount;}
//    int GetWake(){return wakeCount;}
//    void SetSleep(int sleep){sleepCount = sleep;}
//    void SetWake(int wake){wakeCount = wake;}
//private:
//    int sleepCount;
//    int wakeCount;
//    void Randomize(Creature* cell);
//};

//#endif // RANDOMIZER_H
