#include "truck.h"


truck::truck() {}

truck::truck(int x,int y,bool direction):vehicle(x,y,direction){}

void truck::drawBackward()
{
	TextColor(4);
	gotoXY(this->getX(), this->getY());
	cout << "       ___________";
	gotoXY(this->getX(), this->getY() + 1);
	cout << "  ____|           |";
	gotoXY(this->getX(), this->getY() + 2);
	cout << " //__||----OOP----|";
	gotoXY(this->getX(), this->getY() + 3);
	cout << "|_____|___________|";
	gotoXY(this->getX(), this->getY() + 4);
	cout << " `(+).........(+)`";
	TextColor(7);
}

void truck::drawForward()
{
	TextColor(4);
	gotoXY(this->getX(), this->getY());
	cout << " ___________";
	gotoXY(this->getX(), this->getY() + 1);
	cout << "|           |____";
	gotoXY(this->getX(), this->getY() + 2);
	cout << "|----OOP----||__\\\\";
	gotoXY(this->getX(), this->getY() + 3);
	cout << "|___________|_____|";
	gotoXY(this->getX(), this->getY() + 4);
	cout << " `(+).........(+)`";
	TextColor(7);
}

void truck::draw()
{
	if (direction)
		drawForward();
	else
		drawBackward();
}

void truck::deleteCharBackward()
{
	gotoXY(this->getX(), this->getY());
	cout << "                  ";
	gotoXY(this->getX(), this->getY() + 1);
	cout << "                   ";
	gotoXY(this->getX(), this->getY() + 2);
	cout << "                   ";
	gotoXY(this->getX(), this->getY() + 3);
	cout << "                   ";
	gotoXY(this->getX(), this->getY() + 4);
	cout << "                  ";
}

void truck::deleteCharForward()
{
	TextColor(4);
	gotoXY(this->getX(), this->getY());
	cout << "            ";
	gotoXY(this->getX(), this->getY() + 1);
	cout << "                 ";
	gotoXY(this->getX(), this->getY() + 2);
	cout << "                  ";
	gotoXY(this->getX(), this->getY() + 3);
	cout << "                   ";
	gotoXY(this->getX(), this->getY() + 4);
	cout << "                  ";
	TextColor(7);
}

void truck::deleteChar()
{
	if (direction)
		deleteCharForward();
	else
		deleteCharBackward();
}

bool truck::checkCrashForward(people p)
{
	for (int i = 1; i <= 11; i++)
	{
		if (this->getX() + i == p.getX() + 1 && (this->getY() == p.getY() || this->getY() == p.getY() + 2))
			return true;

		if ((this->getX() + i == p.getX() || this->getX() + i == p.getX() + 2) && (this->getY() == p.getY() + 1))
			return true;
	}

	if (this->getY() + 1 == p.getY() || this->getY() + 1 == p.getY() + 2)
	{
		if (this->getX() == p.getX() + 1)
			return true;

		for (int i = 12; i <= 15; i++)
			if (this->getX() + i == p.getX() + 1)
				return true;
	}

	if (this->getY() + 1 == p.getY() + 1)
	{
		if (this->getX() == p.getX() || this->getX() == p.getX() + 2)
			return true;

		for (int i = 12; i <= 15; i++)
			if (this->getX() + i == p.getX() || this->getX() + i == p.getX() + 2)
				return true;
	}

	if (this->getY() + 2 == p.getY() || this->getY() + 2 == p.getY() + 2)
	{
		if (this->getX() == p.getX() + 1 || this->getX() + 17 == p.getX() + 1)
			return true;
	}

	if (this->getY() + 2 == p.getY() + 1)
	{
		if (this->getX() == p.getX() || this->getX() + 17 == p.getX())
			return true;

		if (this->getX() == p.getX() + 2 || this->getX() + 17 == p.getX() + 2)
			return true;
	}

	if (this->getY() + 3 == p.getY() || this->getY() + 3 == p.getY() + 2)
	{
		if (this->getX() == p.getX() + 1 || this->getX() + 18 == p.getX() + 1)
			return true;
	}

	if (this->getY() + 3 == p.getY() + 1)
	{
		if (this->getX() == p.getX() || this->getX() + 18 == p.getX())
			return true;

		if (this->getX() == p.getX() + 2 || this->getX() + 18 == p.getX() + 2)
			return true;
	}

	for (int i = 1; i <= 17; i++)
	{
		if (this->getX() + i == p.getX() + 1 && (this->getY() + 4 == p.getY() || this->getY() + 4 == p.getY() + 2))
			return true;

		if ((this->getX() + i == p.getX() || this->getX() + i == p.getX() + 2) && (this->getY() + 4 == p.getY() + 1))
			return true;
	}

	return false;
}

bool truck::checkCrashBackward(people p)
{
	for (int i = 7; i <= 17; i++)
	{
		if (this->getX() + i == p.getX() + 1 && (this->getY() == p.getY() || this->getY() == p.getY() + 2))
			return true;

		if ((this->getX() + i == p.getX() || this->getX() + i == p.getX() + 2) && (this->getY() == p.getY() + 1))
			return true;
	}

	if (this->getY() + 1 == p.getY() || this->getY() + 1 == p.getY() + 2)
	{
		for (int i = 2; i <= 5; i++)
			if (this->getX() + i == p.getX() + 1)
				return true;

		if (this->getX() + 18 == p.getX() + 1)
			return true;
	}

	if (this->getY() + 1 == p.getY() + 1)
	{
		for (int i = 2; i <= 5; i++)
			if (this->getX() + i == p.getX() || this->getX() + i == p.getX() + 2)
				return true;

		if (this->getX() + 18 == p.getX() || this->getX() + 18 == p.getX() + 2)
			return true;
	}

	if (this->getY() + 2 == p.getY() || this->getY() + 2 == p.getY() + 2)
	{
		if (this->getX() + 1 == p.getX() + 1 || this->getX() + 18 == p.getX() + 1)
			return true;
	}

	if (this->getY() + 2 == p.getY() + 1)
	{
		if (this->getX() + 1 == p.getX() || this->getX() + 18 == p.getX())
			return true;

		if (this->getX() + 1 == p.getX() + 2 || this->getX() + 18 == p.getX() + 2)
			return true;
	}

	if (this->getY() + 3 == p.getY() || this->getY() + 3 == p.getY() + 2)
	{
		if (this->getX() == p.getX() + 1 || this->getX() + 18 == p.getX() + 1)
			return true;
	}

	if (this->getY() + 3 == p.getY() + 1)
	{
		if (this->getX() == p.getX() || this->getX() + 18 == p.getX())
			return true;

		if (this->getX() == p.getX() + 2 || this->getX() + 18 == p.getX() + 2)
			return true;
	}

	for (int i = 1; i <= 17; i++)
	{
		if (this->getX() + i == p.getX() + 1 && (this->getY() + 4 == p.getY() || this->getY() + 4 == p.getY() + 2))
			return true;

		if ((this->getX() + i == p.getX() || this->getX() + i == p.getX() + 2) && (this->getY() + 4 == p.getY() + 1))
			return true;
	}

	return false;
}

bool truck::checkCrash(people p)
{
	if (direction)
		return checkCrashForward(p);
	else
		return checkCrashBackward(p);
}

void truck::move()
{
	int x = this->getX();
	int y = this->getY();

	if (direction)
	{
		++x;
		if (this->getX() + 18 >= WIDTH)
			x = 0;
	}
	else
	{
		--x;
		if (this->getX() <= 0)
			x = WIDTH - 18;
	}

	this->moveXY(x, y);
}