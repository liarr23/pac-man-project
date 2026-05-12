#include "Inky.h"

Point Inky::chase(const Point &pacmanPos, const Point &blinkyPos,Direction pacmanDir) {
    Point ahead = pacmanPos;
    switch (pacmanDir) {
        case Direction::Up:    ahead.y -= 2; break;
        case Direction::Down:  ahead.y += 2; break;
        case Direction::Left:  ahead.x -= 2; break;
        case Direction::Right: ahead.x += 2; break;
        default: break;
    }
    return Point(2 * ahead.x - blinkyPos.x, 2 * ahead.y - blinkyPos.y);
}

Point Inky::GetInkyStartPoint() const{
    return spawnPoint;
}

Point Inky::GetInkyPoint() const {
    return m_position;
}
