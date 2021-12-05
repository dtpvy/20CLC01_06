#ifndef TRUCK_H_
#define TRUCK_H_

#include "vehicle.h"

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

	void move();
};

#endif // !TRUCK_H_



