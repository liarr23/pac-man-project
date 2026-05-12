#include "Clyde.h"
Point Clyde::chase(const Point &pacmanPos, const Point &blinkyPos,Direction pacmanDir) {
    Point goal;
    goal = pacmanPos;
    return goal;
}

Point Clyde::GetClydeStartPoint() const {
    return spawnPoint;
}
Point Clyde::GetClydePoint() const {
    return m_position;
}
