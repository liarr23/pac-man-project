#pragma once
#include <SFML/Graphics.hpp>

enum class Direction { Up, Down, Left, Right, None };

enum class State { Chase, Scatter, Frightened, Eaten };

struct Point {
    int x;
    int y;
    Point(int x = 0, int y = 0) : x(x), y(y) {}
    bool operator==(const Point& p) const {
        return x == p.x && y == p.y;
    }
};

struct Point2 {
    float x, y;
    Point2 operator+(const Point2& other) const;
    Point2 operator*(float scalar) const;
};

struct GridPos {
    int row, col;
};
