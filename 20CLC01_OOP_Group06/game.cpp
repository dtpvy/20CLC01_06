#include "game.h"

game::game()
{
	this->score = 0;
	this->lv = 0;
	this->lvMax = 0;
	this->player.reset();
}

game::~game()
{
	laneArr.clear();
}

void game::drawGame()
{
	player.draw();
	for (int i = 0; i < laneArr.size(); i++)
	{
		laneArr[i].drawLane();
	}
}

void game::drawHome()
{
	int x = getWidth()-115;
	int color = rand() % 7 + 9;
	TextColor(color);
	gotoXY(x, 2);
	cout << " ******  *******    *******   ****    ****   **    **		******     *******      **       ******" << endl;
	gotoXY(x, 3);
	cout << "**       **   **    **   **   **      **      **  **		**   **    **   **     ** **     **   **" << endl;
	gotoXY(x, 4);
	cout << "**	 ** * **    **   **   *****   *****     **		** * **    **   **    **   **    **    **" << endl;
	gotoXY(x, 5);
	cout << "**	 **   **    **   **	 **      **     **		**   **    **   **   ** *** **   **   **" << endl;
	gotoXY(x, 6);
	cout << " ******  **    **   *******   *****   *****     **		**    **   *******  **       **  ******" << endl;
	TextColor(15);

	for (int i = 1; i < getWidth(); i++)
	{
		for (int j = 10; j <= 20; j++)
		{
			if (i % 25 == 0 && j % 2 == 0) {
				gotoXY(i, j);
				cout << (char)219;
			}
			if (j == 10 || j == 20)
			{
				gotoXY(i, j);
				cout << (char)178;
			}
		}
	}
	Sleep(100);
}

void game::drawMenuGame()
{
	int x = WIDTH + 10;
	int y = 0;
	TextColor(ColorCode_Red);
	gotoXY(x, y + 5);
	cout << "LEVEL MAX: " << this->lvMax;
	gotoXY(x, y + 6);
	cout << "SCORE: " << this->score;
	gotoXY(x, y + 7);
	cout << "LEVEL: " << this->lv;
	TextColor(ColorCode_Pink);
	gotoXY(x, y+10);
	cout << "Press W to UP";
	gotoXY(x, y+11);
	cout << "Press A to LEFT";
	gotoXY(x, y+12);
	cout << "Press S to DOWN";
	gotoXY(x, y+13);
	cout << "Press D to RIGHT";
	gotoXY(x, y+14);
	cout << "Press P to PauseGame";
	gotoXY(x, y+15);
	cout << "Press L to SaveGame";
	gotoXY(x, y+16);
	cout << "Press E to Exit";
	gotoXY(x, y+17);
	cout << "Press T to LoadGame";
	TextColor(7);
	TextColor(187);
	for (int i = 0; i <= GHEIGHT; i++)
	{
		gotoXY(0, i);
		cout << (char)219;
		gotoXY(getWidth()-1, i);
		cout << (char)219;
		gotoXY(WIDTH+1, i);
		cout << (char)219;
	}
	for (int i = 0; i < getWidth(); i++)
	{
		gotoXY(i, 0);
		cout << (char)219;
		gotoXY(i, GHEIGHT);
		cout << (char)219;
	}
	TextColor(7);
}

