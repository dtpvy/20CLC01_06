#pragma once
#pragma comment(lib,"winmm.lib")
#ifndef _game_h
#define _game_h
#include "console.h"
#include "people.h"
#include "vehicle.h"
#include "animal.h"
#include "lane.h"
#include <thread>
#include <vector>
#include <string>
#include <conio.h>
#include <fstream>
#include <time.h>

#define cWidth 1280
#define cHeight 600
#define WIDTH 115
#define GHEIGHT 31
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
	int lv;
	int lvMax;
	vector<lane> laneArr;
	bool sound;
public:
	game();
	~game();
	void drawLane();
	void drawPlayer();
	void drawGame();
	void drawHome();
	void drawMenuGame();
	void drawMenuHome();
	void createGame();
	void updatePosPeople(char c);
	bool lvUp();
	int getLvMax();
	void drawDie();
	void drawWin();
	int speedGame();
	int getLane();
	people getPeople();
	bool isRunning();
	void resetGame();
	void exitGame(thread* t);
	void startGame(int lvMax);
	void loadGame();
	void loadGame(HANDLE t);
	void saveGame(HANDLE t);
	void settingGame();
	void pauseGame(HANDLE t);
	void resumeGame(HANDLE t);
	void updateLane();
	bool checkLane();
	void playSound(char* name, bool sound);
};

#endif // !_game_h

