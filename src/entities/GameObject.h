#pragma once
#include "../core/Types.h"

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
