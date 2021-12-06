#include "dog.h"
#include "animal.h"
#include "console.h"
#include <iostream>
using namespace std;

dog::dog() : animal() {}

dog::dog(int x, int y, bool direc) : animal(x, y, direc) {}

void dog::drawForward() {
	//row 1
	gotoXY(this->getX() + 6, this->getY());
	cout << char(220);
	gotoXY(this->getX() + 5, this->getY());
	cout << char(219);
	gotoXY(this->getX() + 4, this->getY());
	cout << char(219);

	//row 2
	gotoXY(this->getX() + 4, this->getY() + 1);
	cout << char(219);
	gotoXY(this->getX() + 3, this->getY() + 1);
	cout << char(220);
	gotoXY(this->getX() + 2, this->getY() + 1);
	cout << char(220);
	gotoXY(this->getX() + 1, this->getY() + 1);
	cout << char(220);
	gotoXY(this->getX(), this->getY() + 1);
	cout << char(219);

	//row 3
	gotoXY(this->getX() + 4, this->getY() + 2);
	cout << char(223);
	gotoXY(this->getX() + 3, this->getY() + 2);
	cout << char(219);
	gotoXY(this->getX() + 2, this->getY() + 2);
	cout << char(223);
	gotoXY(this->getX() + 1, this->getY() + 2);
	cout << char(219);
	gotoXY(this->getX(), this->getY() + 2);
	cout << char(223);
}

void dog::drawBackward() {
	//row 1
	gotoXY(this->getX(), this->getY());
	cout << char(220);
	gotoXY(this->getX() + 1, this->getY());
	cout << char(219);
	gotoXY(this->getX() + 2, this->getY());
	cout << char(219);

	//row 2
	gotoXY(this->getX() + 2, this->getY() + 1);
	cout << char(219);
	gotoXY(this->getX() + 3, this->getY() + 1);
	cout << char(220);
	gotoXY(this->getX() + 4, this->getY() + 1);
	cout << char(220);
	gotoXY(this->getX() + 5, this->getY() + 1);
	cout << char(220);
	gotoXY(this->getX() + 6, this->getY() + 1);
	cout << char(219);

	//row 3
	gotoXY(this->getX() + 2, this->getY() + 2);
	cout << char(223);
	gotoXY(this->getX() + 3, this->getY() + 2);
	cout << char(219);
	gotoXY(this->getX() + 4, this->getY() + 2);
	cout << char(223);
	gotoXY(this->getX() + 5, this->getY() + 2);
	cout << char(219);
	gotoXY(this->getX() + 6, this->getY() + 2);
	cout << char(223);
}

void dog::draw() {
	if (direction) {
		drawForward();
	}
	else drawBackward();
}

void dog::deleteCharForward() {
	//row 1
	gotoXY(this->getX() + 6, this->getY());
	cout << " ";
	gotoXY(this->getX() + 5, this->getY());
	cout << " ";
	gotoXY(this->getX() + 4, this->getY());
	cout << " ";

	//row 2
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

	//row 3
	gotoXY(this->getX() + 4, this->getY() + 2);
	cout << " ";
	gotoXY(this->getX() + 3, this->getY() + 2);
	cout << " ";
	gotoXY(this->getX() + 2, this->getY() + 2);
	cout << " ";
	gotoXY(this->getX() + 1, this->getY() + 2);
	cout << " ";
	gotoXY(this->getX(), this->getY() + 2);
	cout << " ";
}

void dog::deleteCharBackward() {
	//row 1
	gotoXY(this->getX(), this->getY());
	cout << " ";
	gotoXY(this->getX() + 1, this->getY());
	cout << " ";
	gotoXY(this->getX() + 2, this->getY());
	cout << " ";

	//row 2
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

	//row 3
	gotoXY(this->getX() + 2, this->getY() + 2);
	cout << " ";
	gotoXY(this->getX() + 3, this->getY() + 2);
	cout << " ";
	gotoXY(this->getX() + 4, this->getY() + 2);
	cout << " ";
	gotoXY(this->getX() + 5, this->getY() + 2);
	cout << " ";
	gotoXY(this->getX() + 6, this->getY() + 2);
	cout << " ";
}

void dog::deleteChar() {
	if (direction) {
		deleteCharForward();
	}
	else deleteCharBackward();
}

bool dog::checkCrashForward(people p) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 7; j++) {
			if (this->getX() + j == p.getX() && this->getY() + i == p.getY()) {
				return true;
			}
		}
	}
	return false;
}

bool dog::checkCrashBackward(people p) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 7; j++) {
			if (this->getX() + j == p.getX() && this->getY() + i == p.getY()) {
				return true;
			}
		}
	}
	return false;
}

bool dog::checkCrash(people p) {
	if (direction) {
		return checkCrashForward(p);
	}
	else return checkCrashBackward(p);
}

void dog::move()
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