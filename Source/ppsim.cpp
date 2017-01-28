#include "ppsim.h"

PPSim::PPSim() : QObject(){
    MainWindow = new Window;
    timer = new QTimer;
    connect(timer,SIGNAL(timeout()),this,SLOT(Advance()));

    connect(MainWindow,SIGNAL(startSignal()),this,SLOT(TimerStart()));
    connect(MainWindow,SIGNAL(stopSignal()),this,SLOT(TimerStop()));
    connect(MainWindow,SIGNAL(resetSignal()),this,SLOT(Restart()));
}

void PPSim::Advance(){
    MainWindow -> Step();
    MainWindow -> Update();
}

void PPSim::Run(){
    MainWindow -> show();
    MainWindow -> SUpdate();
}

void PPSim::TimerStart(){
    timer -> start(REFRESHRATE);
}

void PPSim::TimerStop(){
    timer -> stop();
}

void PPSim::Restart(){
    TimerStop();
    MainWindow -> ResetDisplay();
    MainWindow -> Update();
}


