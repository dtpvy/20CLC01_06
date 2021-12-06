#include <iostream>
using namespace std;

#include "car.h"
#include "vehicle.h"
#include "console.h"

car::car(){}

car::car(int x,int y,bool direction):vehicle(x,y,direction){}

void car::drawForward()
{
    TextColor(9);
    gotoXY(this->getX(), this->getY());
    cout << "   __________";
    gotoXY(this->getX(), this->getY() + 1);
    cout << "  /  /|    \\ \\___";
    gotoXY(this->getX(), this->getY() + 2);
    cout << " |  /_|_____\\    \\";
    gotoXY(this->getX(), this->getY() + 3);
    cout << "(________________|";
    gotoXY(this->getX(), this->getY() + 4);
    cout << "`(+).........(+)`";
    TextColor(7);
}

void car::drawBackward()
{
    TextColor(9);
    gotoXY(this->getX(), this->getY());
    cout << "      __________";
    gotoXY(this->getX(), this->getY() + 1);
    cout << "  ___/ /    |\\  \\  ";
    gotoXY(this->getX(), this->getY() + 2);
    cout << " /    /_____|_\\  |";
    gotoXY(this->getX(), this->getY() + 3);
    cout << "|________________)";
    gotoXY(this->getX(), this->getY() + 4);
    cout << " `(+)........(+)`";
    TextColor(7);
}

void car::draw()
{
    if (direction)
        drawForward();
    else
        drawBackward();
}

void car::deleteCharForward()
{
    gotoXY(this->getX(), this->getY());
    cout << "             ";
    gotoXY(this->getX(), this->getY() + 1);
    cout << "                 ";
    gotoXY(this->getX(), this->getY() + 2);
    cout << "                  ";
    gotoXY(this->getX(), this->getY() + 3);
    cout << "                  ";
    gotoXY(this->getX(), this->getY() + 4);
    cout << "                 ";
}

void car::deleteCharBackward()
{
    TextColor(9);
    gotoXY(this->getX(), this->getY());
    cout << "                ";
    gotoXY(this->getX(), this->getY() + 1);
    cout << "                   ";
    gotoXY(this->getX(), this->getY() + 2);
    cout << "                  ";
    gotoXY(this->getX(), this->getY() + 3);
    cout << "                  ";
    gotoXY(this->getX(), this->getY() + 4);
    cout << "                 ";
    TextColor(7);
}

void car::deleteChar()
{
    if (direction)
        deleteCharForward();
    else
        deleteCharBackward();
}

bool car::checkCrashForward(people p)
{
    for (int i = 3; i <= 12; i++)
    {
        if (this->getX() + i == p.getX() + 1 && (this->getY() == p.getY() || this->getY() == p.getY() + 2))
            return true;

        if ((this->getX() + i == p.getX() || this->getX() + i == p.getX() + 2) && this->getY() == p.getY() + 1)
            return true;
    }

    if (this->getY() + 1 == p.getY() || this->getY() + 1 == p.getY() + 2)
    {
        if (this->getX() + 2 == p.getX() + 1)
            return true;

        for (int i = 13; i <= 16; i++)
            if (this->getX() + i == p.getX() + 1)
                return true;
    }

    if (this->getY() + 1 == p.getY() + 1)
    {
        if (this->getX() + 2 == p.getX() || this->getX() + 2 == p.getX())
            return true;

        for (int i = 13; i <= 16; i++)
            if (this->getX() + i == p.getX() || this->getX() + i == p.getX() + 2)
                return true;
    }

    if (this->getY() + 2 == p.getY() || this->getY() + 2 == p.getY() + 2)
    {
        if ((this->getX() + 1 == p.getX() + 1) || (this->getX() + 17 == p.getX() + 1))
            return true;
    }

    if (this->getY() + 2 == p.getY() + 1)
    {
        if ((this->getX() + 1 == p.getX()) || (this->getX() + 17 == p.getX()))
            return true;

        if ((this->getX() + 1 == p.getX() + 2) || (this->getX() + 17 == p.getX() + 2))
            return true;
    }

    if (this->getY() + 3 == p.getY() || this->getY() + 3 == p.getY() + 2)
    {
        if ((this->getX() == p.getX() + 1) || (this->getX() + 17 == p.getX() + 1))
            return true;
    }

    if (this->getY() + 3 == p.getY() + 1)
    {
        if ((this->getX() == p.getX()) || (this->getX() + 17 == p.getX()))
            return true;

        if ((this->getX() == p.getX() + 2) || (this->getX() + 17 == p.getX() + 2))
            return true;
    }

    for (int i = 1; i <= 16; i++)
    {
        if (this->getX() + i == p.getX() + 1 && (this->getY() + 4 == p.getY() || this->getY() + 4 == p.getY() + 2))
            return true;

        if ((this->getX() + i == p.getX() || this->getX() + i == p.getX() + 2) && (this->getY() + 4 == p.getY() + 1))
            return true;
    }

    return false;
}

