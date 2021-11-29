#include "peoPle.h"
#include "game.h"
#include <conio.h>
#include <thread>
game* cg;
char MOVING;
void SetWindowSize(SHORT width, SHORT height)
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	SMALL_RECT WindowSize;
	WindowSize.Top = 0;
	WindowSize.Left = 0;
	WindowSize.Bottom = height;
	WindowSize.Right = width;

	SetConsoleWindowInfo(hStdout, 1, &WindowSize);
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
		//delete[]
		if (!cg->getPeople().isDead()) //Nếu người vẫn còn sống
		{
			cg->updatePosPeople(MOVING);//Cập nhật vị trí người theo thông tin từ main
		}
		MOVING = ' ';// Tạm khóa không cho di chuyển, chờ nhận phím từ hàm main
		if (!cg->getTraffic().getStatus())
		{
			cg->updatePosVehicle();//Cập nhật vị trí xe
		}
		cg->updatePosAnimal(); //Cập nhật vị trí thú
		cg->updateTraffic();
		cg->drawGame(); //ve
		int lv = cg->getLevel();
		if (cg->getPeople().isImpact(cg->getBird(), lv) || cg->getPeople().isImpact(cg->getDinausou(), lv)
			|| cg->getPeople().isImpact(cg->getCar(), lv) || cg->getPeople().isImpact(cg->getTruck(), lv))
		{
			//xử lí khi chết
			mciSendStringA("stop nen.mp3", 0, NULL, 0);
			mciSendStringA("play die.mp3", 0, NULL, 0);

			cg->drawDie();
			gotoXY(1, HEIGHT + 3);
			cout << " nhan Y de tiep tuc tro choi";
			char temp = toupper(_getch());
			if (temp == 'Y')
			{
				system("pause");

				cg->startGame();
				mciSendStringA("play nen.mp3", 0, NULL, 0);
				cg->resetGame(LV_MIN);
			}

			else
				exit(0);
		}
		if (cg->getPeople().isFinish())
		{
			// Xử lý khi về đích
			// cho level tang, xoaa het vat can sau do ve  lai.

			cg->lvUp();
		}
		Sleep(cg->speedGame());

	}
}


int main()
{
	cg = new game;
	char temp;
	FixConsoleWindow();
	cg->DangNhap();
	mciSendStringA("play nen.mp3", 0, NULL, 0);
	thread t1(SubThread);
	while (1)
	{
		ShowCur(false); //xóa dấu nháy con trỏ.
		temp = toupper(_getch());
		if (!cg->getPeople().isDead())
		{
			if (temp == 27)
			{
				cg->exitGame(t1.native_handle());
			}
			else if (temp == 'P')
			{
				cg->pauseGame(t1.native_handle());

			}
			else if (temp == 'L')
			{
				cg->pauseGame(t1.native_handle());
				cg->saveGame();
			}
			else if (temp == 'T')
			{
				mciSendStringA("stop nen.mp3", 0, NULL, 0);
				cg->pauseGame(t1.native_handle());
				system("cls");
				cg->loadGame();
				cg->startGame();
				cg->drawGame();
				mciSendStringA("play nen.mp3", 0, NULL, 0);


			}
			else
			{
				cg->resumeGame((HANDLE)t1.native_handle());
				MOVING = temp; //Cập nhật bước di chuyển
			}
		}
		else
		{
			if (temp == 'Y')
				cg->startGame();
			else {
				cg->exitGame(t1.native_handle());
				return;
			}
		}
	}
	return 0;
}