#pragma once
#include <SFML/Graphics.hpp>

enum class Direction { Up, Down, Left, Right, None };

enum class GhostState { Chase, Scatter, Frightened, Eaten };

struct Point {
    int x;
    int y;
    Point(int x = 0, int y = 0) : x(x), y(y) {}
    bool operator==(const Point& p) const {
        return x == p.x && y == p.y;
    }
    bool operator < (const Point& p) const {
        return x < p.x || (x == p.x && y < p.y);
    }
};

struct Point2 {
    double x, y;
    Point2(double x = 0, double y = 0) : x(x), y(y) {}
    bool operator==(const Point2& p) const {
        return x == p.x && y == p.y;
    }
    bool operator < (const Point2& p) const {
        return x < p.x || (x == p.x && y < p.y);
    }
};

struct GridPos {
    int row, col;
};
