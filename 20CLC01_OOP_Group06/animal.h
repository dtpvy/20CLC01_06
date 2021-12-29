#pragma once
#ifndef _animal_h
#define _animal_h

#include "point.h"
#define WIDTH 115
#include "people.h"

class animal : public point
{
protected:
	bool direction;	//true:	forward, false: backward
public:
	animal();
	animal(int x, int y,bool direc);

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

#endif // !_animal_h



