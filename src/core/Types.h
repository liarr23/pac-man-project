#pragma once
#include <SFML/Graphics.hpp>

enum class Direction { Up, Down, Left, Right, None };// 方向枚举

enum class State { Chase, Scatter, Frightened, Eaten };//状态枚举

struct Point {// 位置结构体
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

struct Point2 {// 位置结构体
    float x, y;
    Point2 operator+(const Point2& other) const;
    Point2 operator*(float scalar) const;
};

struct GridPos {// 砖块位置

    int row, col;
};
