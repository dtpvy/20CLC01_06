#pragma once
#ifndef _people_h
#define _people_h
#include "point.h"
#include "car.h"
#include "console.h"

static const int bLEFT = 0;
static const int bTOP = 1;
static const int bRIGHT = 1023; // so minh hoa, chinh sua sau
static const int bBOTTOM = 549; // so minh hoa, chinh sua sau
static const int LIFE = 3;

class people: public point
{
private:
	bool m_State;
	int X, Y;
	int remain;
public:
	people();
	people(int, int);
	void reset();
	void goUp();
	void goLeft();
	void goRight();
	void goDown();
	bool isFinish();
	bool isDead();
	void draw(int Hcolor, int Bcolor);     
	void deleteChar();
};

#endif // !_people_h


