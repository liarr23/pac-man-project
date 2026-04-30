#include "Ghost.h"
#include <cmath>
#include <vector>
#include <utility>

void Ghost::update(float deltaTime) {
    (void)deltaTime;
}

void Ghost::render(sf::RenderWindow& window) {
    (void)window;
}

void Ghost::setFrightened() {
    state = State::Frightened;
    scarytime = 0;
}

void Ghost::eaten() {
    state = State::Eaten;
    isAlive = false;
}

Ghost::Ghost(int x, int y, double speed, Direction dir) {
    position.x = x;
    position.y = y;
    spawnPoint.x = x;
    spawnPoint.y = y;
    this->dir = dir;
    nextdir = Direction::None;
    scarytime = 0;
    this->speed = speed;
    isAlive = true;
    statetime = 0;
    state = State::Scatter;
}

void Ghost::reset() {
    position = spawnPoint;
    dir = Direction::None;
    nextdir = Direction::None;
    scarytime = 0;
    isAlive = true;
    statetime = 0;
}

Direction Ghost::opposite(Direction dir) {
    if (dir == Direction::None) return Direction::None;
    else if (dir == Direction::Up) return Direction::Down;
    else if (dir == Direction::Down) return Direction::Up;
    else if (dir == Direction::Left) return Direction::Right;
    else if (dir == Direction::Right) return Direction::Left;
    else return Direction::None;
}

Direction Ghost::getDirection(const Point& pacmanPos, const Point& blinkyPos) {
    Direction opp = opposite(this->dir);
    Point current = this->position;
    Point target = chase(pacmanPos, blinkyPos);
    Direction currentDir = this->dir;
    Direction best = Direction::None;
    int bestDist = 999999;
    std::vector<std::pair<Direction, Point>> candidates = {
        {Direction::Up,    {current.x, current.y - 1}},
        {Direction::Down,  {current.x, current.y + 1}},
        {Direction::Left,  {current.x - 1, current.y}},
        {Direction::Right, {current.x + 1, current.y}}
    };
    for (const auto& cand : candidates) {
        Direction d = cand.first;
        Point next = cand.second;
        if (d == opp && currentDir != Direction::None) continue;
        int dist = std::abs(next.x - target.x) + std::abs(next.y - target.y);
        if (dist < bestDist) {
            bestDist = dist;
            best = d;
        }
    }
    return best;
}
