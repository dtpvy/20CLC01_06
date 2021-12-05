#include "snake.h"
#include "animal.h"
#include "console.h"
#include <iostream>
using namespace std;

snake::snake():animal() {}

snake::snake(int x,int y){}

void snake::draw(int velocity) {
	gotoXY(this->getX() + 3, this->getY() - 1);
	cout << char(220);
	gotoXY(this->getX() + 2, this->getY() - 1);
	cout << char(220);
	gotoXY(this->getX() + 3, this->getY());
	cout << char(219);
	gotoXY(this->getX() + 2, this->getY());
	cout << char(220);
	gotoXY(this->getX() + 1, this->getY());
	cout << char(220);
	gotoXY(this->getX(), this->getY());
	cout << char(220);
	gotoXY(this->getX() - 1, this->getY());
	cout << char(220);
	gotoXY(this->getX() - 2, this->getY());
	cout << char(220);
	gotoXY(this->getX() - 3, this->getY());
	cout << char(220);
}
void snake::deleteChar() {
	gotoXY(this->getX() + 3, this->getY() - 1);
	cout << " ";
	gotoXY(this->getX() + 2, this->getY() - 1);
	cout << " ";
	gotoXY(this->getX() + 3, this->getY());
	cout << " ";
	gotoXY(this->getX() + 2, this->getY());
	cout << " ";
	gotoXY(this->getX() + 1, this->getY());
	cout << " ";
	gotoXY(this->getX(), this->getY());
	cout << " ";
	gotoXY(this->getX() - 1, this->getY());
	cout << " ";
	gotoXY(this->getX() - 2, this->getY());
	cout << " ";
	gotoXY(this->getX() - 3, this->getY());
	cout << " ";
}

void snake::move(int velocity)
{
	int x = (this->getX() + velocity + 5 * 1029) % 1029;
	int y = this->getY();
}