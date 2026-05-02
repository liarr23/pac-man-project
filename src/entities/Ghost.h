#pragma once
#include<vector>
#include<SFML/Graphics.hpp>

#include "Character.h"
#include "../core/Types.h"
#include "../map/MapManager.h"

class Ghost: public Character {
protected:
    virtual Point chase(const Point& pacmanPos, const Point& blinkyPos) = 0;//重写寻路逻辑
    State state;
public:
    Point spawnPoint;//出生点
    int scarytime;//恐惧时间长度
    bool isAlive;//是否存活
    double statetime;//处在某一状态的时间
    void update(float deltaTime) override;
    void render(sf::RenderWindow& window) override;
    void setFrightened();
    void eaten();

    Ghost (int x,int y,double speed,Direction,MapManager* map);
    void reset();

    Direction getDirection(const Point& pacmanPos, const Point& blinkyPos);
};
