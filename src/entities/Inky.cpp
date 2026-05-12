#include "Inky.h"

Point Inky::chase(const Point &pacmanPos, const Point &blinkyPos,Direction pacmanDir) {
Point goal;
    goal.x = 2*pacmanPos.x - blinkyPos.x;
    goal.y = 2*pacmanPos.y - blinkyPos.y;
    return goal;
}

Point Inky::GetInkyStartPoint() const{
    return spawnPoint;
}

Point Inky::GetInkyPoint() const {
    return m_position;
}
