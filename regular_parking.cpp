//
// Created by Administrator on 2020/12/12 0012.
//

#include "parkinglot.h"
using namespace std;

int Parking::findlot()
{
    for (int i = 0; i < size; i++)
    {
        if (b[i].isempty())
        {
            b[i].changestate();
            return b[i].getposition();
        }
    }
    return -1;
}
int RegularVehicle::getpos() {return pos;}
void RegularVehicle::setpos(int x) {pos=x;}
void Parking::enterticket(int number)
{
    a0[number]->setpos(findlot());
    if (a0[number]->getpos()==-1) {cout << "NO EMPTY SLOT ANY MORE!" << endl; return;}
    cout << "***** enterticket *****\n";
    int* strtime = new int[6];
    auto now=time(NULL);
    tm* time = localtime(&now);
    strtime[0] = time->tm_year + 1900;
    strtime[1] = time->tm_mon + 1;
    strtime[2] = time->tm_mday;
    strtime[3] = time->tm_hour;
    strtime[4] = time->tm_min;
    strtime[5] = time->tm_sec;
    cout << "Time of arrival: " << strtime[0] << "." << strtime[1] << "." << strtime[2] << " " << strtime[3] << ":" << strtime[4] << ":" << strtime[5] << endl;
    sleep(1);
    cout << "Type of vehicle: " << a0[number]->getname() << endl;
    //cout<<  a[number]->price() << endl;
    cout << "Empty slot is in position " << a0[number]->getpos();
    if (a0[number]->getType() <= 1) cout << " at the first floor" << endl;
    else cout << " at the second floor" << endl;
    cout << "**********************\n";
    delete[] strtime;
}
void Lot::changestate() { state = 1; }
void Parking::exitticket(int number)
{
    if (a0[number]->getpos()==-1) return;
    cout << "***** exitticket *****\n";
    cout << "Time spent in parking lot: " << time(NULL) - a0[number]->getArrival() << " seconds" << endl;
    cout << "Type of vehicle: " << a0[number]->getname() << endl;
    cout << "Price: " << a0[number]->price() << endl;
    cout << "**********************\n";
}
Parking::Parking(int size_, int num_)
{
    status = 0;
    int r;
    size = size_;
    num = num_;
    b = new Lot[size];
    for (int i = 0; i < size; i++)
    {
        b[i].setposition(i);
    }
    for (int i = 0; i < num; i++)
    {
        r = rand() % 4;
        //cout << r << " ";
        switch (r)
        {
            case 0:
                a0[i] = new RegularCar(i, 0, time(nullptr));
                break;
            case 1:
                a0[i] = new Van(i, 1, time(nullptr));
                break;
            case 2:
                a0[i] = new Motorbike(i, 2, time(nullptr));
                break;
            case 3:
                a0[i] = new Bicycle(i, 3, time(nullptr));
                break;
            default:
                a0[i] = new Bicycle(i, 3, time(nullptr));
        }
    }
}
