#include "Dot.h"

Dot::Dot(int x, int y) {
    m_position = Point(x, y);
    static constexpr float TILE_SIZE = 32.0f;
    m_texture.loadFromFile("assets/textures/dot.png"); // TODO: 准备好图片后取消注释或替换路径
    m_sprite.setTexture(m_texture);
    m_sprite.setPosition(x * TILE_SIZE, y * TILE_SIZE);
}

ItemType Dot::onCollect() {
    return ItemType::Dot;
}

int Dot::getScore() const {
    return m_score;
}

void Dot::render(sf::RenderWindow& window) {
    if (!m_active) return;
    window.draw(m_sprite);
}
