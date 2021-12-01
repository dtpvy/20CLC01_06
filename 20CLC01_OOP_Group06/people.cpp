#include "people.h"


people::people()
{
	this->m_State = true;
	X = bRIGHT / 2 - 1;
	Y = bBOTTOM - 1;
	this->remain = LIFE;
}

void people::goUp()
{
	if (this->Y == bTOP)
		return;
	else
		Y -= 1;
}


void people::goDown()
{
	if (this->Y == bBOTTOM - 1)
		return;
	else
		Y += 1;
}

void people::goRight()
{
	if (this->X == bRIGHT)
		return;
	else
	X += 1;
}

void people::goLeft()
{
	if (this->X == bLEFT)
		return;
	else
		X -= 1;
}

void people::reset()
{
	this->X = bRIGHT / 2 - 1;
	this->Y = bBOTTOM - 1;
	this->m_State = true;
}

bool people::isFinish()
{
	if (this->X == bTOP && remain > 0)
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

void people::draw(int Hcolor, int Bcolor)
{
	TextColor(Hcolor);
	gotoXY(this->X, this->Y);
	cout << (char)148;
	gotoXY(this->X, this->Y + 1);
	TextColor(Bcolor);
	cout << (char)234;
}

void people::deleteChar()
{
	gotoXY(this->X, this->Y);
	cout << " ";
	gotoXY(this->X, this->Y + 1);
	cout << " ";
}

bool people::isImpact()
{

}

