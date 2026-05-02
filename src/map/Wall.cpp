#include "Wall.h"

Wall::Wall(int x, int y) {
    m_position = Point(x, y);
    m_shape.setSize(sf::Vector2f(TILE_SIZE, TILE_SIZE));
    m_shape.setPosition(x * TILE_SIZE, y * TILE_SIZE);
    m_shape.setFillColor(sf::Color(33, 33, 33));
}

void Wall::update(float deltaTime) {
    (void)deltaTime;
}

void Wall::render(sf::RenderWindow& window) {
    if (m_active)
        window.draw(m_shape);
}

sf::FloatRect Wall::getBounds() const {
    return m_shape.getGlobalBounds();
}