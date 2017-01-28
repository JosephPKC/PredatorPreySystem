#ifndef UTILITES_H
#define UTILITIES_H
#include <cstdlib>
#include <ctime>
#include <iostream>
#include "coord.h"
using namespace std;

int getRand(int min, int max);
void Copy(Coord *dest, Coord* source, int length);
float GetPercent(float part, float total);

#endif // UTILITIES_H
