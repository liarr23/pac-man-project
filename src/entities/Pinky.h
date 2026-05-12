#pragma once
#include "Ghost.h"

class Pinky : public Ghost {
public:
    Point chase(const Point& pacmanPos, const Point& blinkyPos) override;
    using Ghost::Ghost;
    Point GetPinkyPoint()const ;
    Point GetPinkyStartPoint()const;
};