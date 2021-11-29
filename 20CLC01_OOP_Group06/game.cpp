#include "game.h"

void game::drawGame()
{
	player.draw();
	for (int i = 0; i < laneArr.size(); i++)
	{
		laneArr[i].drawRoad();
	}
}

void game::drawHome()
{
	int x = (cHeight - 100) / 2;
	int color = rand() % 7 + 9;
	TextColor(color);
	gotoXY(x, 0);
	cout << " ******  *******    *******   ****    ****   **    **		******     *******      **       ******" << endl;
	gotoXY(x, 1);
	cout << "**       **   **    **   **   **      **      **  **		**   **    **   **     ** **     **   **" << endl;
	gotoXY(x, 2);
	cout << "**	 ** * **    **   **   *****   *****     **		** * **    **   **    **   **    **    **" << endl;
	gotoXY(x, 3);
	cout << "**	 **   **    **   **	 **      **     **		**   **    **   **   ** *** **   **   **" << endl;
	gotoXY(x, 4);
	cout << " ******  **    **   *******   *****   *****     **		**    **   *******  **       **  ******" << endl;
	TextColor(7);
	TextColor(238);

	for (int i = 0; i <= cHeight; i++)
	{
		for (int j = 10; j <= 40; j++)
		{
			if (j == 10 || j == 40)
			{
				gotoXY(i, j);
				cout << "*";
			}
			if (i % 30 == 0 && j % 2 == 0) {
				gotoXY(i, j);
				cout << "*";
			}
		}
	}
}

void game::drawMenuGame(int x,  int y)
{
	TextColor(ColorCode_Pink);
	gotoXY(x + 5, y + 10);
	cout << "SCORE: " << this->score;
	gotoXY(x+10, y+10);
	cout << "Press W to UP";
	gotoXY(x+11, y+10);
	cout << "Press A to LEFT";
	gotoXY(x+12, y+10);
	cout << "Press S to DOWN";
	gotoXY(x+13, y+10);
	cout << "Press D to RIGHT";
	gotoXY(x+14, y+10);
	cout << "Press P to PauseGame";
	gotoXY(x+15, y+10);
	cout << "Press L to SaveGame";
	gotoXY(x+16, y+10);
	cout << "Press E to Exit";
	gotoXY(x+17, y+10);
	cout << "Press T to LoadGame";
	TextColor(7);
	TextColor(187);
	for (int i = 0; i <= cHeight; i++)
	{
		gotoXY(0, i);
		cout << "*";
		gotoXY(cWidth, i);
		cout << "*";
	}
	for (int i = 0; i < cWidth; i++)
	{
		gotoXY(i, 0);
		cout << "*";
		gotoXY(i, cHeight);
		cout << "*";
		gotoXY(i, y);
		cout << "*";
	}
	TextColor(7);
}

void game::drawMenuHome()
{
	int menuSize = 4;
	char menu[][20] = { "Start Game", "Load Game", "Setting", "Exit"};
	int pos = 0;
	int x = cHeight / 2;
	int y = 20;
	while (1)
	{
		drawHome();
		TextColor(7);
		for (int i = 0; i < menuSize; i++)
		{
			if (i == pos)
			{
				TextColor(227);
				gotoXY(x - strlen(menu[i]), y + i);
				cout << menu[i];
				TextColor(7);
			}
			else
			{
				gotoXY(x, y + i);
				cout << menu[i];
			}
		}
		while (1)
		{
			if (_kbhit())
			{
				
				int key = _getch();
				switch (key)
				{
				case (int)'w': case (int)'W': case 72: {
					pos = (pos - 1 + menuSize) % menuSize;
					break;
				}
				case (int)'s': case (int)'S': case 80: {
					pos = (pos + 1) % menuSize;
					break;
				}
				case 13: {
					if (pos == 0)
					{
						startGame();
					}
					if (pos == 1)
					{
						loadGame();
					}
					if (pos == 2)
					{
						settingGame();
					}
					if (pos == 3)
					{
						exit(0);
					}
					break;
				}
				}
			}
		}
	}
}

void game::updatePosPeople(int c)
{
	switch (c)
	{
	case (int)'a': case (int)'A': case LEFT: 
	{
		player.goLeft();
		break;
	}
	case (int)'w': case (int)'W': case UP:
	{
		player.goUp();
		break;
	}
	case (int)'d': case (int)'D': case RIGHT:
	{
		player.goRight();
		break;
	}
	case (int)'s': case (int)'S': case DOWN:
	{
		player.goDown();
		break;
	}
	default:
		break;
	}
}

void game::startGame()
{
	system("cls");
	drawMenuGame(20, cHeight-50);
	drawGame();
}

void game::updateLane()
{
	for (int i = 0; i < laneArr.size(); i++)
	{
		
	}
}

void game::drawDie()
{
	char s[] = "YOU ARE DIE!";
	gotoXY(cWidth / 2 - 1, cHeight / 2 - 50 - strlen(s));
	cout << s;
}

void game::updatePosAnimal()
{
}
