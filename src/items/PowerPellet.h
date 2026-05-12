#pragma once
#include "Item.h"
class PowerPellet : public Item {
private:
    int m_score = 50;
    sf::Texture m_texture;
    sf::Sprite m_sprite;
public:
    PowerPellet(int x, int y);
    ~PowerPellet() = default;
    ItemType onCollect() override;
    int getScore() const override;
    void render(sf::RenderWindow& window) override;
};