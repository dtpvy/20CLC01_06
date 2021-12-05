#pragma once
#ifndef _car_h
#define _car_h

#include "vehicle.h"

class car : public vehicle
{
public:
	car();
	car(int x, int y,bool direction);

	void drawForward();
	void drawBackward();
	void draw();

	void deleteCharForward();
	void deleteCharBackward();
	void deleteChar();

	bool checkCrashForward(people p);
	bool checkCrashBackward(people p);
	bool checkCrash(people p);

	void move();
};


#endif // !_vehicle_h_


