#pragma once
#include "../core/GameObject.h"

enum class ItemType { Dot, PowerPellet, Fruit };

class Item : public GameObject {
private:
    int m_score = 0;
public:
    Item() = default;
    ~Item() = default;
    void update(float deltaTime) override;
    void render(sf::RenderWindow& window) override;
    sf::FloatRect getBounds() const override;
    virtual ItemType onCollect() = 0;
    virtual int getScore() const = 0;
};
