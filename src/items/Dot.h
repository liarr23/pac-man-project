#pragma once
#include "Item.h"
class Dot : public Item {
private:
    int m_score = 10;
    sf::Texture m_texture;
    sf::Sprite m_sprite;
public:
    Dot(int x, int y);
    ~Dot() = default;
    ItemType onCollect() override;
    int getScore() const override;
    void render(sf::RenderWindow& window) override;
};