#pragma once
#include "../core/GameObject.h"

class MapManager;

class Character : public GameObject {
public:
    Direction dir;
    Direction nextdir;
    double speed;
    MapManager* map;

    bool canWalkTo(int x, int y) const;
    bool canWalkTo(const Point &p) const;
    static Direction opposite(Direction dir);
};
