//
// Created by Administrator on 2020/12/12 0012.
//
#include "parkinglot.h"
string RegularVehicle::getname(){
    switch(type)
    {
        case 0:
            return "Car";
        case 1:
            return "Van";
        case 2:
            return "Motorbike";
        case 3:
            return "Bicycle";
        default:
            break;
    }
    return "";
}
int RegularVehicle::getnum(){return number;}
int RegularVehicle::getType(){return type;}
time_t RegularVehicle::getArrival() {return current;}

int Van::price()
{
    time_t now=time(NULL);
    return VAN*(int)(now-current);
}
Van::Van(int number_,int type_,time_t current_)
{
    number=number_;
    type=type_;
    current=current_;
}

int RegularCar::price()
{
    time_t now=time(NULL);
    return MOTORBIKE*(int)(now-current);
}
int Motorbike::price()
{
    time_t now=time(NULL);
    return MOTORBIKE*(int)(now-current);
}
Motorbike::Motorbike(int number_,int type_,time_t current_)
{
    number=number_;
    type=type_;
    current=current_;
}
RegularCar::RegularCar(int number_,int type_,time_t current_)
{
    number=number_;
    type=type_;
    current=current_;
}

int Bicycle::price()
{
    time_t now=time(NULL);
    return BICYCLE*(int)(now-current);
}
Bicycle::Bicycle(int number_,int type_,time_t current_)
{
    number=number_;
    type=type_;
    current=current_;
}


