#pragma once

#ifndef _point_h
#define _point_h
#include <fstream>
using namespace std;

class point
{
public:
	point();
	point(int x, int y);
	int getX();
	int getY();
	void setX(int x);
	void setY(int y);
	void moveXY(int x, int y);
	void writeFile(fstream& fo);
	void readFile(fstream& fi);
private:
	int x, y;
};


#endif // !_point_h


