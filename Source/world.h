#ifndef WORLD_H
#define WORLD_H
#include "creature.h"
#include "predator.h"
#include "prey.h"
#include "hunter.h"
#include "infected.h"
#include "wall.h"

class World{
public:
    World();
    World(const World& SourceWorld);
    World& operator =(const World& SourceWorld);
    ~World();

    void Display(ostream& out) const;
    void Populate();
    void Step(); // Perform all simulations for one time step

    Creature *Get(int i, int j);

    int GetPredatorC(){return predators;}
    int GetPreyC(){return prey;}
    int GetHunterC(){return hunters;}
    int GetInfectedC(){return infected;}
    int GetTotal(){return total;}

    float GetPredatorPT(){return percentPredator;}
    float GetPreyPT(){return percentPrey;}
    float GetHunterPT(){return percentHunter;}
    float GetInfectedPT(){return percentInfected;}

    bool GetInfectionState(){return infection;}
    void SetInfectionState(bool state);

    friend ostream& operator <<(ostream& out, const World& outW);
private:
    Creature* Grid[MAXHEIGHT + 2][MAXLENGTH + 2];
    int predators;
    int prey;
    int hunters;
    int infected;

    float percentPredator;
    float percentPrey;
    float percentHunter;
    float percentInfected;
    int total;

    bool infection;

    void PredatorStep();
    void PreyStep();
    void HunterStep();
    void InfectedStep();
    void UpdateStep();

    void PopulatePredator();
    void PopulatePrey();
    void PopulateHunter();
    void PopulateInfected();

    void CreateInfected();
    Creature* InfectCreature();
    Creature* PickCreature(int i, int j, int n);
    bool CheckInfection();

    bool IsNull(Creature *cell) const;
    bool CanMove(Creature* cell) const;
    bool IsSameType(Creature* cell, char type) const;

    void CreateWall();
    void InitializeNull();

    void CalculatePercent();
    void CalculateTotal();
    void UpdatePopulation(Creature* cell);
    void ResetPopulationCount();
};

#endif // WORLD_H
