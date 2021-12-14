#pragma once
#ifndef _lane_h
#define _lane_h
#include "vehicle.h"
#include "animal.h"
#include "car.h"
#include "dog.h"
#include "crawfish.h"
#include "snake.h"
#include "truck.h"
#include "light.h"
#include "people.h"
#include <vector>
#include "console.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#define WIDTH 115
#define HEIGHT 30

using namespace std;

class lane
{
private:
	int type;
	vector<vehicle*> vehicleArr;
	vector<animal*> animalArr;
	light tLight;
	bool _light;
	bool direction;
	int row;
public:
	lane();
	lane(int y);
	lane(const lane& lane);
	void createLane(int type, bool _light, int num, bool direction, int y);
	void createLane(int type, int num, bool direction, int y);
	void draw();
	void drawLane();
	void deleteLane();
	void updateLane();
	void updateLightTraffic();
	void deleteChar();
	bool checkLane(people p);
	void reset();
	void add(int type, int x, int y);
	void set(int type, int _light, light tLight, int _direction, int row);
	void set(int type, int _light, int _direction, int row);
	void writeFile(fstream& fo);
	vehicle*& createVehicle(int type, int x, int y);
	animal*& createAnimal(int type, int x, int y);
	bool checkInScreen(vehicle* vehicle);
	bool checkInScreen(animal* animal);
	~lane();
};

#endif