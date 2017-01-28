#include "window.h"

Window::Window(){
    InitializeVar();
    ConnectVar();
    CreateLayout();
}

void Window::InitializeVar(){
    time = 0;
    statTracker = new QTimer;

    start = new QPushButton("Start");
    exit = new QPushButton("Exit");
    reset = new QPushButton("Reset");

    infection = new QCheckBox("Enable Infection");
    infection -> setChecked(true);

    namePrey = new QLabel("Prey: ");
    namePredator = new QLabel("Predator: ");
    nameHunter = new QLabel("Hunter: ");
    nameInfected = new QLabel("Infected: ");
    totalCreatures = new QLabel("Total Creatures: ");
    totalSteps = new QLabel("Total Steps: ");

    prey = new QLCDNumber(LCDDIGITS);
    prey -> setSegmentStyle(QLCDNumber::Flat);
    predator = new QLCDNumber(LCDDIGITS);
    predator -> setSegmentStyle(QLCDNumber::Flat);
    hunter = new QLCDNumber(LCDDIGITS);
    hunter -> setSegmentStyle(QLCDNumber::Flat);
    infected = new QLCDNumber(LCDDIGITS);
    infected -> setSegmentStyle(QLCDNumber::Flat);

    percentPrey = new QLCDNumber(LCDDIGITS);
    percentPrey -> setSegmentStyle(QLCDNumber::Flat);
    percentPredator = new QLCDNumber(LCDDIGITS);
    percentPredator -> setSegmentStyle(QLCDNumber::Flat);
    percentHunter = new QLCDNumber(LCDDIGITS);
    percentHunter -> setSegmentStyle(QLCDNumber::Flat);
    percentInfected = new QLCDNumber(LCDDIGITS);
    percentInfected-> setSegmentStyle(QLCDNumber::Flat);

    totalC = new QLCDNumber(LCDDIGITS);
    totalC -> setSegmentStyle(QLCDNumber::Flat);
    steps = new QLCDNumber(LCDDIGITS);
    steps -> setSegmentStyle(QLCDNumber::Flat);

    display = new glwidget;
    display ->setMinimumHeight(DEFAULTHEIGHT);
    display ->setMinimumWidth(DEFAULTWIDTH);
}

void Window::CreateLayout(){
    QVBoxLayout* MainMenu = new QVBoxLayout;
    MainMenu -> addWidget(start);
    MainMenu -> addWidget(reset);
    MainMenu -> addWidget(exit);

    QVBoxLayout* ModifCheckMenu = new QVBoxLayout;
    ModifCheckMenu -> addWidget(infection);

    QVBoxLayout* StatText = new QVBoxLayout;
    StatText -> addWidget(namePrey);
    StatText -> addWidget(namePredator);
    StatText -> addWidget(nameHunter);
    StatText -> addWidget(nameInfected);

    QVBoxLayout* CurrentStats = new QVBoxLayout;
    CurrentStats -> addWidget(prey);
    CurrentStats -> addWidget(predator);
    CurrentStats -> addWidget(hunter);
    CurrentStats -> addWidget(infected);

    QVBoxLayout* PercentStats = new QVBoxLayout;
    PercentStats -> addWidget(percentPrey);
    PercentStats -> addWidget(percentPredator);
    PercentStats -> addWidget(percentHunter);
    PercentStats -> addWidget(percentInfected);

    QVBoxLayout* MiscStats = new QVBoxLayout;
    MiscStats -> addWidget(totalCreatures);
    MiscStats -> addWidget(totalC);
    MiscStats -> addWidget(totalSteps);
    MiscStats -> addWidget(steps);

    QGroupBox* DisplayName = new QGroupBox("Type");
    DisplayName -> setLayout(StatText);
    DisplayName -> setAlignment(Qt::AlignCenter);
    SetSize(DisplayName,80,40,160,80);

    QGroupBox* DisplayCurrent = new QGroupBox("Current");
    DisplayCurrent -> setLayout(CurrentStats);
    DisplayCurrent -> setAlignment(Qt::AlignCenter);
    SetSize(DisplayCurrent,80,160,160,300);

    QGroupBox* DisplayPercent = new QGroupBox("Percentage of Total");
    DisplayPercent -> setLayout(PercentStats);
    DisplayPercent -> setAlignment(Qt::AlignCenter);
    SetSize(DisplayPercent,80,160,160,300);

    QGroupBox* DisplayOther = new QGroupBox("Misc");
    DisplayOther -> setLayout(MiscStats);
    DisplayOther -> setAlignment(Qt::AlignCenter);
    SetSize(DisplayOther,80,160,160,300);

    QHBoxLayout* StatDisplay = new QHBoxLayout;
    StatDisplay -> addWidget(DisplayName);
    StatDisplay -> addWidget(DisplayCurrent);
    StatDisplay -> addWidget(DisplayPercent);
    StatDisplay -> addWidget(DisplayOther);

    QHBoxLayout* ModifMenu = new QHBoxLayout;
    ModifMenu -> addLayout(ModifCheckMenu);

    QGroupBox* MainMenuBox = new QGroupBox("Main Menu");
    MainMenuBox -> setLayout(MainMenu);
    MainMenuBox -> setAlignment(Qt::AlignCenter);
    SetSize(MainMenuBox,100,100,200,150);

    QGroupBox* ModifierBox = new QGroupBox("Customize");
    ModifierBox -> setLayout(ModifMenu);
    ModifierBox -> setAlignment(Qt::AlignCenter);
    SetSize(ModifierBox,100,100,200,200);

    QGroupBox* DisplayBox = new QGroupBox("Statistics");
    DisplayBox -> setLayout(StatDisplay);
    DisplayBox -> setAlignment(Qt::AlignCenter);
    SetSize(DisplayBox,100,500,200,800);

    QHBoxLayout* BottomHolder = new QHBoxLayout;
    BottomHolder -> addWidget(MainMenuBox);
    BottomHolder -> addWidget(ModifierBox);
    BottomHolder -> addWidget(DisplayBox);

    QVBoxLayout* Overall = new QVBoxLayout;
    Overall -> addWidget(display);
    Overall -> addLayout(BottomHolder);

    setLayout(Overall);
}

