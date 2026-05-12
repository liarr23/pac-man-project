#pragma once
#include "Item.h"
class Fruit : public Item {
private:
    int m_score = 100;
    sf::Texture m_texture;
    sf::Sprite m_sprite;
public:
    Fruit(int x, int y);
    ~Fruit() = default;
    ItemType onCollect() override;
    int getScore() const override;
    void render(sf::RenderWindow& window) override;
};