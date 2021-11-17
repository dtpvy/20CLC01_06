#pragma once

#ifndef _point_h
#define _point_h

class point
{
public:
	point();
	point(int x, int y);
	int getX();
	int getY();
	void moveXY(int x, int y);
private:
	int x, y;
};


#endif // !_point_h


