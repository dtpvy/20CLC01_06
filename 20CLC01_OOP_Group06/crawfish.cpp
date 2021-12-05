#include "crawfish.h"
#include "console.h"
#include "animal.h"
#include <iostream>
using namespace std;

crawfish::crawfish() : animal() {}

crawfish::crawfish(int x, int y) : animal(x, y) {}

void crawfish::draw() {
	//row 1
	gotoXY(m_x + 3, m_y - 1);
	cout << char(220);
	gotoXY(m_x + 2, m_y - 1);
	cout << char(220);
	gotoXY(m_x + 1, m_y - 1);
	cout << char(220);
	gotoXY(m_x - 3, m_y - 1);
	cout << char(220);

	//row 2
	gotoXY(m_x + 1, m_y);
	cout << char(220);
	gotoXY(m_x, m_y);
	cout << char(219);
	gotoXY(m_x - 1, m_y);
	cout << char(220);
	gotoXY(m_x - 2, m_y);
	cout << char(220);
	gotoXY(m_x - 3, m_y);
	cout << char(222);

	//row 3
	gotoXY(m_x + 1, m_y + 1);
	cout << char(223);
	gotoXY(m_x, m_y + 1);
	cout << char(219);
	gotoXY(m_x - 1, m_y + 1);
	cout << char(223);
	gotoXY(m_x - 2, m_y + 1);
	cout << char(223);
	gotoXY(m_x - 3, m_y + 1);
	cout << char(222);

	//row 4
	gotoXY(m_x + 3, m_y + 2);
	cout << char(223);
	gotoXY(m_x + 2, m_y + 2);
	cout << char(223);
	gotoXY(m_x + 1, m_y + 2);
	cout << char(223);
	gotoXY(m_x - 3, m_y + 2);
	cout << char(223);
}

void crawfish::deleteChar() {
	//row 1
	gotoXY(m_x + 3, m_y - 1);
	cout << " ";
	gotoXY(m_x + 2, m_y - 1);
	cout << " ";
	gotoXY(m_x + 1, m_y - 1);
	cout << " ";
	gotoXY(m_x - 3, m_y - 1);
	cout << " ";

	//row 2
	gotoXY(m_x + 1, m_y);
	cout << " ";
	gotoXY(m_x, m_y);
	cout << " ";
	gotoXY(m_x - 1, m_y);
	cout << " ";
	gotoXY(m_x - 2, m_y);
	cout << " ";
	gotoXY(m_x - 3, m_y);
	cout << " ";

	//row 3
	gotoXY(m_x + 1, m_y + 1);
	cout << " ";
	gotoXY(m_x, m_y + 1);
	cout << " ";
	gotoXY(m_x - 1, m_y + 1);
	cout << " ";
	gotoXY(m_x - 2, m_y + 1);
	cout << " ";
	gotoXY(m_x - 3, m_y + 1);
	cout << " ";

	//row 4
	gotoXY(m_x + 3, m_y + 2);
	cout << " ";
	gotoXY(m_x + 2, m_y + 2);
	cout << " ";
	gotoXY(m_x + 1, m_y + 2);
	cout << " ";
	gotoXY(m_x - 3, m_y + 2);
	cout << " ";
}

void crawfish::move(int velocity)
{
	int x = (this->getX() + velocity + 5 * 1029) % 1029;
	int y = this->getY();
}