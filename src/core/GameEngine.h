#pragma once
#include <SFML/Graphics.hpp>
#include "InputHandler.h"
class GameEngine {

public:
    GameEngine();
    ~GameEngine();
    InputHandler m_inputHandler;
    void run();
    private:
    void processEvents();
    void update(sf::Time deltaTime);
    void render();
    sf ::RenderWindow window;
    sf ::Clock clock;
};
