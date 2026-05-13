#pragma once
#include "../core/GameObject.h"
#include <map>
#include <unordered_map>
#include <vector>

#include "entities/Pacman.h"
using namespace std;
class MapManager {
public:
    int width, height;
    Point ClydeStartPos;
    Point BlinkyStartPos;
    Point PinkyStartPos;
    Point InkyStartPos;
    Point PacmanStartPos;
    Point GhostDoor;
    map<Point,char> world;
    map<Point,bool>walkable;
    bool isWalkable(const Point &p) const;
    Point getBlinkyStartPos()const;
    Point getPinkyStartPos()const;
    Point getInkyStartPos()const;
    Point getClydeStartPos()const;
    Point getPacmanStartPos() const;
    bool isWalkable(int x, int y) const;

    MapManager(int width, int height);
    bool LoadFromFile(const string &fileName);
    char getWord(int x,int y) const;

    char getWord(Point &p) const;
    int getWidth() const;
    int getHeight() const;
    ~MapManager();
};