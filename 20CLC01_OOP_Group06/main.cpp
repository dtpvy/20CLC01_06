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
	//system("cls");
	//cg->drawMenuGame();
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
			cg->getPeople().draw();
			cg->drawDie();
			system("pause");
		}
		if (cg->getPeople().isFinish())
		{
			if (cg->lvUp())
			{
				cg->drawWin();
				system("pause");
			}
		}
		Sleep(cg->speedGame());
	}
}

int main()
{
	ShowCur(false);
	cg = new game;
	char temp;
	SetWindowSize(cWidth, cHeight);
	cg->drawMenuHome();
	thread* t1 = new thread(SubThread);
	while (1)
	{
		ShowCur(false);
		temp = toupper(_getch());
		if (!cg->getPeople().isDead())
		{
			if (temp == 'E' || temp == 27)
			{
				
				cg->resetGame();
				cg->exitGame(t1);
				cg->drawMenuHome();
				t1 = new thread(SubThread);
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
				cg->resetLv();
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
			else if (temp == 'E' || temp == 27) {
				cg->resetGame();
				cg->exitGame(t1);
				t1 = new thread(SubThread);
			}
		}
	}
	return 0;
}