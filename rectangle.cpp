#include "parkinglot.h"
Rectang :: Rectang(){
    anchor = Vec(0 , 0);
    point1 = Vec(0 , 0);
    point2 = Vec(0 , 0);
    r = 1.0;
    g = 1.0;
    b = 1.0;
    a = 1.0;
    zoom_times = 1.0;
}

Rectang :: Rectang(Vec _anchor , Vec _point1 , Vec _point3 , double _r , double _g , double _b , double _a){
    anchor = _anchor;
    point1 = _point1;
    point3 = _point3;
    point2 = Vec(point1.getX() , point3.getY());
    point4 = Vec(point3.getX() , point1.getY());
    r = _r;
    g = _g;
    b = _b;
    a = _a;
    zoom_times = 1.0;
}

void Rectang :: draw(){
//    cout << "Rectang draw";
    glColor4f((float)r ,(float) g ,(float) b ,(float) a);
    glBegin(GL_QUADS);
    glVertex2f((float)(anchor.getX() + point1.getX() * zoom_times), (float)(anchor.getY() + point1.getY() * zoom_times));
    glVertex2f((float)(anchor.getX() + point2.getX() * zoom_times), (float)(anchor.getY() + point2.getY() * zoom_times));
    glVertex2f((float)(anchor.getX() + point3.getX() * zoom_times), (float)(anchor.getY() + point3.getY() * zoom_times));
    glVertex2f((float)(anchor.getX() + point4.getX() * zoom_times), (float)(anchor.getY() + point4.getY() * zoom_times));
    glEnd();
}

void Rectang :: rotate(double angle){
    point1 = (point1 << angle);
    point2 = (point2 << angle);
    point3 = (point3 << angle);
    point4 = (point4 << angle);
}