#include "Ghost.h"

void Ghost::update(float deltaTime) {
    // 这里可以添加幽灵移动和状态更新逻辑
    (void)deltaTime;
}

void Ghost::render(sf::RenderWindow& window) {
    // 这里可以添加幽灵绘制逻辑
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
    nextdir = Direction::NONE;
    scarytime = 0;
    this->speed = speed;
    isAlive = true;
    statetime = 0;
    state = State::Scatter;
}

void Ghost::reset() {
    position = spawnPoint;
    dir = Direction::NONE;
    nextdir = Direction::NONE;
    scarytime = 0;
    isAlive = true;
    statetime = 0;
}

Direction Ghost::opposite(Direction dir) {
    if (dir==Direction::NONE) {
        return Direction::NONE;
    }
    else if (dir==Direction::UP) {
        return Direction::DOWN;
    }
    else if (dir==Direction::DOWN) {
        return Direction::UP;
    }
    else if (dir==Direction::LEFT) {
        return Direction::RIGHT;
    }
    else if (dir==Direction::RIGHT) {
        return Direction::LEFT;
    }
    else {
        return Direction::NONE;
    }
}
Direction Ghost::getDirection(const Point& pacmanPos, const Point& blinkyPos) {
    Direction opposite = opposite(this->dir);
    Point current=this->position;
    Point target = chase(pacmanPos, blinkyPos);
    Direction currentDir = this->dir;
        Direction best = Direction::NONE;
        int bestDist = 999999;
        std::vector<std::pair<Direction, Point>> candidates = {
            {Direction::UP,    {current.x, current.y - 1}},
            {Direction::DOWN,  {current.x, current.y + 1}},
            {Direction::LEFT,  {current.x - 1, current.y}},
            {Direction::RIGHT, {current.x + 1, current.y}}
        };
        for (const auto& cand : candidates) {
            Direction d = cand.first;
            Point next = cand.second;
            if (d == opposite && currentDir != Direction::NONE) continue;
            if (!isWalkable(next, map)) continue;
            int dist = std::abs(next.x - target.x) + std::abs(next.y - target.y);
            if (dist < bestDist) {
                bestDist = dist;
                best = d;
            }
        }
        if (best == Direction::NONE) {
            for (const auto& cand : candidates) {
                if (isWalkable(cand.second, map)) {
                    return cand.first;
                }
            }
        }
        return best;
    }

