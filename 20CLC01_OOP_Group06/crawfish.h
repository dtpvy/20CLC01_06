#pragma once
#ifndef _crawfish_h
#define _crawfish_h
#include "animal.h"
class crawfish : public animal
{
public:
	crawfish();
	crawfish(int x, int y);
	void draw();
	void deleteChar();
};
#endif
