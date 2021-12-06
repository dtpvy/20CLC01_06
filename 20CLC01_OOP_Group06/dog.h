#pragma once
#ifndef _dog_h
#define _dog_h
#include "animal.h"

class dog : public animal
{
public:
	dog();
	dog(int x, int y, bool direc);

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

#endif // !_dog_h