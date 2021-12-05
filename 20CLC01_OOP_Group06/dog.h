#pragma once
#ifndef _dog_h
#define _dog_h
#include "animal.h"

class dog : public animal
{
public:
	dog();
	dog(int x, int y);
	void draw();
	void deleteChar();
	void move(int velocity);
};

#endif // !_dog_h