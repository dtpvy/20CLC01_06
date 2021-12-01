#pragma once
#ifndef _vehicle_h
#define _vehicle_h

#define WIDTH 115
#define HEIGHT 36
#include "point.h"

class vehicle: public point 
{
public:
	vehicle();
	vehicle(int x, int y);
	virtual void draw() = 0;
	virtual void deleteChar() = 0;
	virtual void run() = 0;
};


#endif // !_vehicle_h_



