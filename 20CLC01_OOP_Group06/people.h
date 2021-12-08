#pragma once
#ifndef _people_h
#define _people_h
#include "point.h"
#include "console.h"

static const int bLEFT = 7;
static const int bTOP = 0;
static const int bRIGHT = 70; 
static const int bBOTTOM = 28; 
static const int LIFE = 3;

class people: public point
{
private:
	bool m_State;
	int remain;
	int old_X, old_Y;

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


