#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "InputHandler.h"

class GameState;

class GameEngine {
public:
    GameEngine();
    ~GameEngine();
    void run();

    void pushState(GameState* state);
    void popState();
    void changeState(GameState* state);

private:
    void processEvents();
    void update(float deltaTime);
    void render();

    sf::RenderWindow m_window;
    sf::Clock m_clock;
    InputHandler m_inputHandler;
    std::vector<GameState*> m_states;
};
