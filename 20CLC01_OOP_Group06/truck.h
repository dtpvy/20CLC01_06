#ifndef TRUCK_H_
#define TRUCK_H_

#include "vehicle.h"

class truck:public vehicle
{
public:
	truck();
	truck(int x, int y);
	void draw();
	void deleteChar();
	void run(int velocity);
};

#endif // !TRUCK_H_



