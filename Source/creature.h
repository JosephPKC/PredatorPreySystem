#ifndef CREATURE_H
#define CREATURE_H
#include "coord.h"
#include "utilities.h"
#include "Constants.h"
class Creature{
public:
    Creature() : position(Coord(0,0)), type('\0'),moved(false),breedCount(0),deathCount(0){}
    Creature(int i, int j, char typing) : position(Coord(i,j)),type(typing),moved(false),breedCount(0),deathCount(0){}

    virtual Coord Move(Creature* grid[][MAXLENGTH + 2]);
    virtual void Breed(Creature* grid[][MAXLENGTH + 2]);
    virtual void Eat();
    virtual void Die(Creature* grid[][MAXLENGTH + 2]);

    Coord GetPosition(){return position;}
    int GetI(){return position.i;}
    int GetJ(){return position.j;}
    char GetType(){return type;}

    int GetBreedCount(){return breedCount;}
    int GetDeathCount(){return deathCount;}

    void SetPosition(int i, int j){position = Coord(i,j);}
    void SetMoveStatus(bool status){moved = status;}
    void SetBreedStatus(int breedNum){breedCount = breedNum;}
    void SetDeathStatus(int deathNum){deathCount = deathNum;}

    void IncrementDeath(){deathCount++;}
    void IncrementBreed(){breedCount++;}

    bool HasMoved(){return moved;}
    bool HasDied(int deathNum);
    bool CanBreed(int breedNum);

    friend ostream& operator <<(ostream& out, const Creature& outC);
private:
    Coord position;
    char type;
    bool moved;
    int breedCount;
    int deathCount;
protected:
    Coord* CheckAroundNull(Creature* grid[][MAXLENGTH + 2], int& numOfCells); //Checks surrounding cells for null cells
    Coord* CheckAroundCreature(Creature* grid[][MAXLENGTH + 2], int& numOfCells); //Checks surrounding cells for creature cells
    Coord* CheckAroundNotWall(Creature* grid[][MAXLENGTH + 2], int& numOfCells); //Checks surrounding cells for Non-Wall cells
    Coord* CheckAroundType(Creature* grid[][MAXLENGTH + 2], int &numOfCells, char type); //Checks surrounding cells for a specific type
    Coord* CheckAroundNotType(Creature* grid[][MAXLENGTH + 2], int& numOfCells, char type); //Checks surrounding cells for anything but wall or another specific type
    Coord* GetSurroundings(Creature* grid[][MAXLENGTH + 2], int& numOfCells); //Checks surroundings for any cell

    Coord PickCell(Coord* listOfCells, int numOfCells);
    void MoveCreature(Creature *&newPos, Creature *&oldPos, Coord newCoord);
    void CreateOffspring(Creature *&newPos, Coord newCoord);
    void Delete(Creature *&cell);
    bool IsNull(Creature* cell);
    bool IsSamePos(Creature *cellOne, Creature *cellTwo);
};
#endif // CREATURE_H
