#include "dog.h"
#include "animal.h"
#include "console.h"
#include <iostream>
using namespace std;

dog::dog() : animal() {}

dog::dog(int x, int y) : animal(x, y) {}

void dog::draw() {
	//row 1
	gotoXY(this->getX() + 3, this->getY() - 1);
	cout << char(220);
	gotoXY(this->getX() + 2, this->getY() - 1);
	cout << char(219);
	gotoXY(this->getX() + 1, this->getY() - 1);
	cout << char(219);

	//row 2
	gotoXY(this->getX() + 1, this->getY());
	cout << char(219);
	gotoXY(this->getX(), this->getY());
	cout << char(220);
	gotoXY(this->getX() - 1, this->getY());
	cout << char(220);
	gotoXY(this->getX() - 2, this->getY());
	cout << char(220);
	gotoXY(this->getX() - 3, this->getY());
	cout << char(219);

	//row 3
	gotoXY(this->getX() + 1, this->getY() + 1);
	cout << char(223);
	gotoXY(this->getX(), this->getY() + 1);
	cout << char(219);
	gotoXY(this->getX() - 1, this->getY() + 1);
	cout << char(223);
	gotoXY(this->getX() - 2, this->getY() + 1);
	cout << char(219);
	gotoXY(this->getX() - 3, this->getY() + 1);
	cout << char(223);
}

void dog::deleteChar() {
	//row 1
	gotoXY(this->getX() + 3, this->getY() - 1);
	cout << " ";
	gotoXY(this->getX() + 2, this->getY() - 1);
	cout << " ";
	gotoXY(this->getX() + 1, this->getY() - 1);
	cout << " ";

	//row 2
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

	//row 3
	gotoXY(this->getX() + 1, this->getY() + 1);
	cout << " ";
	gotoXY(this->getX(), this->getY() + 1);
	cout << " ";
	gotoXY(this->getX() - 1, this->getY() + 1);
	cout << " ";
	gotoXY(this->getX() - 2, this->getY() + 1);
	cout << " ";
	gotoXY(this->getX() - 3, this->getY() + 1);
	cout << " ";
}

void dog::move(int velocity)
{
	int x = (this->getX() + velocity + 5 * 1029) % 1029;
	int y = this->getY();
}