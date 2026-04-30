#pragma once
#include<vector>
#include<SFML/Graphics.hpp>

#include "Character.h"
#include "../core/GameObject.h"
enum class State { Chase, Scatter, Frightened, Eaten };//散开，追赶，恐惧，死亡
class Ghost: public Character {
protected:
    virtual Point chase(const Point& pacmanPos, const Point& blinkyPos) = 0;//重写寻路逻辑
    State state;
public:
    Point position;
    Point spawnPoint;//出生点
    Direction dir;//移动方向
    Direction nextdir;//下一次移动目标方向
    int scarytime;//恐惧时间长度
    double speed;//速度
    bool isAlive;//是否存活
    double statetime;//处在某一状态的时间
    void update(float deltaTime) override;
    void render(sf::RenderWindow& window) override;
    void setFrightened();
    void eaten();
    Ghost (int x,int y,double speed,Direction);
    void reset();
    static Direction opposite(Direction dir);
    Direction getDirection(const Point& pacmanPos, const Point& blinkyPos);
};
