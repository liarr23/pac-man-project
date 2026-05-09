#pragma once
#include <SFML/Graphics.hpp>

class GameEngine;

class GameState {
public:
    virtual ~GameState() = default;
    virtual void handleInput(GameEngine& engine, sf::Event& event) = 0;
    virtual void update(GameEngine& engine, float deltaTime);
    virtual void render(sf::RenderWindow& window) = 0;
};
