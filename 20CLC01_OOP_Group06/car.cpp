#include <iostream>
using namespace std;

#include "car.h"
#include "vehicle.h"
#include "console.h"

car::car(){}

car::car(int x,int y):vehicle(x,y){}

void car::draw()
{
    TextColor(9);
    gotoXY(this->getX(), this->getY());
    cout << "   __________";
    gotoXY(this->getX(), this->getY() + 1);
    cout << "  /  /|    \\ \\___";
    gotoXY(this->getX(), this->getY() + 2);
    cout << " |  /_|_____\\    B";
    gotoXY(this->getX(), this->getY() + 3);
    cout << "(________________|";
    gotoXY(this->getX(), this->getY() + 4);
    cout << "`(+).........(+)`";
    TextColor(7);
}

void car::deleteChar()
{
    gotoXY(this->getX(), this->getY());
    cout << "             ";
    gotoXY(this->getX(), this->getY() + 1);
    cout << "                   ";
    gotoXY(this->getX(), this->getY() + 2);
    cout << "                   ";
    gotoXY(this->getX(), this->getY() + 3);
    cout << "                  ";
    gotoXY(this->getX(), this->getY() + 4);
    cout << "                 ";
}

void car::run()
{
    int x = this->getX() + 1;
    int y = this->getY();
   
    if (x+ 17 >= WIDTH)
        x = 0;

    this->moveXY(x,y);
}