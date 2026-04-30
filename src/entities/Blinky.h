#pragma once
#include "Character.h"
#include "Ghost.h"

class Blinky : public Ghost {
    public:
    Point GetBlinkyPoint() const;
    Point chase(const Point& pacmanPos, const Point& blinkyPos) override;
};
