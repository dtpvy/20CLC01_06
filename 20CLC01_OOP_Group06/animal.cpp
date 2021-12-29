#include "animal.h"

animal::animal() : direction() {

}
animal::animal(int x, int y, bool direc) : point(x, y), direction(direc) {

}
