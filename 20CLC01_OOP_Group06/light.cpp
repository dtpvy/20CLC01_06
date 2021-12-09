#include "light.h"

light::light()
{
	this->_status = true;
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
		gotoXY(this->getX(), this->getY());
		TextColor(10);
		cout << (char)220;
		TextColor(8);
		gotoXY(this->getX(), this->getY() + 1);
		cout << (char)223;
	}
	else
	{
		gotoXY(this->getX(), this->getY());
		TextColor(8);
		cout << (char)220;
		TextColor(12);
		gotoXY(this->getX(), this->getY() + 1);
		cout << (char)223;
	}
}

void light::writeFile(fstream& fo)
{
	fo << this->_status << " " << this->_time << " " << this->getX() << " " << this->getY();
}