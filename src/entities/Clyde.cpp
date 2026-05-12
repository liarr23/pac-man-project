#include "Clyde.h"
#include "../core/Config.h"
#include <cstdlib>
#include <cmath>

void Clyde::update(float deltaTime) {
    m_targetTimer -= deltaTime;
    if (m_targetTimer <= 0) {
        m_randomTarget = Point(std::rand() % 28, std::rand() % 31);
        m_targetTimer = 2.0f + static_cast<float>(std::rand() % 200) / 100.0f;
    }
}

Point Clyde::chase(const Point &pacmanPos, const Point &, Direction) {
    float dist = std::sqrt(
        (m_position.x - pacmanPos.x) * (m_position.x - pacmanPos.x) +
        (m_position.y - pacmanPos.y) * (m_position.y - pacmanPos.y)
    );
    if (dist > 8.0f) return m_randomTarget;
    return Point(0, Config::MAP_HEIGHT);
}

Point Clyde::GetClydeStartPoint() const {
    return spawnPoint;
}
Point Clyde::GetClydePoint() const {
    return m_position;
}
