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
public:
	lane();
	void createLane(int type, bool _light, int num, int y);
	void createLane(int type, int num, int y);
	void draw();
	void updateLane();
	void updateLightTraffic();
	void deleteChar();
	bool checkLane(people p);
	void reset();
	void add(int type, int x, int y);
	void set(int type, int _light, light tLight, int _direction);
	void set(int type, int _light, int _direction);
	bool writeFile(fstream& fo);
	vehicle* createVehicle(int type, int x, int y);
	animal* createAnimal(int type, int x, int y);
	
};



//static const int LENGTH = 128; // so thu nghiem
//	
//
//class Map
//{
//private:
//
//public:
//	virtual void draw(int x, int y, int step, int start_index) = 0;
//	virtual int LengthOfLane() = 0;
//	virtual void Erase(int x, int y) = 0;
//	virtual void Light_execution(int x, int y, int lane_index, int& pos) = 0;
//	virtual void LoadCharacter() = 0;
//};
//
//
//class Map1 : public Map
//{
//private:
//	vector<pair<int, pair<int,string>>> RawLane; 
	//{
	//	{0,"                    0000000000                      0000000000                     0000000000                          0000000000                      0000000000"}, //0
	//	{0,"                    0000000000                      0000000000                     0000000000                          0000000000                      0000000000"}, //1
	//	{-2,"             XXXX      XXXX                   XXXX XXXX XXXX             XXXX          XXXX XXXX   XXXX     XXXX XXXX                     XXXX      XXXX         "}, //2
	//	{-2,"             XXXX      XXXX                   XXXX XXXX XXXX             XXXX          XXXX XXXX   XXXX     XXXX XXXX                     XXXX      XXXX         "}, //3
	//	{1,"     BBBBBBBBBBBB                  BBBBBBBBBBBB               BBBBBBBBBBBB               BBBBBBBBBBBB          BBBBBBBBBBBB                     BBBBBBBBBBBB     "}, //4
	//	{1,"     BBBBBBBBBBBB                  BBBBBBBBBBBB               BBBBBBBBBBBB               BBBBBBBBBBBB          BBBBBBBBBBBB                     BBBBBBBBBBBB     "}, //5
	//	{0,"                             0000000000                       0000000000                 0000000000                 0000000000                  0000000000       "}, //6
	//	{0,"                             0000000000                       0000000000                 0000000000                 0000000000                  0000000000       "}, //7
	//	{2,"    XXXX                  XXXX              XXXX        XXXX             XXXX          XXXX                                      XXXX                            "}, //8
	//	{2,"    XXXX                  XXXX              XXXX        XXXX             XXXX          XXXX                                      XXXX                            "}, //9
	//	{0,"                                                                                                                                                                 "}, //10
	//	{-2,"              DDD                               DDD       CCC                        CCC        DDD                          DDD DDD                             "}, //11
	//	{0,"                                                                                                                                                                 "}, //12
	//	{0,"                                                                                                                                                                 "} //13
	//}; 
	//         <velocity, {color, string}>
	//string eraseStr;
	//vector<pair<bool, int>> Light;
	/*{
		{true,-1}, {true,-1}, {true,105}, {true,105}, {true,-1}, {true,-1}, {true,-1}, {true,-1}, {true,-1}, {true,-1}, {true,-1}, {true,-1}, {true,-1}, {true,-1}
	};*/
	
	//int Stoptime = 18; // khoang 2s

	//vector<vehicle*> vehicleArr;
	//vector<animal*> animalArr;

	// RawLane[i].first = velocity.         RawLane[i].first < 0-> velocity > 0. RawLane[i].first < 0 -> velocity < 0
//public:
//	Map1();
//	void draw(int x, int y, int step, int start_index);
//	int LengthOfLane();
//	void Erase(int x, int y);
//	void Light_execution(int x, int y, int lane_index, int& pos);
//	void LoadCharacter();
//};
//
//
//class lane
//{
//private:
//	Map* cur_state;
//
//public:
//	lane();
//	void TransitionTo(Map* state);
//	void DrawLane(int x, int y, int step, int _start_index);
//	void Erase(int x, int y);
//	int LenOfLane();
//	void LoadCharacter();
//	~lane()
//	{
//		delete cur_state;
//	}
//
//};


#endif // !_lane_h




