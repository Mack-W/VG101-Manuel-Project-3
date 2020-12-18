#include "parkinglot.h"
HalfCircle :: HalfCircle(){
    anchor = Vec(0 , 0);
    heart = Vec(0 , 0);
    radius = 1.0;
    start_drawing_angle = (double)(- PI / 2.0);
    r = 1.0;
    g = 1.0;
    b = 1.0;
    a = 1.0;
    zoom_times = 1.0;
}

HalfCircle :: HalfCircle(Vec _anchor , Vec _heart , double _radius , double _start_drawing_angle , double _r , double _g , double _b , double _a){
    anchor = _anchor;
    heart = _heart;
    radius = _radius;
    r = _r;
    g = _g;
    b = _b;
    a = _a;
    start_drawing_angle = _start_drawing_angle;
    zoom_times = 1.0;
}
void HalfCircle :: draw(){
    glColor4f((float)r,(float)g ,(float)b ,(float)a);
    glBegin(GL_POLYGON);
    for (int i = 0 ; i <= draw_circle_num ; ++i)
        glVertex2f((GLfloat)(anchor.getX() + heart.getX() * zoom_times + radius * zoom_times * cos(start_drawing_angle + PI * (float)i / draw_circle_num)),
                   (GLfloat)(anchor.getY() + heart.getY() * zoom_times + radius * zoom_times * sin(start_drawing_angle + PI * (float)i / draw_circle_num)));
    glEnd();
}
void HalfCircle :: rotate(double angle){
    start_drawing_angle += angle;
    heart = (heart >>  angle);
}