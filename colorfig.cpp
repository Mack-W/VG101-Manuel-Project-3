#include "parkinglot.h"
ColorFig :: ColorFig(){
    r =1.0f;g=0.1f;r=0.5f;
}
ColorFig::~ColorFig()=default;
void ColorFig :: change_color(double _a){
    a = _a;
}

double ColorFig :: get_alpha(){
    return a;
}

void ColorFig :: change_random_color() {
    r = (double)rand() / (double)RAND_MAX;
    g = (double)rand() / (double)RAND_MAX;
    b = (double)rand() / (double)RAND_MAX;
}