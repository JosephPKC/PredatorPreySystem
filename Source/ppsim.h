#ifndef PPSIM_H
#define PPSIM_H
#include "window.h"
#include <QTimer>

class PPSim : public QObject{
    Q_OBJECT
public:
    PPSim();

    void Run();
public slots:
    void Advance();
    void TimerStart();
    void TimerStop();
    void Restart();

private:
    Window* MainWindow;
    QTimer* timer;
};

#endif // PPSIM_H