void game::drawMenuHome()
{
	int menuSize = 4;
	char menu[][20] = { "Start Game", "Load Game", "Setting", "Exit"};
	int pos = 0;
	int x = getWidth();
	int y = 13;
	while (1)
	{
		drawHome();
		TextColor(7);
		for (int i = 0; i < menuSize; i++)
		{
			if (i == pos)
			{
				TextColor(227);
				gotoXY((x-strlen(menu[i]))/2, y + i);
				cout << menu[i];
				TextColor(7);
			}
			else
			{
				gotoXY((x - strlen(menu[i])) / 2, y + i);
				cout << menu[i];
			}
		}
		if (_kbhit())
		{
			char key = _getch();
			switch (key)
			{
				case 'w': case 'W': {
					pos = (pos - 1 + menuSize) % menuSize;
					break;
				}
				case 's': case 'S':  {
					pos = (pos + 1) % menuSize;
					break;
				}
				case 13: {
					if (pos == 0)
					{
						startGame();
						return;
					}
					if (pos == 1)
					{
						loadGame();
						return;
					}
					if (pos == 2)
					{
						settingGame();
						return;
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

void game::createGame()
{
	
	srand(time(NULL));
	lane tmp;
	laneArr.push_back(tmp);
	int i = HEIGHT - 3;
	int cnt = 0;
	while (i > 0 && cnt < 4)
	{
		int type = rand() % 3 + 1;
		if (i - 5 < 0)
		{
			if (i - 4 < 0)
			{
				laneArr.push_back(lane(i));
				break;
			}
			else
			{
				type = (type < 3) ? (rand() % 3 + 3) : type;
			}
		}
		int num = rand() % 3 + 2;
		int light = (num + rand() % 2) % 2;
		lane cLane;
		switch (type)
		{
		case 1: case 2:
		{
			i -= 5;
			cLane.createLane(type, light, num, rand() % 2, i);
			break;
		}
		case 3: case 4: case 5:
		{
			i -= 4;
			cLane.createLane(type, num + rand() % 2, rand() % 2, i);
			break;
		}
		}
		--i;
		laneArr.push_back(cLane);
		++cnt;
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

void game::lvUp()
{
	player.deleteChar();
	laneArr.clear();
	if (lv == lvMax)
	{
		gotoXY(2, GHEIGHT + 2);
		cout << "You win";
		_getch();
		exit(0);
	}
	lv++;
	player.reset();
	this->createGame();
}

void game::startGame()
{
	system("cls");
	drawGame();
	drawMenuGame();
}

void game::loadGame()
{
	string file;
	cout << "Nhap ten duong dan file" << endl;
	getline(cin, file);
	clrscr();
	fstream fi(file, ios::in);
	if (fi.fail())
	{
		TextColor(ColorCode_Green);
		cout << "DU LIEU KHONG TON TAI, BAT DAU TRO CHOI." << endl;
		TextColor(7);
		system("pause");
		clrscr();
		return;
	}
	laneArr.clear();
	int n;
	fi >> this->score >> this->lv >> this->lvMax >> n;
	for (int i = 0; i < n; i++)
	{
		int type, direction;
		bool _light;
		light tLight;
		fi >> type >> _light >> direction;
		lane tmp;
		if (_light)
		{
			int status, _time, x, y;
			fi >> status >> _time >> x >> y;
			tLight.set(status, _time);
			tLight.setX(x);
			tLight.setY(y);
			tmp.set(type, _light, tLight, direction);
		}
		else
		{
			tmp.set(type, _light, direction);
		}

		int num;
		fi >> num;
		for (int j = 0; j < num; j++)
		{
			int x, y;
			fi >> x >> y;
			tmp.add(type, x, y);
		}	
		laneArr.push_back(tmp);
	}
	fi.close();
}

void game::saveGame()
{
	TextColor(ColorCode_Green);
	string file;
	cout << "Nhap ten file Can Luu" << endl;
	getline(cin, file);
	fstream fo(file, ios::out);
	TextColor(7);
	fo << this->score << " " << this->lv << " " << this->lvMax << " " << this->getLane() << endl;
	for (int i = 0; i < laneArr.size(); i++)
	{
		laneArr[i].writeFile(fo);
		fo << endl;
	}
	fo.close();
	clrscr();
	this->startGame();
	return;
}

void game::settingGame()
{
}

void game::pauseGame(HANDLE t)
{
	SuspendThread(t);
}

void game::resumeGame(HANDLE t)
{
	ResumeThread(t);
}

void game::updateLane()
{
	for (int i = 0; i < laneArr.size(); i++)
	{
		laneArr[i].updateLane();
		laneArr[i].updateLightTraffic();
	}
}

bool game::checkLane()
{
	return laneArr[this->player.getY()].checkLane(player);
}

void game::drawDie()
{
	char s[] = "YOU ARE DIE!";
	gotoXY(cWidth / 2 - 1, cHeight / 2 - 50 - strlen(s));
	cout << s;
}

int game::speedGame()
{
	return (((double)lvMax-lv+1)/10)*50;
}

int game::getLane()
{
	return this->laneArr.size();
}

people game::getPeople()
{
	return this->player;
}

void game::Delete()
{
}

bool game::isRunning()
{
	return !player.isDead();
}

void game::resetGame()
{
	player.deleteChar();
	for (int i = 0; i < laneArr.size(); i++)
	{
		laneArr[i].deleteChar();
	}
	player.reset();
	for (int i = 0; i < laneArr.size(); i++)
	{
		laneArr[i].reset();
	}
}

void game::exitGame(HANDLE)
{
	system("cls");
	exit(0);
}


