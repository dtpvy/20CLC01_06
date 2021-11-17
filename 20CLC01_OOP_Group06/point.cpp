#include "point.h"

point::point()
{
	this->x = this->y = 0;
}

point::point(int x, int y)
{
	this->x = x;
	this->y = y;
}

int point::getX()
{
	return this->x;
}

int point::getY()
{
	return this->y;
}

void point::moveXY(int x, int y)
{
	this->x = x;
	this->y = y;
}
