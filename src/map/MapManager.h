#pragma once
#include "../core/GameObject.h"
#include <map>
#include <vector>
using namespace std;
class Map {
public:
    int width, height;
    map<Point,char> world;
    map<Point,bool>walkable;
    bool isWalkable(Point& p);
    bool isWalkable(int x,int y);
    Map();
    bool ReadFromFile(string &name);
    char getWord(int x,int y);
    char getWord(Point& p);

};