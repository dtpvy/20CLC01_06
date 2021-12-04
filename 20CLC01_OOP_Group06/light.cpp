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
