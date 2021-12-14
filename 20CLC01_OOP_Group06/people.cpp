#include "people.h"


people::people(): point((bRIGHT + bLEFT) / 2, bBOTTOM)
{
	this->m_State = true;
}

void people::goUp()
{
	if (this->getY() - 1 < bTOP) return;
	this->moveXY(this->getX(), this->getY() - 1);
}


void people::goDown()
{
	if (this->getY() + 1 > bBOTTOM) return;
	this->moveXY(this->getX(), this->getY() + 1);
}

void people::goRight()
{
	if (this->getX() + 1 > bRIGHT) return;
	this->moveXY(this->getX() + 1, this->getY());
}

void people::goLeft()
{
	if (this->getX() - 1 < bLEFT) return;
	this->moveXY(this->getX() - 1, this->getY());
}

void people::reset()
{
	this->setStatus(true);
	this->moveXY((bRIGHT + bLEFT) / 2, bBOTTOM);
}

bool people::isFinish()
{
	return ((this->getY() == 0 ) && this->m_State);
}

bool people::isDead()
{
	return !m_State;
}

void people::draw()
{
	TextColor(14);
	gotoXY(this->getX() + 1, this->getY());
	cout << (char)2;
	TextColor(11);
	gotoXY(this->getX(), this->getY() + 1);
	cout << "<" << (char)178 << ">";
	TextColor(10);
	gotoXY(this->getX() + 1, this->getY() + 2);
	cout << (char)206;
}

void people::deleteChar()
{
	TextColor(0);
	gotoXY(this->getX() + 1, this->getY());
	cout << (char)219;
	gotoXY(this->getX(), this->getY() + 1);
	cout << (char)219 << (char)219 << (char)219;
	gotoXY(this->getX() + 1, this->getY() + 2);
	cout << (char)219;
}

void people::setStatus(bool status)
{
	this->m_State = status;
}


