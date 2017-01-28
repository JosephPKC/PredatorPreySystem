#include <iostream>
#include <QApplication>
#include "utilities.h"
#include "world.h"
#include "ppsim.h"
#include <windows.h>
using namespace std;

int main(int argc, char** argv){
    srand(time(NULL));
    QApplication app(argc,argv);
    PPSim sim;
    sim.Run();
    return app.exec();

//    World w;
//    while(true){
//        system("cls");
//        cout << w << endl;
////        cin.get();
//        w.Step();
////        Sleep(1);
//    }
//    return 0;

    return app.exec();



}



