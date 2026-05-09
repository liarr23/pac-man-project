#pragma once
#include "GameState.h"
class PausedState : public GameState {
public:
    void handleInput(GameEngine& engine, sf::Event& event) override;
    void render(sf::RenderWindow& window) override;
};