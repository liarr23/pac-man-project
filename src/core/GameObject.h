//
// Created by MrX on 2026/4/28.
//

#ifndef PACMAN_GAMEOBJECT_H
#define PACMAN_GAMEOBJECT_H
#include <SFML/Graphics.hpp>
enum class Direction {UP, DOWN, LEFT, RIGHT,NONE};
struct Point {
    int x;
    int y;
    Point(int x=0, int y=0) : x(x), y(y) {}
    bool operator == (const Point &p) const {
        return x == p.x && y == p.y;
    }
};
class GameObject {
public:
    virtual ~GameObject() = default;
    virtual void update(float deltaTime) = 0;
    virtual void render(sf::RenderWindow& window) = 0;
    virtual sf::FloatRect getBounds() const = 0;
    bool isActive() const;
    void setActive(bool active);
protected:
    Point m_position;
    bool m_active = true;
};
#endif //PACMAN_GAMEOBJECT_H
