#include "utilities.h"

int getRand(int min, int max){
    return rand() % (max - min + 1) + min;
}

void Copy(Coord *dest, Coord* source, int length){
    if(source){
        for(int i = 0; i < length; i++){
            dest[i] = source[i];
        }
    }
}

float GetPercent(float part, float total){
    return part / total * 100.0;
}
