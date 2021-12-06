#pragma once
#ifndef _crawfish_h
#define _crawfish_h
#include "animal.h"
class crawfish : public animal
{
public:
	crawfish();
	crawfish(int x, int y, bool direc);

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
#endif