void Window::ConnectVar(){
    connect(start,SIGNAL(clicked()),this,SLOT(Start()));
    connect(exit,SIGNAL(clicked()),this,SLOT(close()));
    connect(reset,SIGNAL(clicked()),this,SLOT(Reset()));
    connect(infection,SIGNAL(stateChanged(int)),this,SLOT(ToggleInfection()));
    connect(statTracker,SIGNAL(timeout()),this,SLOT(SUpdate()));
    connect(statTracker,SIGNAL(timeout()),this,SLOT(IncrementTime()));
}

void Window::Start(){
    emit startSignal();
    start -> setText("Stop");
    disconnect(start,SIGNAL(clicked()),this,SLOT(Start()));
    connect(start,SIGNAL(clicked()),this,SLOT(Stop()));
    statTracker -> start(REFRESHRATE);
}

void Window::Reset(){
    emit resetSignal();
    time = 0;
    Stop();
    SUpdate();
}

void Window::Stop(){
    emit stopSignal();
    start -> setText("Start");
    disconnect(start,SIGNAL(clicked()),this,SLOT(Stop()));
    connect(start,SIGNAL(clicked()),this,SLOT(Start()));
    statTracker -> stop();
}


void Window::SUpdate(){
    UpdateStats(prey,display -> world -> GetPreyC());
    UpdateStats(predator,display -> world -> GetPredatorC());
    UpdateStats(hunter,display -> world -> GetHunterC());
    UpdateStats(infected,display -> world -> GetInfectedC());

    UpdateStats(percentPrey,display -> world -> GetPreyPT());
    UpdateStats(percentPredator,display -> world -> GetPredatorPT());
    UpdateStats(percentHunter,display -> world -> GetHunterPT());
    UpdateStats(percentInfected,display -> world -> GetInfectedPT());

    UpdateStats(totalC,display -> world -> GetTotal());
    UpdateStats(steps,time);
}

void Window::ToggleInfection(){
    SetInfectionState(infection -> isChecked());
}

void Window::Step(){
    display -> world -> Step();
}

void Window::Update(){
    display -> repaint();
}

void Window::ResetDisplay(){
    display -> glwidget::Reset();
}

void Window::SetInfectionState(bool state){
    cout << (state ? "TRUE" : "FALSE") << endl;
    display -> world -> SetInfectionState(state);
}

void Window::IncrementTime(){
    time++;
}

void Window::UpdateStats(QLCDNumber* stat, double number){
    int hold = number * 100;
    number = hold /100.0;
    stat -> display(number);
}

void Window::SetSize(QGroupBox* box, int minh, int minw, int maxh, int maxw){
    box -> setMinimumHeight(minh);
    box -> setMinimumWidth(minw);
    box -> setMaximumHeight(maxh);
    box -> setMaximumWidth(maxw);
}
