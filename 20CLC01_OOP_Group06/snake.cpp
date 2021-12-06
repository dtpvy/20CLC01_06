#include "snake.h"
#include "animal.h"
#include "console.h"
#include <iostream>
using namespace std;

snake::snake(): animal() {}

snake::snake(int x,int y,bool direc):animal(x,y,direc) {}

void snake::drawForward() {
	// row 1
	gotoXY(this->getX() + 6, this->getY());
	cout << char(220);
	gotoXY(this->getX() + 5, this->getY());
	cout << char(220);
	//row 2
	gotoXY(this->getX() + 5, this->getY() + 1);
	cout << char(219);
	gotoXY(this->getX() + 4, this->getY() + 1);
	cout << char(220);
	gotoXY(this->getX() + 3, this->getY() + 1);
	cout << char(220);
	gotoXY(this->getX() + 2, this->getY() + 1);
	cout << char(220);
	gotoXY(this->getX() + 1, this->getY() + 1);
	cout << char(220);
	gotoXY(this->getX(), this->getY() + 1);
	cout << char(220);
}

void snake::drawBackward() {
	// row 1
	gotoXY(this->getX(), this->getY());
	cout << char(220);
	gotoXY(this->getX() + 1, this->getY());
	cout << char(220);
	//row 2
	gotoXY(this->getX() + 1, this->getY() + 1);
	cout << char(219);
	gotoXY(this->getX() + 2, this->getY() + 1);
	cout << char(220);
	gotoXY(this->getX() + 3, this->getY() + 1);
	cout << char(220);
	gotoXY(this->getX() + 4, this->getY() + 1);
	cout << char(220);
	gotoXY(this->getX() + 5, this->getY() + 1);
	cout << char(220);
	gotoXY(this->getX() + 6, this->getY() + 1);
	cout << char(220);
}
void snake::draw() {
	if (direction) {
		drawForward();
	}
	else drawBackward();
}

void snake::deleteCharForward() {
	// row 1
	gotoXY(this->getX() + 6, this->getY());
	cout << " ";
	gotoXY(this->getX() + 5, this->getY());
	cout << " ";
	//row 2
	gotoXY(this->getX() + 5, this->getY() + 1);
	cout << " ";
	gotoXY(this->getX() + 4, this->getY() + 1);
	cout << " ";
	gotoXY(this->getX() + 3, this->getY() + 1);
	cout << " ";
	gotoXY(this->getX() + 2, this->getY() + 1);
	cout << " ";
	gotoXY(this->getX() + 1, this->getY() + 1);
	cout << " ";
	gotoXY(this->getX(), this->getY() + 1);
	cout << " ";
}

void snake::deleteCharBackward() {
	// row 1
	gotoXY(this->getX(), this->getY());
	cout << " ";
	gotoXY(this->getX() + 1, this->getY());
	cout << " ";
	//row 2
	gotoXY(this->getX() + 1, this->getY() + 1);
	cout << " ";
	gotoXY(this->getX() + 2, this->getY() + 1);
	cout << " ";
	gotoXY(this->getX() + 3, this->getY() + 1);
	cout << " ";
	gotoXY(this->getX() + 4, this->getY() + 1);
	cout << " ";
	gotoXY(this->getX() + 5, this->getY() + 1);
	cout << " ";
	gotoXY(this->getX() + 6, this->getY() + 1);
	cout << " ";
}

void snake::deleteChar() {
	if (direction) {
		deleteCharForward();
	}
	else deleteCharBackward();
}

bool snake::checkCrashForward(people p) {
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 7; j++) {
			if (this->getX() + j == p.getX() && this->getY() + i == p.getY()) {
				return true;
			}
		}
	}
	return false;
}

bool snake::checkCrashBackward(people p) {
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 7; j++) {
			if (this->getX() + j == p.getX() && this->getY() + i == p.getY()) {
				return true;
			}
		}
	}
	return false;
}

bool snake::checkCrash(people p) {
	if (direction)
		return checkCrashForward(p);
	else
		return checkCrashBackward(p);
}

void snake::move()
{
	int x = this->getX();
	int y = this->getY();

	if (direction) {
		++x;
		if (this->getX() + 6 >= WIDTH) {
			x = 0;
		}
	}
	else {
		--x;
		if (this->getX() <= 0) {
			x = WIDTH - 6;
		}
	}
	this->moveXY(x, y);
}