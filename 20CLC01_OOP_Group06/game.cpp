#include "game.h"

game::game()
{
	this->score = 0;
	this->lv = 1;
	this->lvMax = 1;
	this->player.reset();
	this->sound = true;
}

game::~game()
{
	laneArr.clear();
}

void game::drawLane()
{
	for (int i = 0; i < laneArr.size(); i++)
	{
		laneArr[i].drawLane();
	}
}

void game::drawPlayer()
{
	player.draw();
}

void game::drawGame()
{
	this->drawLane();
	this->drawPlayer();
}

void game::drawHome()
{
	int x = 28;
	int color = rand() % 7 + 9;
	TextColor(color);
	gotoXY(x, 2);
	cout << " ******  *******    *******   *****   *****  **    **       *******    *******      ***      ******" << endl;
	gotoXY(x, 3);
	cout << "**       **   **    **   **   **      **      **  **        **   **    **   **     ** **     **   **" << endl;
	gotoXY(x, 4);
	cout << "**       ** * **    **   **   *****   *****     **          ** * **    **   **    **   **    **    **" << endl;
	gotoXY(x, 5);
	cout << "**       **   **    **   **      **      **     **          **   **    **   **   ** *** **   **   **" << endl;
	gotoXY(x, 6);
	cout << " ******  **    **   *******   *****   *****     **          **    **   *******  **       **  ******" << endl;
	TextColor(15);

	for (int i = 0; i < getWidth(); i++)
	{
		for (int j = 10; j <= 20; j++)
		{
			if (i % 30 == 0 && j % 2 == 0) {
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
		if (i > WIDTH)
		{
			gotoXY(i, 0);
			cout << (char)219;
		}
		gotoXY(i, GHEIGHT);
		cout << (char)219;
	}
	TextColor(7);
}

void game::drawMenuHome()
{
	system("cls");
	int menuSize = 4;
	char menu[2][4][20] = { "Start Game", "Load Game", "Setting", "Exit",
							"   Easy   ", "  Medium  ", "  Hard  ", "Back" };
	int pos = 0;
	int x = getWidth();
	int y = 13;
	int j = 0;
	playSound((char*)"play nen1.mp3", 1);
	while (1)
	{
		TextColor(7);
		drawHome();
		for (int i = 0; i < menuSize; i++)
		{
			if (i == pos)
			{
				TextColor(227);
				gotoXY((x-strlen(menu[j][i]))/2, y + i);
				cout << menu[j][i];
				TextColor(7);
			}
			else
			{
				TextColor(7);
				gotoXY((x - strlen(menu[j][i])) / 2, y + i);
				cout << menu[j][i];
			}
		}
		if (_kbhit())
		{
			char key = _getch();
			switch (key)
			{
				case -32:
				{
					key = _getch();
					if (key == UP)
					{ 
						pos = (pos - 1 + menuSize) % menuSize;
					}
					if (key == DOWN)
					{
						pos = (pos + 1) % menuSize;
					}
					break;
				}
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
						if (j == 0) j++;
						else
						{
							playSound((char*)"stop nen1.mp3", 1);
							startGame((pos + 1) * 10);
							return;
						}
					}
					if (pos == 1)
					{
						if (j == 1)
						{
							playSound((char*)"stop nen1.mp3", 1);
							startGame((pos + 1) * 10);
						}
						else loadGame();
						return;
					}
					if (pos == 2)
					{
						if (j == 1)
						{
							playSound((char*)"stop nen1.mp3", 1);
							startGame((pos + 1) * 10);
						}
						else settingGame();
						return;
					}
					if (pos == 3)
					{
						if (j == 1)
						{
							j--;
						}
						else
						{
							gotoXY(0, HEIGHT + 1);
							exit(0);
						}
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
	while (i > 0)
	{
		int type = rand() % 5 + 1;
		int num = this->lv/10 + this->lvMax/10 + rand() % 2;
		int light = (num + rand() % 2) % 2;
		lane cLane;
		switch (type)
		{
		case 1: case 2:
		{
			i -= 5;
			if (i < 0) break;
			cLane.createLane(type, light, num, rand() % 2, i);
			break;
		}
		case 3: 
		{
			i = i - 3;
			if (i < 0) break;
			cLane.createLane(type, num + rand() % 2, rand() % 2, i);
			break;
		}
		case 4:
		{
			i = i - 2;
			if (i < 0) break;
			cLane.createLane(type, num + rand() % 2, rand() % 2, i);
			break;
		}
		case 5:
		{
			i = i - 4;
			if (i < 0) break;
			cLane.createLane(type, num + rand() % 2, rand() % 2, i);
			break;
		}
		}
		--i;
		laneArr.push_back(cLane);
		++cnt;
	}
}

void game::updatePosPeople(char c)
{
	switch (c)
	{
	case 'a': case 'A':  
	{
		player.deleteChar();
		player.goLeft();
		player.draw();
		break;
	}
	case 'w': case 'W': 
	{
		player.deleteChar();
		player.goUp();
		player.draw();
		break;
	}
	case 'd': case 'D': 
	{
		player.deleteChar();
		player.goRight();
		player.draw();
		break;
	}
	case 's': case 'S':
	{
		player.deleteChar();
		player.goDown();
		player.draw();
		break;
	}
	default:
		break;
	}
}

bool game::lvUp()
{
	if (lv == this->lvMax)
	{
		return 1;
	}
	this->score += this->lv * 100;
	this->lv++;
	this->resetGame();
	this->startGame(this->lvMax);
	return 0;
}

int game::getLvMax()
{
	return this->lvMax;
}

void game::startGame(int lvMax)
{
	stopSound();
	laneArr.clear();
	this->player.setStatus(true);
	this->lvMax = lvMax;
	system("cls");
	drawMenuGame();
	createGame();
	drawGame();
	playSound((char*)"play nen2.mp3 repeat", 1);
}

void game::loadGame()
{
	system("cls");
	this->drawHome();
	string file;
	int i = 0;
	while (1)
	{
		if (i == 0)
		{
			TextColor(7);
			gotoXY(getWidth() / 2 - 4, 16);
			cout << "Back";
			TextColor(14);
			gotoXY(40, 15);
			cout << "Nhap ten file: ";
			gotoXY(60 , 15);
			cout << file;
		}
		else
		{
			TextColor(7);
			gotoXY(40, 15);
			cout << "Nhap ten file: ";
			TextColor(14);
			gotoXY(getWidth() / 2 - 4, 16);
			cout << "Back";
		}
		if (_kbhit)
		{
			char c = _getch();
			if ((int)c == -32) {
				c = _getch();
				if ((int)c == 72)
				{
					i = (1 + i) % 2;
				}
				if ((int)c == 80)
				{
					i = (2 - i + 1) % 2;
				}
			}
			else if ((int)c == 13)
			{
				if (i == 1)
				{
					drawMenuHome();
					return;
				}
				else
				{
					break;
				}
			}
			else {
				if ((int)c == 8 && file.size() > 0) file.pop_back();
				if ((int)c != 8) file.push_back(c);
			}
		}
	}

	fstream fi(file, ios::in);
	if (fi.fail())
	{
		gotoXY(50, 17);
		TextColor(ColorCode_Green);
		cout << "DU LIEU KHONG TON TAI, BAT DAU TRO CHOI." << endl;
		TextColor(7);
		gotoXY(getWidth() / 2 - 17, 19);
		system("pause");
		drawMenuHome();
		return;
	}
	laneArr.clear();
	int n;
	gotoXY(40, 17);
	cout << "Loading...";
	gotoXY(61, 17);
	cout << "[";
	int status = 0;
	fi >> this->score >> this->lv >> this->lvMax >> status >> n;
	player.readFile(fi);
	player.setStatus(status);
	fi >> this->score >> this->lv >> this->lvMax >> n;
	player.readFile(fi);
	int tmp = 0, j = 0;
	for (int i = 0; i < n; i++)
	{
		tmp = i * 30 / n;
		for (; j <= tmp; j++)
		{
			gotoXY(62 + j, 17);
			cout << ".";
		}
		j = tmp;
		int type, direction, row;
		bool _light;
		light tLight;
		fi >> row >> type >> _light >> direction;
		lane tmp;
		if (_light)
		{
			int status, _time, x, y;
			fi >> status >> _time >> x >> y;
			tLight.set(status, _time);
			tLight.setX(x);
			tLight.setY(y);
			tmp.set(type, _light, tLight, direction, row);
		}
		else
		{
			tmp.set(type, _light, direction, row);
		}

		if (type == 0)
		{
			laneArr.push_back(tmp);
			continue;
		}
		int num;
		fi >> num;
		for (int j = 0; j < num; j++)
		{
			int x, y;
			fi >> x >> y;
			tmp.add(type, x, y);
		}	
		cout << endl;
		laneArr.push_back(tmp);
	}
	fi.close();
	gotoXY(63 + tmp, 17);
	cout << "]";
	TextColor(14);
	gotoXY(getWidth() / 2 - 17, 19);
	stopSound();
	system("pause");
	while (1)
	{
		if (_kbhit)
		{
			system("cls");
			playSound((char*)"play nen2.mp3 repeat", 1);
			drawMenuGame();
			return;
		}
	}
	return;
}

void game::loadGame(HANDLE t)
{
	system("cls");
	this->drawHome();
	string file;
	int i = 0;
	while (1)
	{
		if (i == 0)
		{
			TextColor(7);
			gotoXY(getWidth() / 2 - 4, 16);
			cout << "Back";
			TextColor(14);
			gotoXY(40, 15);
			cout << "Nhap ten file: ";
			gotoXY(60, 15);
			cout << file;
		}
		else
		{
			TextColor(7);
			gotoXY(40, 15);
			cout << "Nhap ten file: ";
			TextColor(14);
			gotoXY(getWidth() / 2 - 4, 16);
			cout << "Back";
		}
		if (_kbhit)
		{
			char c = _getch();
			if ((int)c == -32) {
				c = _getch();
				if ((int)c == 72)
				{
					i = (1 + i) % 2;
				}
				if ((int)c == 80)
				{
					i = (2 - i + 1) % 2;
				}
			}
			else if ((int)c == 13)
			{
				if (i == 1)
				{
					system("cls");
					drawMenuGame();
					resumeGame(t);
					return;
				}
				else
				{
					break;
				}
			}
			else {
				if ((int)c == 8 && file.size() > 0) file.pop_back();
				if ((int)c != 8) file.push_back(c);
			}
		}
	}

	fstream fi(file, ios::in);
	if (fi.fail())
	{
		gotoXY(50, 17);
		TextColor(ColorCode_Green);
		cout << "DU LIEU KHONG TON TAI, BAT DAU TRO CHOI." << endl;
		system("cls");
		drawMenuGame();
		resumeGame(t);
		return;
	}
	laneArr.clear();
	int n;
	gotoXY(40, 17);
	cout << "Loading...";
	gotoXY(61, 17);
	cout << "[";
	int status;
	fi >> this->score >> this->lv >> this->lvMax >> status >> n;
	player.setStatus(status);
	fi >> this->score >> this->lv >> this->lvMax >> n;
	player.readFile(fi);
	int tmp = 0, j = 0;
	for (int i = 0; i < n; i++)
	{
		tmp = i * 30 / n;
		for (; j <= tmp; j++)
		{
			gotoXY(62 + j, 17);
			cout << ".";
		}
		j = tmp;
		int type, direction, row;
		bool _light;
		light tLight;
		fi >> row >> type >> _light >> direction;
		lane tmp;
		if (_light)
		{
			int status, _time, x, y;
			fi >> status >> _time >> x >> y;
			tLight.set(status, _time);
			tLight.setX(x);
			tLight.setY(y);
			tmp.set(type, _light, tLight, direction, row);
		}
		else
		{
			tmp.set(type, _light, direction, row);
		}

		if (type == 0)
		{
			laneArr.push_back(tmp);
			continue;
		}
		int num;
		fi >> num;
		for (int j = 0; j < num; j++)
		{
			int x, y;
			fi >> x >> y;
			tmp.add(type, x, y);
		}
		cout << endl;
		laneArr.push_back(tmp);
	}
	fi.close();
	gotoXY(63 + tmp, 17);
	cout << "]";
	TextColor(14);
	gotoXY(getWidth() / 2 - 17, 19);
	system("pause");
	while (1)
	{
		if (_kbhit)
		{
			system("cls");
			drawMenuGame();
			resumeGame(t);
			return;
		}
	}
	return;
}

void game::saveGame(HANDLE t)
{
	system("cls");
	this->drawHome();
	string file;
	int i = 0;
	while (1)
	{
		if (i == 0)
		{
			TextColor(7);
			gotoXY(getWidth() / 2 - 4, 16);
			cout << "Back";
			TextColor(14);
			gotoXY(40, 15);
			cout << "Enter file name: ";
			gotoXY(60, 15);
			cout << file;
		}
		else
		{
			TextColor(7);
			gotoXY(40, 15);
			cout << "Enter file name: ";
			TextColor(14);
			gotoXY(getWidth() / 2 - 4, 16);
			cout << "Back";
		}
		if (_kbhit)
		{
			char c = _getch();
			if ((int)c == -32) {
				c = _getch();
				if ((int)c == 72)
				{
					i = (1 + i) % 2;
				}
				if ((int)c == 80)
				{
					i = (2 - i + 1) % 2;
				}
			}
			else if ((int)c == 13)
			{
				if (i == 1)
				{
					system("cls");
					drawMenuGame();
					resumeGame(t);
					return;
				}
				else
				{
					break;
				}
			}
			else {
				if ((int)c == 8 && file.size() > 0) file.pop_back(), cout << ' ';
				if ((int)c != 8) file.push_back(c);
			}
		}
	}

	fstream fo(file, ios::out);
	TextColor(6);
	gotoXY(40, 17);
	cout << "Saving...";
	gotoXY(61, 17);
	cout << "[";
	fo << this->score << " " << this->lv << " " << this->lvMax << " " << " " << !this->player.isDead() << " " << this->getLane() << endl;
	fo << this->score << " " << this->lv << " " << this->lvMax << " " << this->getLane() << endl;
	this->player.writeFile(fo);
	fo << endl;
	int tmp = 0, j = 0;
	for (int i = 0; i < laneArr.size(); i++)
	{
		tmp = i * 30 / laneArr.size();
		for (; j <= tmp; j++)
		{
			gotoXY(62 + j, 17);
			cout << ".";
		}
		j = tmp;
		laneArr[i].writeFile(fo);
		fo << endl;
	}
	gotoXY(63+tmp, 17);
	cout << "]";
	TextColor(14);
	gotoXY(getWidth() / 2 - 17, 19);
	system("pause");
	while (1)
	{
		if (_kbhit)
		{
			system("cls");
			drawMenuGame();
			resumeGame(t);
			return;
		}
	}
	return;
}

void game::settingGame()
{
	system("cls");
	int menuSize = 3;
	char menu[][20] = { "Unmute", "Mute", "Back"};
	int pos = 0;
	int x = getWidth();
	int y = 13;

	while (1)
	{
		TextColor(7);
		drawHome();
		for (int i = 0; i < menuSize; i++)
		{
			if (i == pos)
			{
				TextColor(227);
				gotoXY((x - strlen(menu[i])) / 2, y + i);
				cout << menu[i];
				TextColor(7);
			}
			else
			{
				TextColor(7);
				gotoXY((x - strlen(menu[i])) / 2, y + i);
				cout << menu[i];
			}
		}
		if (_kbhit())
		{
			char key = _getch();
			switch (key)
			{
			case -32:
			{
				key = _getch();
				if (key == UP)
				{
					pos = (pos - 1 + menuSize) % menuSize;
				}
				if (key == DOWN)
				{
					pos = (pos + 1) % menuSize;
				}
				break;
			}
			case 'w': case 'W': {
				pos = (pos - 1 + menuSize) % menuSize;
				break;
			}
			case 's': case 'S': {
				pos = (pos + 1) % menuSize;
				break;
			}
			case 13: {
				if (pos == 0)
				{
					this->sound = true;
					drawMenuHome();
					return;
				}
				if (pos == 1)
				{
					this->sound = false;
					stopSound();
					drawMenuHome();
					return;
				}
				if (pos == 2)
				{
					drawMenuHome();
					return;
				}
				break;
			}
			}
		}
	}
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
	}
}

bool game::checkLane()
{
	for (int i = 0; i < laneArr.size(); i++)
	{
		int tmp = laneArr[i].checkLane(player);
		if (tmp == 1)
		{
			player.setStatus(false);
			return 1;
		}
	}
	return 0;
}

void game::playSound(char* name, bool sound)
{
	if (sound == 1)
	{
		if (this->sound) mciSendStringA(name, 0, NULL, 0);
	}
	else
	{
		mciSendStringA(name, 0, NULL, 0);
	}
	
}

void game::stopSound()
{
	playSound((char*)"stop nen1.mp3", 0);
	playSound((char*)"stop nen2.mp3", 0);
	playSound((char*)"stop die.mp3", 0);
	playSound((char*)"stop win.mp3", 0);
}

void game::drawDie()
{
	stopSound();
	char s[] = "YOU ARE DIE!";
	int x = WIDTH + 10;
	int y = 0;
	TextColor(ColorCode_Red);
	gotoXY(x, y + 5);
	cout << "LEVEL MAX: " << this->lvMax;
	gotoXY(x, y + 6);
	cout << "SCORE: " << this->score;
	gotoXY(x, y + 7);
	cout << "LEVEL: " << this->lv;
	gotoXY(x, y + 8);
	cout << s;
	TextColor(ColorCode_Pink);
	gotoXY(x, y + 10);
	cout << "Press W to UP";
	gotoXY(x, y + 11);
	cout << "Press A to LEFT";
	gotoXY(x, y + 12);
	cout << "Press S to DOWN";
	gotoXY(x, y + 13);
	cout << "Press D to RIGHT";
	gotoXY(x, y + 14);
	cout << "Press P to PauseGame";
	gotoXY(x, y + 15);
	cout << "Press L to SaveGame";
	gotoXY(x, y + 16);
	cout << "Press E to Exit";
	gotoXY(x, y + 17);
	cout << "Press T to LoadGame";
	gotoXY(x, y + 18);
	cout << "Press Y to Playagain";

	TextColor(7);
	TextColor(187);
	for (int i = 0; i <= GHEIGHT; i++)
	{
		gotoXY(0, i);
		cout << (char)219;
		gotoXY(getWidth() - 1, i);
		cout << (char)219;
		gotoXY(WIDTH + 1, i);
		cout << (char)219;
	}
	for (int i = 0; i < getWidth(); i++)
	{
		if (i > WIDTH)
		{
			gotoXY(i, 0);
			cout << (char)219;
		}
		gotoXY(i, GHEIGHT);
		cout << (char)219;
	}
	TextColor(7);
	player.setStatus(false);
	playSound((char*)"play die.mp3", 1);
}

void game::drawWin()
{
	stopSound();
	char s[] = "YOU ARE WINER!";
	int x = WIDTH + 10;
	int y = 0;
	TextColor(ColorCode_Red);
	gotoXY(x, y + 5);
	cout << "LEVEL MAX: " << this->lvMax;
	gotoXY(x, y + 6);
	cout << "SCORE: " << this->score;
	gotoXY(x, y + 7);
	cout << "LEVEL: " << this->lv;
	gotoXY(x, y + 8);
	cout << s;
	TextColor(ColorCode_Pink);
	gotoXY(x, y + 10);
	cout << "Press W to UP";
	gotoXY(x, y + 11);
	cout << "Press A to LEFT";
	gotoXY(x, y + 12);
	cout << "Press S to DOWN";
	gotoXY(x, y + 13);
	cout << "Press D to RIGHT";
	gotoXY(x, y + 14);
	cout << "Press P to PauseGame";
	gotoXY(x, y + 15);
	cout << "Press L to SaveGame";
	gotoXY(x, y + 16);
	cout << "Press E to Exit";
	gotoXY(x, y + 17);
	cout << "Press T to LoadGame";
	gotoXY(x, y + 18);
	cout << "Press Y to Playagain";

	TextColor(7);
	TextColor(187);
	for (int i = 0; i <= GHEIGHT; i++)
	{
		gotoXY(0, i);
		cout << (char)219;
		gotoXY(getWidth() - 1, i);
		cout << (char)219;
		gotoXY(WIDTH + 1, i);
		cout << (char)219;
	}
	for (int i = 0; i < getWidth(); i++)
	{
		if (i > WIDTH)
		{
			gotoXY(i, 0);
			cout << (char)219;
		}
		gotoXY(i, GHEIGHT);
		cout << (char)219;
	}
	TextColor(7);
	playSound((char*)"play win.mp3", 1);
}

int game::speedGame()
{
	return 150/(lvMax/10);
}

int game::getLane()
{
	return this->laneArr.size();
}

people game::getPeople()
{
	return this->player;
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
		laneArr[i].deleteLane();
	}
	player.reset();
	for (int i = 0; i < laneArr.size(); i++)
	{
		laneArr[i].reset();
	}
}

void game::resetLv()
{
	this->lv = 1;
	this->score = 0;
}

void game::exitGame(thread* t)
{
	stopSound();
	player.setStatus(false);
	t->join();
}


