#pragma once
#ifndef _people_h
#define _people_h
#include "point.h"
#include "car.h"

class people: public point
{
private:
	bool m_State;
public:
	people();
	people(int, int);
	void reset();
	void goUp();
	void goLeft();
	void goRight();
	void goDown();
	bool isFinish();
	bool isDead();
	void draw();     
	void deleteChar();
	bool isImpact(car* carArr, int lane);
};

#endif // !_people_h


