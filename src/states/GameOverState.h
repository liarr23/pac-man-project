#pragma once
#include "GameState.h"

class GameOverState : public GameState {
public:
    GameOverState(bool won, int finalScore);
    void handleInput(GameEngine& engine, sf::Event& event) override;
    void update(GameEngine& engine, float deltaTime) override;
    void render(sf::RenderWindow& window) override;

private:
    bool m_won;
    int m_finalScore;
};
