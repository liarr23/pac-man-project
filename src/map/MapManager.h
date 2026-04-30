#pragma once
#include "../core/GameObject.h"
#include <map>
#include <vector>
using namespace std;
class Map {
public:
    map<Point,bool>walkable;
    bool isWalkable(Point& p);
    bool iswalkable(int x,int y);
};