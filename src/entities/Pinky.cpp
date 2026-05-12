#include "Pinky.h"


Point Pinky::chase(const Point &pacmanPos, const Point &blinkyPos,Direction pacmanDir) {
    Point target = pacmanPos;
    switch (pacmanDir) {
        case Direction::Up:    target.y -= 4; break;
        case Direction::Down:  target.y += 4; break;
        case Direction::Left:  target.x -= 4; break;
        case Direction::Right: target.x += 4; break;
        default: break;
    }
    return target;
}

Point Pinky::GetPinkyPoint() const {
    return m_position;
}

Point Pinky::GetPinkyStartPoint() const {
    return spawnPoint;
}
