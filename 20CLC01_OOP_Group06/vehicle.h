#pragma once
#ifndef _vehicle_h
#define _vehicle_h
#include "point.h"

class vehicle: public point 
{
public:
	vehicle();
	vehicle(int x, int y);
	virtual void draw() = 0;
	virtual void deleteChar() = 0;
	virtual bool checkCrash() = 0;
	void stop();
	void run();
};


#endif // !_vehicle_h_



