#pragma once
#ifndef _game_h
#define _game_h
#include "console.h"
#include "people.h"
#include "vehicle.h"
#include "animal.h"
#include "lane.h"
#include <vector>
#include <string>
#include <conio.h>
#include <fstream>
#include <time.h>
using namespace std;

class game
{
private:
	people user;
	int score;
	vector<lane> laneArr;
public:
	game();
	~game();
	void drawGame();
	void drawMenu1();
	void drawMenu2();
	void createGame(int level);
	void updatePosPeople(char);
	void lvUp();
	void gameSetting();
	void drawDie();
	int speedGame();
	int getLevel();
	int getLane();
	void Delete();
	bool isRunning();
	void resetGame(int lv);
	void exitGame(HANDLE);
	void startGame();
	void loadGame();
	void saveGame();
	void pauseGame(HANDLE);
	void resumeGame(HANDLE);
};

#endif // !_game_h



