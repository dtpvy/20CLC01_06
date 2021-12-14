#include "peoPle.h"
#include "game.h"
#include <conio.h>
#include <thread>
game* cg;
char MOVING;
void SetWindowSize(int width, int height)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, 50, 50, width, height, TRUE);
}

void ShowCur(bool CursorVisibility) // xóa dấu con trỏ
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursor = { 1, CursorVisibility };
	SetConsoleCursorInfo(handle, &cursor);
}

void SubThread()
{
	while (cg->isRunning())
	{
		if (!cg->getPeople().isDead()) //Nếu người vẫn còn sống
		{
			cg->updatePosPeople(MOVING);//Cập nhật vị trí người theo thông tin từ main
		}
		MOVING = ' ';
		cg->updateLane();
		cg->drawGame(); 
		if (cg->checkLane())
		{
			cg->playSound((char*)"stop nen2.mp3", 0);
			cg->playSound((char*)"play die.mp3", 1);
			cg->drawDie();
			system("pause");
		}
		if (cg->getPeople().isFinish())
		{
			if (cg->lvUp())
			{
				cg->playSound((char*)"stop nen2.mp3", 0);
				cg->playSound((char*)"play win.mp3", 1);
				cg->drawWin();
				system("pause");
			}
		}
		Sleep(cg->speedGame());
	}
}


int main()
{
	cg = new game;
	char temp;
	SetWindowSize(cWidth, cHeight);
	cg->playSound((char*)"play nen1.mp3", 1);
	cg->drawMenuHome();
	cg->playSound((char*)"stop nen1.mp3", 0);
	cg->playSound((char*)"play nen2.mp3", 1);
	thread* t1 = new thread(SubThread);
	while (1)
	{
		ShowCur(false);
		temp = toupper(_getch());
		if (!cg->getPeople().isDead())
		{
			if (temp == 'E' || temp == 27)
			{
				cg->exitGame(t1);
			}
			else if (temp == 'P')
			{
				cg->pauseGame((*t1).native_handle());
			}
			else if (temp == 'L')
			{
				cg->pauseGame((*t1).native_handle());
				cg->saveGame((*t1).native_handle());
			}
			else if (temp == 'T')
			{
				cg->pauseGame((*t1).native_handle());
				cg->loadGame((*t1).native_handle());
			}
			else if (temp == 'Y') 
			{
				cg->resetGame();
				cg->startGame(cg->getLvMax());
			}
			else
			{
				cg->resumeGame((*t1).native_handle());
				MOVING = temp; //Cập nhật bước di chuyển
			}
		}
		else
		{
			if (temp == 'Y')
			{
				cg->resetGame();
				cg->startGame(cg->getLvMax());
			}
			else {
				cg->exitGame(t1);
				break;
			}
		}
	}
	return 0;
}