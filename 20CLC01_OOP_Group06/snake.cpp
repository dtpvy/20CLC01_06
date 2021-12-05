#include "snake.h"
#include "animal.h"
#include "console.h"
#include <iostream>
using namespace std;

snake::snake():animal() {}

snake::snake(int x,int y){}

void snake::draw() {
	gotoXY(m_x + 3, m_y - 1);
	cout << char(220);
	gotoXY(m_x + 2, m_y - 1);
	cout << char(220);
	gotoXY(m_x + 3, m_y);
	cout << char(219)
	gotoXY(m_x + 2, m_y);
	cout << char(220);
	gotoXY(m_x + 1, m_y);
	cout << char(220);
	gotoXY(m_x, m_y);
	cout << char(220);
	gotoXY(m_x - 1, m_y);
	cout << char(220);
	gotoXY(m_x - 2, m_y);
	cout << char(220);
	gotoXY(m_x - 3, m_y);
	cout << char(220);
}
void snake::deleteChar() {
	gotoXY(m_x + 3, m_y - 1);
	cout << " ";
	gotoXY(m_x + 2, m_y - 1);
	cout << " ";
	gotoXY(m_x + 3, m_y);
	cout << " ";
	gotoXY(m_x + 2, m_y);
	cout << " ";
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
}

void snake::move(int velocity)
{
	int x = (this->getX() + velocity + 5 * 1029) % 1029;
	int y = this->getY();
}