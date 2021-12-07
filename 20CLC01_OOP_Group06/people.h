#pragma once
#ifndef _people_h
#define _people_h
#include "point.h"
#include "car.h"
#include "console.h"

static const int bLEFT = 7;
static const int bTOP = 1;
static const int bRIGHT = 108; 
static const int bBOTTOM = 33; 
static const int LIFE = 3;

class people: public point
{
private:
	bool m_State;
	int X, Y;
	int old_X, old_Y;
	int remain;
public:
	people();
	//people(int,int)
	void reset();
	void goUp();
	void goLeft();
	void goRight();
	void goDown();
	bool isFinish();
	bool isDead();
	void draw();     
	void deleteChar();
};

#endif // !_people_h


