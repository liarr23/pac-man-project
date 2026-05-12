#pragma once
#include<vector>
#include<SFML/Graphics.hpp>
#include "Character.h"
#include "../core/Types.h"
#include "../map/MapManager.h"

class Ghost: public Character {
public:
    virtual Point chase(const Point& pacmanPos, const Point& blinkyPos,Direction pacmanDir) = 0;//重写寻路逻辑
    State state;
    Point spawnPoint;//出生点
    int scarytime;//恐惧时间长度
    bool isAlive;//是否存活
    double statetime;//处在某一状态的时间
    virtual void update(float deltaTime) override;
    void render(sf::RenderWindow& window) override;
    sf::FloatRect getBounds() const override;
    void setFrightened();
    void eaten();
    Point getPosition();
    Ghost (int x,int y,double speed,Direction dir,MapManager* map);
    void reset();
    Direction getDirection(const Point& pacmanPos, const Point& blinkyPos, Direction pacmanDir);
};
