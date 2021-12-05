#include <iostream>
using namespace std;

#include "vehicle.h"

vehicle::vehicle():direction(true){}

vehicle::vehicle(int x, int y,bool direction_):point(x,y),direction(direction_){}
