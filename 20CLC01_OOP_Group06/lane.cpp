#include "lane.h"


lane::lane()
{
	srand((unsigned int)time(NULL));
	this->direction = rand()*5 % 2;
	if (rand() % 2 == 0) // negative
	{
		this->direction = -1 * this->direction;
	}
}

void lane::createLane(int type, bool _light, int num, int y)
{
	srand(time(NULL));
	this->type = type;
	this->_light = _light;
	if (_light == true)
	{
		tLight.setX(rand() % (WIDHT / 2) + WIDHT / 2);
		tLight.setY(y);
	}
	int x = 0;
	for (int i = 0; i < num; i++)
	{
		x += -(rand() % (i * 5 + 10));
		vehicleArr.push_back(createVehicle(type, x, y));
	}
}

void lane::createLane(int type, int num, int y)
{
	this->type = type;
	int x = 0;
	for (int i = 0; i < num; i++)
	{
		x += -(rand() % (i * 5 + 10));
		animalArr.push_back(createAnimal(type, x, y));
	}
}

void lane::updateLane()
{
	if (_light && tLight.getStatus()) // green light
	{
		for (int i = 0; i < vehicleArr.size(); i++)
		{
			vehicleArr[i]->deleteChar();
			vehicleArr[i]->move();
		}
	}
	for (int i = 0; i < animalArr.size(); i++)
	{
		animalArr[i]->deleteChar();
		animalArr[i]->move();
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

bool lane::writeFile(fstream& fo)
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

vehicle* lane::createVehicle(int type, int x, int y)
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
}


animal* lane::createAnimal(int type, int x, int y)
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
}


void lane::draw()
{
	this->updateLane();
	for (int i = 0; i < vehicleArr.size(); i++)
	{
		vehicleArr[i]->draw();
	}
	for (int j = 0; j < animalArr.size(); j++)
	{
		animalArr[j]->draw();
	}
	
	if (_light)
		tLight.draw();

	if (!vehicleArr.empty())
	{
		int Y = vehicleArr[0]->getY();
		TextColor(14);
		for (int i = 0; i < 5; i++)
		{
			gotoXY(0, Y + i);
			cout << "     " << (char)186 << "  ";
			gotoXY(WIDTH - 7, Y + i);
			cout << "  " << (char)186 << "     ";
		}
	}
	else if (!animalArr.empty())
	{
		TextColor(14);
		for (int i = 0; i < 2; i++)
		{
			gotoXY(0, animalArr[0]->getY() + i);
			cout << "     " << (char)186 << "  ";
			gotoXY(WIDTH - 7, animalArr[0]->getY() + i);
			cout << "  " << (char)186 << "     ";
		}
	}

}

void lane::deleteChar()
{
	for (int i = 0; i < vehicleArr.size(); i++)
	{
		vehicleArr[i]->deleteChar();
	}
	for (int i = 0; i < animalArr.size(); i++)
	{
		animalArr[i]->deleteChar();
	}
}

