#include "lane.h"

lane::lane()
{
	this->type = 0;
	this->row = HEIGHT;
}

lane::lane(int y)
{
	this->type = 0;
	this->row = y;
}

lane::lane(const lane& lane)
{
	this->type = lane.type;
	for (int i = 0; i < lane.animalArr.size(); i++)
	{
		this->animalArr.push_back(lane.animalArr[i]);
	}
	for (int i = 0; i < lane.vehicleArr.size(); i++)
	{
		this->vehicleArr.push_back(lane.vehicleArr[i]);
	}
	this->row = lane.row;
	this->tLight = lane.tLight;
	this->_light = lane._light;
	this->direction = lane.direction;
}

void lane::createLane(int type, bool _light, int num, bool direction, int y)
{
	this->row = y;
	this->type = type;
	this->_light = _light;
	this->direction = direction;
	if (_light == true)
	{
		tLight.setX(rand() % (WIDTH - 30) + 30);
		tLight.setY(y);
		tLight.set(true, rand() % greenLight);
	}
	if (this->direction)
	{
		int x = rand() % 20;
		for (int i = 0; i < num; i++)
		{
			vehicleArr.push_back(createVehicle(type, x, y));
			x -= (rand() % 20 + 20);
		}
	}
	else
	{
		int x = WIDTH - rand() % 20;
		for (int i = 0; i < num; i++)
		{
			vehicleArr.push_back(createVehicle(type, x, y));
			x += (rand() % 20 + 20);
		}
	}
}

void lane::createLane(int type, int num, bool direction, int y)
{
	this->row = y;
	this->type = type;
	this->direction = direction;
	if (this->direction)
	{
		int x = rand() % 20;
		for (int i = 0; i < num; i++)
		{
			animalArr.push_back(createAnimal(type, x, y));
			x -= rand() % 20 + 15;
		}
	}
	else
	{
		int x = WIDTH - rand() % 20;
		for (int i = 0; i < num; i++)
		{
			animalArr.push_back(createAnimal(type, x, y));
			x += (rand() % 20 + 15);
		}
	}
}

void lane::updateLane()
{
	updateLightTraffic();
	deleteChar();
	int x = WIDTH * (1 - this->direction), y = 0;
	if (vehicleArr.size() > 0)
	{
		if (_light && tLight.getStatus() || !_light) // green light
		{
			for (int i = 0; i < vehicleArr.size(); i++)
			{
				if (this->direction)
				{
					if (!vehicleArr[i]->move())
					{
						x -= rand() % 20;
						int tmp = (vehicleArr.size() + i - 1) % vehicleArr.size();
						if (vehicleArr[tmp]->getX() <= 0)
						{
							x += (vehicleArr[tmp]->getX() - 20);
						}
						else x -= 15;
						y = this->row;
						delete vehicleArr[i];
						vehicleArr[i] = createVehicle(type, x, y);
					}
				}
				else
				{
					if (!vehicleArr[i]->move())
					{
						x += rand() % 20;
						int tmp = (vehicleArr.size() + i - 1) % vehicleArr.size();
						if (vehicleArr[tmp]->getX() + vehicleArr[tmp]->getLength() >= WIDTH)
						{
							x += (vehicleArr[tmp]->getX() + vehicleArr[tmp]->getLength() + 10);
						}
						else x += 15;
						y = this->row;
						delete vehicleArr[i];
						vehicleArr[i] = createVehicle(type, x, y);
					}
				}
			}
		}
		if (_light && !tLight.getStatus())
		{
			for (int i = 0; i < vehicleArr.size(); i++)
			{
				
				if (this->direction)
				{
					if (vehicleArr[i]->getX() + vehicleArr[i]->getLength() <= tLight.getX()) continue;
					if (!vehicleArr[i]->move())
					{
						x -= rand() % 20;
						int tmp = (vehicleArr.size() + i - 1) % vehicleArr.size();
						if (vehicleArr[tmp]->getX() <= 0)
						{
							x += (vehicleArr[tmp]->getX() - 20);
						}
						else x -= 15;
						y = this->row; 
						delete vehicleArr[i];
						vehicleArr[i] = createVehicle(type, x, y);
					}
				}
				else
				{
					if (vehicleArr[i]->getX() >= tLight.getX()) continue;
					if (!vehicleArr[i]->move()) 
					{
						x += rand() % 20;
						int tmp = (vehicleArr.size() + i - 1) % vehicleArr.size();
						if (vehicleArr[tmp]->getX() + vehicleArr[tmp]->getLength() >= WIDTH)
						{
							x += (vehicleArr[tmp]->getX() + vehicleArr[tmp]->getLength() + 10);
						}
						else x += 15;
						y = this->row;
						delete vehicleArr[i];
						vehicleArr[i] = createVehicle(type, x, y);
					}
				}				
			}
		}
	}
	
	for (int i = 0; i < animalArr.size(); i++)
	{
		if (this->direction)
		{
			if (!animalArr[i]->move())
			{
				x -= rand() % 20;
				int tmp = (animalArr.size() + i - 1) % animalArr.size();
				if (animalArr[tmp]->getX() <= 0)
				{
					x += (animalArr[tmp]->getX() - 15);
				}
				else x -= 20;
				y = this->row;
				delete animalArr[i];
				animalArr[i] = createAnimal(type, x, y);
			}
		}
		else
		{
			if (!animalArr[i]->move())
			{
				x += rand() % 20;
				int tmp = (animalArr.size() + i - 1) % animalArr.size();
				if (animalArr[tmp]->getX() + animalArr[tmp]->getLength() >= WIDTH)
				{
					x += (animalArr[tmp]->getX() + animalArr[tmp]->getLength() + 10);
				}
				else x += 20;
				y = this->row;
				delete animalArr[i];
				animalArr[i] = createAnimal(type, x, y);
			}
		}
	}
}

