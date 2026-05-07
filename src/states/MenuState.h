#pragma once
#include "GameState.h"
class MenuState : public GameState {
public:
    void handleInput(GameEngine& engine, sf::Event& event) override;
    void update(GameEngine& engine, float deltaTime) override;
    void render(sf::RenderWindow& window) override;
};