#pragma once
#ifndef _light_h
#define _light_h
#include "point.h"
#define greenLight 10

class light: public point
{
private:
	bool _status;
	int _time;
public:
	light();
	bool getStatus();
	int getTime();
	void set(bool status, int time);
	void changeStatus();
	void updateTime();
};


#endif // !_light_h