void lane::reset()
{
	int coor_Y;
	if ((this->type == 1 || this->type == 2) && !vehicleArr.empty())
	{
		coor_Y = vehicleArr[0]->getY();
		vehicleArr.clear();
		createLane(this->type, this->_light, 4, coor_Y);
		if(this->_light)
			tLight.set(true, 0);
	}
	else
	{
		coor_Y = animalArr[0]->getY();
		animalArr.clear();
		createLane(this->type, 4, coor_Y);
	}
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

void lane::set(int type, int _light, light tLight, int _direction)
{
	this->type = type;
	this->_light = _light;
	this->tLight = tLight;
	this->direction = _direction;
}

void lane::set(int type, int light, int _direction)
{
	this->type = type;
	this->_light = light;
	this->direction = _direction;
}


//void lane::TransitionTo(Map* state)
//{
//	if (cur_state)
//		delete cur_state;
//	cur_state = state;
//}
//
//void lane::DrawLane(int x, int y, int step, int _start_index)
//{
//	if (!cur_state)
//		return;
//	cur_state->draw(x, y, step, _start_index);
//}
//
//void lane::Erase(int x, int y)
//{
//	if (!cur_state)
//		return;
//	cur_state->Erase(x, y);
//}
//
//int lane::LenOfLane()
//{
//	if (!cur_state)
//		return -1;
//	return cur_state->LengthOfLane();
//}

/////MAP 1////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//Map1::Map1()
//{
//	this->RawLane = 
//	{
//		{0, { 7,"                    0000000000                      0000000000                     0000000000                          0000000000                      0000000000" }}, //0
//		{0, { 7,"                    0000000000                      0000000000                     0000000000                          0000000000                      0000000000"}}, //1
//		{-2,{ 7,"             XXXX      XXXX                   XXXX XXXX XXXX             XXXX          XXXX XXXX   XXXX     XXXX XXXX                     XXXX      XXXX         "}}, //2 
//		{-2,{ 7,"             XXXX      XXXX                   XXXX XXXX XXXX             XXXX          XXXX XXXX   XXXX     XXXX XXXX                     XXXX      XXXX         "}}, //3
//		{1, { 7,"     BBBBBBBBBBBB                  BBBBBBBBBBBB               BBBBBBBBBBBB               BBBBBBBBBBBB          BBBBBBBBBBBB                     BBBBBBBBBBBB     "}}, //4
//		{1, { 7,"     BBBBBBBBBBBB                  BBBBBBBBBBBB               BBBBBBBBBBBB               BBBBBBBBBBBB          BBBBBBBBBBBB                     BBBBBBBBBBBB     "}}, //5
//		{0, { 7,"                             0000000000                       0000000000                 0000000000                 0000000000                  0000000000       "}}, //6
//		{0, { 7,"                             0000000000                       0000000000                 0000000000                 0000000000                  0000000000       "}}, //7
//		{2, { 7,"    XXXX                  XXXX              XXXX        XXXX             XXXX          XXXX                                      XXXX                            "}}, //8
//		{2, { 7,"    XXXX                  XXXX              XXXX        XXXX             XXXX          XXXX                                      XXXX                            "}}, //9
//		{0, { 7,"                                                                                                                                                                 "}}, //10
//		{-2,{ 7,"              DDD                               DDD       CCC                        CCC        DDD                          DDD DDD                             "}}, //11
//		{0, { 7,"                                                                                                                                                                 "}}, //12
//		{0, { 7,"                                                                                                                                                                 "}} //13
//	};
//	this->eraseStr = "                                                                                                                               ";
//	this->Light =
//	{
//		{true,-1}, {true,-1}, {true,105}, {true,105}, {true,-1}, {true,-1}, {true,-1}, {true,-1}, {true,-1}, {true,-1}, {true,-1}, {true,-1}, {true,-1}, {true,-1}
//	};
//}
//
//void Map1::draw(int x, int y, int step, int start_index)
//{
//	int _step = 0;
//	string handling("");
//	int totalLanes = RawLane.size();
//	int lenOfLane = RawLane[0].second.second.length();
//	int pos, last_pos;
//	for (int i = 0; i < totalLanes; i++)
//	{
//		gotoXY(x, y + _step);
//		pos = (start_index * RawLane[i].first + 2 * lenOfLane) % lenOfLane;
//		Light_execution(x, y + _step, i, pos);
//		last_pos = (pos + LENGTH) % lenOfLane;
//		if (last_pos > pos)
//		{
//			handling.append(RawLane[i].second.second, pos, last_pos - pos);
//		}
//		//else if(RawLane[i].first >= 0) // velocity < 0
//		//{
//		//	handling.append(RawLane[i].second, pos, lenOfLane - pos);
//		//	handling.append(RawLane[i].second, 0, last_pos);
//		//}
//		//else // velocity >= 0 
//		//{
//		//	handling.append(RawLane[i].second, 0, last_pos);
//		//	handling.append(RawLane[i].second, pos, lenOfLane - pos);
//		//}
//		else
//		{
//			handling.append(RawLane[i].second.second, pos, lenOfLane - pos);
//			handling.append(RawLane[i].second.second, 0, last_pos);
//		}
//		TextColor(RawLane[i].second.first);
//		cout << handling;
//		handling.clear();
//		_step += step;
//	}
//}
//
//int Map1::LengthOfLane()
//{
//	return RawLane[0].second.second.length();
//}
//
//void Map1::Erase(int x, int y)
//{
//	int numLanes = RawLane.size();
//	for (int i = 0; i < numLanes; i++)
//	{
//		gotoXY(x, y);
//		cout << eraseStr;
//		y += 1;
//	}
//}
//
//void Map1::Light_execution(int x, int y, int lane_index, int& pos)
//{
//	if (Light[lane_index].first == true) // running - green light
//	{
//		if (Light[lane_index].second < 0)
//		{
//			cout << " ";
//			return;
//		}
//		else if (pos == Light[lane_index].second)
//		{
//			Light[lane_index].second = (pos + RawLane[lane_index].first * Stoptime + RawLane[lane_index].second.second.length()) % RawLane[lane_index].second.second.length();
//			Light[lane_index].first = false;
//			TextColor(12);
//			cout << (char)15;
//			TextColor(7);
//			return; // turn into red light
//		}
//	}
//	else // stopping - red light
//	{
//		if (Light[lane_index].second < 0)
//		{
//			cout << " ";
//			return;
//		}
//		else if (pos != Light[lane_index].second)
//		{
//			pos = Light[lane_index].second;
//			TextColor(12);
//			cout << (char)15;
//			TextColor(7);
//			return; // still red light
//		}
//		else
//		{
//			pos = Light[lane_index].second;
//			Light[lane_index].first = true;
//		}
//	}
//	TextColor(10);
//	cout << (char)15;
//	TextColor(7);  // turn into green light
//}
//
//void Map1::LoadCharacter()
//{
//
//}

