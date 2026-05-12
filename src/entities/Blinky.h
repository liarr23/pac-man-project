#pragma once
#include "Character.h"
#include "Ghost.h"

class Blinky : public Ghost {
    public:
    Point chase(const Point& pacmanPos, const Point& blinkyPos,Direction pacmanDir) override;
    using Ghost::Ghost;
    Point GetBlinkyPos()const;
    Point GetBlinkyStartPos()const;
};
