#include "Inky.h"

Point Inky::chase(const Point &pacmanPos, const Point &blinkyPos) {
Point goal;
    goal.x = 2*pacmanPos.x - blinkyPos.x;
    goal.y = 2*pacmanPos.y - blinkyPos.y;
    return goal;
}
