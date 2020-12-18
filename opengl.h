#ifndef OPENGL_H
#define OPENGL_H
#include <iostream>
#include <cmath>
#include <ctime>
#include <GL/glut.h>
#include <vector>
#include <unistd.h>
using namespace std;

static const int draw_circle_num=200;
static const double PI=3.14159265;
static const double default_alpha =0.8;

class Vec {
private:
    double x, y;
public:
    Vec();
    ~Vec()= default;
    Vec(double _x , double _y);
    void print();
    double getX();
    double getY();
    Vec operator + (Vec v);
    Vec operator - (Vec v);
    Vec operator * (double k);
    double operator * (Vec v);
    Vec operator >> (double k);
    Vec operator << (double k);
};
class Figure{
protected:
    Vec anchor;
    double zoom_times;
public:
    Figure();
    virtual ~Figure()=0;
    virtual Vec get_anchor();
    double get_zoom_times();
    void set_anchor(Vec a);
    void zoom(double k);
    void move(Vec dir);
    virtual void draw(){};
    virtual void rotate(double angle) = 0;
};
class ColorFig : public Figure{
protected:
    double r , g , b , a;
public:
    ColorFig();
    virtual void draw() = 0;
    virtual ~ColorFig()=0;
    double get_alpha();
    void change_color(double _a);
    void change_random_color();
};
class Line : public ColorFig{
protected:
    Vec point1 , point2;
public:
    Line();
    Line(Vec _anchor , Vec _point1 , Vec _point2 ,
         double _r=0, double _g=0, double _b=0, double _a=default_alpha);
    void draw();
    void change_point(Vec _point1 , Vec _point2);
    void rotate(double angle);
};
class Rectang : public ColorFig{
protected:
    Vec point1 , point2 , point3 , point4;
public:
    Rectang();
    Rectang(Vec _anchor , Vec _point1, Vec _point3 ,
            double _r=1 , double _g=0.0 , double _b=0 , double _a=default_alpha);
    void draw();
    void rotate(double angle);
};

class Circle : public ColorFig{
protected:
    Vec heart;
    double radius;
public:
    Circle();
    Circle(Vec _anchor , Vec _heart , double _radius ,
           double _r = 0 , double _g = 0, double _b = 0, double _a = default_alpha);
    void draw();
    void rotate(double angle);
};
class HalfCircle : public ColorFig{
protected:
    Vec heart;
    double radius , start_drawing_angle;
public:
    HalfCircle();
    HalfCircle(Vec _anchor , Vec _heart , double _radius, double _start_drawing_angle ,
               double _r=0 , double _g=0, double _b=0 , double _a=default_alpha);
    void draw();
    void rotate(double angle);
};
class Trapezium : public ColorFig{
protected:
    Vec point1 , point2 , point3 , point4;
public:
    Trapezium();
    Trapezium(Vec _anchor , Vec _point1, Vec _point2, Vec _point3, Vec _point4 ,
              double _r = 0.0 , double _g =0.0 , double _b = 0.0 , double _a = default_alpha);
    void draw();
    void rotate(double angle);
};
class Triangle : public ColorFig{
protected:
    Vec point1 , point2 , point3;
public:
    Triangle();
    Triangle(Vec _anchor , Vec _point1, Vec _point2, Vec _point3 ,
             double _r = 0.0 , double _g = 0.0 , double _b = 0.0 , double _a = default_alpha);
    void draw();
    void rotate(double angle);
};
#endif
//-lglu32 -lfreeglut -lopengl32