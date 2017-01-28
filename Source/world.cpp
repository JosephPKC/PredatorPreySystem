#include "world.h"

World::World() : predators(PREDATORINITIAL),prey(PREYINITIAL),hunters(HUNTERINITIAL),infected(INFECTEDINITIAL),infection(true){
    CalculateTotal(); //Calculates total creatures from initial population
    CalculatePercent(); //Calculates the percentage of each population based on total
    InitializeNull(); //Sets all pointers to NULL
    CreateWall(); //Creates the exterior walls
    Populate(); //Populates the grid with the initial population
}

World::World(const World& SourceWorld){
    for(int i = 0; i <= MAXHEIGHT + 1; i++){
        for(int j = 0; j <= MAXLENGTH + 1; j++){
            *Grid[i][j] = *SourceWorld.Grid[i][j];
        }
    }
}

World& World::operator =(const World& SourceWorld){
    for(int i = 0; i <= MAXHEIGHT + 1; i++){
        for(int j = 0; j <= MAXLENGTH + 1; j++){
            delete Grid[i][j];
            *Grid[i][j] = *SourceWorld.Grid[i][j];
        }
    }
    return *this;
}

World::~World(){ //Destructor: deletes each cell
    for(int i = 0; i <= MAXHEIGHT + 1; i++){
        for(int j = 0; j <= MAXLENGTH + 1; j++){
            delete Grid[i][j];
        }
    }
}

void World::Display(ostream& out) const{
    for(int i = 0; i <= MAXHEIGHT + 1; i++){
        for(int j = 0; j <= MAXLENGTH + 1; j++){
            if(!IsNull(Grid[i][j]))
                out << *(Grid[i][j]);
            else
                out << " ";
        }
        cout << endl;
    }
    cout << "Predators: " << predators << endl;
    cout << "Prey: " << prey << endl;
    cout << "Hunters: " << hunters << endl;
    cout << "Infected: " << infected << endl;
    cout << "Total: " << total << endl;
}

void World::Populate(){
    PopulatePredator(); //Populates the predators
    PopulatePrey(); //Populates the prey
    PopulateHunter(); //Populates the hunters
    PopulateInfected(); //Populates the infected
}

void World::Step(){
    ResetPopulationCount();
    PredatorStep();
    PreyStep();
    HunterStep();
    InfectedStep();
    UpdateStep();
}

void World::PredatorStep(){
    Coord newPos;
    for(int i = 1; i <= MAXHEIGHT; i++){
        for(int j = 1; j <= MAXLENGTH; j++){
            if(CanMove(Grid[i][j]) && IsSameType(Grid[i][j],PREDATORTYPE)){
                newPos = Grid[i][j] -> Move(Grid);
                Grid[newPos.i][newPos.j] -> Breed(Grid);
                Grid[newPos.i][newPos.j] -> Die(Grid);
            }
        }
    }
}

void World::PreyStep(){
    Coord newPos;
    for(int i = 1; i <= MAXHEIGHT; i++){
        for(int j = 1; j <= MAXLENGTH; j++){
            if(CanMove(Grid[i][j]) && IsSameType(Grid[i][j],PREYTYPE)){
                newPos = Grid[i][j] -> Move(Grid);
                Grid[newPos.i][newPos.j] -> Breed(Grid);
                Grid[newPos.i][newPos.j] -> Die(Grid);
            }
        }
    }
}

void World::HunterStep(){
    Coord newPos;
    for(int i = 1; i <= MAXHEIGHT; i++){
        for(int j = 1; j <= MAXLENGTH; j++){
            if(CanMove(Grid[i][j]) && IsSameType(Grid[i][j],HUNTERTYPE)){
                newPos = Grid[i][j] -> Move(Grid);
                Grid[newPos.i][newPos.j] -> Breed(Grid);
                Grid[newPos.i][newPos.j] -> Die(Grid);
            }
        }
    }
}

void World::InfectedStep(){
    if(infection){
        if(!CheckInfection())
            CreateInfected();

        Coord newPos;
        for(int i = 1; i <= MAXHEIGHT; i++){
            for(int j = 1; j <= MAXLENGTH; j++){
                if(CanMove(Grid[i][j]) && IsSameType(Grid[i][j],INFECTEDTYPE)){
                    newPos = Grid[i][j] -> Move(Grid);
                    Grid[newPos.i][newPos.j] -> Breed(Grid);
                    Grid[newPos.i][newPos.j] -> Die(Grid);
                }
            }
        }
    }
}

void World::UpdateStep(){
    for(int i = 1; i <= MAXHEIGHT; i++){
        for(int j = 1; j <= MAXLENGTH; j++){
            if(!IsNull(Grid[i][j])){
                Grid[i][j] -> SetMoveStatus(false);
                UpdatePopulation(Grid[i][j]);
            }
        }
    }
    CalculateTotal();
    CalculatePercent();
}

void World::PopulatePredator(){
    int randI, randJ;
    for(int n = 0; n < PREDATORINITIAL; n++){
        randI = getRand(1,MAXLENGTH);
        randJ = getRand(1,MAXLENGTH);
        if(IsNull(Grid[randI][randJ]))
            Grid[randI][randJ] = new Predator(randI,randJ);
        else
            n--;
    }
}

