#include "people.h"


people::people(): point((bRIGHT + 7) / 2, bBOTTOM)
{
	this->m_State = true;
	this->remain = LIFE;
	old_X = point::getX();
	old_Y = point::getY();
}

void people::goUp()
{
	old_X = point::getX();
	old_Y = point::getY();
	if (old_Y >= bTOP)
		return;
	point::setY(old_Y - 1);
}


void people::goDown()
{
	old_X = point::getX();
	old_Y = point::getY();
	if (old_Y <= bBOTTOM)
		return;
	point::setY(old_Y + 1);
}

void people::goRight()
{
	old_X = point::getX();
	old_Y = point::getY();
	if (old_X >= bRIGHT)
		return;
	point::setX(old_X + 1);
}

void people::goLeft()
{
	old_X = point::getX();
	old_Y = point::getY();
	if (old_X <= bLEFT)
		return;
	point::setX(old_X - 1);
}

void people::reset()
{
	remain -= 1;
	point::setX((bRIGHT + 7) / 2);
	point::setY(bBOTTOM);
	this->old_X = point::getX();
	this->old_Y = point::getY();
	this->m_State = true;
}

bool people::isFinish()
{
	if (point::getX() == bTOP && remain > 0)
		return true;
	else
		return false;
}

bool people::isDead()
{
	if (remain <= 0)
		return true;
	else
		return false;
}

void people::draw()
{
	TextColor(14);
	gotoXY(point::getX() + 1, point::getY());
	cout << (char)2;
	TextColor(11);
	gotoXY(point::getX(), point::getY() + 1);
	cout << "<" << (char)178 << ">";
	TextColor(10);
	gotoXY(point::getX() + 1, point::getY() + 2);
	cout << (char)206;
}

void people::deleteChar()
{
	TextColor(0);
	gotoXY(old_X + 1, old_Y);
	cout << (char)219;
	gotoXY(old_X, old_Y + 1);
	cout << (char)219 << (char)219 << (char)219;
	gotoXY(old_X + 1, old_Y + 2);
	cout << (char)219;
}


