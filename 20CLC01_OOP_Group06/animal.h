#pragma once
#ifndef _animal_h
#define _animal_h
#include "point.h"

#include "people.h"
class animal : public point
{
public:
	animal();
	animal(int x, int y);
	virtual void draw() = 0;
	virtual void deleteChar() = 0;
	virtual bool checkCrash(people p) = 0;
	virtual void move() = 0;
};


#endif // !_animal_h



