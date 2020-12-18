#include "parkinglot.h"
Figure ::Figure(){
    anchor = Vec();
    zoom_times = 1.0;
}
Figure::~Figure()=default;
Vec Figure ::  get_anchor(){
    return anchor;
}
void Figure :: set_anchor(Vec a){
    anchor = a;
}
void Figure :: zoom(double k){
    zoom_times *= k;
}
double Figure :: get_zoom_times(){
    return zoom_times;
}
void Figure :: move(Vec dir){
    anchor = anchor + dir;
}
