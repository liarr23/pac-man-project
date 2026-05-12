#include "Item.h"

void Item::update(float deltaTime) {
    (void)deltaTime;
}

void Item::render(sf::RenderWindow& window) {
    if (!m_active) return;
    static constexpr float TILE_SIZE = 32.0f;
    float cx = m_position.x * TILE_SIZE + TILE_SIZE / 2.0f;
    float cy = m_position.y * TILE_SIZE + TILE_SIZE / 2.0f;
    sf::CircleShape shape(4.0f);
    shape.setFillColor(sf::Color(255, 200, 150));
    shape.setOrigin(4.0f, 4.0f);
    shape.setPosition(cx, cy);
    window.draw(shape);
}

sf::FloatRect Item::getBounds() const {
    static constexpr float TILE_SIZE = 32.0f;
    return sf::FloatRect(
        m_position.x * TILE_SIZE, m_position.y * TILE_SIZE,
        TILE_SIZE, TILE_SIZE
    );
}
