#ifndef WINDOW_H
#define WINDOW_H
#include <QWidget>
#include <QPushButton>
#include <QHBoxLayout>
#include <QGroupBox>
#include <QCheckBox>
#include <QLCDNumber>
#include <QLabel>
#include <QTimer>
#include "glwidget.h"

class Window : public QWidget{
    Q_OBJECT
public:
    Window();

    void Step();
    void Update();
    void ResetDisplay();

signals:
    void startSignal();
    void stopSignal();
    void resetSignal();

public slots:
    void Start();
    void Reset();
    void Stop();
    void SUpdate();

    void ToggleInfection();
    void IncrementTime();

private:
    int time;
    glwidget* display;
    QPushButton* start;
    QPushButton* exit;
    QPushButton* reset;

    QCheckBox* infection;

    QLabel* namePrey;
    QLabel* namePredator;
    QLabel* nameHunter;
    QLabel* nameInfected;

    QLabel* totalCreatures;
    QLabel* totalSteps;

    QLCDNumber* prey;
    QLCDNumber* predator;
    QLCDNumber* hunter;
    QLCDNumber* infected;

    QLCDNumber* percentPrey;
    QLCDNumber* percentPredator;
    QLCDNumber* percentHunter;
    QLCDNumber* percentInfected;

    QLCDNumber* totalC;
    QLCDNumber* steps;

    QTimer* statTracker;

    void InitializeVar();
    void ConnectVar();
    void CreateLayout();

    void SetInfectionState(bool state);

    void UpdateStats(QLCDNumber* stat, double number);
    void SetSize(QGroupBox* box, int minh, int minw, int maxh, int maxw);
};

#endif // WINDOW_H
