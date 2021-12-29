#pragma once
//#ifndef _vehicle_h
//#define _vehicle_h
#define WIDTH 115
#include "people.h"
#include "point.h"
#include <iostream>
using namespace std;

class vehicle: public point 
{
protected:
	bool direction;		//true:	forward, false: backward
public:
	vehicle();
	vehicle(int x, int y, bool direction_);

	virtual void drawForward() = 0;
	virtual void drawBackward() = 0;
	virtual void draw() = 0;

	virtual void deleteCharForward() = 0;
	virtual void deleteCharBackward() = 0;
	virtual void deleteChar() = 0;

	virtual bool checkCrashForward(people p) = 0;
	virtual bool checkCrashBackward(people p) = 0;
	virtual bool checkCrash(people p) = 0;

	virtual int getLength() = 0;
	virtual bool move() = 0;
};

//#endif // !_vehicle_h_

