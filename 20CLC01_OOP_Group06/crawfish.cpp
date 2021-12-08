#include "crawfish.h"
#include "console.h"
#include "animal.h"
#include <iostream>
using namespace std;

crawfish::crawfish() : animal() {}

crawfish::crawfish(int x, int y, bool direc) : animal(x, y, direc) {}

void crawfish::drawForward(){
	//row 1
	gotoXY(this->getX() + 6, this->getY());
	cout << char(220);
	gotoXY(this->getX() + 5, this->getY());
	cout << char(220);
	gotoXY(this->getX() + 4, this->getY());
	cout << char(220);
	gotoXY(this->getX(), this->getY());
	cout << char(220);

	//row 2
	gotoXY(this->getX() + 4, this->getY() + 1);
	cout << char(220);
	gotoXY(this->getX() + 3, this->getY() + 1);
	cout << char(219);
	gotoXY(this->getX() + 2, this->getY() + 1);
	cout << char(220);
	gotoXY(this->getX() + 1, this->getY() + 1);
	cout << char(220);
	gotoXY(this->getX(), this->getY() + 1);
	cout << char(222);

	//row 3
	gotoXY(this->getX() + 4, this->getY() + 2);
	cout << char(223);
	gotoXY(this->getX() + 3, this->getY() + 2);
	cout << char(219);
	gotoXY(this->getX() + 2, this->getX() + 2);
	cout << char(223);
	gotoXY(this->getX() + 1, this->getX() + 2);
	cout << char(223);
	gotoXY(this->getX(), this->getY() + 2);
	cout << char(222);

	//row 4
	gotoXY(this->getX() + 6, this->getY() + 3);
	cout << char(223);
	gotoXY(this->getX() + 5, this->getY() + 3);
	cout << char(223);
	gotoXY(this->getX() + 4, this->getY() + 3);
	cout << char(223);
	gotoXY(this->getX(), this->getY() + 3);
	cout << char(223);
}

void crawfish::drawBackward(){
	//row 1
	gotoXY(this->getX(), this->getY());
	cout << char(220);
	gotoXY(this->getX() + 1, this->getY());
	cout << char(220);
	gotoXY(this->getX() + 2, this->getY());
	cout << char(220);
	gotoXY(this->getX() + 6, this->getY());
	cout << char(220);

	//row 2
	gotoXY(this->getX() + 2, this->getY() + 1);
	cout << char(220);
	gotoXY(this->getX() + 3, this->getY() + 1);
	cout << char(219);
	gotoXY(this->getX() + 4, this->getY() + 1);
	cout << char(220);
	gotoXY(this->getX() + 5, this->getY() + 1);
	cout << char(220);
	gotoXY(this->getX() + 6, this->getY() + 1);
	cout << char(221);

	//row 3
	gotoXY(this->getX() + 2, this->getY() + 2);
	cout << char(223);
	gotoXY(this->getX() + 3, this->getY() + 2);
	cout << char(219);
	gotoXY(this->getX() + 4, this->getX() + 2);
	cout << char(223);
	gotoXY(this->getX() + 5, this->getX() + 2);
	cout << char(223);
	gotoXY(this->getX() + 6, this->getY() + 2);
	cout << char(221);

	//row 4
	gotoXY(this->getX(), this->getY() + 3);
	cout << char(223);
	gotoXY(this->getX() + 1, this->getY() + 3);
	cout << char(223);
	gotoXY(this->getX() + 2, this->getY() + 3);
	cout << char(223);
	gotoXY(this->getX() + 6, this->getY() + 3);
	cout << char(223);
}

void crawfish::draw() {
	if (direction)
		drawForward();
	else
		drawBackward();
}

void crawfish::deleteCharForward(){
	//row 1
	gotoXY(this->getX() + 6, this->getY());
	cout << " ";
	gotoXY(this->getX() + 5, this->getY());
	cout << " ";
	gotoXY(this->getX() + 4, this->getY());
	cout << " ";
	gotoXY(this->getX(), this->getY());
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
	gotoXY(this->getX() + 2, this->getX() + 2);
	cout << " ";
	gotoXY(this->getX() + 1, this->getX() + 2);
	cout << " ";
	gotoXY(this->getX(), this->getY() + 2);
	cout << " ";

	//row 4
	gotoXY(this->getX() + 6, this->getY() + 3);
	cout << " ";
	gotoXY(this->getX() + 5, this->getY() + 3);
	cout << " ";
	gotoXY(this->getX() + 4, this->getY() + 3);
	cout << " ";
	gotoXY(this->getX(), this->getY() + 3);
	cout << " ";
}

void crawfish::deleteCharBackward(){
	//row 1
	gotoXY(this->getX(), this->getY());
	cout << " ";
	gotoXY(this->getX() + 1, this->getY());
	cout << " ";
	gotoXY(this->getX() + 2, this->getY());
	cout << " ";
	gotoXY(this->getX() + 6, this->getY());
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
	gotoXY(this->getX() + 4, this->getX() + 2);
	cout << " ";
	gotoXY(this->getX() + 5, this->getX() + 2);
	cout << " ";
	gotoXY(this->getX() + 6, this->getY() + 2);
	cout << " ";

	//row 4
	gotoXY(this->getX(), this->getY() + 3);
	cout << " ";
	gotoXY(this->getX() + 1, this->getY() + 3);
	cout << " ";
	gotoXY(this->getX() + 2, this->getY() + 3);
	cout << " ";
	gotoXY(this->getX() + 6, this->getY() + 3);
	cout << " ";
}

void crawfish::deleteChar() {
	if (direction)
		deleteCharForward();
	else
		deleteCharBackward();
}

bool crawfish::checkCrashForward(people p) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 7; j++) {
			if (this->getX() + j == p.getX() && this->getY() + i == p.getY()) {
				return true;
			}
		}
	}
	return false;
}

bool crawfish::checkCrashBackward(people p) {
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 7; j++) {
			if (this->getX() + j == p.getX() && this->getY() + i == p.getY()) {
				return true;
			}
		}
	}
	return false;
}

bool crawfish::checkCrash(people p)
{
	if (direction)
		return checkCrashForward(p);
	else
		return checkCrashBackward(p);
}
int crawfish::getLength()
{
	return 6;
}
bool crawfish::move()
{
	int x = this->getX();
	int y = this->getY();

	if (direction) {
		if (this->getX() + 6 >= WIDTH) return false;
		++x;
	}
	else {
		if (this->getX() <= 0) return false;
		--x;
	}
	this->moveXY(x, y);
	return true;
}