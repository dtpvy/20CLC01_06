#pragma once
#ifndef _car_h
#define _car_h

#include "vehicle.h"
#include "console.h"
#include <iostream>
using namespace std;

class car : public vehicle
{
public:
	car();
	car(int x, int y, bool direction);

	void drawForward();
	void drawBackward();
	void draw();

	bool checkCrashForward(people p);
	bool checkCrashBackward(people p);
	bool checkCrash(people p);

	void deleteCharForward();
	void deleteCharBackward();
	void deleteChar();

	int getLength();
	bool move();
};


#endif // !_vehicle_h_
