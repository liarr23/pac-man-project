#include "Pinky.h"


Point Pinky::chase(const Point &pacmanPos, const Point &blinkyPos) {
    for (int i=4;i>=-4;i--) {
        for (int j=4;j>=-4;j--) {
            if (canWalkTo(pacmanPos.x+i,pacmanPos.y+j)) {
                return Point(pacmanPos.x+i,pacmanPos.y+j);
            }
        }
    }
    return pacmanPos;
}

Point Pinky::GetPinkyPoint() const {
    return m_position;
}

Point Pinky::GetPinkyStartPoint() const {
    return spawnPoint;
}
