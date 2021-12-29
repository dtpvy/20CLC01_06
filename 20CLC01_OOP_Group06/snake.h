#pragma once
#ifndef _snake_h
#define _snake_h
#include "animal.h"

class snake : public animal
{
public:
	snake();
	snake(int x, int y, bool direc);

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


#endif
