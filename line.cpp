#include "parkinglot.h"
Line :: Line(){
    anchor = Vec(0 , 0);
    point1 = Vec(0 , 0);
    point2 = Vec(0 , 0);
    r = 1.0;
    g = 1.0;
    b = 1.0;
    a = 1.0;
    zoom_times = 1.0;
}
Line :: Line(Vec _anchor , Vec _point1 , Vec _point2 , double _r , double _g , double _b , double _a){
    anchor = _anchor;
    point1 = _point1;
    point2 = _point2;
    a = _a;
    r = _r;
    g = _g;
    b = _b;
    zoom_times = 1.0;
}
void Line :: draw(){
    glColor4f((float)r ,(float) g ,(float) b , (float)a);
    glBegin(GL_LINES);
    glVertex2f((float)(anchor.getX() + zoom_times * point1.getX()) , (float)(anchor.getY() + zoom_times * point1.getY()));
    glVertex2f((float)(anchor.getX() + zoom_times * point2.getX()) , (float)(anchor.getY() + zoom_times * point2.getY()));
    glEnd();
}
void Line :: change_point(Vec _point1 , Vec _point2){
    point1 = _point1;
    point2 = _point2;
}
void Line :: rotate(double angle){
    point1 = (point1 << angle);
    point2 = (point2 << angle);
}