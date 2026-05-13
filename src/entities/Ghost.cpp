#include "Ghost.h"
#include "Pacman.h"
#include <cmath>
#include <cstdlib>
#include <vector>
#include <utility>

void Ghost::update(float deltaTime) {
    if (!m_active) return;
    statetime += deltaTime;
    if (state == State::Frightened) {
        scarytime += deltaTime;
        if (scarytime >= FRIGHTENED_DURATION) {
            state = State::Chase;
            scarytime = 0;
            statetime = 0;
        }
    }

    moveCooldown -= deltaTime * speed;
    if (moveCooldown > 0.0) return;
    moveCooldown = 1.0;

    Point pacmanPos;
    Point blinkyPos;
    Direction pacmanDir = Direction::None;
    if (m_pacman) {
        sf::FloatRect b = m_pacman->getBounds();
        pacmanPos = Point(static_cast<int>(b.left / 32.0f), static_cast<int>(b.top / 32.0f));
        pacmanDir = m_pacman->dir;
    }
    if (m_blinky) {
        blinkyPos = m_blinky->getPosition();
    }
    Direction nextDir = getDirection(pacmanPos, blinkyPos, pacmanDir);
    if (nextDir != Direction::None) {
        dir = nextDir;
    }
    if (dir != Direction::None) {
        Point next = m_position;
        switch (dir) {
            case Direction::Up:    next.y--; break;
            case Direction::Down:  next.y++; break;
            case Direction::Left:  next.x--; break;
            case Direction::Right: next.x++; break;
            default: break;
        }
        if (canWalkTo(next)) {
            m_position = next;
            if (map) {
                if (m_position.x < 0) m_position.x = map->getWidth() - 1;
                if (m_position.x >= map->getWidth()) m_position.x = 0;
            }
        }
    }
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

sf::FloatRect Ghost::getBounds() const {
    return sf::FloatRect(
        m_position.x * 32.0f, m_position.y * 32.0f,
        32.0f, 32.0f
    );
}

Point Ghost::getPosition() const {
    return m_position;
}
Ghost::Ghost(int x, int y, double speed, Direction dir,MapManager* map) {
    m_position.x = x;
    m_position.y = y;
    spawnPoint = map->GhostDoor;
    this->dir = dir;
    nextdir = Direction::None;
    scarytime = 0;
    this->speed = speed;
    isAlive = true;
    statetime = 0;
    state = State::Scatter;
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

Direction Ghost::getDirection(const Point& pacmanPos, const Point& blinkyPos, Direction pacmanDir) {
    Point current = this->m_position;
    Direction currentDir = this->dir;
    Direction oppo_direction = opposite(currentDir);
    std::vector<std::pair<Direction, Point>> candidates = {
            {Direction::Up,    {current.x, current.y - 1}},
            {Direction::Down,  {current.x, current.y + 1}},
            {Direction::Left,  {current.x - 1, current.y}},
            {Direction::Right, {current.x + 1, current.y}}
    };

    if (state == State::Frightened) {
        std::vector<Direction> validDirs;
        for (const auto& cand : candidates) {
            if (cand.first != oppo_direction && canWalkTo(cand.second)) {
                validDirs.push_back(cand.first);
            }
        }
        if (!validDirs.empty()) {
            return validDirs[std::rand() % validDirs.size()];
        }
        for (const auto& cand : candidates) {
            if (canWalkTo(cand.second)) {
                return cand.first;
            }
        }
        return Direction::None;
    }

    Point target = chase(pacmanPos, blinkyPos, pacmanDir);
    Direction best = Direction::None;
    int bestDist = 999999;

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
