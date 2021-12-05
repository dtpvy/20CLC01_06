#pragma once
#ifndef _vehicle_h
#define _vehicle_h

#include "people.h"
#define WIDTH 115
#define HEIGHT 36
#include "point.h"

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

	
	virtual bool checkCrashForward(const people& p) = 0;
	virtual bool checkCrashBackward(const people& p) = 0;
	virtual bool checkCrash(const people& p) = 0;

	virtual void move() = 0;
	
};


#endif // !_vehicle_h_



