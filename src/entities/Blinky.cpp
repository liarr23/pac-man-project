#include "Blinky.h"
Point Blinky::chase(const Point& pacmanPos, const Point& blinkyPos,Direction pacmanDir) {
    Point goal;
    goal = pacmanPos;
    return goal;
}

Point Blinky::GetBlinkyPos() const {
    return m_position;
}
Point Blinky::GetBlinkyStartPos() const {
    return spawnPoint;
}
