#pragma once
#include "../core/GameObject.h"
#include <map>
#include <unordered_map>
#include <vector>
using namespace std;
class MapManager {
public:
    int width, height;
    map<Point,char> world;
    map<Point,bool>walkable;
    bool isWalkable(Point& p) const;
    bool isWalkable(int x, int y) const;
    MapManager(int width, int height);
    bool LoadFromFile(string &fileName);
    char getWord(int x,int y) const;

    char getWord(Point &p) const;
    int getWidth() const;
    int getHeight() const;
    ~MapManager();
};