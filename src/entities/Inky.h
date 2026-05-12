#pragma once
#include "Ghost.h"
class Inky : public Ghost {
    public:
    Point GetInkyPoint() const;
    using Ghost::Ghost;
    Point chase(const Point& pacmanPos, const Point& blinkyPos) override;
    Point GetInkyStartPoint() const;
};