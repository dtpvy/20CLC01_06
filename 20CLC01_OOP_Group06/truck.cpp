#include <iostream>
using namespace std;

#include "vehicle.h"
#include "console.h"
#include "truck.h"
#include "point.h"

truck::truck() {}

truck::truck(int x,int y):vehicle(x,y){}

void truck::draw()
{
	TextColor(4);
	gotoXY(this->getX(), this->getY());
	cout << "____________";
	gotoXY(this->getX() - 5, this->getY() + 1);
	cout << " ____|           |";
	gotoXY(this->getX() - 5, this->getY() + 2);
	cout << "//__||----OOP----|";
	gotoXY(this->getX() - 6, this->getY() + 3);
	cout << "|_____|___________|";
	gotoXY(this->getX() - 5, this->getY() + 4);
	cout << " `(+)........(+)`";
	TextColor(7);
}

void truck::deleteChar()
{
	gotoXY(this->getX(), this->getY());
	cout << "            ";
	gotoXY(this->getX() - 5, this->getY() + 1);
	cout << "                    ";
	gotoXY(this->getX() - 5, this->getY() + 2);
	cout << "                  ";
	gotoXY(this->getX() - 6, this->getY() + 3);
	cout << "                   ";
	gotoXY(this->getX() - 5, this->getY() + 4);
	cout << "                 ";
}

void truck::run(int velocity)
{
	int x = (this->getX() + velocity + 5 * 1029) % 1029;
	int y = this->getY();

	if (x - 6 <= 0)
		x = WIDTH - 12;

	this->moveXY(x, y);
}
