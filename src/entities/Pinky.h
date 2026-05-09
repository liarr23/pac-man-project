#pragma once
#include "Ghost.h"

class Pinky : public Ghost {
    public:
    Point chase(const Point& pacmanPos, const Point& blinkyPos) override;

};