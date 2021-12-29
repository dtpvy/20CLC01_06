#pragma once
#ifndef _TRUCK_H_
#define _TRUCK_H_

#include "vehicle.h"
#include "console.h"
#include <iostream>
using namespace std;

class truck:public vehicle
{
public:
	truck();
	truck(int x, int y,bool direction);

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

#endif // !TRUCK_H_