bool car::checkCrashBackward( people p)
{
    for (int i = 5; i <= 14; i++)
    {
        if (this->getX() + i == p.getX() + 1 && (this->getY() == p.getY() || this->getY() == p.getY() + 2))
            return true;

        if ((this->getX() + i == p.getX() || this->getX() + i == p.getX() + 2) && (this->getY() == p.getY() + 1))
            return true;
    }

    if (this->getY() + 1 == p.getY() || this->getY() + 1 == p.getY() + 2)
    {
        for (int i = 1; i <= 4; i++)
            if (this->getX() + i == p.getX() + 1)
                return true;

        if (this->getX() + 15 == p.getX() + 1)
            return true;
    }

    if (this->getY() + 1 == p.getY() + 1)
    {
        for (int i = 1; i <= 4; i++)
            if (this->getX() + i == p.getX() || this->getX() + i == p.getX() + 2)
                return true;

        if (this->getX() + 15 == p.getX() || this->getX() + 15 == p.getX() + 2)
            return true;
    }

    if (this->getY() + 2 == p.getY() || this->getY() + 2 == p.getY() + 2)
    {
        if ((this->getX() == p.getX() + 1) || (this->getX() + 16 == p.getX() + 1))
            return true;
    }

    if (this->getY() + 2 == p.getY() + 1)
    {
        if ((this->getX() == p.getX()) || (this->getX() + 16 == p.getX()))
            return true;

        if ((this->getX() == p.getX()) || (this->getX() + 16 == p.getX() + 2))
            return true;
    }

    if (this->getY() + 3 == p.getY() || this->getY() + 3 == p.getY() + 2)
    {
        if ((this->getX() == p.getX() + 1) || (this->getX() + 17 == p.getX() + 1))
            return true;
    }

    if (this->getY() + 3 == p.getY() + 1)
    {
        if ((this->getX() == p.getX()) || (this->getX() + 17 == p.getX()))
            return true;

        if ((this->getX() == p.getX()) || (this->getX() + 17 == p.getX() + 2))
            return true;
    }

    for (int i = 1; i <= 16; i++)
    {
        if (this->getX() + i == p.getX() + 1 && (this->getY() + 4 == p.getY() || this->getY() + 4 == p.getY() + 2))
            return true;

        if ((this->getX() + i == p.getX() || this->getX() + i == p.getX() + 2) && (this->getY() + 4 == p.getY() + 1))
            return true;
    }

    return false;
}

bool car::checkCrash( people p)
{
    if (direction)
        return checkCrashForward(p);
    else
        return checkCrashBackward(p);
}

void car::move()
{
    int x = this->getX();
    int y = this->getY();

    if (direction)
    {
        ++x;
        if (this->getX() + 17 >= WIDTH)
            x = 0;
    }
    else
    {
        --x;
        if (this->getX() <= 0)
            x = WIDTH - 17;
    }

    this->moveXY(x, y);
}