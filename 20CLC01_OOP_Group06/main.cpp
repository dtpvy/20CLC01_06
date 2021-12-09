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
	MoveWindow(console, r.left, r.top, width, height, TRUE);
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
		
		cg->drawGame(); //ve
		cg->updateLane(); //Cập nhật vị trí thú

		//kiem tra nguoi voi cac vi tri
		Sleep(cg->speedGame());
	}
}


int main()
{
	cg = new game;
	char temp;
	SetWindowSize(cWidth, cHeight);	
	ShowCur(false);
	cg->createGame();
	cg->drawMenuGame();
	while (1)
	{
		cg->drawGame();
		Sleep(100);
		cg->updateLane();
	}
	Sleep(1500);
	return 0;
}