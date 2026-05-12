#include "Fruit.h"

Fruit::Fruit(int x, int y) {
    m_position = Point(x, y);
    static constexpr float TILE_SIZE = 32.0f;
    m_texture.loadFromFile("assets/textures/fruit.png"); // TODO: 准备好图片后取消注释或替换路径
    m_sprite.setTexture(m_texture);
    m_sprite.setPosition(x * TILE_SIZE, y * TILE_SIZE);
}

ItemType Fruit::onCollect() {
    return ItemType::Fruit;
}

int Fruit::getScore() const {
    return m_score;
}

void Fruit::render(sf::RenderWindow& window) {
    if (!m_active) return;
    window.draw(m_sprite);
}
