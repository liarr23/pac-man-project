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
    state = GhostState::Frightened;
    scarytime = 0;
}

void Ghost::eaten() {
    state = GhostState::Eaten;
    isAlive = false;
}

Ghost::Ghost(int x, int y, double speed, Direction dir,MapManager* map) {
    m_position.x = x;
    m_position.y = y;
    spawnPoint.x = x;
    spawnPoint.y = y;
    this->dir = dir;
    nextdir = Direction::None;
    scarytime = 0;
    this->speed = speed;
    isAlive = true;
    statetime = 0;
    state = GhostState::Scatter;
    this->map = map;
}
void Ghost::reset() {
    m_position = spawnPoint;
    dir = Direction::None;
    nextdir = Direction::None;
    scarytime = 0;
    isAlive = true;
    statetime = 0;
}

Direction Ghost::getDirection(const Point& pacmanPos, const Point& blinkyPos) {
    Point current = this->m_position;
    Point target = chase(pacmanPos, blinkyPos);
    Direction currentDir = this->dir;
    Direction best = Direction::None;
    int bestDist = 999999;
    Direction oppo_direction = opposite(currentDir);
    std::vector<std::pair<Direction, Point>> candidates = {
            {Direction::Up,    {current.x, current.y - 1}},
            {Direction::Down,  {current.x, current.y + 1}},
            {Direction::Left,  {current.x - 1, current.y}},
            {Direction::Right, {current.x + 1, current.y}}
        };

        for (const auto& cand : candidates) {
            Direction d = cand.first;
            Point next = cand.second;
            if (d == oppo_direction && currentDir != Direction::None) continue;
            if (!canWalkTo(next)) continue;
            int dist = std::abs(next.x - target.x) + std::abs(next.y - target.y);
            if (dist < bestDist) {
                bestDist = dist;
                best = d;
            }
        }
        if (best == Direction::None) {
            for (const auto& cand : candidates) {
                if (canWalkTo(cand.second)) {
                    return cand.first;
                }
            }
        }
        return best;
    }
