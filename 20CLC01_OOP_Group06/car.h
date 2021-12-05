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
<<<<<<< HEAD

	bool checkCrashForward(const people& p);
	bool checkCrashBackward(const people& p);
	bool checkCrash(const people& p);

	void move();
=======
	void run(int velocity);
>>>>>>> 581a1e25e0709523f775537a4f704d7d6ef7123b
};


#endif // !_vehicle_h_


