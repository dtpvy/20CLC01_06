#pragma once
#ifndef _lane_h
#define _lane_h
#include "vehicle.h"
#include "animal.h"
#include "light.h"
#include <vector>
using namespace std;

class lane
{
private:
	bool type;
	vector<vehicle*> vehicleArr;
	vector<animal*> animalArr;
	light tLight;
	bool _light;
public:
	lane();
	lane(bool type = true, bool _light = false);
	void drawRoad();
	void drawRoadside();
	void updatePos();
	void updatePosVehicle();
	void updatePosAnimal();
	void updateTraffic();
};

#endif // !_lane_h




