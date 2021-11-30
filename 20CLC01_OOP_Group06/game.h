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
#define cWidth 1036
#define cHeight 600
#define UP 72
#define LEFT 75
#define RIGHT 77
#define DOWN 80
using namespace std;

class game
{
private:
	people player;
	int score;
	vector<lane> laneArr;
public:
	game();
	~game();
	void drawGame();
	void drawHome();
	void drawMenuGame(int x, int y);
	void drawMenuHome();
	void createGame(int size);
	void updatePosPeople(int c);
	void lvUp();
	void gameSetting();
	void drawDie();
	int speedGame(int y);
	int getLane();
	void Delete();
	bool isRunning();
	void resetGame();
	void exitGame(HANDLE);
	void startGame();
	void loadGame();
	void saveGame();
	void settingGame();
	void pauseGame(HANDLE t);
	void resumeGame(HANDLE t);
	void updateLane();
};

#endif // !_game_h