void lane::updateLightTraffic()
{
	if (_light == true)
	{
		tLight.updateTime();
	}
}

bool lane::checkLane(people p)
{
	int ok = 1;
	for (int i = 0; i < vehicleArr.size(); i++)
	{
		if (vehicleArr[i]->checkCrash(p))
		{
			ok = 0;
			break;
		}
	}

	for (int i = 0; i < animalArr.size(); i++)
	{
		if (animalArr[i]->checkCrash(p))
		{
			ok = 0;
			break;
		}
	}
	return ok;
}

void lane::writeFile(fstream& fo)
{
	fo << this->type << " " << this->_light << " " << this->direction;
	if (this->_light)
	{
		fo << " ";
		this->tLight.writeFile(fo);
	}
	fo << endl;
	if (type == 1 || type == 2)
	{
		fo << vehicleArr.size() << " ";
		for (int i = 0; i < vehicleArr.size(); i++)
		{
			vehicleArr[i]->writeFile(fo);
			fo << " ";
		}
	}
	
	if (type == 3 || type == 4 || type == 5)
	{
		fo << animalArr.size() << " ";
		for (int i = 0; i < animalArr.size(); i++)
		{
			animalArr[i]->writeFile(fo);
			fo << " ";
		}
	}
}

vehicle*& lane::createVehicle(int type, int x, int y)
{
	vehicle* tmp;
	switch (type)
	{
	case 1:
	{
		tmp = new car(x, y, this->direction);
		break;
	}
	case 2:
	{
		tmp = new truck(x, y, this->direction);
		break;
	}
	}
	return tmp;
}


animal*& lane::createAnimal(int type, int x, int y)
{
	animal* tmp;
	switch (type)
	{
	case 3:
	{
		tmp = new dog(x, y, this->direction);
		break;
	}
	case 4:
	{
		tmp = new snake(x, y, this->direction);
		break;
	}
	case 5:
	{
		tmp = new crawfish(x, y, this->direction);
		break;
	}
	}
	return tmp;
}

bool lane::checkInScreen(vehicle* vehicle)
{
	if (vehicle->getX() > 2 && vehicle->getX() + vehicle->getLength() < WIDTH)
	{
		return true;
	}
	return false;
}

bool lane::checkInScreen(animal* animal)
{
	if (animal->getX() > 2 && animal->getX() + animal->getLength() < WIDTH)
	{
		return true;
	}
	return false;
}


void lane::draw()
{
	for (int i = 0; i < vehicleArr.size(); i++)
	{
		if (checkInScreen(vehicleArr[i]))
		{
			vehicleArr[i]->draw();
		}

	}
	for (int i = 0; i < animalArr.size(); i++)
	{
		if (checkInScreen(animalArr[i]))
		{
			animalArr[i]->draw();
		}

	}
}

void lane::drawLane()
{
	if (this->type == 0)
	{
		TextColor(ColorCode_Grey);
		if (row - 3 > 0)
		{
			for (int i = 2; i < WIDTH; i++)
			{
				gotoXY(i, this->row - 3);
				cout << (char)205;
			}
		}
	}
	else 
	{
		TextColor(ColorCode_DarkWhite);
		if (row - 1 > 0)
		{
			for (int i = 1; i < WIDTH; i++)
			{
				if (i % 5 != 0)
				{
					gotoXY(i, this->row - 1);
					cout << (char)205;
				}
			}
		}

		draw();
		if (_light)
		{
			tLight.draw();
		}
	}
}

void lane::deleteChar()
{
	for (int i = 0; i < vehicleArr.size(); i++)
	{
		if (checkInScreen(vehicleArr[i]))
		{
			vehicleArr[i]->deleteChar();
		}
	}
	for (int i = 0; i < animalArr.size(); i++)
	{
		if (checkInScreen(animalArr[i]))
		{
			animalArr[i]->deleteChar();
		}
		
	}
}

void lane::reset()
{
	//int coor_Y;
	//if ((this->type == 1 || this->type == 2) && !vehicleArr.empty())
	//{
	//	coor_Y = vehicleArr[0]->getY();
	//	vehicleArr.clear();
	//	createLane(this->type, this->_light, 4, coor_Y);
	//	if(this->_light)
	//		tLight.set(true, 0);
	//}
	//else
	//{
	//	coor_Y = animalArr[0]->getY();
	//	animalArr.clear();
	//	createLane(this->type, 4, coor_Y);
	//}
}

void lane::add(int type, int x, int y)
{
	if (type == 1 || type == 2) // vehicles
	{
		vehicleArr.push_back(createVehicle(type, x, y));
	}
	else
	{
		animalArr.push_back(createAnimal(type, x, y));
	}
}

void lane::set(int type, int _light, light tLight, int _direction, int row)
{
	this->type = type;
	this->_light = _light;
	this->tLight = tLight;
	this->direction = _direction;
	this->row = row;
}

void lane::set(int type, int light, int _direction, int row)
{
	this->type = type;
	this->_light = light;
	this->direction = _direction;
	this->row = row;
}