void World::PopulatePrey(){
    int randI, randJ;
    for(int n = 0; n < PREYINITIAL; n++){
        randI = getRand(1,MAXLENGTH);
        randJ = getRand(1,MAXLENGTH);
        if(IsNull(Grid[randI][randJ]))
            Grid[randI][randJ] = new Prey(randI,randJ);
        else
            n--;
    }
}

void World::PopulateHunter(){
    int randI, randJ;
    for(int n = 0; n < HUNTERINITIAL; n++){
        randI = getRand(1,MAXLENGTH);
        randJ = getRand(1,MAXLENGTH);
        if(IsNull(Grid[randI][randJ]))
            Grid[randI][randJ] = new Hunter(randI,randJ);
        else
            n--;
    }
}

void World::PopulateInfected(){
    int randI, randJ;
    if(infected){
        for(int n = 0; n < INFECTEDINITIAL; n++){
            randI = getRand(1,MAXHEIGHT);
            randJ = getRand(1,MAXLENGTH);
            if(IsNull(Grid[randI][randJ]))
                Grid[randI][randJ] = new Infected(randI,randJ);
            else
                n--;
        }
    }
}

void World::InitializeNull(){
    for(int i = 0; i <= MAXHEIGHT + 1; i++){
        for(int j = 0; j <= MAXLENGTH + 1; j++){
            Grid[i][j] = NULL;
        }
    }
}

void World::CreateWall(){
    for(int i = 0; i <= MAXHEIGHT + 1; i++){
        if(i == 0 || i == MAXHEIGHT + 1){
            for(int j = 0; j <= MAXLENGTH + 1; j++){
                Grid[i][j] = new Wall(i,j);
            }
        }
        else{
            Grid[i][0] = new Wall(i,0);
            Grid[i][MAXLENGTH + 1] = new Wall(i,MAXLENGTH + 1);
        }
    }
}

void World::CreateInfected(){
    int infectSpawn = getRand(0,100);
    if(infectSpawn < INFECTSPAWNCHANCE){
        Creature* cell = InfectCreature();
        if(!IsNull(cell)){
            int i = cell -> GetPosition().i, j = cell -> GetPosition().j;
            delete Grid[i][j];
            Grid[i][j] = new Infected(i,j);
        }
    }
}

bool World::CheckInfection(){
    for(int i = 1; i <= MAXHEIGHT; i++){
        for(int j = 1; j <= MAXLENGTH; j++){
            if(!IsNull(Grid[i][j]) && IsSameType(Grid[i][j],INFECTEDTYPE))
                return true;
        }
    }
    return false;
}

Creature* World::InfectCreature(){ //Tries to infect a random creature
    int i = getRand(1,MAXHEIGHT), j = getRand(1,MAXLENGTH), n = 0;
    return PickCreature(i,j,n);
}

Creature* World::PickCreature(int i, int j, int n){
    if(!IsNull(Grid[i][j]))
        return Grid[i][j];
    if(n >= 50)
        return NULL;
    i = getRand(1,MAXHEIGHT);
    j = getRand(1,MAXLENGTH);
    return PickCreature(i,j,++n);
}

ostream& operator <<(ostream& out, const World& outW){
    outW.Display(out);
    return out;
}

void World::UpdatePopulation(Creature* cell){
    if(IsSameType(cell,PREDATORTYPE))
        predators++;
    else if(IsSameType(cell,PREYTYPE))
        prey++;
    else if(IsSameType(cell,HUNTERTYPE))
        hunters++;
    else if(IsSameType(cell,INFECTEDTYPE))
        infected++;
}

void World::ResetPopulationCount(){
    predators = prey = hunters = infected = 0;

}

Creature* World::Get(int i, int j){
    return Grid[i][j];
}

void World::SetInfectionState(bool state){
    if(!state){
        for(int i = 1; i <= MAXLENGTH; i++){
            for(int j = 1; j <= MAXLENGTH; j++){
                if(!IsNull(Grid[i][j]) && IsSameType(Grid[i][j],INFECTEDTYPE)){
                    delete Grid[i][j];
                    Grid[i][j] = NULL;
                }
            }
        }
        infection = false;
        infected = 0;
    }
    else
        infection = true;
}

void World::CalculatePercent(){
    if(total == 0){
        percentPrey = 0.0;
        percentPredator = 0.0;
        percentHunter = 0.0;
        percentInfected = 0.0;
    }
    else{
        percentPrey = GetPercent(prey,total);
        percentPredator = GetPercent(predators,total);
        percentHunter = GetPercent(hunters,total);
        percentInfected = GetPercent(infected,total);
    }
}

void World::CalculateTotal(){
    total = prey + predators + hunters + infected;
}

bool World::CanMove(Creature* cell) const{
    return (!IsNull(cell)) && !(cell -> HasMoved()) ?
                true : false;
}

bool World::IsNull(Creature* cell) const{
    return !cell ? true : false;
}

bool World::IsSameType(Creature* cell, char type) const{
    return cell -> GetType() == type ? true : false;
}

