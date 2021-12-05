#pragma once
#ifndef _snake_h
#define _snake_h
#include "animal.h"
class snake : public animal
{
public:
	snake();
	snake(int x, int y);
	void draw();
	void deleteChar();
	void move(int velocity);
};


#endif
