#pragma once
#include <SFML/Graphics.hpp>
class GameEngine {

public:
    GameEngine();
    ~GameEngine();

    void run();
    private:
    void processEvents();
    void update(sf::Time deltaTime);
    void render();
    sf ::RenderWindow window;
    sf ::Clock clock;
};
