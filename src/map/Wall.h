#pragma once
#include "../core/GameObject.h"
#include <SFML/Graphics.hpp>

class Wall : public GameObject {
public:
    static constexpr int TILE_SIZE = 32;

    Wall(int x, int y);

    void update(float deltaTime) override;
    void render(sf::RenderWindow& window) override;
    sf::FloatRect getBounds() const override;

private:
    sf::RectangleShape m_shape;
};