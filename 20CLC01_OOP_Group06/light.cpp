#include "light.h"

light::light()
{
	this->_status = true;
	this->_time = 0;
}

bool light::getStatus()
{
	return this->_status;
}

int light::getTime()
{
	return this->_time;
}

void light::set(bool status, int time)
{
	this->_status = status;
	this->_time = time;
}

void light::changeStatus()
{
	if (this->_status)
	{
		this->_status = false;
	}
	else
	{
		this->_status = true;
	}
}

void light::updateTime()
{
	this->_time++;
	if (this->_status && this->_time == greenLight)
	{
		this->changeStatus();
		this->_time = 0;
	}
	else if (this->_status == false && this->_time == redLight)
	{
		this->changeStatus();
		this->_time = 0;
	}
}


void light::draw()
{
	if (this->_status) // green light
	{
		gotoXY(X, Y);
		TextColor(10);
		cout << (char)220;
		TextColor(8);
		gotoXY(X, Y + 1);
		cout << (char)223;
	}
	else
	{
		gotoXY(X, Y);
		TextColor(8);
		cout << (char)220;
		TextColor(12);
		gotoXY(X, Y + 1);
		cout << (char)223;
	}
}

void light::setX(int x)
{
	this->_status = x;
}

void light::setY(int y)
{
	this->_time = y;
}

void light::writeFile(fstream& fo)
{
	fo << this->_status << " " << this->_time << " " << this->X << " " << this->Y;
}