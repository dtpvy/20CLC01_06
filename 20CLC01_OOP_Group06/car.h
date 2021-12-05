#pragma once
#ifndef _car_h
#define _car_h

#include "vehicle.h"

class car : public vehicle
{
public:
	car();
	car(int x, int y);
	void draw();
	void deleteChar();
	void run(int velocity);
};


#endif // !_vehicle_h_


