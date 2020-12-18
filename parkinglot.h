

#ifndef _PARKING
#define _PARKING
#include <string>
#include <GL/freeglut.h>
#include "opengl.h"
static const int MAX=12;
using namespace std;
static const int CAR=10; //this stands for unit price
static const int VAN=20;
static const int MOTORBIKE=5;
static const int BICYCLE=2;
static const double TWO=0.70710678;
static const double unit=0.25;
class Lot
{
private:
    int position;
    int state;
public:
    Lot(int position_=0,int state_=0);
    ~Lot(){};
    void setposition(int position_){position=position_;};
    void setstate(int state_){state=state_;};
    void changestate();
    bool isempty();
    int getposition();
    int getstate();
};
class RegularVehicle
{
public:
    virtual ~RegularVehicle()=default;
    virtual int price()=0;
    int getType();
    time_t getArrival();
    int getnum();
    string getname();
    int getpos();
    void setpos(int x);
protected:
    int type;
    time_t current;//entertime
    int number;
    int pos;
};
class Vehicle
{
public:
    void move(Vec *anchor_list,Vec path);
    virtual void draw()=0;
    void rotate(double *direction_list,double angle);
    virtual ~Vehicle()=default;
    int movetolot(Vec *anchor_list,double *direction_list,
                  int position,double *direction2_list,int *flag);
    virtual int gotolot(Vec *anchor_list,double *direction_list,
                        int position,double *direction2_list,double *l_list,int *flag,int *flag2)=0;
protected:
    int type;
    int number;
    double direction=0;//angle
    Vec anchor;
};
class Parking
{
private:
    Vehicle* a[MAX];
    RegularVehicle* a0[MAX];
    Lot* b;
    int size;
    int num;
    ColorFig *fig[15];
    int status;
public:
    Parking(int size_,int num_,Vec *anchor_list,double *direction_list
            ,double *direction2_list,double *l_list,int *rand_list);
    Parking(int size_,int num_);
    void run(Vec *anchor_list,double *direction_list,double *direction2_list,
             double *l_list,int *flag,int *flag2);
    ~Parking();
    int findlot();
    int getsize() { return size; };
    void draw();
    void gotolot(Vec *anchor_,double *direction_,int position);
    void enterticket(int number);
    void exitticket(int number);
};

class Car : public Vehicle{
public:
    Car(Vec anchor_,double direction_);
    ~Car();
    void draw() override;
    int gotolot(Vec *anchor_list,double *direction_list,
                int position,double *direction2_list,double *l_list,int *flag,int *flag2) override;
private:
    ColorFig *fig[4];
};
class UFO :public Vehicle{
public:
    UFO(Vec anchor_,double direction_,double direction2_);
    ~UFO();
    int price() {return 0;}
    void draw() override;
    int gotolot(Vec *anchor_list,double *direction_list,
                int position,double *direction2_list,double *l_list,int *flag,int *flag2) override;
private:
    ColorFig *fig[5];
    double direction2;
};
class Spacecraft :public Vehicle{
public:
    Spacecraft(Vec anchor_,double direction_,double l_);
    ~Spacecraft();
    int price() {return 0;}
    void draw() override;
    void zoom(double *l_list,int *flag2);
    int gotolot(Vec *anchor_list,double *direction_list,
                int position,double *direction2_list,double *l_list,int *flag,int *flag2) override;
private:
    ColorFig *fig[4];
    double l;
};
class Teleported :public Vehicle{
public:
    Teleported(Vec anchor_,double direction_);
    ~Teleported();
    void draw() override;
    int gotolot(Vec *anchor_list,double *direction_list,
                int position,double *direction2_list,double *l_list,int *flag,int *flag2)
                {Vec z(0,0);
        *anchor_list=*anchor_list+z;*direction_list/=1;position/=1;*direction2_list/=1;
                *l_list/=1;*flag/=1;*flag2/=1;return 0;}
private:
    void paint(double*r,double*g,double*b);
    ColorFig *fig[1];
};
class RegularCar:public RegularVehicle
{
public:
    RegularCar(int number_,int type_,time_t current_);
    ~RegularCar()= default;
    int price();
};
class Van:public RegularVehicle
{
public:
    Van(int number_,int type_,time_t current_);
    ~Van()= default;
    int price();
};


class Bicycle:public RegularVehicle
{
public:
    Bicycle(int number_,int type_,time_t current_);
    ~Bicycle()= default;
    int price();
};

class Motorbike:public RegularVehicle
{
public:
    Motorbike(int number_,int type_,time_t current_);
    ~Motorbike()= default;
    int price();
};
#endif