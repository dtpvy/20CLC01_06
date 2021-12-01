#include "lane.h"



lane::lane()
{
	cur_state = nullptr;
}

void lane::TransitionTo(Map* state)
{
	if (cur_state)
		delete cur_state;
	cur_state = state;
}

void lane::DrawLane(int x, int y, int step, int _start_index)
{
	if (!cur_state)
		return;
	cur_state->draw(x, y, step, _start_index);
}

void lane::Erase(int x, int y)
{
	if (!cur_state)
		return;
	cur_state->Erase(x, y);
}

int lane::LenOfLane()
{
	if (!cur_state)
		return -1;
	return cur_state->LengthOfLane();
}

/////MAP 1////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Map1::Map1()
{
	this->RawLane = 
	{
		{0, { 7,"                    0000000000                      0000000000                     0000000000                          0000000000                      0000000000" }}, //0
		{0, { 7,"                    0000000000                      0000000000                     0000000000                          0000000000                      0000000000"}}, //1
		{-2,{ 7,"             XXXX      XXXX                   XXXX XXXX XXXX             XXXX          XXXX XXXX   XXXX     XXXX XXXX                     XXXX      XXXX         "}}, //2 
		{-2,{ 7,"             XXXX      XXXX                   XXXX XXXX XXXX             XXXX          XXXX XXXX   XXXX     XXXX XXXX                     XXXX      XXXX         "}}, //3
		{1, { 7,"     BBBBBBBBBBBB                  BBBBBBBBBBBB               BBBBBBBBBBBB               BBBBBBBBBBBB          BBBBBBBBBBBB                     BBBBBBBBBBBB     "}}, //4
		{1, { 7,"     BBBBBBBBBBBB                  BBBBBBBBBBBB               BBBBBBBBBBBB               BBBBBBBBBBBB          BBBBBBBBBBBB                     BBBBBBBBBBBB     "}}, //5
		{0, { 7,"                             0000000000                       0000000000                 0000000000                 0000000000                  0000000000       "}}, //6
		{0, { 7,"                             0000000000                       0000000000                 0000000000                 0000000000                  0000000000       "}}, //7
		{2, { 7,"    XXXX                  XXXX              XXXX        XXXX             XXXX          XXXX                                      XXXX                            "}}, //8
		{2, { 7,"    XXXX                  XXXX              XXXX        XXXX             XXXX          XXXX                                      XXXX                            "}}, //9
		{0, { 7,"                                                                                                                                                                 "}}, //10
		{-2,{ 7,"              DDD                               DDD       CCC                        CCC        DDD                          DDD DDD                             "}}, //11
		{0, { 7,"                                                                                                                                                                 "}}, //12
		{0, { 7,"                                                                                                                                                                 "}} //13
	};
	this->eraseStr = "                                                                                                                               ";
	this->Light =
	{
		{true,-1}, {true,-1}, {true,105}, {true,105}, {true,-1}, {true,-1}, {true,-1}, {true,-1}, {true,-1}, {true,-1}, {true,-1}, {true,-1}, {true,-1}, {true,-1}
	};
}

void Map1::draw(int x, int y, int step, int start_index)
{
	int _step = 0;
	string handling("");
	int totalLanes = RawLane.size();
	int lenOfLane = RawLane[0].second.second.length();
	int pos, last_pos;
	for (int i = 0; i < totalLanes; i++)
	{
		gotoXY(x, y + _step);
		pos = (start_index * RawLane[i].first + 2 * lenOfLane) % lenOfLane;
		Light_execution(x, y + _step, i, pos);
		last_pos = (pos + LENGTH) % lenOfLane;
		if (last_pos > pos)
		{
			handling.append(RawLane[i].second.second, pos, last_pos - pos);
		}
		//else if(RawLane[i].first >= 0) // velocity < 0
		//{
		//	handling.append(RawLane[i].second, pos, lenOfLane - pos);
		//	handling.append(RawLane[i].second, 0, last_pos);
		//}
		//else // velocity >= 0 
		//{
		//	handling.append(RawLane[i].second, 0, last_pos);
		//	handling.append(RawLane[i].second, pos, lenOfLane - pos);
		//}
		else
		{
			handling.append(RawLane[i].second.second, pos, lenOfLane - pos);
			handling.append(RawLane[i].second.second, 0, last_pos);
		}
		TextColor(RawLane[i].second.first);
		cout << handling;
		handling.clear();
		_step += step;
	}
}

int Map1::LengthOfLane()
{
	return RawLane[0].second.second.length();
}

void Map1::Erase(int x, int y)
{
	int numLanes = RawLane.size();
	for (int i = 0; i < numLanes; i++)
	{
		gotoXY(x, y);
		cout << eraseStr;
		y += 1;
	}
}

void Map1::Light_execution(int x, int y, int lane_index, int& pos)
{
	if (Light[lane_index].first == true) // running - green light
	{
		if (Light[lane_index].second < 0)
		{
			cout << " ";
			return;
		}
		else if (pos == Light[lane_index].second)
		{
			Light[lane_index].second = (pos + RawLane[lane_index].first * Stoptime + RawLane[lane_index].second.second.length()) % RawLane[lane_index].second.second.length();
			Light[lane_index].first = false;
			TextColor(12);
			cout << (char)15;
			TextColor(7);
			return; // turn into red light
		}
	}
	else // stopping - red light
	{
		if (Light[lane_index].second < 0)
		{
			cout << " ";
			return;
		}
		else if (pos != Light[lane_index].second)
		{
			pos = Light[lane_index].second;
			TextColor(12);
			cout << (char)15;
			TextColor(7);
			return; // still red light
		}
		else
		{
			pos = Light[lane_index].second;
			Light[lane_index].first = true;
		}
	}
	TextColor(10);
	cout << (char)15;
	TextColor(7);  // turn into green light
}

void Map1::LoadCharacter()
{

}