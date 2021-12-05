#include "people.h"


people::people()
{
	this->m_State = true;
	old_X = X = bRIGHT / 2 - 1;
	old_Y = Y = bBOTTOM - 1;
	this->remain = LIFE;
}

void people::goUp()
{
	if (this->Y == bTOP)
	{
		old_Y = Y;
		old_X = X;
		return;
	}
	else
	{
		old_X = X;
		old_Y = Y;
		Y -= 1;
	}
}


void people::goDown()
{
	if (this->Y == bBOTTOM - 1)
	{
		old_Y = Y;
		old_X = X;
		return;
	}
		
	else
	{
		old_X = X;
		old_Y = Y;
		Y += 1;
	}
}

void people::goRight()
{
	if (this->X == bRIGHT)
	{
		old_X = X;
		old_Y = Y;
		return;
	}
	else
	{
		old_X = X;
		old_Y = Y;
		X += 1;
	}

}

void people::goLeft()
{
	if (this->X == bLEFT)
	{
		old_X = X;
		old_Y = Y;
		return;
	}
	else
	{
		old_X = X;
		old_Y = Y;
		X -= 1;
	}
}

void people::reset()
{
	remain -= 1;
	this->old_X = this->X = bRIGHT / 2 - 1;
	this->old_Y = this->Y = bBOTTOM - 1;
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

void people::draw()
{
	TextColor(14);
	gotoXY(this->X + 1, this->Y);
	cout << (char)2;
	TextColor(11);
	gotoXY(this->X, this->Y + 1);
	cout << "<" << (char)178 << ">";
	TextColor(10);
	gotoXY(this->X + 1, this->Y + 2);
	cout << (char)206;
}

void people::deleteChar()
{
	TextColor(0);
	gotoXY(this->old_X + 1, this->old_Y);
	cout << " ";
	gotoXY(this->old_X, this->old_Y + 1);
	cout << "   ";
	gotoXY(this->old_X + 1, this->old_Y + 2);
	cout << " ";
}


