#pragma once
#include "Ghost.h"
class Clyde : public Ghost {
    public:
    Point chase(const Point& pacmanPos, const Point& blinkyPos,Direction pacmanDir) override;
    using Ghost::Ghost;
    Point GetClydeStartPoint()const;
    Point GetClydePoint()const;
};