#include "dog.h"
#include "animal.h"
#include "console.h"
#include <iostream>
using namespace std;

dog::dog() : animal() {}

dog::dog(int x, int y) : animal(x, y) {}

void dog::draw() {
	//row 1
	gotoXY(m_x + 3, m_y - 1);
	cout << char(220);
	gotoXY(m_x + 2, m_y - 1);
	cout << char(219);
	gotoXY(m_x + 1, m_y - 1);
	cout << char(219);

	//row 2
	gotoXY(m_x + 1, m_y);
	cout << char(219);
	gotoXY(m_x, m_y);
	cout << char(220);
	gotoXY(m_x - 1, m_y);
	cout << char(220);
	gotoXY(m_x - 2, m_y);
	cout << char(220);
	gotoXY(m_x - 3, m_y);
	cout << char(219);

	//row 3
	gotoXY(m_x + 1, m_y + 1);
	cout << char(223);
	gotoXY(m_x, m_y + 1);
	cout << char(219);
	gotoXY(m_x - 1, m_y + 1);
	cout << char(223);
	gotoXY(m_x - 2, m_y + 1);
	cout << char(219);
	gotoXY(m_x - 3, m_y + 1);
	cout << char(223);
}

void dog::deleteChar() {
	//row 1
	gotoXY(m_x + 3, m_y - 1);
	cout << " ";
	gotoXY(m_x + 2, m_y - 1);
	cout << " ";
	gotoXY(m_x + 1, m_y - 1);
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
}
