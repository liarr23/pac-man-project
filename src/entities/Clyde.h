#pragma once
#include "Ghost.h"
class Clyde : public Ghost {
    public:
    Point chase(const Point& pacmanPos, const Point& blinkyPos, Direction pacmanDir) override;
    void update(float deltaTime) override;
    using Ghost::Ghost;
    Point GetClydeStartPoint()const;
    Point GetClydePoint()const;
private:
    Point m_randomTarget;
    float m_targetTimer = 0;
};