#pragma once
#include<vector>
#include<SFML/Graphics.hpp>
#include "Character.h"
#include "../core/Types.h"
#include "../map/MapManager.h"

class Pacman;

class Ghost: public Character {
public:
    virtual Point chase(const Point& pacmanPos, const Point& blinkyPos,Direction pacmanDir) = 0;
    State state;
    Point spawnPoint;
    double scarytime;
    bool isAlive;
    double statetime;
    virtual void update(float deltaTime) override;
    void render(sf::RenderWindow& window) override;
    sf::FloatRect getBounds() const override;
    void setFrightened();
    void eaten();
    void setPacman(const Pacman* p) { m_pacman = p; }
    void setBlinky(const Ghost* b) { m_blinky = b; }
    Point getPosition() const;
    static constexpr double FRIGHTENED_DURATION = 6.0;
    Ghost (int x,int y,double speed,Direction dir,MapManager* map);
    void reset();
    Direction getDirection(const Point& pacmanPos, const Point& blinkyPos, Direction pacmanDir);
private:
    const Pacman* m_pacman = nullptr;
    const Ghost* m_blinky = nullptr;
    double moveCooldown = 0.0;
};
