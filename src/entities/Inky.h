#pragma once
#include "Ghost.h"
class Inky : public Ghost {
    public:
    Point GetInkyPoint() const;
    Point chase(const Point& pacmanPos, const Point& blinkyPos) override;
};